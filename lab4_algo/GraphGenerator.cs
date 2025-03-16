namespace lab4_algo
{
    internal class GraphGenerator
    {
        private Random random = new Random();

        public List<Graph> GenerateGraphList(int graphCount)
        {
            Random random = new Random();

            List<Graph> graphs = new List<Graph>();

            int startVerticesCount = 5;
            int startEdgesCount = 6;
            int step = 2;

            for (int i = 0; i < graphCount; i++)
            {
                int vertices = startVerticesCount + (i * step);
                int edges = startEdgesCount + (i * step * 2);

                int is_oriented = random.Next(0, 2);

                Graph graph = GenerateGraph(vertices, vertices, edges, edges, 4, is_oriented == 1 ? true : false);

                graphs.Add(graph);
            }

            return graphs;
        }

        private Graph GenerateGraph(int minVertices, int maxVertices, int minEdges, int maxEdges, int maxEdgesPerVertex, bool oriented)
        {
            int vertexCount = random.Next(minVertices, maxVertices + 1);
            int edgeCount = random.Next(minEdges, maxEdges + 1);

            Graph graph = new Graph(oriented);

            List<Vertex> vertices = new List<Vertex>();
            for (int i = 1; i <= vertexCount; i++)
            {
                var vertex = new Vertex(i);
                vertices.Add(vertex);
                graph.AddVertex(vertex);
            }

            HashSet<(int, int)> existingEdges = new HashSet<(int, int)>();

            for (int i = 0; i < edgeCount; i++)
            {
                Vertex start, end;
                do
                {
                    start = vertices[random.Next(vertices.Count)];
                    end = vertices[random.Next(vertices.Count)];
                }
                while (start == end || existingEdges.Contains((start.Number, end.Number)) || (!oriented && existingEdges.Contains((end.Number, start.Number))));

                graph.AddEdge(new Edge(start, end));
                existingEdges.Add((start.Number, end.Number));

                if (!oriented)
                    existingEdges.Add((end.Number, start.Number));
            }

            return graph;
        }
    }
}
