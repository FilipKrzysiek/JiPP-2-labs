//
// Created by filip on 20.12.2021.
//

#ifndef JIPP_2_LABS_FUNCTION_H
#define JIPP_2_LABS_FUNCTION_H

template <typename T>
T add(T a, T b) {
    static_assert(!std::is_same<decltype(a), double>::value, "Passing double is forbidden!!");
    return a + b;
}

#endif //JIPP_2_LABS_FUNCTION_H
