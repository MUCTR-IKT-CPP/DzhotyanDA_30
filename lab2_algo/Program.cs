using System.Diagnostics;

namespace lab2_algo
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
            Dictionary<int, long[]> resultCallMakeHeapFunctionCount = [];
            Dictionary<int, long[]> resultCallSiftDownFunctionCount = [];
            Dictionary<int, long[]> resultInternalSiftDownCount = [];
            Dictionary<int, long[]> resultDepth = [];

            foreach (var N in itemsCountArray)
            {
                Console.WriteLine($"N = {N}:");

                long[] timeMeasurementsArray = new long[numberOfVectorGeneration];
                long[] callMakeHeapFunctionArray = new long[numberOfVectorGeneration];
                long[] callSiftDownFunctionArray = new long[numberOfVectorGeneration];
                long[] internalSiftDownCountArray = new long[numberOfVectorGeneration];
                long[] depthArray = new long[numberOfVectorGeneration];

                for (int j = 0; j < numberOfVectorGeneration; j++)
                {
                    double[] nums = new double[N];
                    double[] nums2 = new double[N];

                    for (int i = 0; i < nums.Length; i++)
                    {
                        nums[i] = random.NextDouble() * (1 - (-1)) - 1;
                        nums2[i] = nums[i];
                    }

                    //double[] nums = [5, 0, -2, 7, 3];
                    //double[] nums2 = [5, 0, -2, 7, 3];

                    stopwatch.Start();
                    HeapSortIterative(nums, out long callMakeHeapFunctionCount, out long callSiftDownFunctionCount, out long internalSiftDownCount);
                    stopwatch.Stop();

                    //Console.WriteLine(string.Join(" ", nums));

                    HeapSortRecursive(nums2, out long depth);

                    //Console.WriteLine(string.Join(" ", nums2));

                    long microseconds = (long)stopwatch.Elapsed.TotalMicroseconds;
                    timeMeasurementsArray[j] = microseconds;

                    callMakeHeapFunctionArray[j] = callMakeHeapFunctionCount;

                    callSiftDownFunctionArray[j] = callSiftDownFunctionCount;

                    internalSiftDownCountArray[j] = internalSiftDownCount;

                    depthArray[j] = depth;

                    Console.WriteLine(
                        $"Series {j + 1}: " +
                        $"\tMicroseconds = {microseconds} " +
                        $"\tCalls of make heap function = {callMakeHeapFunctionCount} " +
                        $"\tCalls of sift down function = {callSiftDownFunctionCount}" +
                        $"\tCalls of internal sift down function = {internalSiftDownCount}" +
                        $"\tDepth = {depth}");

                    stopwatch.Reset();
                }
                
                Console.WriteLine("---------------------------------------------------------------------------");
                resultStopwatch.TryAdd(N, timeMeasurementsArray);
                resultCallMakeHeapFunctionCount.TryAdd(N, callMakeHeapFunctionArray);
                resultCallSiftDownFunctionCount.TryAdd(N, callSiftDownFunctionArray);
                resultInternalSiftDownCount.TryAdd(N, internalSiftDownCountArray);
                resultDepth.TryAdd(N, depthArray);
            }

            WriteToFile(resultStopwatch, resultCallMakeHeapFunctionCount, resultCallSiftDownFunctionCount, resultInternalSiftDownCount, resultDepth);
        }

        public static void SiftDownIterative(double[] arr, int i, int last_index, ref long internalSiftDownCount)
        {
            while (true)
            {
                int leftIndex = 2 * i + 1;
                int rightIndex = 2 * i + 2;
                int j = i;

                if (leftIndex < last_index && arr[j] < arr[leftIndex])
                {
                    j = leftIndex;
                }

                if (rightIndex < last_index && arr[j] < arr[rightIndex])
                {
                    j = rightIndex;
                }

                if (j != i)
                {
                    (arr[i], arr[j]) = (arr[j], arr[i]);
                    i = j;
                    internalSiftDownCount++;
                }
                else
                {
                    break;
                }
            }
        }

        public static void SiftDownRecursive(double[] arr, int i, int last_index, ref long depth)
        {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            int j = i;

            if (leftIndex < last_index && arr[j] < arr[leftIndex])
            {
                j = leftIndex;
            }

            if (rightIndex < last_index && arr[j] < arr[rightIndex])
            {
                j = rightIndex;
            }

            if (j != i)
            {
                (arr[i], arr[j]) = (arr[j], arr[i]);
                depth++;
                SiftDownRecursive(arr, j, last_index, ref depth);
            }
        }

        public static void HeapSortIterative(
            double[] arr,
            out long callMakeHeapFunctionCount, 
            out long callSiftDownFunctionCount,
            out long internalSiftDownCount)
        {
            callMakeHeapFunctionCount = 0;
            callSiftDownFunctionCount = 0;
            internalSiftDownCount = 0;

            int n = arr.Length / 2;
            int lastIndex = arr.Length;

            for (int i = n; i >= 0; i--)
            {
                SiftDownIterative(arr, i, lastIndex, ref internalSiftDownCount);
                callMakeHeapFunctionCount++;
            }

            lastIndex--;

            while (lastIndex > 0)
            {
                (arr[0], arr[lastIndex]) = (arr[lastIndex], arr[0]);
                SiftDownIterative(arr, 0, lastIndex, ref internalSiftDownCount);
                callSiftDownFunctionCount++;
                lastIndex--;
            }
        }
        
        public static void HeapSortRecursive(double[] arr, out long depth)
        {
            depth = 1;

            int n = arr.Length / 2;
            int lastIndex = arr.Length;

            for (int i = n; i >= 0; i--)
            {
                SiftDownRecursive(arr, i, lastIndex, ref depth);
            }

            lastIndex--;

            while (lastIndex > 0)
            {
                (arr[0], arr[lastIndex]) = (arr[lastIndex], arr[0]);
                SiftDownRecursive(arr, 0, lastIndex, ref depth);
                lastIndex--;
            }
        }

        public static void WriteToFile(
            Dictionary<int, long[]> resultStopwatch,
            Dictionary<int, long[]> resultCallMakeHeapFunctionCount,
            Dictionary<int, long[]> resultCallSiftDownFunctionCount,
            Dictionary<int, long[]> resultInternalSiftDownCount,
            Dictionary<int, long[]> resultDepth)
        {
            var path = Path.Combine(Directory.GetCurrentDirectory(), "..", "..", "..", "Measurements.txt");

            using (StreamWriter sw = new StreamWriter(path, false, System.Text.Encoding.Default))
            {
                foreach (var item in resultStopwatch)
                {
                    sw.WriteLine($"N = {item.Key}" +
                        $"\n\tMicroseconds: {string.Join(" ", item.Value)}" +
                        $"\n\tCalls of make heap function: {string.Join(" ", resultCallMakeHeapFunctionCount[item.Key])}" +
                        $"\n\tCalls of sift down function: {string.Join(" ", resultCallSiftDownFunctionCount[item.Key])}" +
                        $"\n\tCalls of internal sift down function: {string.Join(" ", resultInternalSiftDownCount[item.Key])}" +
                        $"\n\tRecursion depth: {string.Join(" ", resultDepth[item.Key])}");
                    sw.WriteLine();
                    Console.WriteLine($"Замеры для N = {item.Key} записаны в файл");
                }
            }
        }
    }
}