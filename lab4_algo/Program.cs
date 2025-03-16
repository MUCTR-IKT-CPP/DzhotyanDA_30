using System.Diagnostics;

namespace lab4_algo
{
    class Program
    {
        public static void Main()
        {
            int graphCount = 10;

            GraphGenerator generator = new GraphGenerator();

            Stopwatch stopwatch = new Stopwatch();

            List<Graph> graphs = generator.GenerateGraphList(graphCount);

            long[] nanosecBFSArray = new long[graphCount];
            long[] nanosecDFSArray = new long[graphCount];
            int[] verticesCountArray = new int[graphCount];
            int[] edgesCountArray = new int[graphCount];

            for (int i = 0; i < graphCount; i++)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine($"Граф {i + 1}");
                Console.ForegroundColor = ConsoleColor.White;

                var graph = graphs[i];

                verticesCountArray[i] = graph.VertexCount;
                edgesCountArray[i] = graph.EdgeCount;

                graph.PrintGraph();

                stopwatch.Start();
                TestBFS(graph, graph.Vertices[0], graph.Vertices[graph.VertexCount - 1]);
                stopwatch.Stop();
                long nanosec = (long)stopwatch.Elapsed.TotalNanoseconds;
                nanosecBFSArray[i] = nanosec;
                Console.WriteLine($"Время выполнения BFS: {nanosec} наносек");

                stopwatch.Restart();
                TestDFS(graph, graph.Vertices[0], graph.Vertices[graph.VertexCount - 1]);
                stopwatch.Stop();
                nanosec = (long)stopwatch.Elapsed.TotalNanoseconds;
                nanosecDFSArray[i] = nanosec;
                Console.WriteLine($"Время выполнения DFS: {nanosec} наносек");

                stopwatch.Reset();

                TestAdjacencyMatrix(graph);

                TestGetAdjacencyList(graph, graph.Vertices[0]);

                TestIncidenceMatrix(graph);

                TestEdgesList(graph);

                Console.WriteLine("############################################################");
            }

            WriteToFile(nanosecBFSArray, nanosecDFSArray, verticesCountArray, edgesCountArray);
        }

        /// <summary>
        /// Тестирование обхода в ширину
        /// </summary>
        /// <param name="graph"></param>
        /// <param name="Start"></param>
        /// <param name="End"></param>
        public static void TestBFS(Graph graph, Vertex Start, Vertex End)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"Обход в ширину: {Start.Number} -> {End.Number}");
            Console.ForegroundColor = ConsoleColor.White;

            var path = graph.BFS(Start, End);

            if (path.Count == 0)
            {
                Console.WriteLine($"Невозможно попасть из вершины {Start.Number} в вершину {End.Number}\n");
            }
            else
            {
                foreach (var item in path)
                {
                    Console.Write(item.Number + " ");
                }
                Console.WriteLine("\n");
            }
        }

        /// <summary>
        /// Тестирование обхода в глубину
        /// </summary>
        /// <param name="graph"></param>
        /// <param name="Start"></param>
        /// <param name="End"></param>
        public static void TestDFS(Graph graph, Vertex Start, Vertex End)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"Обход в глубину: {Start.Number} -> {End.Number}");
            Console.ForegroundColor = ConsoleColor.White;

            var path = graph.DFS(Start, End);

            if (path.Count == 0)
            {
                Console.WriteLine($"Невозможно попасть из вершины {Start.Number} в вершину {End.Number}\n");
            }
            else
            {
                foreach (var item in path)
                {
                    Console.Write(item.Number + " ");
                }
                Console.WriteLine("\n");
            }
        }

        /// <summary>
        /// Тестирование получения матрицы смежности
        /// </summary>
        /// <param name="graph"></param>
        public static void TestAdjacencyMatrix(Graph graph)
        {
            int[,] matrix = graph.GetAdjacencyMatrix();

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Матрица смежности");
            Console.ForegroundColor = ConsoleColor.White;

            Console.Write("  ");
            Console.ForegroundColor = ConsoleColor.Cyan;
            for (int j = 0; j < graph.VertexCount; j++)
            {
                Console.Write((j + 1) + " ");
            }
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.White;

            for (int i = 0; i < graph.VertexCount; i++)
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
                Console.Write((i + 1) + " ");
                Console.ForegroundColor = ConsoleColor.White;

                for (int j = 0; j < graph.VertexCount; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        /// <summary>
        /// Тестирование получения матрицы инцидентности
        /// </summary>
        /// <param name="graph"></param>
        public static void TestIncidenceMatrix(Graph graph)
        {
            int[,] matrix = graph.GetIncidenceMatrix();

            List<Edge> edges = graph.GetEdges();

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("\nМатрица инцидентности");
            Console.ForegroundColor = ConsoleColor.White;

            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.Write("  ");
            for (int i = 0; i < edges.Count; i++)
            {
                Console.Write($"a{i + 1} ");
            }
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.White;

            for (int i = 0; i < graph.VertexCount; i++)
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
                Console.Write((i + 1) + " ");
                Console.ForegroundColor = ConsoleColor.White;

                for (int j = 0; j < graph.EdgeCount; j++)
                {
                    if (matrix[i, j] < 0)
                        Console.Write(matrix[i, j] + " ");
                    else
                        Console.Write(" " + matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        /// <summary>
        /// Тестирование получения списка смежности
        /// </summary>
        /// <param name="graph"></param>
        public static void TestGetAdjacencyList(Graph graph, Vertex v)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"\nСписок смежности для вершины {v.Number}");
            Console.ForegroundColor = ConsoleColor.White;

            var x = graph.GetAdjacencyList(v);

            if (x.Count == 0)
            {
                Console.Write("Список смежности пуст");
            }
            else
            {
                foreach (var item in x)
                {
                    Console.Write(item + " ");
                }
            }
            Console.WriteLine();
        }

        /// <summary>
        /// Тестирование получения списка рёбер
        /// </summary>
        /// <param name="graph"></param>
        public static void TestEdgesList(Graph graph)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("\nСписок рёбер");
            Console.ForegroundColor = ConsoleColor.White;

            foreach (var item in graph.GetEdges())
            {
                Console.WriteLine(item);
            }
        }

        /// <summary>
        /// Запись в файл времени выполнения обходов в графах в наносекундах
        /// </summary>
        /// <param name="nanosecBFSArray"></param>
        /// <param name="nanosecDFSArray"></param>
        public static void WriteToFile(long[] nanosecBFSArray, long[] nanosecDFSArray, int[] verticesCountArray, int[] edgesCountArray)
        {
            var path = Path.Combine(Directory.GetCurrentDirectory(), "..", "..", "..", "Measurements.txt");

            using (StreamWriter sw = new StreamWriter(path, false, System.Text.Encoding.Default))
            {
                sw.WriteLine("Измерения времени выполнения обходов в графах в наносекундах");
                sw.WriteLine($"BFS: {string.Join(" ", nanosecBFSArray)}");
                sw.WriteLine($"DFS: {string.Join(" ", nanosecDFSArray)}");
                sw.WriteLine($"Количество вершин: {string.Join(" ", verticesCountArray)}");
                sw.WriteLine($"Количество рёбер: {string.Join(" ", edgesCountArray)}");
            }
        }
    }
}