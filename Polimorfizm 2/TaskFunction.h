//
// Created by filip on 03.01.2022.
//

#ifndef SYF_TASKFUNCTION_H
#define SYF_TASKFUNCTION_H

#include <tic.h>
#include "Task.h"

class TaskFunction: public Task {

public:
    void *(name());

    TaskFunction(time_t timeGap, void *(name())){
        this->timeGap = timeGap;
        this->name() = name();
    }

    void run() override;

};


#endif //SYF_TASKFUNCTION_H
