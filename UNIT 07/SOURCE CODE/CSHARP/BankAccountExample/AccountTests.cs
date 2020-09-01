using Microsoft.VisualStudio.TestTools.UnitTesting;
using BankAccountExample;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankAccountExample.Tests
{
    [TestClass()]
    public class AccountTests
    {
        [TestMethod()]
        public void withdrawTest()
        {
            //arrange
            float amount = 1000.0F;
            Account instance = new Account(amount);
            float expected_new_balance = 700.0F;

            //act
            instance.withdraw(300.0F);

            //assert
            Assert.IsTrue(instance.balance == expected_new_balance);
        }

        [TestMethod()]
        public void depositTest()
        {
            //arrange
            float amount = 1000.0F;
            Account instance = new Account(amount);
            float expected_new_balance = 1500.0F;

            //act
            instance.deposit(500.0F);

            //assert
            Assert.IsTrue(instance.balance == expected_new_balance);
        }

        [TestMethod()]
        public void displayBalanceTest()
        {
            //arrange
            float amount = 1000;
            Account instance = new Account(amount);
            String expected_result = "Balance is 1000 Emalangeni";

            using (var sw = new System.IO.StringWriter())
            {
                Console.SetOut(sw);

                //try
                instance.displayBalance();
                String actual_result = sw.ToString();

                //assert 
                Assert.AreEqual(expected_result, actual_result);
            }
        }
    }
}