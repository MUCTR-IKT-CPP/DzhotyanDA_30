namespace BinarySearchTree
{
    internal class BinaryTree
    {
        public void InorderTraversal(Node? node)
        {
            if (node == null)
                return;

            InorderTraversal(node.left);
            Console.WriteLine(node.value);
            InorderTraversal(node.right);
        }

        public Node Insert(Node? root, int value)
        {
            if (root == null)
            {
                root = new Node(value);
            }

            else if (value < root.value)
            {
                root.left = Insert(root.left, value);
            }

            else if (value > root.value)
            {
                root.right = Insert(root.right, value);
            }

            return root;
        }

        public Node Search(Node? node, int value)
        {
            if (node == null || node.value == value)
                return node;

            if (value < node.value)
                return Search(node.left, value);
            else
                return Search(node.right, value);
        }

        public Node? Delete(Node? root, int value)
        {
            if (root == null)
                return root;

            if (value < root.value)
            {
                root.left = Delete(root.left, value);
            }
            else if (value > root.value)
            {
                root.right = Delete(root.right, value);
            }
            else if (root.left != null && root.right != null)
            {
                Node minNode = FindMinimum(root.right);
                root.value = minNode.value;
                root.right = Delete(root.right, (int)minNode.value);
            }
            else
            {
                if (root.left != null)
                    root = root.left;
                else if (root.right != null)
                    root = root.right;
                else
                    root = null;
            }

            return root;
        }

        public void PrintTree(Node? node, string indent = "", bool isLeft = true)
        {
            if (node == null)
                return;

            if (node.right != null)
            {
                PrintTree(node.right, indent + (isLeft ? "│   " : "    "), false);
            }

            Console.Write(indent);
            Console.Write(isLeft ? "└── " : "┌── ");
            Console.WriteLine(node.value);

            if (node.left != null)
            {
                PrintTree(node.left, indent + (isLeft ? "    " : "│   "), true);
            }
        }

        private Node FindMinimum(Node node)
        {
            if (node.left == null)
                return node;
            else
                return FindMinimum(node.left);
        }
    }
}
