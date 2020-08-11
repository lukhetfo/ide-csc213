using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DrawFigureExample_CLI_Decomp
{
    class Program
    {

        static void writeChar(char ch, int n)
        {
            for (int i = 1; i <= n; i++)
                Console.Write(ch);
        }

        static void drawLine(int height, int lineNumber)
        {
            writeChar(' ', height - lineNumber);
            writeChar('*', 2 * lineNumber - 1);
        }

        static void drawFigure(int height)
        {
            for (int lineNumber = 1; lineNumber <= height; lineNumber++)
            {
                drawLine(height, lineNumber);
                Console.WriteLine();
            }
        }


        static void Main(string[] args)
        {
            //Read height from input
            Console.WriteLine("Enter integer height of figure: : ");
            int height;
            int.TryParse(Console.ReadLine(), out height);

            //draw figure
            drawFigure(height);

            Console.ReadKey();

        }
    }
}
