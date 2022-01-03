//
// Created by filip on 03.01.2022.
//

#ifndef SYF_TASKCLASS_H
#define SYF_TASKCLASS_H

#include "Task.h"
#include "TaskClassTemplate.h"

class TaskClass: public Task {

public:
    TaskClassTemplate *classToRun;
    void run() override;

    TaskClass(time_t timeGap, TaskClassTemplate *classToRun): classToRun(classToRun) {
        this->timeGap = timeGap;
    }
};


#endif //SYF_TASKCLASS_H
