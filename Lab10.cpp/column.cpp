#include "column.h"

Column::Column(const std::string &name, const std::string &type)
    : name_(name), type_(type) {}

std::string Column::get_name()
{
    return name_;
}

std::string Column::get_type()
{
    return type_;
}