using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedListExample_Generic
{
    class LinkedListExample_Generic
    {
        //define node structure
        public  class Node<T>
        {
            public T data;
            public Node<T> next;

            public Node()
            {
            }

            public Node(T data, Node<T> next)
            {
                this.data = data;
                this.next = next;
            }

            public Node(T data)
            {
                this.data = data;
                this.next = null;
            }
        }

        //define generic list
        public  class MyLinkedList<T>
        {
            Node<T> head;

            public MyLinkedList() { head = null; }

            public Boolean IsEmpty() { return (head == null); }
            public Boolean IsFull() { return false; }
            public void Insert(T e)
            {
                Node<T> NewNode = new Node<T>(e, head);
                head = NewNode;
            }

            public void Delete(T e)
            {
                Node<T> CurrNode = head;
                Node<T> PrevNode = null;

                while ((CurrNode != null) && (! CurrNode.data.Equals(e)))
                {
                    // searching for node to delete 
                    PrevNode = CurrNode;
                    CurrNode = CurrNode.next;
                }
                if ((CurrNode != null) && (CurrNode.data.Equals(e)))
                {
                    if (PrevNode == null)  // deleting first node
                        head = CurrNode.next;
                    else
                        PrevNode.next = CurrNode.next;
                }
            }

            public void ShowData()
            {
                Node<T> CurrNode = this.head;
                while (CurrNode != null)
                {
                    Console.Write("\t" + CurrNode.data);
                    CurrNode = CurrNode.next;
                }
                Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
            MyLinkedList<int> L = new MyLinkedList<int>();

            L.Insert(10); L.Insert(15); L.Insert(20);
            L.ShowData();
            L.Delete(15);
            L.ShowData();
            L.Insert(30); L.Insert(50); L.Delete(10);
            L.ShowData();

            Console.ReadKey();

        }
    }
}
