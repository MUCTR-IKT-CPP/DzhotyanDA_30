namespace BinarySearchTree
{
    internal class Node
    {
        public int? value;
        
        public Node? left;
        
        public Node? right;

        public int height;

        public Node(int value)
        {
            this.value = value;
            left = null;
            right = null;
            height = 1;
        }
    }
}
