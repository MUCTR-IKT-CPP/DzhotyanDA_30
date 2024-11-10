#include "NaturalNumberDivisors.h"

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> NaturalNumberDivisors::_divisors {1};

/**
 * Конструктор класса хранения делителя натурального числа
 * 
 * @param  int  натуральное число
 */
NaturalNumberDivisors::NaturalNumberDivisors(int num)
{
    FindDivisors(num);
}

/**
 * Деструктор класса хранения делителя натурального числа
 */
NaturalNumberDivisors::~NaturalNumberDivisors() = default;

/**
 * Нахождение делителей натурального числа
 * 
 * @param  int  натуральное число
 */
void NaturalNumberDivisors::FindDivisors(int num)
{
    int divisorsCount = (int) std::floor(sqrt(num));
    
    int divisor = 2;

    while (divisorsCount > 0)
    {
        if (num % divisor == 0)
        {
            _divisors.push_back(divisor);
            divisorsCount--;
        }
        divisor++;
    }
}

/**
 * Получение делителей натурального числа
 * 
 * @return  vector<int>  вектор делителей
 */
std::vector<int> NaturalNumberDivisors::GetDivisors()
{
    return _divisors;
}