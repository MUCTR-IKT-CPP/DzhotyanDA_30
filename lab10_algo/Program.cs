using System;

namespace lab10_algo
{
    class Program
    {
        static void Main()
        {
            const int GAMES_COUNT = 10000;
            
            string[] allCombinations = ["000", "001", "010", "011", "100", "101", "110", "111"];
            double[,] winTable = new double[allCombinations.Length, allCombinations.Length];

            Random rnd = new();

            double totalA = 0;
            double totalB = 0;
            int totalPairs = allCombinations.Length * allCombinations.Length;

            for (int i = 0; i < allCombinations.Length; i++)
            {
                for (int j = 0; j < allCombinations.Length; j++)
                {
                    string combinationA = allCombinations[i];
                    string combinationB = allCombinations[j];
                    int winsA = 0;

                    for (int game = 0; game < GAMES_COUNT; game++)
                    {
                        string sequence = "";
                        while (true)
                        {
                            sequence += FlipCoin(rnd);

                            if (sequence.Length >= 3)
                            {
                                string last3 = sequence.Substring(sequence.Length - 3, 3);

                                if (last3 == combinationA)
                                {
                                    if (last3 != combinationB)
                                        winsA++;
                                    break;
                                }
                                else if (last3 == combinationB)
                                {
                                    break;
                                }
                            }
                        }
                    }

                    double winProbability = (double)winsA / GAMES_COUNT;
                    winTable[i, j] = winProbability;

                    totalA += winProbability;
                    totalB += (1.0 - winProbability);
                }
            }
            Console.WriteLine("Вероятности выигрыша Игрока A против Игрока B");
            Console.Write("      ");
            foreach (var col in allCombinations)
                Console.Write($"{col}   ");
            Console.WriteLine();

            for (int i = 0; i < allCombinations.Length; i++)
            {
                Console.Write($"{allCombinations[i]} | ");
                for (int j = 0; j < allCombinations.Length; j++)
                {
                    Console.Write($"{winTable[i, j]:0.000} ");
                }
                Console.WriteLine();
            }

            double avgA = totalA / totalPairs;
            double avgB = totalB / totalPairs;

            Console.WriteLine($"\nСредний шанс победы игрока A: {avgA:0.000}");
            Console.WriteLine($"Средний шанс победы игрока B: {avgB:0.000}");

        }

        static string FlipCoin(Random rnd)
        {
            return rnd.Next(2) == 0 ? "0" : "1";
        }
    }
}
