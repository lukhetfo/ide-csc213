// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

typedef  int DataType;

struct node {
	DataType data;
	node* next;
};

typedef  node*  List;

void Init(List& L){ L = NULL; } 

bool IsEmpty(List L){ return (L == NULL); }

void Insert(DataType e, List& L) {
	List NewNode = new node;
	NewNode->data = e;
	NewNode->next = L;
	L = NewNode;
}

void Delete(DataType e, List& L)
{
	List CurrNode = L;
	List PrevNode = NULL;

	while ((CurrNode != NULL) && (CurrNode->data != e)){ 	
		PrevNode = CurrNode;
		CurrNode = CurrNode->next;}

	if ((CurrNode != NULL) && (CurrNode->data == e)) {
		if (PrevNode == NULL)  
			L = CurrNode->next;
		else
			PrevNode->next = CurrNode->next;
	}
}

void ShowData(List  L) {
	while (L != NULL) {
		std::cout << L->data << "  ";
		L = L->next;
	}
	std::cout << std::endl;
}


int main()
{
	List L;
	Init(L);
	Insert(10, L); Insert(15, L); Insert(20, L);
	ShowData(L);
	Delete(15, L);
	ShowData(L);
	Insert(30, L); Insert(50, L); Delete(10, L);
	ShowData(L);
	system("pause");

}

