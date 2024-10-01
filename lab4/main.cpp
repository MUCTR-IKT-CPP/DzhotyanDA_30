#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "characters.h"
#include "guild.h"

using namespace std;

Guild guild;
vector<Mercenary> group;

/**
 * Вывод группы наемников пользователя
 * 
 * @param group группа пользователя
 */
void printGroup(vector<Mercenary> group)
{
    cout << "======================== Ваша группа ========================" << endl;
    for (size_t i = 0; i < group.size(); i++)
    {
        group[i].display();
    }   
}

/**
 * Отображение пользовательского меню
 */
int handleMenu()
{
    int choice;
    int countMercenaries;
    string addToGroupChoice;

    while (true)
    {
        cout << "\n===== Меню =====\n";
        cout << "1. Сгенерировать наемников\n";
        cout << "2. Вывести наемников\n";
        cout << "3. Добавить в группу\n";
        cout << "4. Вывести группу\n";
        cout << "0. Выйти\n";
        cout << "================\n";
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите количество наемников: ";
            cin >> countMercenaries;
            guild.fillRandomGroup(countMercenaries);
            
            guild.viewMercenaries();
            cout << "Хотите добавить их в свою группу? Введите YES, иначе NO" << endl;
            cin >> addToGroupChoice;
            
            if (addToGroupChoice == "YES")
            {
                guild.addToGroup(group);
            }
            break;
        case 2:
            guild.viewMercenaries();
            break;
        case 3:
            guild.addToGroup(group);
            break;
        case 4:
            printGroup(group);
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}

int main()
{   
    handleMenu();
    return 0;
}