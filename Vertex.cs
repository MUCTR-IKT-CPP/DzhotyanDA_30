namespace lab5_algo
{
    internal class Vertex
    {
        public int Number { get; }

        public Vertex(int number)
        {
            Number = number;
        }

        public override string ToString()
        {
            return Number.ToString();
        }
    }
}
