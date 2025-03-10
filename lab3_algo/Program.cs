using System;
using System.Diagnostics;

namespace lab3_algo
{
    class Program
    {
        static void Main(string[] args)
        {
            ThousandNumbersTest();
            Console.WriteLine("--------------------------");
            TenStringsTest();
            Console.WriteLine("--------------------------");
            PersonalDataTest();
            Console.WriteLine("--------------------------");
            Reverse();
            Console.WriteLine("--------------------------");
            CompareTwoQueue();
        }

        public static void ThousandNumbersTest()
        {
            int N = 1000;
            double l = -1000;
            double r = 1000;

            double minimum = r;
            double maximum = l;
            double sum = 0;

            QueueSinglyLinkedList<double> queue = new QueueSinglyLinkedList<double>();
            Random rand = new Random();

            for (int i = 0; i < N; i++)
            {
                queue.Add(rand.NextDouble() * (r - l) + l);
            }

            for (int i = 0; i < N; i++)
            {
                double num = queue.PopFirst();

                if (num < minimum)
                {
                    minimum = num;
                }

                if (num > maximum)
                {
                    maximum = num;
                }

                sum += num;
            }

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Thousand numbers test passed");
            Console.ResetColor();
            Console.WriteLine("Minimum: " + minimum);
            Console.WriteLine("Maximum: " + maximum);
            Console.WriteLine("Average: " + sum / N);
        }

        public static void TenStringsTest()
        {
            QueueSinglyLinkedList<string> queue = new QueueSinglyLinkedList<string>();

            string[] arr = new string[] { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

            foreach (string str in arr)
            {
                queue.Add(str);
                string x = queue.PopFirst();
                if (x == null)
                {
                    throw new Exception("Queue is empty");
                }
            }

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Strings test passed");
            Console.ResetColor();
        }
    
        public static void PersonalDataTest()
        {
            QueueSinglyLinkedList<PersonalData> queue = new QueueSinglyLinkedList<PersonalData>();
            
            int N = 100;

            for (int i = 0; i < N; i++)
            {
                var personalData = PersonalData.GenerateData(N);
                queue.Add(personalData);
            }

            QueueSinglyLinkedList<PersonalData> filteredData = new QueueSinglyLinkedList<PersonalData>();
            QueueSinglyLinkedList<PersonalData> otherData = new QueueSinglyLinkedList<PersonalData>();

            for (int i = 0; i < N; i++)
            {
                PersonalData data = queue.PopFirst();
                DateTime birthDate = data.GetBirthDate();
                
                int age = Convert.ToInt32((DateTime.Now - birthDate).TotalDays / 365);

                if (age < 20)
                {
                    filteredData.Add(data);
                }
                else if (age > 30)
                {
                    filteredData.Add(data);
                }
                else
                {
                    otherData.Add(data);
                }
            }

            if (filteredData.Length + otherData.Length == N)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Personal data test passed");
                Console.ResetColor();
            }
            else
            {
                throw new Exception("Personal data test failed");
            }
        }
        
        public static void Reverse()
        {
            int N = 10;
            
            QueueSinglyLinkedList<int> queue = new QueueSinglyLinkedList<int>();
            Stack<int> stack = new Stack<int>();

            for (int i = 1; i <= N; i++)
            {
                queue.Add(i);
            }

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Reverse test passed");
            Console.ResetColor();

            Console.WriteLine($"Before: {string.Join(" ", queue)}");

            while (!queue.IsEmpty())
            {
                stack.Push(queue.PopFirst());
            }

            while (stack.Count > 0)
            {
                queue.Add(stack.Pop());
            }

            Console.WriteLine($"After: {string.Join(" ", queue)}");
        }
    
        public static void CompareTwoQueue()
        {
            int N = 10000;

            QueueSinglyLinkedList<int> qsll = new QueueSinglyLinkedList<int>();
            QueueTwoStacks<int> qts = new QueueTwoStacks<int>();
            
            long[] pushTicksQueueSinglyLinkedList = new long[N];
            long[] pushTicksQueueTwoStacks = new long[N];

            long[] popTicksQueueSinglyLinkedList = new long[N];
            long[] popTicksQueueTwoStacks = new long[N];

            long[] memoryPushQueueSinglyLinkedList = new long[N];
            long[] memoryPushQueueTwoStacks = new long[N];

            Stopwatch sw = Stopwatch.StartNew();

            for (int i = 0; i < N; i++)
            {
                long before = GC.GetTotalMemory(true);

                sw.Start();
                qsll.Add(i);
                sw.Stop();
                
                long after = GC.GetTotalMemory(true);
                long consumedInMegabytes = (after - before);
                memoryPushQueueSinglyLinkedList[i] = consumedInMegabytes;
                pushTicksQueueSinglyLinkedList[i] = sw.ElapsedTicks;

                
                before = GC.GetTotalMemory(false);

                sw.Restart();
                qts.Add(i);
                sw.Stop();

                after = GC.GetTotalMemory(false);
                consumedInMegabytes = (after - before);
                memoryPushQueueTwoStacks[i] = consumedInMegabytes;
                pushTicksQueueTwoStacks[i] = sw.ElapsedTicks;
                sw.Reset();
            }

            for (int i = 0; i < N; i++)
            {
                sw.Start();
                qsll.PopFirst();
                sw.Stop();
                popTicksQueueSinglyLinkedList[i] = sw.ElapsedTicks;

                sw.Restart();
                qts.Pop();
                sw.Stop();
                popTicksQueueTwoStacks[i] = sw.ElapsedTicks;
                sw.Reset();
            }

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Comparing");
            Console.ResetColor();
            Console.WriteLine();
            
            Console.WriteLine("Push:");
            Console.WriteLine($"QueueSinglyLinkedList: " + pushTicksQueueSinglyLinkedList.Average());
            Console.WriteLine("QueueTwoStacks: " + pushTicksQueueTwoStacks.Average());
            Console.WriteLine();

            Console.WriteLine("Memory in bytes:");
            Console.WriteLine("QueueSinglyLinkedList: " + memoryPushQueueSinglyLinkedList.Average());
            Console.WriteLine("QueueTwoStacks: " + memoryPushQueueTwoStacks.Average());
            Console.WriteLine();

            Console.WriteLine("Pop:");
            Console.WriteLine("QueueSinglyLinkedList: " + popTicksQueueSinglyLinkedList.Average());
            Console.WriteLine("QueueTwoStacks: " + popTicksQueueTwoStacks.Average());
        
            //WriteToFile(N, pushTicksQueueSinglyLinkedList, pushTicksQueueTwoStacks, popTicksQueueSinglyLinkedList, popTicksQueueTwoStacks, memoryPushQueueSinglyLinkedList, memoryPushQueueTwoStacks);
        }

        public static void WriteToFile(
            int N,
            long[] pushTicksQueueSinglyLinkedList,
            long[] pushTicksQueueTwoStacks,
            long[] popTicksQueueSinglyLinkedList,
            long[] popTicksQueueTwoStacks,
            long[] memoryPushQueueSinglyLinkedList,
            long[] memoryPushQueueTwoStacks)
        {
            var path = Path.Combine(Directory.GetCurrentDirectory(), "..", "..", "..", "Measurements.txt");

            using (StreamWriter sw = new StreamWriter(path, false, System.Text.Encoding.Default))
            {
                sw.WriteLine("Elapsed Ticks:");
                sw.WriteLine("Push");
                sw.Write("\nQueueSinglyLinkedList");
                for (int i = 0; i < N; i += 500)
                {
                    sw.Write($" {pushTicksQueueSinglyLinkedList[i]}");
                }

                sw.Write("\nQueueTwoStacks");
                for (int i = 0; i < N; i += 500)
                {
                    sw.Write($" {pushTicksQueueTwoStacks[i]}");
                }

                sw.Write("\nPop");
                sw.Write("\nQueueSinglyLinkedList");
                for (int i = 0; i < N; i += 500)
                {
                    sw.Write($" {popTicksQueueSinglyLinkedList[i]}");
                }

                sw.WriteLine("QueueTwoStacks");
                for (int i = 0; i < N; i += 500)
                {
                    sw.Write($" {popTicksQueueTwoStacks[i]}");
                }

                sw.WriteLine("\nMemory in bytes:");
                sw.Write("\nQueueSinglyLinkedList");
                for (int i = 0; i < N; i += 500)
                {
                    sw.Write($" {memoryPushQueueSinglyLinkedList[i]}");
                }

                sw.Write("\nQueueTwoStacks");
                for (int i = 0; i < N; i += 500)
                {
                    sw.Write($" {memoryPushQueueTwoStacks[i]}");
                }
            }
        }
    }
}