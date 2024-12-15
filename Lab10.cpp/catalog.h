#ifndef CATALOG_H
#define CATALOG_H

#include "table.h"
#include <iostream>
#include <string>
#include <unordered_map>

class Catalog
{
private:
  std::unordered_map<std::string, Table> tables_;

public:
  void create_table(const std::string &name);

  void drop_table(const std::string &name);

  Table *get_table(const std::string &name);

  void list_tables();
};

#endif