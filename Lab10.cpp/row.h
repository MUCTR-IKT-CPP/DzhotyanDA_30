#ifndef ROW_H
#define ROW_H

#include "value.h"
#include <iostream>
#include <string>
#include <vector>
#include "identity_column.h"

class Row
{
private:
  std::vector<Value> values_;

public:
  explicit Row() = default;

  void add_value(std::shared_ptr<Column> column, const std::string &data);
  void remove_value(std::shared_ptr<Column> column);

  friend std::ostream &operator<<(std::ostream &os, const Row &r);
};

#endif