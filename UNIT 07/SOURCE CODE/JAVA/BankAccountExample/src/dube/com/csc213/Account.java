/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dube.com.csc213;

/**
 *
 * @author Enock Lukhetfo Dube <lukhetfomzomba@gmail.com>
 */
public class Account {
      public float balance;

      public Account(float openingBalance) { 
          balance = openingBalance; 
      }
      public void withdraw(float amount) { balance -= amount; }
      public void deposit(float amount) { balance += amount; }

      public void displayBalance() {
            System.out.print( "Balance is " + balance + " Emalangeni");
        }
         
}
       