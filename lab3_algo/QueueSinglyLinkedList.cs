using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace lab3_algo
{
    internal class QueueSinglyLinkedList<T> : IEnumerable<T>
    {
        private LinkedList<T> queue = new();

        public void Add(T data)
        {
            queue.AppendLast(data);
        }

        public T PopFirst()
        {
            T result = queue.PopFirst();
            return result;
        }

        public int Length => queue.GetCount();

        public bool IsEmpty() => queue.IsEmpty();

        public IEnumerator<T> GetEnumerator() => queue.GetEnumerator();

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }
}
