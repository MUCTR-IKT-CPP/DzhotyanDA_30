#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * Генерация строки, состоящей из английских символов
 * 
 * @param   size    длина строки
 * @return  char*   массив символов
*/
char* generateStringEnglish(int size)
{
    char* str = new char[size];
    for (int i = 0; i < size; i++)
    {
        str[i] = (char) (97 + rand() % (122 - 97 + 1));
    }
    return str;
}

/*
 * Функция для подсчета попыток угадывания символа
 * 
 * @param   target_char     целевой символ, который нужно угадать
 * @return  int             количество попыток
 */
int guessCharacter(char target_char)
{
    int attempts = 0;
    char guessed_char = (char) (97 + rand() % (122 - 97 + 1));

    while (guessed_char != target_char)
    {
        guessed_char = (char) (97 + rand() % (122 - 97 + 1));
        attempts++;
    }

    return attempts;
}

int main()
{
    srand ( time(NULL) );
    
    const int size = 1000;
    char* target_string = generateStringEnglish(size);
    
    int total_attempts = 0;
    int max_attempts_per_char = 0;

    for (int i = 0; i < size; i++)
    {
        int attempts = guessCharacter(target_string[i]);

        total_attempts += attempts;

        if (attempts > max_attempts_per_char)
        {
            max_attempts_per_char = attempts;
        }
    }

    cout << "Total attempts: " << total_attempts << endl;
    cout << "Maximum attempts per char: " << max_attempts_per_char << endl;

    return 0;
}