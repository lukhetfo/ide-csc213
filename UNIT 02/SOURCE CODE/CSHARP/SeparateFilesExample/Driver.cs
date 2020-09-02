using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SeparateFiles_Example
{
    class Driver
    {
        static void Main(string[] args)
        {
            for (int m = 0; m < 6; m++)
                Console.Write (MyFunctionsDef.factorial(m) +"\t");
            Console.WriteLine();

            for (int n = 0; n < 6; n++)
                Console.Write(MyFunctionsDef.MyPower(2, n) + "\t");
            Console.WriteLine();

            Console.ReadKey();
        }
       
    }
}
