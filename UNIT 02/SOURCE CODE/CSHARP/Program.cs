using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BasicConstructsDemo_CLI
{
    class Program
    {
        //Single Selection
        static void singleSelectionExample(int x, int y)
        {
            if (x > y)
            {
                Console.WriteLine(x);
            }
        }


        //Double Selection
        static void doubleSelectionExample(int x, int y)
        {
            if (x > y)
                Console.WriteLine(x);
	        else
		        Console.WriteLine(y);
        }

        //Multiple Selection
        static void multiplySelectionExample(int day)
        {
            switch (day)
            {
                case 6:
                case 7:
                    Console.WriteLine("Weekend");
                    break;
                default:
                    Console.WriteLine("Week Day");
                    break;
            }
        }

        //While loop
        static void whileLoopExample()
        {
            int i = 1;
            while (i < 5)
            {
                Console.Write(i);
                i++;
            }

            Console.WriteLine();
        }

        //Do ... while loop
        static void doWhileLoopExample()
        {
            int i = 1;
            do
            {
                Console.Write(i);
                i++;
            } while (i < 5);

            Console.WriteLine();
        }

        //FOR loop
        static void forLoopExample()
        {
            for (int i = 1; i < 5; i++)
            {
                Console.Write(i);
            }

            Console.WriteLine();
        }


        static void Main(string[] args)
        {
            //run selection code
            singleSelectionExample(10, 5);
            doubleSelectionExample(5, 10);
            multiplySelectionExample(4);

            //run iteration code
            whileLoopExample();
            doWhileLoopExample();
            forLoopExample();

            Console.ReadKey();
        }
    }
}

