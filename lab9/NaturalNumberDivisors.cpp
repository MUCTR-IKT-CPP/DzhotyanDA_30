#include "NaturalNumberDivisors.h"
#include "Constants.h"

#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <functional>

/**
 * Дефолтный конструктор класса хранения делителя натурального числа
 */
NaturalNumberDivisors::NaturalNumberDivisors() = default;

/**
 * Конструктор класса хранения делителя натурального числа
 * 
 * @param  int  натуральное число
 */
NaturalNumberDivisors::NaturalNumberDivisors(int num)
{
    _number = num;
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
    for (int divisor = 1; divisor <= std::sqrt(num); ++divisor)
    {
        if (num % divisor == 0)
        {
            _divisors.push_back(divisor);
            if (divisor != num / divisor)
            {
                _divisors.push_back(num / divisor);
            }
        }
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

/**
 * Проверка того, что у числа есть указанный в консоли делитель
 * 
 * @param  int  делитель
 * 
 * @return bool  логическое значение есть ли делитель у числа
 */
bool NaturalNumberDivisors::ContainsDivisor(int divisor)
{
    for (size_t i = 0; i < _divisors.size(); i++)
    {
        if (_divisors[i] == divisor)
        {
            return true;
        }
    }

    return false;
}

/**
 * Нахождение среднего арифметического делителей числа
 * 
 * @return  double  среднее арифметическое делителей числа
 */
double NaturalNumberDivisors::GetAverageOfTheDivisors()
{
    if (_divisors.empty()) {
        return 0.0;
    }

    int sum = std::accumulate(_divisors.begin(), _divisors.end(), 0);
    return static_cast<double>(sum) / _divisors.size();
}

/**
 * Нахождение наибольшего общего делителя для двух чисел
 * 
 * @param  int  первое число
 * @param  int  второе число
 * 
 * @return  int  наибольший общий делитель
 */
int NaturalNumberDivisors::FindMaxCommonDivisorForTwoNumbers(int a, int b)
{
    std::vector<int> divisors;
    
    std::copy(_divisors.begin(), _divisors.end(), std::back_inserter(divisors));

    std::sort(divisors.begin(), divisors.end());

    for (size_t i = divisors.size() - 1; i >= 0; i--)
    {
        if (a % divisors[i] == 0 && b % divisors[i] == 0)
        {
            return divisors[i];
        }
    }

    return 1;
}

/**
 * Нахождение наибольшего общего делителя для двух чисел через std::bind
 * 
 * @param  int  первое число
 * @param  int  второе число
 * 
 * @return  int  наибольший общий делитель
 */
int NaturalNumberDivisors::BindFindMaxCommonDivisorForTwoNumbers(int a, int b)
{
    auto bind_find_common_divisor = std::bind(&NaturalNumberDivisors::FindMaxCommonDivisorForTwoNumbers, this, a, std::placeholders::_1);

    int result = bind_find_common_divisor(b);
    
    return result;
}

/**
 * Нахождение наибольшего общего делителя для двух чисел через лямбда выражение
 * 
 * @param  int  первое число
 * @param  int  второе число
 * 
 * @return  int  наибольший общий делитель
 */
int NaturalNumberDivisors::LambdaFindMaxCommonDivisorForTwoNumbers(int a, int b)
{
    std::vector<int> divisors;
    std::copy(_divisors.begin(), _divisors.end(), std::back_inserter(divisors));

    std::sort(divisors.begin(), divisors.end());

    auto find_gcd = [&](int x, int y) -> int {
        for (auto it = divisors.rbegin(); it != divisors.rend(); ++it) {
            if (x % *it == 0 && y % *it == 0) {
                return *it;
            }
        }
        return 1;
    };

    return find_gcd(a, b);
}