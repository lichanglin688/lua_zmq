require("AresZMQ")
zmq = require("zmq")

local ctx = ZmqContext:getSingleton()

local end_point = "tcp://127.0.0.1:5555"
local router = ZmqSocket:new(ctx, zmq.socket_type.router)

local monitor = ZmqMonitor:new()
local pair_socket = monitor:init(router, "inproc://test")

router:bind(end_point)

local dealer = ZmqSocket:new(ctx, zmq.socket_type.dealer)
dealer:connect(end_point)
dealer:send("1")

router:send("target", zmq.send_flags.sndmore)
router:send("1")

print(monitor:recv())
print(monitor:recv())
local eventid, value, end_point = monitor:recv()
print(eventid & zmq.monitor_event.zmq_event_connected)
-- print(monitor:recv())

-- pair_socket:recvMultiMessage()

os.execute("pause")

