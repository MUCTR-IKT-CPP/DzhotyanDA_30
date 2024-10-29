#include <iostream>
#include "Vector.h"

using namespace std;

/**
 * Отображение пользовательского меню для взаимодействия с вектором
 */
template<typename T> int HandleMenuVector(Vector<T>& vector)
{
    int choice;
    int index;
    int element;
    int new_size;

    while (true)
    {
        cout << "\n===== Меню =====\n";
        cout << "1. Получить элементы вектора\n";
        cout << "2. Получить элемент вектора по индексу\n";
        cout << "3. Добавление нового элемента в конец вектора\n";
        cout << "4. Проверить, пустой ли вектор\n";
        cout << "5. Получить размер вектора\n";
        cout << "6. Изменить размер вектора\n";
        cout << "7. Удалить последний элемент вектора\n";
        cout << "8. Получить емкость вектора\n";
        cout << "0. Выйти\n";
        cout << "================\n";
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                for (auto el: vector)
                {
                    cout << el << " ";
                }
                cout << "\n";
                break;
            case 2:
                cout << "Введите индекс: ";
                cin >> index;
                cout << "Элемент под индексом " << index << " равен " << vector[index] << endl;
                break;
            case 3:
                cout << "Введите новый элемент: ";
                cin >> element;
                vector.PushBack(element);
                break;
            case 4:
                vector.IsEmpty() == true ? cout << "Вектор пустой\n" : cout << "Вектор не пустой\n";
                break;
            case 5:
                cout << "Размер вектора: " << vector.GetSize() << endl;
                break;
            case 6:
                cout << "Введите новый размер вектора: ";
                cin >> new_size;
                vector.Resize(new_size);
                break;
            case 7:
                vector.PopBack();
                cout << "Последний элемент вектора удален" << endl;
                break;
            case 8:
                cout << "Емкость вектора: " << vector.GetCapacity() << endl;
                break;
            case 0:
                return 0;
            default:
                break;
        }
    }
}

int main() {
    int size;
    cout << "Введите размер вектора N: ";
    cin >> size;

    Vector<int> vector;
    vector.Create(size);

    vector.FillVector();

    cout << "Вектор заполнен числами от 1 до N" << endl;

    HandleMenuVector(vector);

    return 0;
}