#include <iostream>
#include "commands.h"

int main()
{
  Catalog catalog;
  std::string command;

  std::cout << "Вводите команды" << std::endl;

  while (true)
  {
    std::cin >> command;
    execute(catalog, command);
  }

  return 0;
}
