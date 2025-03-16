namespace lab4_algo
{
    internal class Edge
    {
        public Vertex Start { get; }

        public Vertex End { get; }
    
        public int Weight { get; }

        public Edge(Vertex start, Vertex end, int weight = 1)
        {
            Start = start;
            End = end;
            Weight = weight;
        }

        public override string ToString()
        {
            return $"{Start} -> {End}, Weight = {Weight}";
        }
    }
}
