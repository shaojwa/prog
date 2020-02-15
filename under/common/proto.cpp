

#include "proto.h"

#include <Winsock2.h>

Pkt::Pkt (uint8_t version): m_nLen(0) {
    pkt_header_t *header = (pkt_header_t *)m_szBuf;
    header->magic = htons(kPktMagic);
    header->version = version;
    header->header_len = sizeof(pkt_header_t);
    header->module = 0;
    header->command = 0;
    header->check_sum = 0;
    header->data_len = 0;
}


Pkt::~Pkt() {
}


void Pkt::cleanup() {
    memset(m_szBuf, 0, sizeof(m_szBuf));
}

uint32_t Pkt::getLen() {
    return m_nLen;
}
const uint8_t *Pkt::getBuf(void) {
    return m_szBuf;
}


void Pkt::create(uint8_t module, uint8_t command) {
    pkt_header_t *header = (pkt_header_t *)m_szBuf;
    header->module = module;
    header->command = command;
}

bool Pkt::addItem(void){
    return true;
}