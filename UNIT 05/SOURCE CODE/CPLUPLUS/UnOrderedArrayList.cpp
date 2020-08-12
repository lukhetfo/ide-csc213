// UnOrderedArrayList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

const int MaxSize = 15;
typedef  double DataType;

struct List
{
	int Size;
	DataType Item[MaxSize];
};

void Init(List& L) { L.Size = 0; }

bool IsEmpty(List L) { return L.Size == 0; }

bool IsFull(List L) { return (L.Size == MaxSize); }

void Insert(DataType e, List& L)
{
	if (!(IsFull(L)))
	{
		L.Item[L.Size] = e;
		L.Size++;
	}
}

void Swap(DataType& x, DataType& y)
{
	DataType Temp;
	Temp = x;
	x = y;
	y = Temp;
}

void Delete(int e, List& L)
{
	int index = 0;
	if (!(IsEmpty(L)))
	{
		while ((index < L.Size) && (L.Item[index] != e))
			index++;
		if ((L.Item[index] == e) && (index <= L.Size - 1))
		{
			Swap(L.Item[index], L.Item[L.Size - 1]);

			L.Size--;
		}
	}
}

void ShowData(List L)
{
	for (int index = 0; index < L.Size; index++)
		std::cout << L.Item[index] << "   ";
	std::cout << std::endl;
}



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


