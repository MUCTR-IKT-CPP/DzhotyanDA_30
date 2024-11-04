#include <iostream>
#include <cstdlib>
#include "Gun.h"
#include "Patron.h"
#include "Magazine.h"

using namespace std;

int main() {
    srand(time(NULL));

    // Генерация патрон
    Patron** patrons = Magazine().GeneratePatrons();
    
    Gun g = Gun(patrons);

    g.Shoot();
    
    return 0;
}