#ifndef NATURALNUMBERDIVISORS_H
#define NATURALNUMBERDIVISORS_H

#include <vector>

class NaturalNumberDivisors {
public:
    NaturalNumberDivisors(int num);

    ~NaturalNumberDivisors();

    std::vector<int> GetDivisors();

private:
    static std::vector<int> _divisors;

    void FindDivisors(int num);
};

#endif // NATURALNUMBERDIVISORS_H