require("AresZMQ")
zmq = require("zmq")
Loop = require("Loop")
local ctx = ZmqContext:getSingleton()
local end_point = "inproc://test"
local router = ZmqSocket:new(ctx, zmq.socket_type.router)
router:bind(end_point)

local dealer = ZmqSocket:new(ctx, 5)
dealer:setsockoptString(zmq.sockopt.routing_id, "dealer")
dealer:connect(end_point)

dealer:send("123456")
print(router:recv())
print(router:recv())

local timer = ZmqTimer:new(ZmqContext:getSingleton(), zmq.socket_type.pub)
timer:startTimer(5000, "inproc://time5000");
timer:startTimer(3000, "inproc://time3000");

local timer5000 = ZmqSocket:new(ZmqContext:getSingleton(), zmq.socket_type.sub)
timer5000:setsockoptString(zmq.sockopt.subscribe, "")
timer5000:connect("inproc://time5000");

local timer3000 = ZmqSocket:new(ZmqContext:getSingleton(), zmq.socket_type.sub)
timer3000:setsockoptString(zmq.sockopt.subscribe, "")
timer3000:connect("inproc://time3000");

local loop = Loop:new()
loop:add(timer3000, function ()
            print("3s", timer3000:recv())
            print("timer3000")
end)

loop:add(timer5000, function ()
    print("5s", timer5000:recv())
    print("timer5000")
end)
loop:start()
