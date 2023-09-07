#include "AodvPacket.h"
//kjbkjnknono

void AodvPacket::setType(int type) {
    this->type = type;
}

int AodvPacket::getType() const {
    return type;
}

void AodvPacket::HELLOPacket::setSourceAddr(int source_addr){
    this->source_addr = source_addr;
}

int AodvPacket::RREQPacket::getSourceAddr() const {
    return source_addr;
}

int AodvPacket::RREQPacket:: getSourceSeq() const {
    return source_seq;
}

int AodvPacket::RREQPacket::getBroadcastId() const {
    return broadcast_id;
}

int AodvPacket::RREQPacket::getDestinationAddr() const {
    return dest_addr;
}

int AodvPacket::RREQPacket::getHopCount() const {
    return hop_count;
}

int AodvPacket::RREQPacket::getTTL() const {
    return TTL;
}

void AodvPacket::RREQPacket::setRREQ(int source_addr, int source_seq, int broadcast_id, int dest_addr, int dest_seq, int hop_count, int TTL){
    this->source_addr = source_addr;
    this->source_seq = source_seq;
    this->broadcast_id = broadcast_id;
    this->dest_addr = dest_addr;
    this->dest_seq = dest_seq;
    this->hop_count = hop_count;
    this->TTL = TTL;
}




