

#ifndef WORKER_H
#define WORKER_H

#include "config.h"
#include <windows.h>

enum WORKER_STATE {
    WORKER_STATE_IDLE = 0,
    WORKER_STATE_FIND = 1,
    WORKER_STATE_COPY = 2
};
#endif 