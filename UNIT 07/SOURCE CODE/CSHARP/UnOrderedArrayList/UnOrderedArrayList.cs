using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnOrderedArrayList
{
    public class UnOrderedArrayList
    {
        


        public static void Main(string[] args)
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
