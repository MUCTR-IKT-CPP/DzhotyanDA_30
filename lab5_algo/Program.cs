using System.Diagnostics;

namespace lab5_algo
{
    class Program
    {
        static void Main()
        {
            Stopwatch stopwatch = new Stopwatch();
            GraphGenerator graphGenerator = new GraphGenerator();

            const int MAX_ITER = 7;

            int[] verticesCount = { 10, 20, 50, 100 };
            int[] minEdgesCount = { 3, 4, 10, 20 };

            long[] microsecFWAverage = new long[verticesCount.Length];

            for (int i = 0; i < verticesCount.Length; i++)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine($"Граф {i + 1}");
                Console.ResetColor();

                long[] microsecFW = new long[MAX_ITER];
                int iter = 0;

                while (iter < MAX_ITER)
                {
                    for (int j = 0; j < minEdgesCount.Length; j++)
                    {
                        Graph graph = graphGenerator.GenerateGraph(verticesCount[i], minEdgesCount[j], false);
                        PrintAdjacencyMatrix(graph);

                        stopwatch.Start();
                        var matrix = graph.FloydWarshall();
                        stopwatch.Stop();

                        microsecFW[j] = (long)stopwatch.Elapsed.TotalMicroseconds;
                        stopwatch.Reset();
                        
                        PrintFWMatrix(graph, matrix);
                    }
                    iter++;
                }
                Console.WriteLine($"Ср. время: {microsecFW.Average()} мкс");
                microsecFWAverage[i] = (long)microsecFW.Average();
            }

            WriteToFile(microsecFWAverage);
        }

        static void PrintAdjacencyMatrix(Graph graph)
        {
            var matrix = graph.GetAdjacencyMatrix();
            int size = matrix.Count;

            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Матрица смежности");
            Console.ResetColor();

            Console.Write("   │");
            for (int i = 0; i < size; i++)
                Console.Write($" {i + 1,2} ");
            Console.WriteLine("\n───┼" + new string('─', 4 * size + 1));

            for (int i = 0; i < size; i++)
            {
                Console.Write($"{i + 1,2} │");
                for (int j = 0; j < size; j++)
                {
                    int value = matrix[i][j];
                    if (value == 0)
                        Console.Write($" INF");
                    else
                        Console.Write($" {value,2} ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        static void PrintFWMatrix(Graph graph, int[,] dist)
        {
            int size = graph.GetAdjacencyMatrix().Count;

            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Матрица кратчайших путей: Флойд-Уоршэлл");
            Console.ResetColor();

            Console.Write("   │");
            for (int i = 0; i < size; i++)
                Console.Write($" {i + 1,2} ");
            Console.WriteLine("\n───┼" + new string('─', 4 * size + 1));

            for (int i = 0; i < size; i++)
            {
                Console.Write($"{i + 1,2} │");
                for (int j = 0; j < size; j++)
                {
                    if (dist[i, j] == int.MaxValue)
                        Console.Write("  -");
                    else
                        Console.Write($" {dist[i, j],2} ");
                }
                Console.WriteLine();
            }
        }

        public static void WriteToFile(long[] microsecondsFW)
        {
            var path = Path.Combine(Directory.GetCurrentDirectory(), "..", "..", "..", "Measurements.txt");

            using (StreamWriter sw = new StreamWriter(path, false, System.Text.Encoding.Default))
            {
                sw.WriteLine($"Время выполнения алгоритма Флойда-Уоршелла: {string.Join(" ", microsecondsFW)}");
            }
        }
    }
}