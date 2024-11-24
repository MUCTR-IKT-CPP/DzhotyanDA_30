#ifndef DATATYPES_H
#define DATATYPES_H

#include <ostream>

enum class DataTypes {
    Int,
    Double,
    String,
    Bool
};

std::ostream& operator<<(std::ostream& os, DataTypes type)
{
    switch (type)
    {
    case DataTypes::Int:
        os << "Int";
        break;
    case DataTypes::Double:
        os << "Double";
        break;
    case DataTypes::String:
        os << "String";
        break;
    case DataTypes::Bool:
        os << "Bool";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

#endif // DATATYPES_H