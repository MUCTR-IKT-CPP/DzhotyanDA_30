using System.Drawing;

namespace lab5_algo
{
    internal class Graph
    {
        public List<Vertex> Vertices = new List<Vertex>();

        public List<Edge> Edges = new List<Edge>();

        private bool Oriented;

        public int VertexCount => Vertices.Count;

        public int EdgeCount => Edges.Count;

        List<List<int>> AdjacencyMatrix = new List<List<int>>();

        public Graph(bool oriented = false)
        {
            Oriented = oriented;
        }

        public void AddVertex(Vertex vertex)
        {
            Vertices.Add(vertex);
        }

        public void AddEdge(Edge edge)
        {
            Edges.Add(edge);
            UpdateAdjacencyMatrix(edge);
        }

        /// <summary>
        /// Алгоритм Флойда-Уоршелла
        /// </summary>
        public int[,] FloydWarshall()
        {
            int size = AdjacencyMatrix.Count;
            int[,] dist = new int[size, size];

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == j)
                        dist[i, j] = 0;
                    else if (AdjacencyMatrix[i][j] == 0)
                        dist[i, j] = int.MaxValue;
                    else
                        dist[i, j] = AdjacencyMatrix[i][j];
                }
            }

            for (int k = 0; k < size; k++)
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (dist[i, k] != int.MaxValue && dist[k, j] != int.MaxValue)
                        {
                            dist[i, j] = Math.Min(dist[i, j], dist[i, k] + dist[k, j]);
                        }
                    }
                }
            }

            return dist;
        }


        /// <summary>
        /// Обновление матрицы смежности
        /// </summary>
        /// <param name="edge"></param>
        private void UpdateAdjacencyMatrix(Edge edge)
        {
            var row = edge.Start.Number - 1;

            var column = edge.End.Number - 1;

            int size = Math.Max(row, column) + 1;

            while (AdjacencyMatrix.Count < size)
            {
                AdjacencyMatrix.Add(new List<int>(new int[size]));
            }

            foreach (var rowList in AdjacencyMatrix)
            {
                while (rowList.Count < size)
                {
                    rowList.Add(0);
                }
            }

            AdjacencyMatrix[row][column] = edge.Weight;

            if (!Oriented)
            {
                AdjacencyMatrix[column][row] = edge.Weight;
            }
        }

        /// <summary>
        /// Получение матрицы смежности
        /// </summary>
        /// <returns></returns>
        public List<List<int>> GetAdjacencyMatrix() => AdjacencyMatrix;

        /// <summary>
        /// Вывод ребер графа
        /// </summary>
        public void PrintEdges()
        {
            Console.WriteLine($"Граф (Вершин: {Vertices.Count}, Ребер: {Edges.Count}, Ориентированный: {Oriented})");
            foreach (var edge in Edges)
            {
                Console.WriteLine($"{edge.Start} -> {edge.End}");
            }
            Console.WriteLine();
        }
    }
}
