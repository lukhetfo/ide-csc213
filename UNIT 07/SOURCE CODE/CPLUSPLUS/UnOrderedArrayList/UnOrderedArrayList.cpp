// UnOrderedArrayList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "List.h"

int main()
{
	List L;
	Init(L);
	Insert(10 , L); Insert(15, L); Insert(20, L);
	ShowData(L);
	Delete(15, L);
	ShowData(L);
	Insert(30, L); Insert(50, L); Delete(10, L);
	ShowData(L);
	system("pause");
}


