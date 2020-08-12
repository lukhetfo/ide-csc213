// UnOrderedArrayList_Encap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

const int MaxSize = 15;
typedef  double DataType;

struct List
{
	int Size;
	DataType Item[MaxSize];


void Init() { Size = 0; }

bool IsEmpty() { return Size == 0; }

bool IsFull( ) { return (Size == MaxSize); }

void Insert(DataType e)
{
	if (!(IsFull()))
	{
		Item[Size] = e;
		Size++;
	}
}

void Swap(DataType& x, DataType& y)
{
	DataType Temp;
	Temp = x;
	x = y;
	y = Temp;
}

void Delete(int e)
{
	int index = 0;
	if (!(IsEmpty()))
	{
		while ((index < Size) && (Item[index] != e))
			index++;
		if ((Item[index] == e) && (index <= Size - 1))
		{
			Swap(Item[index], Item[Size - 1]);

			Size--;
		}
	}
}

void ShowData()
{
	for (int index = 0; index < Size; index++)
		std::cout << Item[index] << "   ";
	std::cout << std::endl;
}

}; //end structure definition

int main()
{
	List L;
	L.Init();

	L.Insert(10); L.Insert(15); L.Insert(20);
	L.ShowData();
	L.Delete(15);
	L.ShowData();
	L.Insert(30); L.Insert(50);L.Delete(10);
	L.ShowData();

	system("pause");
}


