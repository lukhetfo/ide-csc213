#pragma once
#include <iostream>

const int MaxSize = 15;
typedef  int DataType;

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
		std::cout << L.Item[index] << "\t";
	std::cout << std::endl;
}

