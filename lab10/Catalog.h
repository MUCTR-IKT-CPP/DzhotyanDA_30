#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <map>
#include <string>
#include "Table.h"

class Catalog
{
private:
    std::map<std::string, Table> _tables;
public:
    Catalog() = default;

    void AddTable(const std::string name, const Table& table)
    {
        if (_tables.count(name))
        {
            std::string choice;
            std::cout << "Таблица с таким названием уже существует! Хотите заменить ее?\n" << std::endl;
            std::cin >> choice;

            if (choice == "Да")
            {
                _tables[name] = table;
            }
            else if (choice != "Да")
            {
                return;
            }
        }
        else
        {
            _tables[name] = table;
        }
    }

    Table& GetTableByName(std::string name)
    {
        return _tables[name];
    }

    const std::map<std::string, Table>& GetTables() const
    {
        return _tables;
    }
};

#endif