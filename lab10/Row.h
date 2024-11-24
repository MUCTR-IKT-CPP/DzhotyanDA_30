#ifndef ROW_H
#define ROW_H

#include <vector>
#include "Value.h"

class Row
{
private:
    std::vector<Value> _values;

public:
    void AddValue(const Value& value)
    {
        _values.push_back(value);
    }

    const std::vector<Value>& GetValues() const 
    {
        return _values;
    }
};

#endif