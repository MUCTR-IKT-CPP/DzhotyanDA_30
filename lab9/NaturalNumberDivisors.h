#ifndef NATURALNUMBERDIVISORS_H
#define NATURALNUMBERDIVISORS_H

#include <vector>
#include <ostream>
#include <iterator>

class NaturalNumberDivisors {
public:
    NaturalNumberDivisors();

    NaturalNumberDivisors(int num);

    ~NaturalNumberDivisors();

    std::vector<int> GetDivisors();

    double GetAverageOfTheDivisors();

    int BindFindMaxCommonDivisorForTwoNumbers(int a, int b);

    int LambdaFindMaxCommonDivisorForTwoNumbers(int a, int b);

    static int CountNumberGeneratedNumbersThatHaveDivisorConsole(int divisor);

    /**
     * Перегрузка оператора вывода в поток через дружественную функцию
     */
    friend std::ostream& operator<<(std::ostream &os, const NaturalNumberDivisors& naturalNumberDivisors)
    {
        os << "Number: " << naturalNumberDivisors._number << " Divisors: { ";

        std::copy(naturalNumberDivisors._divisors.begin(), naturalNumberDivisors._divisors.end(), std::ostream_iterator<int>(os, " "));

        os << "}";
        return os;
    }

private:
    int _number;
    
    std::vector<int> _divisors;

    void FindDivisors(int num);

    int FindMaxCommonDivisorForTwoNumbers(int a, int b);
};

#endif // NATURALNUMBERDIVISORS_H