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

/*
* Размещение элементов вдоль побочной диагонали
* 
* @param arr    указатель на массив
* @param N      количество строк и столбцов
*/
void fillByMainDiagonal(int** arr, int N)
{
    int value = 1;
    for(int j = N - 1; j >= 0; j--)
    {
        int count = N - j - 1;
        int i = 0;
        int temp_j = j;        
        arr[i][temp_j] = value++;

        while(count != 0)
        {
            i++;
            temp_j++;
            arr[i][temp_j] = value++;                       
            count--;                     
        }        
    }

    for(int i = 1; i < N; i++)
    {
        int count = (N-1)-i;
        int j = 0;
        int temp_i = i;
        arr[temp_i][j] = value++;        

        while(count != 0)
        {
            temp_i++;
            j++;        
            arr[temp_i][j] = value++;
            count--;                     
        }
    }
}

/*
* Размещение элементов вдоль побочной диагонали
* 
* @param arr    указатель на массив
* @param N      количество строк и стоблцов
*/
void fillBySideDiagonal(int** arr, int N)
{
    int value = 1;
    for(int j = 0; j < N; j++)
    {
        int count = j;
        int i = 0;
        int temp_j = j;
        arr[i][temp_j] = value++;

        while(count != 0)
        {
            i++;
            temp_j--;        
            arr[i][temp_j] = value++;
            count--;                     
        }
    }

    for(int i = 1; i < N; i++)
    {
        int count = (N - 1) - i;
        int j = N - 1;
        int temp_i = i;
        arr[temp_i][j] = value++;        

        while(count != 0)
        {
            temp_i++;
            j--;        
            arr[temp_i][j] = value++;
            count--;                     
        }
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
        cout << "4. Сделать порядок элементов вдоль главной диагонали\n";
        cout << "5. Сделать порядок элементов вдоль побочной диагонали\n";
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
        case 4:
            fillByMainDiagonal(arr, N);
            printArray(arr, N, N);
            break;
        case 5:
            fillBySideDiagonal(arr, N);
            printArray(arr, N, N);
            break;
        case 0:
            cout << "Выход из программы" << endl;
            
            for (int i = 0; i < N; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
            
            return 0;
        default:
            break;
        }
    }

    return 0;
}