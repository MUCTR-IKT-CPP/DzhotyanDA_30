#include "commands.h"

/**
 * Обработка комманд
 * 
 * @param   Catalog&   ссылка на каталог
 */
void execute(Catalog &catalog, std::string command)
{
  if (command == "exit")
  {
    return;
  }
  else if (command == "help")
  {
    help();
  }
  else if (command == "create")
  {
    create_table(catalog);
  }
  else if (command == "drop")
  {
    drop_table(catalog);
  }
  else if (command == "list")
  {
    catalog.list_tables();
  }
  else if (command == "add_column")
  {
    add_column(catalog);
  }
  else if (command == "remove_column")
  {
    remove_column(catalog);
  }
  else if (command == "add_row")
  {
    add_row(catalog);
  }
  else if (command == "remove_row")
  {
    remove_row(catalog);
  }
  else if (command == "print")
  {
    print(catalog);
  }
  else
  {
    std::cout << "Неизвестная команда" << '\n';
  }
}

/**
 * Функция вызова команды помощи
 */
void help()
{
  std::cout << "Доступные команды: " << '\n';
  std::cout << "help - вывести список доступных команд" << '\n';
  std::cout << "exit - выйти из приложения" << '\n';
  std::cout << "create - создать таблицу" << '\n';
  std::cout << "drop - удалить таблицу" << '\n';
  std::cout << "list - вывести список таблиц" << '\n';
  std::cout << "add_column - добавить столбец в таблицу" << '\n';
  std::cout << "remove_column - удалить столбец из таблицы" << '\n';
  std::cout << "add_row - добавить строку в таблицу" << '\n';
  std::cout << "remove_row - удалить строчку из таблицы" << '\n';
  std::cout << "print - вывести каталог" << '\n';
}

/**
 * Функция вывода
 * 
 * @param   Catalog&    ссылка на каталог
 */
void print(Catalog &catalog)
{
  std::string tableName;
  std::cout << "Введите имя таблицы: ";
  std::cin >> tableName;
  print_test(std::cout, catalog, tableName);
}

void print_test(std::ostream &os, Catalog &catalog, std::string table_name)
{
  try
  {
    Table *table = catalog.get_table(table_name);
    if (table)
      os << *table;
  }
  catch (const std::runtime_error &error)
  {
    os << error.what() << '\n';
  }
}

/**
 * Добавление строки
 * 
 * @param   Catalog&    ссылка на каталог
 */
void add_row(Catalog &catalog)
{
  std::string tableName, rowData;
  std::cout << "Введите имя таблицы и данные строки через ; : ";
  std::cin >> tableName;
  std::cin.ignore();
  std::getline(std::cin, rowData);
  add_row_test(catalog, tableName, rowData);
}

void add_row_test(Catalog &catalog, std::string tableName, std::string rowData)
{
  try
  {
    Table *table = catalog.get_table(tableName);
    if (table)
      table->add_row(rowData);
    std::cout << "Done\n";
  }
  catch (const std::runtime_error &error)
  {
    std::cout << error.what() << '\n';
  }
}

/**
 * Удаление строки
 * 
 * @param   Catalog&    ссылка на каталог
 */
void remove_row(Catalog &catalog)
{
  std::string tableName, row_id;
  std::cout << "Введите имя таблицы и идентификатор строки: ";
  std::cin >> tableName >> row_id;
  remove_row_test(catalog, tableName, row_id);
}

void remove_row_test(Catalog &catalog, std::string tableName, std::string row_id)
{
  try
  {
    Table *table = catalog.get_table(tableName);
    if (table)
      table->remove_row(row_id);
    std::cout << "Done\n";
  }
  catch (const std::runtime_error &error)
  {
    std::cout << error.what() << '\n';
  }
}

/**
 * Удаление столбца
 * 
 * @param   Catalog&    ссылка на каталог
 */
void remove_column(Catalog &catalog)
{
  std::string tableName, colName;
  std::cout << "Введите имя таблицы и столбца: ";
  std::cin >> tableName >> colName;
  remove_column_test(catalog, tableName, colName);
}

void remove_column_test(Catalog &catalog, std::string tableName, std::string colName)
{
  try
  {
    Table *table = catalog.get_table(tableName);
    if (table)
      table->remove_column(colName);
    std::cout << "Done\n";
  }
  catch (const std::runtime_error &error)
  {
    std::cout << error.what() << '\n';
  }
}

/**
 * Добавление столбца
 * 
 * @param   Catalog&    ссылка на каталог
 */
void add_column(Catalog &catalog)
{
  std::string tableName, colName, colType;
  std::cout << "Введите имя таблицы, столбца и тип: ";
  std::cin >> tableName >> colName >> colType;
  add_column_test(catalog, tableName, colName, colType);
}

void add_column_test(Catalog &catalog, std::string tableName, std::string colName, std::string colType)
{
  try
  {
    Table *table = catalog.get_table(tableName);
    if (table)
      table->add_column(colName, colType);
    std::cout << "Done\n";
  }
  catch (const std::runtime_error &error)
  {
    std::cout << error.what() << '\n';
  }
}

/**
 * Удаление таблицы
 * 
 * @param   Catalog&    ссылка на каталог
 */
void drop_table(Catalog &catalog)
{
  std::string name;
  std::cout << "Введите имя таблицы: ";
  std::cin >> name;
  drop_table_test(catalog, name);
}

void drop_table_test(Catalog &catalog, std::string name)
{
  try
  {
    catalog.drop_table(name);
    std::cout << "Done\n";
  }
  catch (const std::runtime_error &error)
  {
    std::cout << error.what() << '\n';
  }
}

/**
 * Создание таблицы
 * 
 * @param   Catalog&    ссылка на каталог
 */
void create_table(Catalog &catalog)
{
  std::string name;
  std::cout << "Введите имя таблицы: ";
  std::cin >> name;
  create_table_test(catalog, name);
}

void create_table_test(Catalog &catalog, std::string name)
{
  try
  {
    catalog.create_table(name);
    std::cout << "Done\n";
  }
  catch (const std::runtime_error &error)
  {
    std::cout << error.what() << '\n';
  }
}
