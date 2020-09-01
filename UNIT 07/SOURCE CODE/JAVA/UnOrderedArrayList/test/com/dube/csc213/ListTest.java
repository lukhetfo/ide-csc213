
package com.dube.csc213;

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
public class ListTest {
    
    public ListTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }

    /**
     * Test of IsEmpty method, of class List.
     */
    @Test
    public void testIsEmpty() {
        System.out.println("IsEmpty");
        List instance = new List();
        boolean expResult = true;
        boolean result = instance.IsEmpty();
        assertEquals(expResult, result);
    }

    /**
     * Test of IsFull method, of class List.
     */
    @Test
    public void testIsFull() {
        System.out.println("IsFull");
        List instance = new List();
        boolean expResult = false;
        boolean result = instance.IsFull();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        
    }

    /**
     * Test of Insert method, of class List.
     */
    @Test
    public void testInsert() {
        System.out.println("Insert");
        int e = 0;
        List instance = new List();
        assertEquals(0, instance.GetSize());
        instance.Insert(e);
        assertFalse(instance.IsFull());
        assertFalse(instance.IsEmpty());
        assertEquals(1, instance.GetSize());

    }

    /**
     * Test of Delete method, of class List.
     */
    @Test
    public void testDelete() {
        System.out.println("Delete");
        int e = 0;
        List instance = new List();
        instance.Delete(e);
        assertTrue(instance.IsEmpty());
        instance.Insert(10);
        instance.Insert(20);
        instance.Insert(30);
        assertEquals(3, instance.GetSize());
        instance.Delete(10);
        assertEquals(0, instance.GetSize());    
    }

    /**
     * Test of ShowData method, of class List.
     */
    @Test
    public void testShowData() {
        System.out.println("ShowData");
        List L = new List();
        L.Insert(10); L.Insert(15); L.Insert(20);
        assertEquals(3, L.GetSize());
        String Expected_Output = "10\t15\t20\t";
        
       /*******************************************/
       // Start capturing console output
       ByteArrayOutputStream buffer = 
               new ByteArrayOutputStream();
       System.setOut(new PrintStream(buffer));
       // Run showData
       L.ShowData();
       // Stop capturing
       
       System.setOut(new PrintStream(new FileOutputStream(FileDescriptor.out)));
       /*******************************************/
       
       // Use captured content
        String result = buffer.toString();
        buffer.reset();        
        assertEquals(Expected_Output, result);
       }
    
}
