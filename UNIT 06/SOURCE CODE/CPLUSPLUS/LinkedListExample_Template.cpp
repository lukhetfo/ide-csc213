// LinkedListExample_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


typedef  int DataType;


template <typename T>
struct node
{
	T data;
	node* next;
};

template <typename T>
void Init(node<T>*& L)
{
	L = NULL;
} 

template <typename T>
bool IsEmpty(node<T>* L)
{
	return (L == NULL);
}

template <typename T>
void Insert(T e, node<T>*& L)
{
	node<T>* NewNode = new node<T>;
	NewNode->data = e;
	NewNode->next = L;
	L = NewNode;
}

template <typename T>
void Delete(T e, node<T>*& L)
{
	node<T>* CurrNode = L;
	node<T>* PrevNode = NULL;

	while ((CurrNode != NULL) && (CurrNode->data != e))
	{ // searching for node to delete 
		PrevNode = CurrNode;
		CurrNode = CurrNode->next;
	}
	if ((CurrNode != NULL) && (CurrNode->data == e))
	{
		if (PrevNode == NULL)  // deleting first node
			L = CurrNode->next;
		else
			PrevNode->next = CurrNode->next;
	}
}

template <typename T>
void ShowData(node<T>*  L)
{
	while (L != NULL)
	{
		std::cout << L->data << "  ";
		L = L->next;
	}
	std::cout << std::endl;
}


int main()
{
	node<int>* L;
	Init(L);
	Insert(10, L); Insert(15, L); Insert(20, L); ShowData(L);
	Delete(15, L);ShowData(L);
	Insert(30, L); Insert(50, L); Delete(10, L);ShowData(L);
	Delete(50, L);ShowData(L);

	system("pause");
}

