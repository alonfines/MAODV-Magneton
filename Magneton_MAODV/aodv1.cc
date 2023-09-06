/*
 * aodv1.cc
 *
 *  Created on: Sep 4, 2023
 *      Author: 97254
 */

#include "routingTable.h"
#include <string.h>
#include <omnetpp.h>
#include "AodvPacket.h"

using namespace omnetpp;

class AodvModule : public cSimpleModule
{
private:

    std::vector<AodvRoutingEntry> routingTable;

protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;


    void broadcastHello();
    int getNodeAddress();
    bool hasRouteTo(int destAddress);
    void sendRREQ();
    void sendRREP();
    void sendMessageTo();

};

Define_Module(AodvModule);

void AodvModule::initialize() {

    broadcastHello();
/*
    if (strcmp(getName(), "A") == 0) {

        if (hasRouteTo(6)) {
            sendMessageTo(6);
        }
        else {
            sendRREQ(6);
        }
    }
}

*/
}

 //

void AodvModule::broadcastHello()
{
    AodvPacket *helloPacket = new AodvPacket("HELLO");
    helloPacket->setType(HELLO);
    source_addr = getAddress();
    helloPacket ->setSourceAddr(source_addr);
    send(helloPacket, "out");
}

int AodvModule::getAddress() {
    return par("address").longValue();
}

bool AodvModule::hasRouteTo(int destAddress) {
    for (const AodvRoutingEntry &entry : routingTable) {
        if (entry.destAddress == destAddress) {
            return true;
        }
    return false;
}


void AodvModule::sendRREQ(int destAdress, int nextHop) {
    AodvPacket *pkt = new AodvPacket("AODV Packet Name");
    pkt->setType(RREQ);

    }
    */
    /*

void AodvModule::sendMessageTo(int destAdress, int nextHop) {
    cMessage *helloMsg = new cMessage("hello");
    // Logic to send "hello" to "F", maybe via sendDirect() or any other method depending on your design.
    send(helloMsg, "out");

}
*/

void AodvModule::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        handleTimer(msg);
    }
    else {
        // Handle incoming messages, e.g., RREQ, RREP, etc.
        AodvPacket *packet = check_and_cast<AodvPacket *>(msg);
        switch (packet->getType()) {
            case RREQ:
                processRREQ(packet);
                break;
            case RREP:
                processRREP(packet);
                break;
            // ... handle other packet types...
            default:
                EV_ERROR << "Unknown AODV packet type";
                delete msg;
        }
    }


void AodvModule::processRREQ(AodvPacket *packet) {
    // Basic RREQ processing
    // 1. Check if destination is this node
    // 2. Update routing table
    // 3. Forward RREQ if needed
    // ... and so on
}

void AodvModule::processRREP(AodvPacket *packet) {
    // Basic RREP processing
    // 1. Check if the source is this node
    // 2. Update routing table
    // 3. Forward RREP if needed
    // ... and so on
}

void AodvModule::handleTimer(cMessage *msg) {
    // Handle timers, e.g., route expiration, RREQ retries, etc.
    // Update the routing table, send RREQ if needed, etc.
}

// ... further methods, utilities, etc. ...
