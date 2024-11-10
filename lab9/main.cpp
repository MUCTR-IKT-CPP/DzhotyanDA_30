#include <iostream>
#include <vector>
#include "NaturalNumberDivisors.h"

using namespace std;

int main()
{
    NaturalNumberDivisors nnd = NaturalNumberDivisors(15);
    vector<int> result = nnd.GetDivisors();
    for (int item: result)
    {
        cout << item << endl;
    }
    return 0;
}