//
// Created by filip on 20.12.2021.
//

#ifndef JIPP_2_LABS_TRIPLE_H
#define JIPP_2_LABS_TRIPLE_H

template<typename type1, typename type2, typename type3>
class Triple {
private:
    type1 variable1;
    type2 variable2;
    type3 variable3;

public:
    Triple(type1 variable1, type2 variable2, type3 variable3): variable1(variable1), variable2(variable2), variable3(variable3) {}

    type1 getVariable1() {
        return variable1;
    }

    type2 getVariable2() {
        return variable2;
    }

    type3 getVariable3() {
        return variable3;
    }
};

#endif //JIPP_2_LABS_TRIPLE_H
