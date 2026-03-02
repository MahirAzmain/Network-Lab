#include <omnetpp.h>
#include "HandshakeMessage.h"

using namespace omnetpp;

class Receiver : public cSimpleModule {
  protected:
    virtual void handleMessage(cMessage *msg) override {
        HandshakeMessage *hs = check_and_cast<HandshakeMessage *>(msg);

        if (strcmp(hs->getType(), "SYN") == 0) {
            EV << "Receiver: Got Sync-Req with ID " << hs->getMsgId() << "\n";
            // Send ACK back
            HandshakeMessage *syn_ack = new HandshakeMessage("Sync-Ack to sender");
            syn_ack->setType("SYN_ACK");
            syn_ack->setMsgId(hs->getMsgId());
            send(syn_ack, "out");
        }

        else if (strcmp(hs->getType(), "ACK") == 0) {
                  EV << "Receiver: Got ACK with ID " << hs->getMsgId() << "\n";
        }

        delete msg;
    }
};

Define_Module(Receiver);
