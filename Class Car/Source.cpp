#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <fstream>
#include <cstring>
#include "Car.h"

using namespace std;

Car InitCar();
Car InitKey();
Car* InitArray(int);
void DisplayArray(Car*, int);
void EnterArray(int*, int);
void SortRelease(Car*, int);
void Swap(Car&, Car&);
int BinarySearch(Car*, int, Car);

int main()
{
	int n;
	cout << "\nEnter the number of cars:";
	cin >> n;
	system("cls");
	Car* Cars = InitArray(n);
	if (!Cars)
	{
		cout << "\nDynamic array doesn't exist!\n";
		system("pause");
		return 0;
	}
	cout << "\nThe list of Cars:\n";
	DisplayArray(Cars, n);
	cout << endl;
	cout << "\nSorted list of Cars:\n";
	SortRelease(Cars, n);
	DisplayArray(Cars, n);
	Car key = InitKey();
	cout << endl;
	int b = BinarySearch(Cars, n, key) + 1;
	if (BinarySearch(Cars, n, key) + 1 == 0)
	{
		cout << "The same year of release of the car not found!!!" << endl;
		system("pause");
		return 0;
	}
	else
	{
		cout << "The year of release what you want of the " << BinarySearch(Cars, n, key) + 1 << " car in your list!";
		cout << endl;
	}
	delete[] Cars;
	system("pause");
	return 0;
}


Car InitKey()
{
	int key;
	cout << "Enter the year release of the car you want to see:";
	cin.ignore();
	cin >> key;
	Car Key;
	Key.SetKey(key);
	return Key;
}

Car InitCar()
{
	char model[N] = "", color[N] = "", mk[N] = "", yinsp[N] = "", val[N] = "";
	int yrel;
	cout << "\nEnter the model:";
	cin.ignore();
	cin.get(model, N, '\n');
	cout << "Enter the color:";
	cin.ignore();
	cin.get(color, N, '\n');
	cout << "Enter the serial number:";
	cin.ignore();
	cin.get(mk, N, '\n');
	cout << "Enter the year of release:";
	cin.ignore();
	cin >> yrel;
	cout << "Enter the year of inspection:";
	cin.ignore();
	cin.get(yinsp, N, '\n');
	cout << "Enter the value in $:";
	cin.ignore();
	cin.get(val, N, '\n');
	Car car;
	car.SetCar(model, color, mk, yrel, yinsp, val);
	return car;
}

Car* InitArray(int n)
{
	Car* array = new Car[n];
	if (!array)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the information about " << (i + 1) << " car\n";
		array[i] = InitCar();
	}
	return array;
}

void EnterArray(int* array, int n)
{
	for (int i = 0; i < M; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}


void DisplayArray(Car* array, int n)
{
	for (int i = 0; i < n; i++)
		array[i].DisplayCar();
	cout << endl;
}

void SortRelease(Car* array, int n)
{
	for (int i = 0; i <= n; i++)
	for (int j = n - 1; j > i; j--)
	if (array[j-1].GetRelease()>array[j].GetRelease())
		Swap(array[j], array[j - 1]);
}

void Swap(Car &a, Car &b)
{
	Car help = a;
	a = b;
	b = help;
}

int BinarySearch(Car* array, int n, Car key)
{
	int first = 0;
	int last = n - 1;
	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (array[mid].GetRelease() == key.GetKey()) return mid;
		if (array[mid].GetRelease() < key.GetKey()) first = mid + 1;
		if (array[mid].GetRelease() > key.GetKey()) last = mid - 1;
	}
	return -1;
}
