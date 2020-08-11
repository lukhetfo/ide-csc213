using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DrawFigureExample_CLI
{
    class Program
    {
        static void Main(string[] args)
        {
            //Read height from input
            Console.WriteLine("Enter integer height of figure: : ");
            int height;
            int.TryParse(Console.ReadLine(), out height);


            //loop and output each line
            for (int lineNumber = 1; lineNumber <= height; lineNumber++)
            {
                //Write(Height – lineNumber) blank characters
                for (int i = 1; i <= height - lineNumber; i++)
                    Console.Write(" ");

                //Write(2 * lineNumber – 1) asterisk characters
                for (int i = 1; i <= 2 * lineNumber - 1; i++)
                    Console.Write("*");

                //Write(Height – lineNumber) blank character
                for (int i = 1; i <= height - lineNumber; i++)
                    Console.Write(" ");

                //Go to a new output line
                Console.WriteLine();
            }

            Console.ReadKey();
        }
    }
}
