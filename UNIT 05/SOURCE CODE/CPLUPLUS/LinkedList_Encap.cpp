// LinkedList_Encap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

typedef  int DataType;

struct node {
	DataType data;
	node* next;
};

struct List {

	node*  head;

	void Init() { head = NULL; }

	bool IsEmpty() { return (head == NULL); }

	void Insert(DataType e) {
		node* NewNode = new node;
		NewNode->data = e;
		NewNode->next = head;
		head = NewNode;
	}

	void Delete(DataType e)
	{
		node* CurrNode = head;
		node* PrevNode = NULL;

		while ((CurrNode != NULL) && (CurrNode->data != e)) {
			PrevNode = CurrNode;
			CurrNode = CurrNode->next;
		}

		if ((CurrNode != NULL) && (CurrNode->data == e)) {
			if (PrevNode == NULL)
				head = CurrNode->next;
			else
				PrevNode->next = CurrNode->next;
		}
	}


	void ShowData() {
		node* L = head;
		while (L != NULL) {
			std::cout << L->data << "  ";
			L = L->next;
		}
		std::cout << std::endl;
	}

};



int main()
{
	List L;
	L.Init();
	L.Insert(10); L.Insert(15); L.Insert(20);
	L.ShowData();
	L.Delete(15);
	L.ShowData();
	L.Insert(30); L.Insert(50); L.Delete(10);
	L.ShowData();
	system("pause");
}
