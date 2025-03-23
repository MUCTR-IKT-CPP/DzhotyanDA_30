using System.ComponentModel.DataAnnotations;
using System.Drawing;

namespace lab5_algo
{
    internal class GraphGenerator
    {
        const int MIN_WEIGHT = 1;
        const int MAX_WEIGHT = 20;
        const int EXTRA_NEUGHBOURS = 2;

        private Random random = new Random();

        public Graph GenerateGraph(int verticesCount, int minEdgesCount, bool oriented)
        {
            Graph graph = new Graph(oriented);
            Random random = new Random();

            int minNeughboursCount = random.Next(minEdgesCount, minEdgesCount + EXTRA_NEUGHBOURS);
            
            Console.WriteLine($"Минимальное количество вершин, с которым связана вершина: {minNeughboursCount}");
            
            List<Vertex> vertices = new List<Vertex>();

            for (int i = 1; i <= verticesCount; i++)
            {
                var vertex = new Vertex(i);
                vertices.Add(vertex);
                graph.AddVertex(vertex);
            }

            for (int i = 0; i < verticesCount; i++)
            {
                Vertex start = vertices[i];

                List<Vertex> notNeughbours = vertices.Where(v => v != start).ToList();

                int edgesToAdd = Math.Min(minNeughboursCount, notNeughbours.Count);

                for (int j = 0; j < edgesToAdd; j++)
                {
                    if (notNeughbours.Count == 0)
                        break;

                    Vertex end = notNeughbours[random.Next(notNeughbours.Count)];
                    notNeughbours.Remove(end);

                    int weight = random.Next(MIN_WEIGHT, MAX_WEIGHT + 1);

                    Edge edge = new Edge(start, end, weight);
                    graph.AddEdge(edge);

                    if (!oriented)
                    {
                        Edge reverseEdge = new Edge(end, start, weight);
                        graph.AddEdge(reverseEdge);
                    }
                }
            }


            return graph;
        }
    }
}
