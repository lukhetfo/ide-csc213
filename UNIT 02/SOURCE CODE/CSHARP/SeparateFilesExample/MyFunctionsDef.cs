using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SeparateFiles_Example
{
    public static class MyFunctionsDef
    {
        public static int factorial(int n)
        {
            return (n == 0) ? 1 : n * factorial(n - 1);
        }

        public  static int MyPower(int x = 1, int n = 0)
        {
            return (n == 0) ? 1 : x * MyPower(x, n - 1);
        }
    }
}
