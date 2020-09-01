
package dube.com.csc213;

/**
 *
 * @author Enock Lukhetfo Dube <lukhetfomzomba@gmail.com>
 */
public class BankAccountExample {

    
    public static void main(String[] args) {
        
            Account A = new Account(1000);
            A.displayBalance();

            A.deposit(500);
            A.displayBalance();

            A.withdraw(300);
            A.displayBalance();
    }
    
}
