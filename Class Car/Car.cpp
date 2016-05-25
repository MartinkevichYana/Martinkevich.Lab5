#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Car.h"

using namespace std;

Car::Car(){}

Car::~Car(){}

void Car::SetKey(int k)
{
	key = k;
}

int Car::GetKey()
{
	return key;
}

void Car::SetModel(char* s)
{
	strcpy(model, s);
}

void Car::SetColor(char* s)
{
	strcpy(color, s);
}

void Car::SetSirealNumber(char* s)
{
	strcpy(mk, s);
}

void Car::SetRelease(int s)
{
	yrel = s;
}

void Car::SetInspection(char* s)
{
	strcpy(yinsp, s);
}

void Car::SetValue(char* s)
{
	strcpy(val, s);
}

char* Car::GetModel()
{
	return model;
}

char* Car::GetColor()
{
	return color;
}

char* Car::GetSirealNumber()
{
	return mk;
}

int Car::GetRelease()
{
	return yrel;
}

char* Car::GetInspection()
{
	return yinsp;
}

char* Car::GetValue()
{
	return val;
}


void Car::SetCar(char* s1, char* s2, char* s3, int s4, char* s5, char* s6)
{
	SetModel(s1);
	SetColor(s2);
	SetSirealNumber(s3);
	SetRelease(s4);
	SetInspection(s5);
	SetValue(s6);
}

void Car::DisplayCar()
{
	cout << endl << model << ", " << color << " color, sireal number " << mk << endl <<
		"The year of release " << yrel << ", of inspection " << yinsp << ". The value " << val << "$." << endl;
	//cout.precision(3);
}

void Car::DisplayKey()
{
	cout << key;
}