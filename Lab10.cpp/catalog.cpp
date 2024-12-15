#include "catalog.h"

void Catalog::create_table(const std::string &name)
{
  if (tables_.find(name) != tables_.end())
  {
    throw std::runtime_error("Таблица уже существует");
  }
  tables_[name] = Table(name);
}

void Catalog::drop_table(const std::string &name)
{
  if (tables_.erase(name) == 0)
  {
    throw std::runtime_error("Таблица не найдена");
  }
}

Table *Catalog::get_table(const std::string &name)
{
  if (tables_.find(name) == tables_.end())
  {
    throw std::runtime_error("Таблица не найдена");
  }
  return &tables_[name];
}

void Catalog::list_tables()
{
  for (const auto &[name, table] : tables_)
  {
    std::cout << name << '\n';
  }
}