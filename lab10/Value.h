#ifndef VALUE_H
#define VALUE_H

#include <ostream>
#include <variant>
#include <string>
#include <stdexcept>
#include "Column.h"
#include "DataTypes.h"

class Value
{
private:
    const Column* _col_pointer;
    
    std::variant<int, double, std::string, bool> _data;
    
    DataTypes _type;

    static bool IsTypeMatching(const std::variant<int, double, std::string, bool>& value, DataTypes t)
    {
        switch (t)
        {
        case DataTypes::Int:
            return std::holds_alternative<int>(value);
        case DataTypes::Double:
            return std::holds_alternative<double>(value);
        case DataTypes::String:
            return std::holds_alternative<std::string>(value);
        case DataTypes::Bool:
            return std::holds_alternative<bool>(value);
        default:
            return false;
        }
    }

public:
    Value(const Column* column, const std::variant<int, double, std::string, bool>& value, DataTypes t)
        : _col_pointer(column), _data(value), _type(t)
    {
        if (!IsTypeMatching(value, t))
        {
            throw std::invalid_argument("Type of value does not match DataTypes!");
        }
    }
    
    const  Column* GetColumn() const { return _col_pointer; }

    std::variant<int, double, std::string, bool> GetData() const { return _data; }

    DataTypes GetType() const { return _type; }

    friend std::ostream& operator<<(std::ostream& os, const Value& value) {
        std::visit([&os](const auto& v) {
            os << v;
        }, value._data);
        return os;
    }
};

#endif // VALUE_H