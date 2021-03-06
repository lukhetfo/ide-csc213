﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnOrderedArrayList
{
    class UnOrderedArrayList
    {
        public class List    // ALTERNATIVE: Like in C++, C# allows use of struct instead of class
        {

            static int maxsize = 15;
            private int size;
            private int[] Item;

           
            public  List () 
            {
                this.size = 0;
                this.Item = new int[maxsize];
            }
            
            Boolean IsEmpty() { return size == 0; }


            Boolean IsFull()
            {
                return (this.size == maxsize);
            }

           
            public void Insert(int e)
            {
                if (!(this.IsFull()))
                {
                    this.Item[this.size] = e;
                    this.size++;
                }
            }
            


            private void Swap(int i, int j)
            {
                int Temp = this.Item[i];
                this.Item[i] = this.Item[j];
                this.Item[j] = Temp;
            }

            
            public void Delete(int e)
            {
                int index = 0;
                if (!(this.IsEmpty()))
                {
                    while ((index < this.size) && (this.Item[index] != e))
                        index++;
                    if ((this.Item[index] == e) && (index <= this.size - 1))
                    {
                        Swap(index, this.size - 1);

                        this.size--;
                    }
                }
            }

           
            public void ShowData()
            {
                for (int index = 0; index < this.size; index++)
                {
                    Console.Write(this.Item[index]);
                    Console.Write(" ");
                }     
                Console.WriteLine();
            }


        }


        static void Main(string[] args)
        {

            List L = new List(); //declare and initialize list L
           

            L.Insert(10); L.Insert(15); L.Insert(20);
            L.ShowData();
            L.Delete(15);
            L.ShowData();
            L.Insert(30); L.Insert(50);L.Delete(10);
            L.ShowData();

            Console.ReadKey();
        }
    }
}
