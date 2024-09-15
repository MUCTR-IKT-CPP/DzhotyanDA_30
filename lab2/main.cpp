#include <iostream>

using namespace std;

/*
* Создание обратного порядка у двумерного массива
*
* @param arr    указатель на массив
* @param rows   количество строк
* @param cols   количество столбцов
*/
void reverseOrderArray(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < (int) rows / 2; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            swap(arr[i][j], arr[rows - i - 1][cols - j - 1]);
        }
    }

    if (rows % 2 == 1)
    {
        for (int i = 0; i < (int) cols / 2; i++)
        {
            swap(arr[(int) rows / 2][cols - i - 1], arr[(int) rows / 2][i]);
        }
    }
}

/*
* Заполнение двумерного массива значениями
*
* @param arr    указатель на массив
* @param rows   количество строк
* @param cols   количество столбцов
*/
void fillArray(int** arr, const int rows, const int cols)
{
    int x = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = x++;
        }
    }
}

/*
* Заполнение двумерного массива значениями по спирали
*
* @param arr    указатель на массив
* @param rows   количество строк
* @param cols   количество столбцов
*/
void fillSpiral(int** arr, const int rows, const int cols)
{
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int value = 1;

    while (top <= bottom && left <= right) {
        
        for (int i = left; i <= right; ++i) {
            arr[top][i] = value++;
        }
        top++;

        
        for (int i = top; i <= bottom; ++i) {
            arr[i][right] = value++;
        }
        right--;

        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                arr[bottom][i] = value++;
            }
            bottom--;
        }

        
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                arr[i][left] = value++;
            }
            left++;
        }
    }
}

/*
* Вывод двумерного массива
*
* @param arr    указатель на массив
* @param rows   количество строк
* @param cols   количество столбцов
*/
void printArray(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Введите число: ";
    cin >> N;
    cout << endl;

    int** arr = new int*[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }

    fillArray(arr, N, N);

    cout << "Initial array" << endl;
    printArray(arr, N, N);

    int choice;
    while (true)
    {
        cout << "\n===== Меню =====\n";
        cout << "1. Восстановить прямой порядок элементов\n";
        cout << "2. Сделать обратный порядок элементов\n";
        cout << "3. Сделать порядок элементов таким, что бы все значения закручивались по часовой стрелке спиралью от элемента [0, 0] \n";
        cout << "0. Выйти\n";
        cout << "================\n";
        cout << "Выберите действие: ";
        
        cin >> choice;

        switch (choice)
        {
        case 1:
            fillArray(arr, N, N);
            printArray(arr, N, N);
            break;
        case 2:
            reverseOrderArray(arr, N, N);
            printArray(arr, N, N);
            break;
        case 3:
            fillSpiral(arr, N, N);
            printArray(arr, N, N);
            break;
        case 0:
            cout << "Выход из программы" << endl;
            return 0;
        default:
            break;
        }
    }

    return 0;
}