require("AresZMQ")
local zmq = require("zmq")
local ZmqMessageRouterHelper = require("ZmqMessageRouterHelper")


local ctx = ZmqContext:getSingleton()
local end_point = "tcp://127.0.0.1:5555"

local backend = ZmqSocket:new(ctx, zmq.socket_type.dealer)
backend:setsockoptString(zmq.sockopt.routing_id, "server2")
backend:connect(end_point)

local frontend = ZmqSocket:new(ctx, zmq.socket_type.dealer)
frontend:setsockoptString(zmq.sockopt.routing_id, ZmqContext:createUuid())
frontend:connect(end_point)

ZmqMessageRouterHelper.WaitServerOnline(frontend, "server1", 1000)
--等待server1服务连接上消息路由器
-- while true do
--     local responeMsg = ZmqMessageRouterHelper.SendAndRecv(frontend, "server1", "is there ?", 10)
--     if responeMsg ~= nil then
--         print(responeMsg)
--         break
--     end
--     print("1")
-- end

--模拟超时
local responeMsg = ZmqMessageRouterHelper.SendAndRecv(frontend, "server1", "2222222222222", 1000)
print("responeMsg1 ==> ", responeMsg)

responeMsg = ZmqMessageRouterHelper.SendAndRecv(frontend, "server1", "3333333333333", 3000)
print("responeMsg2 ==> ", responeMsg)

--模拟崩溃下线
responeMsg = ZmqMessageRouterHelper.SendAndRecv(frontend, "server1", "3333333333333", 3000)
print("responeMsg3 ==> ", responeMsg)

os.execute("pause")
