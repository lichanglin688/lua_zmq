require("AresZMQ")
local zmq = require("zmq")
local ZmqMessageRouterHelper = require("ZmqMessageRouterHelper")

local ctx = ZmqContext:getSingleton()
local end_point = "tcp://127.0.0.1:5555"

local backend = ZmqSocket:new(ctx, zmq.socket_type.dealer)
backend:setsockoptString(zmq.sockopt.routing_id, "server1")
backend:connect(end_point)

local frontend = ZmqSocket:new(ctx, zmq.socket_type.dealer)
frontend:setsockoptString(zmq.sockopt.routing_id, ZmqContext:createUuid())
frontend:connect(end_point)

local requestMsgs = backend:recvMultiMessage()
if requestMsgs[3] == "are you online" then
    ZmqMessageRouterHelper.FeedbackResult(backend, requestMsgs, "yes")
end

requestMsgs = backend:recvMultiMessage()
if requestMsgs ~= nil then
    local msg = requestMsgs[3]
    print("get msg ==> ", msg)
    --模拟超时
    backend:recvAndWait(2000)
    ZmqMessageRouterHelper.FeedbackResult(backend, requestMsgs, "11111111111111111")
end

requestMsgs = backend:recvMultiMessage()
if requestMsgs ~= nil then
    local msg = requestMsgs[3]
    print("get msg ==> ", msg)
    ZmqMessageRouterHelper.FeedbackResult(backend, requestMsgs, "4444444444444")
end

--收到消息不回复，模拟崩溃下线
requestMsgs = backend:recvMultiMessage()

os.execute("pause")