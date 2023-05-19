require("AresZMQ")
zmq = require("zmq")
local ctx = ZmqContext:getSingleton()

local end_point = "tcp://127.0.0.1:5555"
local stream = ZmqSocket:new(ctx, zmq.socket_type.stream)
stream:connect(end_point)
local router_id = stream:getSockoptString(zmq.sockopt.routing_id)

--连接成功或断开时都会收到下面这样的两帧消息
local router_id_1 = stream:recv()
local empty = stream:recv()

--这两种方式得到的router_id一样
print(router_id_1, router_id)
local router_id_size = #router_id_1
stream:sendBySize(router_id_1, router_id_size, zmq.send_flags.sndmore)
stream:send("123\r\n", zmq.send_flags.none)

stream:sendBySize(router_id_1, router_id_size, zmq.send_flags.sndmore)
stream:send("456")

stream:sendBySize(router_id_1, router_id_size, zmq.send_flags.sndmore)
stream:send("789\r\n")

stream:sendBySize(router_id_1, router_id_size, zmq.send_flags.sndmore)
stream:send("789\r\n")

stream:sendBySize(router_id_1, router_id_size, zmq.send_flags.sndmore)
stream:send("exit\r\n")

os.execute("pause")