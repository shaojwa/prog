

#ifndef PROTO_H
#define PROTO_H

#include "type.h"

#define MAX_LEN_IP 16

struct request_t {
    uint16_t module;
    uint16_t command;
};

struct pkt_header_t {
    uint16_t magic;
    uint8_t version;
    uint8_t header_len;
    uint8_t module;
    uint8_t command;
    uint16_t check_sum;
    uint32_t data_len;
    uint8_t  pkt_data[0];
};

struct item_header_t {
    uint16_t magic;
    uint16_t item_len;
    uint8_t  item_data[0];
};

struct tlv_t {
    uint16_t type;
    uint16_t len;
    uint8_t value[0];
};


class Pkt {
public:
    Pkt(uint8_t version = 0);
    ~Pkt();
    void cleanup();
    void create(uint8_t module, uint8_t command);
    uint32_t getLen();
    const uint8_t *getBuf(void);
    static bool parse(uint8_t *buff);
    bool addItem(void);

private:
    static const uint32_t kPktBugLenMax = 1024 * 1024;
    static const uint16_t kPktMagic = 0x07d7;
    static const uint16_t kItemMagic = 0x0203;
    uint8_t m_szBuf[kPktBugLenMax];
    uint32_t m_nLen;
};


#endif