
package com.dube.csc213;

/**
 *
 * @author Enock Lukhetfo Dube  <eldube@uniswa.sz>
 */
public class BasicConstructsDemo_CLI {

    //Single Selection
    static void singleSelectionExample(int x, int y) {
	if (x > y) {
		System.out.println(x);
	}
    }


    //Double Selection
    static void doubleSelectionExample(int x, int y) {
	if (x > y) 
		System.out.println(x);
	else
		System.out.println(y);
    }

    //Multiple Selection
    static void multiplySelectionExample(int day) {
	switch (day) {
	case 6:
	case 7:
		System.out.println("Weekend");
		break;
	default:
		System.out.println("Week Day");
		break;
	}
    }

    //While loop
    static void whileLoopExample() {
	int i = 1;
	while (i < 5) {
            System.out.print(i);
            i++;
	}

	System.out.println();
    }

    //Do ... while loop
    static void doWhileLoopExample() {
	int i = 1;
	do {
		System.out.print(i);
		i++;
	} while (i < 5);

	System.out.println();
    }

    //FOR loop
    static void forLoopExample() {
	for (int i = 1; i < 5; i++) {
		System.out.print(i);
	}

	System.out.println();
    }
    public static void main(String[] args) {
    
	//run selection code
	singleSelectionExample(10, 5);
	doubleSelectionExample(5, 10);
	multiplySelectionExample(4);

	//run iteration code
	whileLoopExample();
	doWhileLoopExample();
	forLoopExample();
    }
    
}
