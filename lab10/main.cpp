#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include "DataTypes.h"
#include "Catalog.h"

using std::cin;
using std::cout;
using std::endl;

Catalog catalog;

void CreateTable();
void InsertDataToTable();
void DisplayTable();
void Pause();

/**
 * Отображение пользовательского меню
 */
int handleMenu()
{
    int choice;

    while (true)
    {
        cout << "\n===== Меню =====\n";
        cout << "1. Создать таблицу\n";
        cout << "2. Заполнить таблицу данными\n";
        cout << "3. Вывести таблицу\n";
        cout << "0. Выйти\n";
        cout << "================\n";
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            CreateTable();
            break;
        case 2:
            InsertDataToTable();
            break;
        case 3:
            DisplayTable();
        case 0:
            return 0;
        default:
            break;
        }
    }
}

/**
 * Создание таблицы
 */
void CreateTable()
{
    std::string table_name;
    
    cout << "Введите название таблицы: ";
    cin >> table_name;

    Table table = Table(table_name);

    table.AddColumn("Id");

    std::string input;
    std::vector<std::string> columns_names;

    cout << "Введите названия столбцов через пробел : ";

    cin.ignore();
    std::getline(std::cin, input);

    std::istringstream stream(input);
    std::string name;

    while (stream >> name)
    {
        table.AddColumn(name);
        columns_names.push_back(name);
    }

   catalog.AddTable(table_name, table);

    cout << "Создана таблица " + table_name + " со столбцами ";

    for (const auto& item : columns_names)
    {
        cout << item << " ";
    }

    cout << endl;

    Pause();
}

void InsertDataToTable()
{
    std::string table_name;
    
    cout << "Введите название таблицы: ";
    cin >> table_name;

    Table& table = catalog.GetTableByName(table_name);

    std::cout << "Вводите строки данных (формат: Value1, Value2, Value3;)\n";
    std::cout << "Введите ; чтобы закончить ввод данных.\n";

    std::cin.ignore();

    const auto& columns = table.GetColumns();
    size_t num_columns = columns.size();

    std::string input;

    while (true)
    {
        std::getline(std::cin, input);

        if (input == ";")
        {
            break;
        }

        Row row;

        if (input.back() == ';')
        {
            input.pop_back();
        }

        std::stringstream ss(input);
        std::string value;
        const auto& columns = table.GetColumns(); // Получаем список колонок таблицы

        size_t col_index = 0; // Индекс текущей колонки
        
        while (std::getline(ss, value, ','))
        {
            // Убираем лишние пробелы вокруг значения
            value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());

            if (col_index >= columns.size())
            {
                std::cerr << "Ошибка: количество значений превышает количество колонок в таблице.\n";
                break;
            }

            // Определяем тип данных текущей колонки
            const auto& column = columns[col_index];
            DataTypes col_type = column.GetType();

            // Добавляем значение с учетом типа данных
            if (col_type == DataTypes::String)
            {
                row.AddValue(Value(&column, value, DataTypes::String));
            }
            else if (col_type == DataTypes::Int)
            {
                try {
                    row.AddValue(Value(&column, std::stoi(value), DataTypes::Int));
                }
                catch (const std::exception&) {
                    std::cerr << "Ошибка: невозможно преобразовать '" << value << "' в Int.\n";
                    break;
                }
            }
            else if (col_type == DataTypes::Double)
            {
                try {
                    row.AddValue(Value(&column, std::stod(value), DataTypes::Double));
                }
                catch (const std::exception&) {
                    std::cerr << "Ошибка: невозможно преобразовать '" << value << "' в Double.\n";
                    break;
                }
            }
            else if (col_type == DataTypes::Bool)
            {
                if (value == "true" || value == "1")
                {
                    row.AddValue(Value(&column, true, DataTypes::Bool));
                }
                else if (value == "false" || value == "0")
                {
                    row.AddValue(Value(&column, false, DataTypes::Bool));
                }
                else
                {
                    std::cerr << "Ошибка: невозможно преобразовать '" << value << "' в Bool.\n";
                    break;
                }
            }

            ++col_index; // Переходим к следующей колонке
        }
        
        if (col_index < columns.size())
        {
            std::cerr << "Ошибка: количество значений меньше количества колонок.\n";
            continue;
        }
        
        table.AddRow(row);
    }
}

void DisplayTable()
{
    std::string table_name;
    
    cout << "Введите название таблицы: ";
    cin >> table_name;

    Table& table = catalog.GetTableByName(table_name);

    cout << table.GetName() << endl;

    for (const auto& row : table.GetRows()) 
    {
        for (const auto& val : row.GetValues())
        {
            std::visit([](auto&& v) { std::cout << v << "\t"; }, val.GetData());
        }
        std::cout << "\n";
    }
}

/**
 * Функция ожидания
 */
void Pause()
{
    cout << "Нажмите Enter для возврата в меню...";
    cin.get();
}

int main() {

    handleMenu();

    /*Table table;

    table.AddColumn("Name");
    table.AddColumn("Age");
    table.AddColumn("Salary");

    Row row1;
    try
    {
        row1.AddValue(Value(&table.GetColumns()[0], 1, DataTypes::String));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    row1.AddValue(Value(&table.GetColumns()[1], 30, DataTypes::Int));
    row1.AddValue(Value(&table.GetColumns()[2], 50000.0, DataTypes::Double));

    Row row2;
    row2.AddValue(Value(&table.GetColumns()[0], std::string("Bob"), DataTypes::String));
    row2.AddValue(Value(&table.GetColumns()[1], 25, DataTypes::Int));
    row2.AddValue(Value(&table.GetColumns()[2], 60000.0, DataTypes::Double));

    // Добавляем строки в таблицу
    table.AddRow(row1);
    table.AddRow(row2);

    // Добавляем таблицу в каталог
    catalog.AddTable(table);

    // Выводим содержимое таблицы
    for (const auto& tbl : catalog.GetTables()) {
        for (const auto& col : tbl.GetColumns()) {
            std::cout << col.GetName() << "\t";
        }
        std::cout << "\n";

        for (const auto& row : tbl.GetRows()) {
            for (const auto& val : row.GetValues()) {
                std::visit([](auto&& v) { std::cout << v << "\t"; }, val.GetData());
            }
            std::cout << "\n";
        }
    }*/

    return 0;
}
