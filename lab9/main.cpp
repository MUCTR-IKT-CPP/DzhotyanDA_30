#include <iostream>
#include <cstdlib>
#include <time.h>
#include "NaturalNumberDivisors.h"
#include "PrintGeneratedObjects.h"
#include "Constants.h"

using namespace std;

/**
 * Отображение пользовательского меню
 */
int handleMenu()
{
    int choice;

    int N;

    NaturalNumberDivisors* nnds;

    while (true)
    {
        cout << "\n===== Меню =====\n";
        cout << "1. Сгенерировать N объектов класса\n";
        cout << "2. Вывести сгенерированные объекты\n";
        cout << "3. Подсчитать количество сгенерированных чисел, у которых есть указанный в консоли делитель\n";
        cout << "4. Найти среднее арифметическое делителей числа\n";
        cout << "5. Для двух чисел найти наибольший общий делитель\n";
        cout << "0. Выйти\n";
        cout << "================\n";
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                cout << "Введите число N: ";
                cin >> N;
                nnds = new NaturalNumberDivisors[N];

                for (int i = 0; i < N; i++)
                {
                    nnds[i] = NaturalNumberDivisors(MIN_DIVISOR_VALUE + rand() % MAX_DIVISOR_VALUE);
                }
            }
            break;
        case 2:
            PrintGeneratedObjects(nnds, N);
            break;
        case 3:
            {
                int divisor;
                cout << "Введите делитель: ";
                cin >> divisor;
                int count = NaturalNumberDivisors::CountNumberGeneratedNumbersThatHaveDivisorConsole(divisor);
                cout << "Число сгенерированных чисел: " << count << endl;
            }
            break;
        case 4:
            for (int i = 0; i < N; i++)
            {
                cout << "Среднее арифметическое для " << nnds[i] << " равно " << nnds[i].GetAverageOfTheDivisors() << endl;
            }
            break;
        case 5:
            {
                int a, b;
                
                cout << "Введите первое число: ";
                cin >> a;

                cout << "Введите второе число: ";
                cin >> b;

                for (int i = 0; i < N; i++)
                {
                    cout << "Наибольший общий делитель для чисел " << a << " и " << b << ": " 
                    << nnds[i].BindFindMaxCommonDivisorForTwoNumbers(a, b) << "(Bind) "
                    << nnds[i].LambdaFindMaxCommonDivisorForTwoNumbers(a, b) << "(Lambda)"
                    << " " << nnds[i] << endl;
                }
            }
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}

int main()
{
    srand(time(NULL));

    handleMenu();
    
    return 0;
}