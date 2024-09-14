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
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    
    cout << "######" << endl;
    reverseOrderTwoDimensionalArray(arr, N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}