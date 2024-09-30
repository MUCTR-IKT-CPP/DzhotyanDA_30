#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "characters.h"
#include "guild.h"

using namespace std;

int handleMenu()
{
    int choice;
    int countMercenaries;

    while (true)
    {
        cout << "\n===== Меню =====\n";
        cout << "1. Сгенерировать наемников\n";
        cout << "2. Вывести наемников\n";
        cout << "0. Выйти\n";
        cout << "================\n";
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cin >> countMercenaries;
            break;
        default:
            break;
        }
    }
}

int main()
{
    Guild guild;
    vector<Mercenary> group;
    
    guild.fillRandomGroup(5);
    guild.viewMercenaries();

    int choice;
    cin >> choice;
    if (choice == 1)
    {
        guild.addToGroup(group);
    }

    for (size_t i = 0; i < group.size(); i++)
    {
        group[i].display();
    }

    return 0;
}