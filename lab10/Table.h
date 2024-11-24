#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include "Row.h"
#include "Column.h"

class Table
{
private:
    std::vector<Row> _rows;
    std::vector<Column> _cols;
public:
    Table() = default;

    void AddColumn(const std::string colName)
    {
        _cols.emplace_back(colName);
    }

    void AddRow(const Row& row) { _rows.push_back(row); }

    const std::vector<Column>& GetColumns() const 
    {
        return _cols;
    }

    const std::vector<Row>& GetRows() const
    {
        return _rows;
    }
};

#endif