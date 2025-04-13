namespace BinarySearchTree
{
    internal class AVLTree
    {
        public Node? root;

        public int Height(Node? node)
        {
            return node?.height ?? 0;
        }

        public int GetBalance(Node? node)
        {
            return node == null ? 0 : Height(node.left) - Height(node.right);
        }

        public Node? Search(Node? node, int key)
        {
            if (node == null || node.value == key)
                return node;

            if (key < node.value)
                return Search(node.left, key);
            else
                return Search(node.right, key);
        }

        public Node Insert(Node? node, int key)
        {
            if (node == null)
                return new Node(key);

            if (key < node.value)
                node.left = Insert(node.left, key);
            else if (key > node.value)
                node.right = Insert(node.right, key);
            else
                return node; // дубликаты не вставляем

            // Обновляем высоту
            node.height = 1 + Math.Max(Height(node.left), Height(node.right));

            // Получаем баланс
            int balance = GetBalance(node);

            // Балансировка
            // LL
            if (balance > 1 && key < node.left!.value)
                return RotateRight(node);

            // RR
            if (balance < -1 && key > node.right!.value)
                return RotateLeft(node);

            // LR
            if (balance > 1 && key > node.left!.value)
            {
                node.left = RotateLeft(node.left);
                return RotateRight(node);
            }

            // RL
            if (balance < -1 && key < node.right!.value)
            {
                node.right = RotateRight(node.right);
                return RotateLeft(node);
            }

            return node;
        }

        private Node RotateRight(Node y)
        {
            Node x = y.left!;
            Node T2 = x.right!;

            x.right = y;
            y.left = T2;

            y.height = 1 + Math.Max(Height(y.left), Height(y.right));
            x.height = 1 + Math.Max(Height(x.left), Height(x.right));

            return x;
        }

        private Node RotateLeft(Node x)
        {
            Node y = x.right!;
            Node T2 = y.left!;

            y.left = x;
            x.right = T2;

            x.height = 1 + Math.Max(Height(x.left), Height(x.right));
            y.height = 1 + Math.Max(Height(y.left), Height(y.right));

            return y;
        }

        public Node? Delete(Node? root, int key)
        {
            if (root == null)
                return root;

            // 1. Обычное удаление как в BST
            if (key < root.value)
                root.left = Delete(root.left, key);
            else if (key > root.value)
                root.right = Delete(root.right, key);
            else
            {
                // Узел с одним или без детей
                if (root.left == null || root.right == null)
                {
                    Node? temp = root.left ?? root.right;

                    if (temp == null)
                    {
                        root = null;
                    }
                    else
                    {
                        root = temp;
                    }
                }
                else
                {
                    // Узел с двумя детьми — находим inorder-последователя (минимум в правом поддереве)
                    Node minLargerNode = GetMinValueNode(root.right);
                    root.value = minLargerNode.value;
                    root.right = Delete(root.right, (int)minLargerNode.value);
                }
            }

            // Если дерево стало пустым
            if (root == null)
                return null;

            // 2. Обновляем высоту
            root.height = 1 + Math.Max(Height(root.left), Height(root.right));

            // 3. Балансировка
            int balance = GetBalance(root);

            // LL
            if (balance > 1 && GetBalance(root.left) >= 0)
                return RotateRight(root);

            // LR
            if (balance > 1 && GetBalance(root.left) < 0)
            {
                root.left = RotateLeft(root.left);
                return RotateRight(root);
            }

            // RR
            if (balance < -1 && GetBalance(root.right) <= 0)
                return RotateLeft(root);

            // RL
            if (balance < -1 && GetBalance(root.right) > 0)
            {
                root.right = RotateRight(root.right);
                return RotateLeft(root);
            }

            return root;
        }

        private Node GetMinValueNode(Node node)
        {
            Node current = node;
            while (current.left != null)
                current = current.left;

            return current;
        }

        // 🖨 Печать дерева
        public void PrintTree(Node? node, string indent = "", bool isLeft = true)
        {
            if (node == null)
                return;

            if (node.right != null)
                PrintTree(node.right, indent + (isLeft ? "│   " : "    "), false);

            Console.Write(indent);
            Console.Write(isLeft ? "└── " : "┌── ");
            Console.WriteLine(node.value);

            if (node.left != null)
                PrintTree(node.left, indent + (isLeft ? "    " : "│   "), true);
        }
    }

}
