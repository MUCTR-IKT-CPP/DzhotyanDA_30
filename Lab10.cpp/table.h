#ifndef TABLE_H
#define TABLE_H

#include "column.h"
#include "identity_column.h"
#include "value_hash.h"
#include "row.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Table
{
private:
  void clean_rows(std::shared_ptr<Column> deleted_col);
  void add_identity(const std::string &type);

public:
  std::string name_;
  std::vector<std::shared_ptr<Column>> data_columns_;
  std::shared_ptr<Column> id_column_;
  std::unordered_map<Value, Row, KeyHash, KeyEqual> rows_;

  explicit Table() = default;
  Table(const std::string &name);
  Table(const std::string &name, const std::string &id_type);

  void add_column(const std::string &name, const std::string &type);
  void remove_column(const std::string &name);

  void add_row(const std::string &data);
  void remove_row(const std::string &id);

  friend std::ostream &operator<<(std::ostream &os, const Table &t);
};

#endif
