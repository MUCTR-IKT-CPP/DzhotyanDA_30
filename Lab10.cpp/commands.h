#ifndef COMMANDS_H
#define COMMANDS_H

#include "catalog.h"

void help();

void execute(Catalog &catalog, std::string command);

void create_table(Catalog &catalog);

void create_table_test(Catalog &catalog, std::string name);

void drop_table(Catalog &catalog);

void drop_table_test(Catalog &catalog, std::string name);

void add_column(Catalog &catalog);

void add_column_test(Catalog &catalog, std::string tableName, std::string colName, std::string colType);

void remove_column(Catalog &catalog);

void remove_column_test(Catalog &catalog, std::string tableName, std::string colName);

void add_row(Catalog &catalog);

void add_row_test(Catalog &catalog, std::string tableName, std::string rowData);

void remove_row(Catalog &catalog);

void remove_row_test(Catalog &catalog, std::string tableName, std::string row_id);

void print(Catalog &catalog);

void print_test(std::ostream &os, Catalog &catalog, std::string table_name);

#endif