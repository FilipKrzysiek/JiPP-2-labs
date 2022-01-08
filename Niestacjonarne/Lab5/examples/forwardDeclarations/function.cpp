//
// Created by filip on 20.12.2021.
//

template <typename T>
T add(T a, T b) {
    return a + b;
}

template int add<int>(int, int);
//template double add<double>(double, double);  - Możesz to zakomentować i odkomentować, aby zobaczyć, czy to będzie działać