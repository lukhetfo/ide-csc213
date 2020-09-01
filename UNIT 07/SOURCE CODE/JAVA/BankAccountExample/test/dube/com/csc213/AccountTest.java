
package dube.com.csc213;

import java.io.ByteArrayOutputStream;
import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.PrintStream;
import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Enock Lukhetfo Dube <lukhetfomzomba@gmail.com>
 */
public class AccountTest {
    
    public AccountTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }

    /**
     * Test of withdraw method, of class Account.
     */
    @Test
    public void testWithdraw() {
        //arrange
         float amount = 1000.0F;
         Account instance = new Account(amount);
         float expected_new_balance = 700.0F;
        //act
        instance.withdraw(300.0F);
        
        //assert
        assertTrue(instance.balance == expected_new_balance);   
    }

    /**
     * Test of deposit method, of class Account.
     */
    @Test
    public void testDeposit() {
        //arrange
         float amount = 1000.0F;
         Account instance = new Account(amount);
         float expected_new_balance = 1500.0F;
        //act
        instance.deposit(500.0F);
        
        //assert
        assertTrue(instance.balance == expected_new_balance); 
    }

    /**
     * Test of displayBalance method, of class Account.
     */
    @Test
    public void testDisplayBalance() {
         //arrange
         float amount = 1000.0F;
         Account instance = new Account(amount);
         String expected_result ="Balance is 1000.0 Emalangeni";
        
       /*******************************************/
       // Start capturing console output
       ByteArrayOutputStream buffer = 
               new ByteArrayOutputStream();
       System.setOut(new PrintStream(buffer));
       // Act - Run showData
       
       instance.displayBalance();
       // Stop capturing
       /*******************************************/
       
       System.setOut(new PrintStream(new FileOutputStream(FileDescriptor.out)));
       /*******************************************/
       
       // Use captured content
        String actual_result = buffer.toString();
        buffer.reset();  
        
        //assert 
        assertEquals(expected_result, actual_result);
    }
    
}
