#include "message_processor.h"
#include "message_queue.h"

MessageProcessor::MessageProcessor(MessageQueue* q, QThread *parent) : QThread(parent), q_(q)
{

}
void MessageProcessor::run()
{
    do {
        if(q_ == Q_NULLPTR || q_->isAbort())
            return;

        for(;;){
            QSharedPointer<MessagePacket> pkt = q_->pop();

            if(pkt.isNull())
                return;

            pkt->process();

            if(pkt->type() == MessagePacket::Text){
                QSharedPointer<TextMessage> msg = pkt.dynamicCast<TextMessage>();
                if(msg){
                    //do something
                }
            }
            if(pkt->type() == MessagePacket::Binary){
                QSharedPointer<BinaryMessage> msg = pkt.dynamicCast<BinaryMessage>();
                if(msg){
                    //do something
                }
            }
        }

    }while (!q_->isAbort());
}
