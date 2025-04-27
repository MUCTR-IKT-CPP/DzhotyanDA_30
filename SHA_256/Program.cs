using System.Diagnostics;

namespace lab9_algo
{
    class Program
    {
        static void Main()
        {
            Test1();
            Test2();
            Test3();
        }

        static void Test1()
        {
            SHA_256 sha_256 = new();

            const int N = 1000;
            const int STRING_LENGTH = 128;

            int[] differentCharactersCount = [1, 2, 4, 8, 16];

            string[] generatedStrings = new string[N];
            string[] generatedStringOneSymbolDifference = new string[N];
            string[] generatedStringTwoSymbolsDifference = new string[N];
            string[] generatedStringFourSymbolsDifference = new string[N];
            string[] generatedStringEightSymbolsDifference = new string[N];
            string[] generatedStringSixteenSymbolsDifference = new string[N];

            string[] hashOriginalStrings = new string[N];
            string[] hashOneSymbolDifference = new string[N];
            string[] hashTwoSymbolsDifference = new string[N];
            string[] hashFourSymbolsDifference = new string[N];
            string[] hashEightSymbolsDifference = new string[N];
            string[] hashSixteenSymbolsDifference = new string[N];

            int maxSubstringLengthOneSymbolDifference = 0;
            int maxSubstringLengthTwoSymbolsDifference = 0;
            int maxSubstringLengthFourSymbolsDifference = 0;
            int maxSubstringLengthEightSymbolsDifference = 0;
            int maxSubstringLengthSixteenSymbolsDifference = 0;

            // Генерация строк
            for (int i = 0; i < N; i++)
            {
                string generatedStr = GenerateString(STRING_LENGTH);
                generatedStrings[i] = generatedStr;
            }

            // Замена символов в строках
            for (int i = 0; i < N; i++)
            {
                string originalStr = generatedStrings[i];
                foreach (var count in differentCharactersCount)
                {
                    char[] strChars = originalStr.ToCharArray();
                    int length = strChars.Length;

                    int step = length / count;

                    for (int j = 0; j < count; j++)
                    {
                        int indexToChange = j * step;
                        if (indexToChange >= length)
                            indexToChange = length - 1;

                        char symbol = strChars[indexToChange];

                        if (symbol == 'z')
                        {
                            symbol = (char)(symbol - 1);
                        }
                        else if (symbol >= 'a' && symbol < 'z')
                        {
                            symbol = (char)(symbol + 1);
                        }
                        else if (symbol == 'Z')
                        {
                            symbol = (char)(symbol - 1);
                        }
                        else if (symbol >= 'A' && symbol < 'Z')
                        {
                            symbol = (char)(symbol + 1);
                        }
                        strChars[indexToChange] = symbol;
                    }

                    switch (count)
                    {
                        case 1:
                            generatedStringOneSymbolDifference[i] = new string(strChars);
                            break;
                        case 2:
                            generatedStringTwoSymbolsDifference[i] = new string(strChars);
                            break;
                        case 4:
                            generatedStringFourSymbolsDifference[i] = new string(strChars);
                            break;
                        case 8:
                            generatedStringEightSymbolsDifference[i] = new string(strChars);
                            break;
                        case 16:
                            generatedStringSixteenSymbolsDifference[i] = new string(strChars);
                            break;
                    }
                }
            }

            // Вычисление хешей
            for (int i = 0; i < N; i++)
            {
                hashOriginalStrings[i] = sha_256.GetHash(generatedStrings[i]);
                hashOneSymbolDifference[i] = sha_256.GetHash(generatedStringOneSymbolDifference[i]);
                hashTwoSymbolsDifference[i] = sha_256.GetHash(generatedStringTwoSymbolsDifference[i]);
                hashFourSymbolsDifference[i] = sha_256.GetHash(generatedStringFourSymbolsDifference[i]);
                hashEightSymbolsDifference[i] = sha_256.GetHash(generatedStringEightSymbolsDifference[i]);
                hashSixteenSymbolsDifference[i] = sha_256.GetHash(generatedStringSixteenSymbolsDifference[i]);
            }

            // Нахождение максимальных длин одинаковых подстрок
            for (int i = 0; i < N; i++)
            {
                string originalHash = hashOriginalStrings[i];
                string oneSymbolDifferenceHash = hashOneSymbolDifference[i];
                string twoSymbolsDifferenceHash = hashTwoSymbolsDifference[i];
                string fourSymbolsDifferenceHash = hashFourSymbolsDifference[i];
                string eightSymbolsDifferenceHash = hashEightSymbolsDifference[i];
                string sixteenSymbolsDifferenceHash = hashSixteenSymbolsDifference[i];

                int length = originalHash.Length;

                int lengthOne = 0;
                int lengthTwo = 0;
                int lengthFour = 0;
                int lengthEight = 0;
                int lengthSixteen = 0;

                for (int j = 0; j < length; j++)
                {
                    // 1 отличие в строках
                    if (originalHash[j] == oneSymbolDifferenceHash[j])
                    {
                        lengthOne++;
                    }
                    else
                    {
                        if (lengthOne > maxSubstringLengthOneSymbolDifference)
                        {
                            maxSubstringLengthOneSymbolDifference = lengthOne;
                        }
                        lengthOne = 0;
                    }
                    if (lengthOne > maxSubstringLengthOneSymbolDifference)
                    {
                        maxSubstringLengthOneSymbolDifference = lengthOne;
                    }

                    // 2 отличия в строках
                    if (originalHash[j] == twoSymbolsDifferenceHash[j])
                    {
                        lengthTwo++;
                    }
                    else
                    {
                        if (lengthTwo > maxSubstringLengthTwoSymbolsDifference)
                        {
                            maxSubstringLengthTwoSymbolsDifference = lengthTwo;
                        }
                        lengthTwo = 0;
                    }
                    if (lengthTwo > maxSubstringLengthTwoSymbolsDifference)
                    {
                        maxSubstringLengthTwoSymbolsDifference = lengthTwo;
                    }

                    // 4 отличия в строках
                    if (originalHash[j] == fourSymbolsDifferenceHash[j])
                    {
                        lengthFour++;
                    }
                    else
                    {
                        if (lengthFour > maxSubstringLengthFourSymbolsDifference)
                        {
                            maxSubstringLengthFourSymbolsDifference = lengthFour;
                        }
                        lengthFour = 0;
                    }
                    if (lengthFour > maxSubstringLengthFourSymbolsDifference)
                    {
                        maxSubstringLengthFourSymbolsDifference = lengthFour;
                    }

                    // 8 отличий в строках
                    if (originalHash[j] == eightSymbolsDifferenceHash[j])
                    {
                        lengthEight++;
                    }
                    else
                    {
                        if (lengthEight > maxSubstringLengthEightSymbolsDifference)
                        {
                            maxSubstringLengthEightSymbolsDifference = lengthEight;
                        }
                        lengthEight = 0;
                    }
                    if (lengthEight > maxSubstringLengthEightSymbolsDifference)
                    {
                        maxSubstringLengthEightSymbolsDifference = lengthEight;
                    }

                    // 16 отличий в строках
                    if (originalHash[j] == sixteenSymbolsDifferenceHash[j])
                    {
                        lengthSixteen++;
                    }
                    else
                    {
                        if (lengthSixteen > maxSubstringLengthSixteenSymbolsDifference)
                        {
                            maxSubstringLengthSixteenSymbolsDifference = lengthSixteen;
                        }
                        lengthSixteen = 0;
                    }
                    if (lengthSixteen > maxSubstringLengthSixteenSymbolsDifference)
                    {
                        maxSubstringLengthSixteenSymbolsDifference = lengthSixteen;
                    }
                }
            }

            Console.WriteLine($"Максимальная длина одинаковых подстрок для 1 отличия: {maxSubstringLengthOneSymbolDifference}");
            Console.WriteLine($"Максимальная длина одинаковых подстрок для 2 отличий: {maxSubstringLengthTwoSymbolsDifference}");
            Console.WriteLine($"Максимальная длина одинаковых подстрок для 4 отличий: {maxSubstringLengthFourSymbolsDifference}");
            Console.WriteLine($"Максимальная длина одинаковых подстрок для 8 отличий: {maxSubstringLengthEightSymbolsDifference}");
            Console.WriteLine($"Максимальная длина одинаковых подстрок для 16 отличий: {maxSubstringLengthSixteenSymbolsDifference}");
            Console.WriteLine("-------------------------------------------------------");
        }

        static void Test2()
        {
            const int STRING_LENGTH = 256;

            SHA_256 sha_256 = new();
            Dictionary<int, int> generationsHashCollisions = [];
            
            for (int i = 2; i <= 6; i++)
            {
                int N = (int)Math.Pow(10, i);
                HashSet<string> hash = [];
                for (int j = 0; j < N; j++)
                {
                    string generatedString = GenerateString(STRING_LENGTH);
                    string generatedHash = sha_256.GetHash(generatedString);
                    hash.Add(generatedHash);
                }
                int collisions = N - hash.Count;
                generationsHashCollisions.Add(N, collisions);
            }

            Console.WriteLine($"{"Количество генераций",25} | {"Количество совпадений",25}");
            Console.WriteLine(new string('-', 55));
            foreach (var kvp in generationsHashCollisions)
            {
                Console.WriteLine($"{kvp.Key,25} | {kvp.Value,25}");
            }
        }

        static void Test3()
        {
            SHA_256 sha_256 = new();
            Stopwatch stopwatch = new();

            const int N = 1000;

            int[] lengths = [64, 128, 256, 512, 1024, 2048, 4096, 8192];

            double[] avgStopwatch = new double[lengths.Length];

            for(int j = 0; j < lengths.Length; j++)
            {
                int length = lengths[j];
                for (int i = 0; i < N; i++)
                {
                    string generatedString = GenerateString(length);
                    stopwatch.Start();
                    sha_256.GetHash(generatedString);
                    stopwatch.Stop();
                    avgStopwatch[j] += stopwatch.Elapsed.TotalMilliseconds;
                }
                avgStopwatch[j] /= N;
            }

            Console.WriteLine($"{"Длина строки",25} | {"Время (мс)",25}");
            Console.WriteLine(new string('-', 55));
            for (int j = 0; j < lengths.Length; j++)
            {
                Console.WriteLine($"{lengths[j],25} | {avgStopwatch[j],25}");
            }
        }

        static string GenerateString(int length)
        {
            Random random = new();
            string str = "";
            for (int j = 0; j < length; j++)
            {
                int isUpperCase = random.Next(0, 2);

                if (isUpperCase == 0)
                {
                    str += (char)random.Next(97, 123); // a-z
                }
                else
                {
                    str += (char)random.Next(65, 91); // A-Z
                }
            }
            return str;
        }
    }
}
