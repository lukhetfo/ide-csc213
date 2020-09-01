using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnOrderedArrayList
{
    
    public class List    
    {

        public static int MaxSize = 15;
        public int Size;
        public int[] Item;


        public List()
        {
            this.Size = 0;
            this.Item = new int[MaxSize];
        }

        public Boolean IsEmpty() { return Size == 0; }


        public Boolean IsFull()
        {
            return (this.Size == MaxSize);
        }


        public void Insert(int e)
        {
            if (!(this.IsFull()))
            {
                this.Item[this.Size] = e;
                this.Size++;
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
                while ((index < this.Size) && (this.Item[index] != e))
                    index++;
                if ((this.Item[index] == e) && (index <= this.Size - 1))
                {
                    Swap(index, this.Size - 1);

                    this.Size--;
                }
            }
        }


        public void ShowData()
        {
            for (int index = 0; index < this.Size; index++)
            {
                Console.Write(this.Item[index]);
                Console.Write(" ");
            }
            Console.WriteLine();
        }


    }
}
