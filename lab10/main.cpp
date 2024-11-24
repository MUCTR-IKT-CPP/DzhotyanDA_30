#include <iostream>
#include <iterator>
#include <sstream>
#include "DataTypes.h"
#include "Catalog.h"

using std::cin;
using std::cout;
using std::endl;

Catalog catalog;

void CreateTable();
void Pause();

/**
 * Отображение пользовательского меню
 */
int handleMenu()
{
    int choice;

    while (true)
    {
        cout << "\n===== Меню =====\n";
        cout << "1. Создать таблицу\n";
        cout << "0. Выйти\n";
        cout << "================\n";
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            CreateTable();
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}

/**
 * Создание таблицы
 */
void CreateTable()
{
    Table table;

    table.AddColumn("Id");

    std::string input;
    std::vector<std::string> columns_names;

    cout << "Введите названия столбцов через пробел : ";

    cin.ignore();
    std::getline(std::cin, input);

    std::istringstream stream(input);
    std::string name;

    while (stream >> name)
    {
        table.AddColumn(name);
        //columns_names.push_back(name);
    }

    /*for (auto& item : columns_names)
    {
        cout << item << endl;
    }*/

   catalog.AddTable(table);

    Pause();
}

/**
 * Функция ожидания
 */
void Pause()
{
    cout << "Нажмите Enter для возврата в меню..." << endl;
    cin.ignore();
    cin.get();
}

int main() {

    handleMenu();

    Table table;

    table.AddColumn("Name");
    table.AddColumn("Age");
    table.AddColumn("Salary");

    Row row1;
    try
    {
        row1.AddValue(Value(&table.GetColumns()[0], 1, DataTypes::String));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    row1.AddValue(Value(&table.GetColumns()[1], 30, DataTypes::Int));
    row1.AddValue(Value(&table.GetColumns()[2], 50000.0, DataTypes::Double));

    Row row2;
    row2.AddValue(Value(&table.GetColumns()[0], std::string("Bob"), DataTypes::String));
    row2.AddValue(Value(&table.GetColumns()[1], 25, DataTypes::Int));
    row2.AddValue(Value(&table.GetColumns()[2], 60000.0, DataTypes::Double));

    // Добавляем строки в таблицу
    table.AddRow(row1);
    table.AddRow(row2);

    // Добавляем таблицу в каталог
    catalog.AddTable(table);

    // Выводим содержимое таблицы
    for (const auto& tbl : catalog.GetTables()) {
        for (const auto& col : tbl.GetColumns()) {
            std::cout << col.GetName() << "\t";
        }
        std::cout << "\n";

        for (const auto& row : tbl.GetRows()) {
            for (const auto& val : row.GetValues()) {
                std::visit([](auto&& v) { std::cout << v << "\t"; }, val.GetData());
            }
            std::cout << "\n";
        }
    }

    return 0;
}
