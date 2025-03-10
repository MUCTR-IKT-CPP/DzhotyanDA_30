using System.Collections;

namespace lab3_algo
{
    internal class LinkedList<T> : IEnumerable<T>
    {
        private Node<T>? head;
        private Node<T>? tail;

        private int count;

        public void AppendLast(T data)
        {
            Node<T> node = new Node<T>(data);
        
            if (tail != null)
                tail.Next = node;
            else
                head = node;

            tail = node;
            count++;
        }

        public T PopFirst()
        {
            if (head == null)
                throw new InvalidOperationException("The list is empty");

            T firstData = head.Data;
            head = head.Next;

            if (head == null)
                tail = null;

            count--;
            return firstData;
        }

        public int GetCount() => count;

        public bool IsEmpty() => count == 0;

        public IEnumerator<T> GetEnumerator()
        {
            Node<T>? current = head;
            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }
}
