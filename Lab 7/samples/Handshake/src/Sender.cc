#include <omnetpp.h>
#include "HandshakeMessage.h"

using namespace omnetpp;
//3-Way handshaking
class Sender : public cSimpleModule {
  private:
    int msgId = 0;

  protected:
    virtual void initialize() override {
        // Start the handshake
        HandshakeMessage *req_syn = new HandshakeMessage("Sync-Request to Receiver");
        req_syn->setType("SYN");
        req_syn->setMsgId(msgId++);
        send(req_syn, "out");

        EV << "Sender: Sent Sync-Req with ID " << req_syn->getMsgId() << "\n";
    }

    virtual void handleMessage(cMessage *msg) override {
        HandshakeMessage *hs = check_and_cast<HandshakeMessage *>(msg);

        if (strcmp(hs->getType(), "SYN_ACK") == 0) {

            EV << "Sender: Received SYNC-ACK with ID " << hs->getMsgId() << "\n";
            HandshakeMessage *ack = new HandshakeMessage("Ack to Receiver");
            ack->setType("ACK");
            ack->setMsgId(hs->getMsgId());
            send(ack, "out");

        }

        delete msg;
    }
};

Define_Module(Sender);
