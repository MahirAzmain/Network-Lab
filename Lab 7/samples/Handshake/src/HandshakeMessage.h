/*
 * HandshakeMessage.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Choyan Barua
 */

// HandshakeMessage.h
#include <omnetpp.h>
using namespace omnetpp;
using namespace std;
class HandshakeMessage : public cMessage {
  private:
    string type;  // "REQ" or "ACK" and "Data"
    int msgId;

  public:
    HandshakeMessage(const char *name=nullptr) : cMessage(name) {}

    void setType(const string &t) { type = t; }
    const char *getType() const { return type.c_str(); }

    void setMsgId(int id) { msgId = id; }
    int getMsgId() const { return msgId; }
};
