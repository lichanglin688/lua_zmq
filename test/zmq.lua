local this = {
    wait_forever = -1,
    
    send_flags = {
        none = 0,
        dontwait = 1,
        sndmore = 2
    },
    recv_flags = {
        none = 0,
        dontwait = 1
    },
    socket_type = {
        pair = 0,
        pub = 1,
        sub = 2,
        req = 3,
        rep = 4,
        dealer = 5,
        router = 6,
        pull = 7,
        push = 8,
        xpub = 9,
        xsub = 10,
        stream = 11
    },
    sockopt ={
        routing_id = 5,
        subscribe = 6
    },
    poll_event = {
        poll_in = 1,
        poll_out = 2,
        poll_err = 4,
        poll_pri = 8,
    },
    monitor_event = {
        zmq_event_connected = 0x0001,
        zmq_event_connect_delayed = 0x0002,
        zmq_event_connect_retried = 0x0004,
        zmq_event_listening = 0x0008,
        zmq_event_bind_failed = 0x0010,
        zmq_event_accepted = 0x0020,
        zmq_event_accept_failed = 0x0040,
        zmq_event_closed = 0x0080,
        zmq_event_close_failed = 0x0100,
        zmq_event_disconnected = 0x0200,
        zmq_event_monitor_stopped = 0x0400,
        zmq_event_handshake_failed_no_detail = 0x0800,
        zmq_event_handshake_succeeded = 0x1000,
        zmq_event_handshake_failed_protocol = 0x2000,
        zmq_event_handshake_failed_auth = 0x4000,
        zmq_event_all = 0xffff
    }
}
return this