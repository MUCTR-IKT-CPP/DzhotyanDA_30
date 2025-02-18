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
            Dictionary<int, long[]> resultSwapsCount = [];
            Dictionary<int, long[]> resultRepeatedPassesCount = [];

            foreach (var N in itemsCountArray)
            {
                Console.WriteLine($"N = {N}:");
                
                long[] timeMeasurementsArray = new long[numberOfVectorGeneration];
                long[] swapsArray = new long[numberOfVectorGeneration];
                long[] repeatedPassesArray = new long[numberOfVectorGeneration];

                for (int j = 0; j < numberOfVectorGeneration; j++)
                {
                    double[] nums = new double[N];
                    
                    for (int i = 0; i < nums.Length; i++)
                    {
                        nums[i] = random.NextDouble() * (1 - (-1)) - 1;
                    }

                    stopwatch.Start();
                    CocktailSortAsc(nums, out long swaps, out long repeatedPasses);
                    stopwatch.Stop();

                    timeMeasurementsArray[j] = stopwatch.ElapsedMilliseconds;

                    swapsArray[j] = swaps;

                    repeatedPassesArray[j] = repeatedPasses;

                    Console.WriteLine($"Series {j + 1}: Milliseconds = {stopwatch.ElapsedMilliseconds} Swaps = {swaps} Repeated passes = {repeatedPasses}");

                    stopwatch.Reset();
                }

                Console.WriteLine("---------------------------------------------------------------------------");
                resultStopwatch.TryAdd(N, timeMeasurementsArray);
                resultSwapsCount.TryAdd(N, swapsArray);
                resultRepeatedPassesCount.TryAdd(N, repeatedPassesArray);
            }

            WriteToFile(resultStopwatch, resultSwapsCount, resultRepeatedPassesCount);
        }

        public static void CocktailSortAsc(double[] arr, out long swaps, out long repeatedPasses)
        {
            swaps = 0;
            repeatedPasses = 0;

            int left = 0;
            int right = arr.Length - 1;

            while (left < right)
            {
                bool swaped = false;

                for (int i = left; i < right; i++)
                {
                    if (arr[i] > arr[i + 1])
                    {
                        (arr[i + 1], arr[i]) = (arr[i], arr[i + 1]);
                        swaps++;
                        swaped = true;
                    }
                }
                right--;

                if (swaped)
                {
                    repeatedPasses++;
                }

                swaped = false;

                for (int i = right; i > left; i--)
                {
                    if (arr[i - 1] > arr[i])
                    {
                        (arr[i - 1], arr[i]) = (arr[i], arr[i - 1]);
                        swaps++;
                        swaped = true;
                    }
                }
                left++;
                
                if (swaped)
                {
                    repeatedPasses++;
                }
            }
        }

        public static void WriteToFile(
            Dictionary<int, long[]> resultStopwatch,
            Dictionary<int, long[]> resultSwapsCount, 
            Dictionary<int, long[]> resultRepeatedPassesCount)
        {
            var path = Path.Combine(Directory.GetCurrentDirectory(), "..", "..", "..", "Measurements.txt");

            using (StreamWriter sw = new StreamWriter(path, false, System.Text.Encoding.Default))
            {
                foreach (var item in resultStopwatch)
                {
                    sw.WriteLine($"N = {item.Key}");
                    sw.WriteLine($"Milliseconds: {string.Join(" ", item.Value)}");
                    sw.WriteLine($"Swaps: {string.Join(" ", resultSwapsCount[item.Key])}");
                    sw.WriteLine($"Repeated passes: {string.Join(" ", resultRepeatedPassesCount[item.Key])}");
                    sw.WriteLine();
                    Console.WriteLine($"Замеры для N = {item.Key} записаны в файл");
                }
            }
        }
    }
}
