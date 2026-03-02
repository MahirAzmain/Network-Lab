/*
 * MessagePassing.cc
 *
 *  Created on: Sep 10, 2025
 *      Author: Choyan Barua
 */

#include <omnetpp.h>
using namespace omnetpp;

class Node : public cSimpleModule {

  protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};


void Node::initialize() {
    if (strcmp(getName(), "pc1") == 0) {
        cMessage *msg = new cMessage("Hello, hi there");
        msg->setKind(0);
        send(msg, "out");
    }
}

void Node::handleMessage(cMessage *msg) {

    const char* nodeName = getName();
    int incomingKind = msg->getKind();

    cMessage *reply = nullptr;

    if (strcmp(nodeName, "pc2") == 0) {
           // pc2 responses
        if (incomingKind == 0) {
               reply = new cMessage("Hey, I am PC2");
           }
        else if (incomingKind == 2) {
               reply = new cMessage("Yeah!!");
           }
       }
       else if (strcmp(nodeName, "pc1") == 0) {
           // pc1 responses
           if (incomingKind == 1) {
               reply = new cMessage("I am PC1, Are you ready to receive data?");
           }
           else if (incomingKind == 3) {
               reply = new cMessage("Ok!! you will receive the data");
           }
       }

    if (reply != nullptr) {
            reply->setKind(incomingKind + 1);
            EV << nodeName << " sent: " << reply->getName()
               << " kind=" << reply->getKind() << endl;
            send(reply, "out");
    }

    delete msg; // Free received message to avoid memory leaks
}

Define_Module(Node);
