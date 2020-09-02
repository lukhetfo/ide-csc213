package com.dube.csc213.driver;

//import contents of MyFunctionsDef.java file
import com.dube.csc213.definition.MyFunctionsDef;

/**
 *
 * @author Enock Lukhetfo Dube  <eldube@uniswa.sz>
 */
public class Driver {

    public static void main(String[] args) {
        for (int m = 0; m < 6; m++)
             System.out.print(MyFunctionsDef.factorial(m) +"\t");
        System.out.println();

        for (int n = 0; n < 6; n++)
             System.out.print(MyFunctionsDef.myPower(2, n) + "\t");
        
        System.out.println();;
    }
    
}
