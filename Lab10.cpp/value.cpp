#include "value.h"
#include <iostream>
#include <iomanip>

Value::Value(std::shared_ptr<Column> col, const std::string &data)
    : column_(col), data_(data) {}

bool Value::validate() {
  if (column_->get_type() == "int") {
    try {
      stoi(data_);
    } catch (...) {
      return false;
    }
  } else if (column_->get_type() == "float") {
    try {
      stof(data_);
    } catch (...) {
      return false;
    }
  } else if (column_->get_type() == "string") {
    return false;
  }
  return true;
}

std::ostream &operator<<(std::ostream &os, const Value &v) {
  os << std::fixed << std::setprecision(6) << v.data_;
  return os;
}