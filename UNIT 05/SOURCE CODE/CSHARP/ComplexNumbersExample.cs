using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ComplexNumbersExample
{
    class ComplexNumbersExample
    {

        public  class Complex
        {

            private float x;     //real part
            private float y;     //imaginary part

            public Complex() { }
            public Complex(float xp, float yp) { x = xp; y = yp; }
            public float Re() { return x; }
            public float Im() { return y; }


            //overload addition operator
            public static Complex operator +(Complex Z1, Complex Z2)
            {
                Complex Z = new Complex();
                Z.x = Z1.Re() + Z2.Re();
                Z.y= Z1.Im() + Z2.Im();
                return Z;
            }


            //overload multiplication operator
            public static Complex operator *(Complex Z1, Complex Z2)
            {
                Complex Z = new Complex();
                Z.x = Z1.Re() * Z2.Re() - Z1.Im() * Z2.Im();
                Z.y = Z1.Re() * Z2.Im() + Z1.Im() * Z2.Re();
                return Z;
            }
           

            //C# uses Write/Writeln method to write output
            //over-ride ToString() method to use Write/Writeln for Complex numbers

            public override string ToString()
            {
                return x + " + " + y + 'i';
            }

            
        }
        static void Main(string[] args)
        {
            Complex Z1 = new Complex(5, 10);
            Complex Z2 = new Complex(4, 5);

            Console.WriteLine(Z1);
            Console.WriteLine(Z2);

            Z1 = Z1 + Z2;
            Console.WriteLine(Z1);

            Complex Z3 = new Complex(5, 10);
            Z3 = Z3*Z2;
            Console.WriteLine(Z3);

            Console.ReadKey();

        }
    }
}
