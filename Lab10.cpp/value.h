#ifndef VALUE_H
#define VALUE_H

#include "column.h"
#include <memory>
#include <string>

class Value {
public:
  std::shared_ptr<Column> column_;
  std::string data_;

  explicit Value() = default;
  Value(std::shared_ptr<Column> col, const std::string &data);

  bool validate();
  friend std::ostream &operator<<(std::ostream &os, const Value &v);
};

#endif