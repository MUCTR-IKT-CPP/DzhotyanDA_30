#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "Table.h"

class Catalog
{
private:
    std::vector<Table> _tables;
public:
    Catalog() = default;

    void AddTable(const Table& table)
    {
        _tables.push_back(table);
    }

    const std::vector<Table>& GetTables() const
    {
        return _tables;
    }
};

#endif