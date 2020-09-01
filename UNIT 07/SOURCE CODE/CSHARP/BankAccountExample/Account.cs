using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankAccountExample
{
    public class Account
    {  
        public float balance;

        public Account(float openingBalance)
        {
            balance = openingBalance;
        }
        
        public void withdraw(float amount) { balance -= amount; }
        public void deposit(float amount) { balance += amount; }

        public void displayBalance() {
            Console.Write( "Balance is " + balance + " Emalangeni");

        }
    }
}
