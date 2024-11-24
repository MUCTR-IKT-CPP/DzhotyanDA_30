#ifndef COLUMN_H
#define COLUMN_H

#include <iostream>

class Column
{
private:
    std::string col_name;

public:
    explicit Column(const std::string name) : col_name(name) {}
    
    std::string GetName() const { return col_name; }
};

#endif