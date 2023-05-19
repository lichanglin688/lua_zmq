require("AresZMQ")
zmq = require("zmq")
local ctx = ZmqContext:getSingleton()

local end_point = "tcp://127.0.0.1:5555"
local stream = ZmqSocket:new(ctx, zmq.socket_type.stream)
stream:bind(end_point)


local msgs = ""
function RecvData(msg, callback)
    print("recv msg ==> ", msg)
    msgs = msgs..msg

    local start_pos = 0
    local messages = {}
    while true do
        local find_start_pos, find_end_pos = string.find(msgs, "\r\n", start_pos)
        if find_start_pos == nil then
            break
        end

        table.insert(messages, string.sub(msgs, start_pos, find_start_pos - 1))
        start_pos = find_end_pos + 1
    end
    if start_pos ~= 0 then
        msgs = string.sub(msgs, start_pos)
    end

    for index, value in ipairs(messages) do
        print("parse ==> ", value)
        callback(value)
    end
end
local id = stream:recv()
local empty = stream:recv()
print("id==>",id)

while true do
    local id = stream:recv()
    local isExit = false
    RecvData(stream:recv(), function (msg)
        if msg == "exit" then
            isExit = true
        end
    end)
    if isExit then
        break
    end
end
os.execute("pause")