#include <iostream>

using namespace std;

void combSort(int* data, int N)
{
	double factor = 1.25;
	int step = N - 1;
    
	while (step >= 1)
	{
		for (int i = 0; i + step < N; i++)
		{
			if (data[i] > data[i + step])
			{
				swap(data[i], data[i + step]);
			}
		}
		step /= factor;
	}
}

void fillTwoDimensionalArray(int** arr, int N, int M)
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