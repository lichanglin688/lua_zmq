local zmq = require("zmq")
local this = {
    messageId = 0
}

function this.GenerateMessageId()
    this.messageId = this.messageId + 1
    return tostring(this.messageId)
end

function this.AreYouThere()
    
end

function this.WaitServerOnline(zmqFrontendSocket, serverRouterId, timeout)
    --等待server服务连接上消息路由器
    local startTime = os.clock()
    while true do
        local responeMsg = this.SendAndRecv(zmqFrontendSocket, serverRouterId, "are you online", 10)
        if responeMsg ~= nil then
            print(responeMsg)
            return true
        end

        local endTime = os.clock()
        if endTime - startTime > timeout then
            return false
        end
    end
end

function this.Send(zmqFrontendSocket, serverRouterId, msg)
    local msgId = this.GenerateMessageId()
    zmqFrontendSocket:send(serverRouterId, zmq.send_flags.sndmore)
    zmqFrontendSocket:send(msgId, zmq.send_flags.sndmore)
    zmqFrontendSocket:send(msg)
    return msgId
end

function this.SendAndRecv(zmqFrontendSocket, serverRouterId, msg, timeout)
    timeout = timeout or zmq.wait_forever
    
    local sendMsgId = this.Send(zmqFrontendSocket, serverRouterId, msg)
    while true do
        local recvMsgs = zmqFrontendSocket:recvMultiMessageAndWait(timeout)
        --对应服务返回消息超时（服务崩溃或者处理消息超时），或者本地程序关闭，或者消息路由服务端关闭
        if recvMsgs == nil then
            return nil
        end
        local recvMsgId = recvMsgs[2]
        if recvMsgId == sendMsgId then
            return recvMsgs[3]
        end
        print("timeout ==> ", recvMsgId, recvMsgs[3])
        --消息id不对应，丢弃，这是被请求服务发过来的之前请求的消息，但是超时了
    end
end

function this.FeedbackResult(zmqBackendSocket, requestMsgs, reponseMsg)
    local requestRouterId = requestMsgs[1]
    local msgId = requestMsgs[2]
    zmqBackendSocket:send(requestRouterId, zmq.send_flags.sndmore)
    zmqBackendSocket:send(msgId, zmq.send_flags.sndmore)
    zmqBackendSocket:send(reponseMsg)
end

return this