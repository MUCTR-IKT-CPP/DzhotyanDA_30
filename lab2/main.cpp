#include <iostream>

using namespace std;

void reverseOrderTwoDimensionalArray(int** arr, const int N, const int M)
{
    for (int i = 0; i < (int) N / 2; i++)
    {
        for (int j = 0; j < M; j++)
        {
            swap(arr[i][j], arr[N - i - 1][M - j - 1]);
        }
    }

    if (N % 2 == 1)
    {
        for (int i = 0; i < (int) M / 2; i++)
        {
            swap(arr[(int) N / 2][M - i - 1], arr[(int) N / 2][i]);
        }
    }
}

void fillTwoDimensionalArray(int** arr, const int N, const int M)
{
    int x = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = x++;
        }
    }
}

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

int main() {
    int N;
    cin >> N;

    int** arr = new int*[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }

    fillTwoDimensionalArray(arr, N, N);

    cout << "Initial array" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    
    cout << "######" << endl;
    reverseOrderTwoDimensionalArray(arr, N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    
    cout << "######" << endl;
    fillSpiral(arr, N, N);    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}