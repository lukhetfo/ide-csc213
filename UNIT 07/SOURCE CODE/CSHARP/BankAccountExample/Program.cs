using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankAccountExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Account A = new Account(1000);
           
            A.displayBalance();

            A.deposit(500);
            A.displayBalance();

            A.withdraw(300);
            A.displayBalance();

            Console.ReadKey();

        }
    }
}
