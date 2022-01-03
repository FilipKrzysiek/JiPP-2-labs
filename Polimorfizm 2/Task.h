//
// Created by filip on 03.01.2022.
//

#ifndef SYF_TASK_H
#define SYF_TASK_H
#include "time.h"


class Task {
public:
    time_t timeGap;

    virtual void run();
};


#endif //SYF_TASK_H
