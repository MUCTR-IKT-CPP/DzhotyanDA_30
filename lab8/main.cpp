#include <iostream>
#include <cstdlib>
#include "Gun.h"
#include "Patron.h"
#include "Magazine.h"

using namespace std;

/**
 * Отображение пользовательского меню
 */
int handleMenu()
{
    int choice;

    while (true)
    {
        cout << "\n===== Меню =====\n";
        cout << "1. Симмуляция процесса стрельбы из оружия\n";
        cout << "0. Выйти\n";
        cout << "================\n";
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Генерация патрон
            Patron** patrons = Magazine().GeneratePatrons();
            
            Gun gun = Gun(patrons);
            gun.SimulatingShootingProcess();

            break;
        }
        case 0:
            return 0;
        default:
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    handleMenu();
    
    return 0;
}