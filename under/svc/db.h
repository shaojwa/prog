

#ifndef DB_H
#define DB_H

#include "type.h"
#include "pth.h"

class Db {
public: 
    Db();
    ~Db();
    static uint32_t __stdcall wait2crud(void* pParam);
private:
    Pth *m_pThreadCRUD;
};

#endif