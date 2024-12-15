#include "table.h"
#include <iomanip>
#include <iostream>

Table::Table(const std::string &name) : name_(name) { add_identity("int"); }

Table::Table(const std::string &name, const std::string &id_type)
    : name_(name)
{
  add_identity(id_type);
}

void Table::add_identity(const std::string &type)
{
  id_column_ = std::make_shared<IdentityColumn>(type);
}

void Table::clean_rows(std::shared_ptr<Column> deleted_col)
{
  for (auto &[val, row] : rows_)
  {
    row.remove_value(deleted_col);
  }
}

void Table::add_column(const std::string &name, const std::string &type)
{
  if (name == IDENTITY_STR)
  {
    throw std::runtime_error("Имя зарезервировано системой! ");
  }
  for (const auto& column : data_columns_)
  {
    if (column->get_name() == name)
    {
      throw std::runtime_error("Столбец уже существует");
    }
  }
  data_columns_.push_back(std::make_shared<Column>(name, type));
}

void Table::remove_column(const std::string &name)
{
  auto iter = data_columns_.begin();
  for (; iter != data_columns_.end(); iter++)
  {
    if ((*iter)->get_name() == name)
    {
      clean_rows(*iter);
      data_columns_.erase(iter);
      return;
    }
  }
  throw std::runtime_error("Столбец не найден");
}

void Table::add_row(const std::string &data)
{
  Row row;
  std::vector<std::string> values;
  std::string temp;
  for (char c : data)
  {
    if (c == ';')
    {
      values.push_back(temp);
      temp = "";
    }
    else
    {
      temp += c;
    }
  }
  values.push_back(temp);
  std::string id = values[0];
  values.erase(values.begin());

  if (values.size() != data_columns_.size())
  {
    throw std::runtime_error(
        "Ошибка: количество значений не соответствует количеству столбцов");
  }

  int i = 0;
  for (auto column : data_columns_)
  {
    row.add_value(column, values[i++]);
  }
  Value val(id_column_, id);
  if (rows_.find(val) != rows_.end())
  {
    throw std::runtime_error(
        "Ошибка: столбец с заданным идентификатором уже существует");
  }
  rows_[val] = row;
}

void Table::remove_row(const std::string &id)
{
  Value val(id_column_, id);
  if (rows_.erase(val) == 0)
  {
    throw std::runtime_error("Не найдено строк с заданным идентификатором! ");
  }
}

std::ostream &operator<<(std::ostream &os, const Table &v)
{
  os << std::fixed << std::setprecision(6) << v.id_column_->get_name() << " ";
  for (const auto& column : v.data_columns_)
  {
    os << std::fixed << std::setprecision(6) << column->get_name() << " ";
  }
  std::cout << '\n';

  for (auto &[val, row] : v.rows_)
  {
    os << val << ":" << row << '\n';
  }
  return os;
}