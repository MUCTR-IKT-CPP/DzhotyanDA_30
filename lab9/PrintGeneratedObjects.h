#ifndef PRINTGENERATEDOBJECTS_H
#define PRINTGENERATEDOBJECTS_H

#include <iostream>

template <typename T>
void PrintGeneratedObjects(T* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

#endif // PRINTGENERATEDOBJECTS_H