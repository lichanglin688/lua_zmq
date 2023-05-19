if AresZMQ == nil then
    require("AresZMQ")
end

local zmq = require("zmq")

local this = {}

function this:new()
    local o = {};
    setmetatable(o,self)
    self.__index = self
    o.poller = ZmqPoller:new()
    o.sockets = {}
    return o
end

function this:add(zmqSocket, callback, event)
    if event == nil then
        event = zmq.poll_event.poll_in
    end

    self.poller:add(zmqSocket, event)
    table.insert(self.sockets, {
        socket = zmqSocket,
        callback = callback
    })
end

function this:start(timeout)
    if timeout == nil then
        timeout = zmq.wait_forever
    end
    while true do
        if self.poller:poll(timeout) > 0 then
            for index, value in ipairs(self.sockets) do
                if self.poller:has_in(value.socket) then
                    value.callback()
                end
            end
        else
            print("=====loop=====poll===error===")
        end
    end
end

return this