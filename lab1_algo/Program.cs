using System.Diagnostics;

namespace lab1_algo
{
    public class Program
    {
        public static void Main()
        {
            Random random = new();
            Stopwatch stopwatch = new();

            const int numberOfVectorGeneration = 20;
            
            int[] itemsCountArray = [1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000];

            Dictionary<int, long[]> resultStopwatch = [];

            foreach (var N in itemsCountArray)
            {
                Console.Write($"N = {N}: ");
                long[] timeMeasurements = new long[numberOfVectorGeneration];
                for (int j = 0; j < numberOfVectorGeneration; j++)
                {
                    double[] nums = new double[N];

                    for (int i = 0; i < nums.Length; i++)
                    {
                        nums[i] = random.NextDouble() * (1 - (-1)) - 1;
                    }

                    stopwatch.Start();
                    CocktailSortAsc(nums);
                    stopwatch.Stop();

                    timeMeasurements[j] = stopwatch.ElapsedMilliseconds;

                    Console.Write(stopwatch.ElapsedMilliseconds + " ");

                    stopwatch.Reset();
                }
                Console.WriteLine();
                resultStopwatch.TryAdd(N, timeMeasurements);
            }

            WriteToFile(resultStopwatch);
        }

        public static void CocktailSortAsc(double[] arr)
        {
            int left = 0;
            int right = arr.Length - 1;

            while (left < right)
            {
                for (int i = left; i < right; i++)
                {
                    if (arr[i] > arr[i + 1])
                    {
                        (arr[i + 1], arr[i]) = (arr[i], arr[i + 1]);
                    }
                }
                right--;

                for (int i = right; i > left; i--)
                {
                    if (arr[i] > arr[i + 1])
                    {
                        (arr[i + 1], arr[i]) = (arr[i], arr[i + 1]);
                    }
                }
                left++;
            }
        }

        public static void WriteToFile(Dictionary<int, long[]> resultStopwatch)
        {
            var path = "C:\\Users\\david\\source\\repos\\lab1_algo\\TimeMeasurements.txt";
            using (StreamWriter sw = new StreamWriter(path, false, System.Text.Encoding.Default))
            {
                foreach (var item in resultStopwatch)
                {
                    sw.WriteLine($"{item.Key}: {string.Join(" ", item.Value)}");
                    Console.WriteLine($"Замеры для N = {item.Key} записаны в файл");
                }
            }
        }
    }
}