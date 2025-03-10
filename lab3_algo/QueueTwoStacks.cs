using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace lab3_algo
{
    internal class QueueTwoStacks<T> : IEnumerable<T>
    {
        private readonly Stack<T> stack1 = new();
        private readonly Stack<T> stack2 = new();

        public void Add(T data)
        {
            stack1.Push(data);
        }

        public T Pop()
        {
            if (stack2.Count == 0)
            {
                if (stack1.Count == 0)
                    throw new InvalidOperationException("Queue is empty");

                while (stack1.Count > 0)
                {
                    stack2.Push(stack1.Pop());
                }
            }
            return stack2.Pop();
        }

        public int Length => stack1.Count + stack2.Count;

        public bool IsEmpty() => Length == 0;

        public IEnumerator<T> GetEnumerator()
        {
            while (!IsEmpty())
            {
                yield return Pop();
            }
        }

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }
}
