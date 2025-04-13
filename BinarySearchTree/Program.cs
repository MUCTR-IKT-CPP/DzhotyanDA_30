using System.Diagnostics;

namespace BinarySearchTree
{
    class Program
    {
        public static void Main()
        {
            var mainThread = new Thread(() => Test(), maxStackSize: 1024 * 1024 * 64);
            mainThread.Start();
            mainThread.Join();
        }

        public static void Test()
        {
            const int TEST_COUNT = 10;
            const int GENERATION_COUNT = 20;
            const int OPERATIONS_COUNT = 1000;
            const int LEFT_BOUND_RAND = 1;
            const int RIGHT_BOUND_RAND = 10000;

            Random random = new();
            Stopwatch stopwatch = new();

            List<double> insertBinaryRandom = new();
            List<double> insertAVLRandom = new();
            List<double> searchBinaryRandom = new();
            List<double> searchAVLRandom = new();
            List<double> searchArrayRandom = new();
            List<double> deleteBinaryRandom = new();
            List<double> deleteAVLRandom = new();

            List<double> insertBinarySort = new();
            List<double> insertAVLSort = new();
            List<double> searchBinarySort = new();
            List<double> searchAVLSort = new();
            List<double> searchArraySort = new();
            List<double> deleteBinarySort = new();
            List<double> deleteAVLSort = new();

            for (int i = 1; i <= TEST_COUNT; i++)
            {
                int size = 1 << (10 + i);
                for (int j = 0; j < GENERATION_COUNT; j++)
                {
                    int[] arr = new int[size];

                    // Заполнение массива случайными числами
                    if (j <= GENERATION_COUNT / 2)
                    {
                        for (int k = 0; k < size; k++)
                        {
                            arr[k] = random.Next(LEFT_BOUND_RAND, RIGHT_BOUND_RAND);
                        }
                    }
                    // Заполнение массива последовательными числами
                    else
                    {
                        for (int k = 0; k < size; k++)
                        {
                            arr[k] = k;
                        }
                    }

                    // Вставка в BinaryTree
                    BinaryTree binaryTree = new();
                    Node? rootBinary = null;
                    stopwatch.Restart();
                    for (int k = 0; k < size; k++)
                        rootBinary = binaryTree.Insert(rootBinary, arr[k]);
                    stopwatch.Stop();
                    var insertBinaryTime = stopwatch.Elapsed.TotalMilliseconds;

                    // Вставка в AVLTree
                    AVLTree avlTree = new();
                    stopwatch.Restart();
                    for (int k = 0; k < size; k++)
                        avlTree.root = avlTree.Insert(avlTree.root, arr[k]);
                    stopwatch.Stop();
                    var insertAVLTime = stopwatch.Elapsed.TotalMilliseconds;

                    // 1000 операций поиска
                    int[] searchKeys = Enumerable.Range(0, OPERATIONS_COUNT)
                                                 .Select(_ => arr[random.Next(size)]).ToArray();

                    // BinaryTree поиск
                    stopwatch.Restart();
                    foreach (var key in searchKeys)
                        binaryTree.Search(rootBinary, key);
                    stopwatch.Stop();
                    var searchBinaryTime = stopwatch.Elapsed.TotalMilliseconds / OPERATIONS_COUNT;

                    // AVLTree поиск
                    stopwatch.Restart();
                    foreach (var key in searchKeys)
                        avlTree.Search(avlTree.root, key);
                    stopwatch.Stop();
                    var searchAVLTime = stopwatch.Elapsed.TotalMilliseconds / OPERATIONS_COUNT;

                    // Array поиск
                    stopwatch.Restart();
                    foreach (var key in searchKeys)
                        Array.IndexOf(arr, key);
                    stopwatch.Stop();
                    var searchArrayTime = stopwatch.Elapsed.TotalMilliseconds / OPERATIONS_COUNT;

                    // Удаление
                    stopwatch.Restart();
                    foreach (var key in searchKeys)
                        rootBinary = binaryTree.Delete(rootBinary, key);
                    stopwatch.Stop();
                    var deleteBinaryTime = stopwatch.Elapsed.TotalMilliseconds / OPERATIONS_COUNT;

                    stopwatch.Restart();
                    foreach (var key in searchKeys)
                        avlTree.root = avlTree.Delete(avlTree.root, key);
                    stopwatch.Stop();
                    var deleteAVLTime = stopwatch.Elapsed.TotalMilliseconds / OPERATIONS_COUNT;

                    // Сохраняем в список (по выбору: случайные или отсортированные)
                    if (j < GENERATION_COUNT / 2)
                    {
                        insertBinaryRandom.Add(insertBinaryTime);
                        insertAVLRandom.Add(insertAVLTime);
                        searchBinaryRandom.Add(searchBinaryTime);
                        searchAVLRandom.Add(searchAVLTime);
                        searchArrayRandom.Add(searchArrayTime);
                        deleteBinaryRandom.Add(deleteBinaryTime);
                        deleteAVLRandom.Add(deleteAVLTime);
                    }
                    else
                    {
                        insertBinarySort.Add(insertBinaryTime);
                        insertAVLSort.Add(insertAVLTime);
                        searchBinarySort.Add(searchBinaryTime);
                        searchAVLSort.Add(searchAVLTime);
                        searchArraySort.Add(searchArrayTime);
                        deleteBinarySort.Add(deleteBinaryTime);
                        deleteAVLSort.Add(deleteAVLTime);
                    }
                }

                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine($"Test {i} completed. Size: {size}");
                Console.ForegroundColor = ConsoleColor.White;
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("Random part");
                Console.ForegroundColor = ConsoleColor.White;
                Console.WriteLine($"BinaryTree Insert Random: {insertBinaryRandom.Average()} ms");
                Console.WriteLine($"AVLTree Insert Random: {insertAVLRandom.Average()} ms");
                Console.WriteLine($"BinaryTree Search Random: {searchBinaryRandom.Average()} ms");
                Console.WriteLine($"AVLTree Search Random: {searchAVLRandom.Average()} ms");
                Console.WriteLine($"Array Search Random: {searchArrayRandom.Average()} ms");
                Console.WriteLine($"BinaryTree Delete Random: {deleteBinaryRandom.Average()} ms");
                Console.WriteLine($"AVLTree Delete Random: {deleteAVLRandom.Average()} ms");
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("Sorted part");
                Console.ForegroundColor = ConsoleColor.White;
                Console.WriteLine($"BinaryTree Insert Sorted: {insertBinarySort.Average()} ms");
                Console.WriteLine($"AVLTree Insert Sorted: {insertAVLSort.Average()} ms");
                Console.WriteLine($"BinaryTree Search Sorted: {searchBinarySort.Average()} ms");
                Console.WriteLine($"AVLTree Search Sorted: {searchAVLSort.Average()} ms");
                Console.WriteLine($"Array Search Sorted: {searchArraySort.Average()} ms");
                Console.WriteLine($"BinaryTree Delete Sorted: {deleteBinarySort.Average()} ms");
                Console.WriteLine($"AVLTree Delete Sorted: {deleteAVLSort.Average()} ms");
                Console.WriteLine("-------------------------------------------------");

                WriteToFile(i, insertBinaryRandom, insertAVLRandom, searchBinaryRandom, searchAVLRandom, searchArrayRandom, deleteBinaryRandom, deleteAVLRandom, insertBinarySort, insertAVLSort, searchBinarySort, searchAVLSort, searchArraySort, deleteBinarySort, deleteAVLSort);
            }
        }

        public static void WriteToFile(
            int testNumber,
            List<double> insertBinaryRandom,
            List<double> insertAVLRandom,
            List<double> searchBinaryRandom,
            List<double> searchAVLRandom,
            List<double> searchArrayRandom,
            List<double> deleteBinaryRandom,
            List<double> deleteAVLRandom,
            List<double> insertBinarySort,
            List<double> insertAVLSort,
            List<double> searchBinarySort,
            List<double> searchAVLSort,
            List<double> searchArraySort,
            List<double> deleteBinarySort,
            List<double> deleteAVLSort)
        {
            var path = Path.Combine(Directory.GetCurrentDirectory(), "..", "..", "..", "Measurements.txt");

            using (StreamWriter sw = new StreamWriter(path, true, System.Text.Encoding.Default))
            {
                sw.WriteLine($"Test {testNumber}");
                sw.WriteLine($"Size: {1 << (10 + testNumber)}");
                sw.WriteLine("Random part");
                sw.WriteLine($"BinaryTree Insert Random: {insertBinaryRandom.Average():F6} ms");
                sw.WriteLine($"AVLTree Insert Random: {insertAVLRandom.Average():F6} ms");
                sw.WriteLine($"BinaryTree Search Random: {searchBinaryRandom.Average():F6} ms");
                sw.WriteLine($"AVLTree Search Random: {searchAVLRandom.Average():F6} ms");
                sw.WriteLine($"Array Search Random: {searchArrayRandom.Average():F6} ms");
                sw.WriteLine($"BinaryTree Delete Random: {deleteBinaryRandom.Average():F6} ms");
                sw.WriteLine($"AVLTree Delete Random: {deleteAVLRandom.Average():F6} ms");
                sw.WriteLine("Sorted part");
                sw.WriteLine($"BinaryTree Insert Sorted: {insertBinarySort.Average():F6} ms");
                sw.WriteLine($"AVLTree Insert Sorted: {insertAVLSort.Average():F6} ms");
                sw.WriteLine($"BinaryTree Search Sorted: {searchBinarySort.Average():F6} ms");
                sw.WriteLine($"AVLTree Search Sorted: {searchAVLSort.Average():F6} ms");
                sw.WriteLine($"Array Search Sorted: {searchArraySort.Average():F6} ms");
                sw.WriteLine($"BinaryTree Delete Sorted: {deleteBinarySort.Average():F6} ms");
                sw.WriteLine($"AVLTree Delete Sorted: {deleteAVLSort.Average():F6} ms");
                sw.WriteLine("-------------------------------------------------");
            }
        }

        public static void testTree()
        {
            BinaryTree tree = new BinaryTree();
            Node? root = new Node(8);
            tree.Insert(root, 10);
            tree.Insert(root, 3);
            tree.Insert(root, 1);
            tree.Insert(root, 6);
            tree.Insert(root, 7);
            tree.Insert(root, 4);
            tree.Insert(root, 14);
            tree.Insert(root, 13);
            tree.InorderTraversal(root);
            
            tree.PrintTree(root);

            Console.WriteLine("Deleting 10");
            root = tree.Delete(root, 10);
            tree.InorderTraversal(root);
            Console.WriteLine();

            /*var result = tree.Search(root, 14);
            Console.WriteLine(result.value);
            Console.WriteLine(result.left?.value.ToString() ?? "null");
            Console.WriteLine(result.right?.value.ToString() ?? "null");*/

            tree.PrintTree(root);
        }

        public static void testAvlTree()
        {
            var tree = new AVLTree();
            int[] values = { 10, 20, 30, 40, 50, 25 };

            foreach (var val in values)
            {
                tree.root = tree.Insert(tree.root, val);
            }

            tree.PrintTree(tree.root);

            tree.root = tree.Delete(tree.root, 20); // удалить значение 20
            tree.PrintTree(tree.root);
        }
    }
}