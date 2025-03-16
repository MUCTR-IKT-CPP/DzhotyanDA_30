namespace lab4_algo
{
    internal class Graph
    {
        public List<Vertex> Vertices = new List<Vertex>();

        public List<Edge> Edges = new List<Edge>();

        private bool Oriented;

        public int VertexCount => Vertices.Count;

        public int EdgeCount => Edges.Count;

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
        }

        /// <summary>
        /// Обход в ширину
        /// </summary>
        /// <param name="Start"></param>
        /// <param name="End"></param>
        /// <returns>Список вершин от Start до End</returns>
        public List<Vertex> BFS(Vertex Start, Vertex End)
        {
            HashSet<Vertex> visited = new HashSet<Vertex>();
            Dictionary<Vertex, Vertex> parent = new Dictionary<Vertex, Vertex>(); // Хранит путь
            Queue<Vertex> queue = new Queue<Vertex>();

            queue.Enqueue(Start);
            visited.Add(Start);
            parent[Start] = null;

            while (queue.Count > 0)
            {
                Vertex current = queue.Dequeue();

                if (current == End) // Если достигли конечной вершины
                {
                    return ReconstructPath(parent, Start, End);
                }

                foreach (var neighbor in GetNeighbors(current))
                {
                    if (!visited.Contains(neighbor))
                    {
                        visited.Add(neighbor);
                        parent[neighbor] = current; // Запоминаем, откуда пришли
                        queue.Enqueue(neighbor);
                    }
                }
            }

            return new List<Vertex>();
        }

        /// <summary>
        /// Обход в глубину
        /// </summary>
        /// <param name="Start"></param>
        /// <param name="End"></param>
        /// <returns></returns>
        public List<Vertex> DFS(Vertex Start, Vertex End)
        {
            Dictionary<Vertex, Vertex> parent = new Dictionary<Vertex, Vertex>();
            HashSet<Vertex> visited = new HashSet<Vertex>();
            List<Vertex> path = new List<Vertex>();

            if (DFSHelper(Start, End, visited, parent))
            {
                return ReconstructPath(parent, Start, End);
            }

            return new List<Vertex>();
        }

        /// <summary>
        /// Вспомогательная функция для обхода в глубину
        /// </summary>
        /// <param name="current"></param>
        /// <param name="end"></param>
        /// <param name="visited"></param>
        /// <param name="parent"></param>
        /// <returns></returns>
        private bool DFSHelper(Vertex current, Vertex end, HashSet<Vertex> visited, Dictionary<Vertex, Vertex> parent)
        {
            visited.Add(current);

            if (current == end) // Если достигли конечной вершины
            {
                return true;
            }

            foreach (var neighbor in GetNeighbors(current))
            {
                if (!visited.Contains(neighbor))
                {
                    parent[neighbor] = current; // Запоминаем, откуда пришли
                    if (DFSHelper(neighbor, end, visited, parent))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        /// <summary>
        /// Восстановление пути из parent-словаря
        /// </summary>
        /// <param name="parent"></param>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <returns></returns>
        private List<Vertex> ReconstructPath(Dictionary<Vertex, Vertex> parent, Vertex start, Vertex end)
        {
            List<Vertex> path = new List<Vertex>();
            for (Vertex v = end; v != null; v = parent.GetValueOrDefault(v))
            {
                path.Add(v);
            }
            path.Reverse();
            return path;
        }

        /// <summary>
        /// Получение соседей вершины
        /// </summary>
        /// <param name="v"></param>
        /// <returns></returns>
        private List<Vertex> GetNeighbors(Vertex v)
        {
            List<Vertex> neighbors = new List<Vertex>();
            foreach (var edge in Edges)
            {
                if (edge.Start == v)
                {
                    neighbors.Add(edge.End);
                }
                if (!Oriented && edge.End == v) // Если граф неориентированный
                {
                    neighbors.Add(edge.Start);
                }
            }
            return neighbors;
        }

        /// <summary>
        /// Получение матрицы смежности
        /// </summary>
        /// <returns></returns>
        public int[,] GetAdjacencyMatrix()
        {
            int[,] matrix = new int[VertexCount, VertexCount];

            foreach (var edge in Edges)
            {
                var row = edge.Start.Number - 1;

                var column = edge.End.Number - 1;

                matrix[row, column] = edge.Weight;
            }

            return matrix;
        }

        /// <summary>
        /// Получение матрицы инцидентности
        /// </summary>
        /// <returns></returns>
        public int[,] GetIncidenceMatrix()
        {
            int[,] matrix = new int[VertexCount, EdgeCount];

            for (int i = 0; i < EdgeCount; i++)
            {
                var edge = Edges[i];

                if (Oriented)
                {
                    matrix[edge.End.Number - 1, i] = -1 * edge.Weight;
                }
                else
                {
                    matrix[edge.End.Number - 1, i] = edge.Weight;
                }

                matrix[edge.Start.Number - 1, i] = edge.Weight;
            }

            return matrix;
        }

        /// <summary>
        /// Получение списка смежности
        /// </summary>
        /// <param name="vertex"></param>
        /// <returns></returns>
        public List<Vertex> GetAdjacencyList(Vertex vertex)
        {
            List<Vertex> adjacencyList = new List<Vertex>();
            
            foreach (var edge in Edges)
            {
                if (edge.Start == vertex)
                {
                    adjacencyList.Add(edge.End);
                }
            }

            return adjacencyList;
        }

        /// <summary>
        /// Получение списка ребер
        /// </summary>
        /// <returns></returns>
        public List<Edge> GetEdges() => Edges;

        public void PrintGraph()
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
