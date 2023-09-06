// AodvPacket.h

#ifndef AODVPACKET_H
#define AODVPACKET_H

#include <omnetpp.h>

// Define the packet types for AODV
enum AodvPacketType {
    HELLO = 1,
    RREQ = 2,
    RREP = 3,
    RERR = 4,
    DATA = 5,

};

// Base packet class for AODV
class AodvPacket : public omnetpp::cPacket {
protected:
    int type;  // to store the AodvPacketType

public:
    AodvPacket(int type);
    int getType() const;
    void setType(int type);
    // ... any other general methods or members common to all AODV packets
};

// HELLO packet
class HELLOPacket : public AodvPacket {
protected:
    int source_addr=0;
    void setSourceAddr(int source_addr);
};


// RREQ packet
class RREQPacket : public AodvPacket {
protected:
    int source_addr = 0;
    int source_seq = 0;
    int broadcast_id = 1;
    int dest_addr = 0;
    int dest_seq = 0;
    int hop_count = 0;
    int TTL = 10;

    // ... members specific to RREQ like source address, destination address, etc.

public:
    RREQPacket();
    int getSourceAddr() const;
    int getSourceSeq() const;
    int getBroadcastId() const;
    int getDestinationAddr() const;
    int getDestinationSeq() const;
    int getHopCount() const;
    int getTTL() const;
    void setRREQ(int source_addr, int source_seq, int broadcast_id, int dest_addr, int dest_seq, int hop_count,int TTL=10);

    // ... getter and setter methods for RREQ-specific members
};

// RREP packet
class RREPPacket : public AodvPacket {

public:
    RREPPacket();
    // ... getter and setter methods for RREP-specific members
};



// ... Similarly, you can define other packet types like RERR, RACK, etc.

#endif  // AODVPACKET_H
