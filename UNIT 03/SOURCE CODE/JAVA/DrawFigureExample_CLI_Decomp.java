/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dube.csc213;

import java.util.Scanner;

/**
 *
 * @author Enock Lukhetfo Dube  <eldube@uniswa.sz>
 */
public class DrawFigureExample_CLI_Decomp {

        static void writeChar(char ch, int n)
        {
            for (int i = 1; i <= n; i++)
                System.out.print(ch);
        }

        static void drawLine(int height, int lineNumber)
        {
            writeChar(' ', height - lineNumber);
            writeChar('*', 2 * lineNumber - 1);
        }

        static void drawFigure(int height)
        {
            for (int lineNumber = 1; lineNumber <= height; lineNumber++)
            {
                drawLine(height, lineNumber);
                System.out.println();
            }
        }

    public static void main(String[] args) {
        
        //Read height from input
        Scanner in = new Scanner(System.in);
        System.out.print("Enter integer height of figure: ");
        int height = in.nextInt();
        in.close();
        
        //draw figure
        drawFigure(height);

        
    }
    
}
