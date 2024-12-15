#include "row.h"
#include <exception>

void Row::add_value(std::shared_ptr<Column> column, const std::string &data)
{
  if (column->get_name() == IDENTITY_STR)
  {
    throw std::runtime_error("Идентификатор строки задается в таблице! ");
  }
  Value value(column, data);
  if (!value.validate())
  {
    throw std::runtime_error("Ошибка валидации значения для столбца: " + column->get_name());
  }
  values_.push_back(value);
}

std::ostream &operator<<(std::ostream &os, const Row &r)
{
  for (const auto& value : r.values_)
  {
    os << value << ' ';
  }
  return os;
}

void Row::remove_value(const std::shared_ptr<Column> column)
{
  if (column->get_name() == IDENTITY_STR)
  {
    throw std::runtime_error("Нельзя удалить значение-идентификатор из строки!");
  }
  auto iter = values_.begin();
  for (; iter != values_.end(); iter++)
  {
    if (iter->column_.get() == column.get())
    {
      values_.erase(iter);
      return;
    }
  }
}