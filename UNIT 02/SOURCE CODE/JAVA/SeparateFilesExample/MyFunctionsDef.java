package com.dube.csc213.definition;

/**
 *
 * @author Enock Lukhetfo Dube  <eldube@uniswa.sz>
 */
public class MyFunctionsDef {
    public static int factorial(int n) {
            return (n == 0) ? 1 : n * factorial(n - 1);
    }

    public static int myPower(int x, int n){
            return (n == 0) ? 1 : x * myPower(x, n - 1);
    }
}
