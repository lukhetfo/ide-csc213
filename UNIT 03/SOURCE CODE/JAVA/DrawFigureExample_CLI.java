package com.dube.csc213;

import java.util.Scanner;

/**
 *
 * @author Enock Lukhetfo Dube  <eldube@uniswa.sz>
 */
public class DrawFigureExample_CLI {

    
    public static void main(String[] args) {
        //Read height from input
        Scanner in = new Scanner(System.in);
        System.out.print("Enter integer height of figure: : ");
        int height = in.nextInt();
        in.close();

	//loop and output each line
	for (int lineNumber = 1; lineNumber <= height; lineNumber++)
	{
		//Write(Height – lineNumber) blank characters
		for (int i = 1; i <= height - lineNumber; i++)
			System.out.print(" ");

		//Write(2 * lineNumber – 1) asterisk characters
		for (int i = 1; i <= 2 * lineNumber-1; i++)
			System.out.print("*");

		//Write(Height – lineNumber) blank character
		for (int i = 1; i <= height-lineNumber; i++)
			System.out.print(" ");

		//Go to a new output line
		System.out.println(); 
        }
    }   
}
