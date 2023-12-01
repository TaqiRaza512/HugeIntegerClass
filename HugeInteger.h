#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class HugeInteger
{
	int* Ds;
	int size;
	bool IsNeg;

public:

	HugeInteger();
	HugeInteger(int num);
	HugeInteger(ifstream& Rdr);
	HugeInteger(const HugeInteger& H);
	const HugeInteger& operator=(const HugeInteger&);
	void SetInteger(ifstream& Rdr);
	void SetInteger(const HugeInteger&);	
	friend ifstream& operator>>(ifstream& Rdr, HugeInteger& H);
	friend istream& operator>>(istream& Rdr, HugeInteger& H);
	friend ostream& operator<<(ostream& Out,const HugeInteger& H);
	HugeInteger AddQuantityWise(const HugeInteger& H)const;
	HugeInteger SubQuantityWise(const HugeInteger& H)const;
	bool LessThanQuantityWise(const HugeInteger& H)const;
	bool GrtThanQuantityWise(const HugeInteger& H)const;
	bool EqualQuantityWise(const HugeInteger& H)const;
	const HugeInteger SimpleMult(const HugeInteger& H)const;
	void Trim();

	HugeInteger operator+(const HugeInteger& H);
	const HugeInteger operator++(int d);
	const HugeInteger& operator++();
	const HugeInteger operator--(int d);
	const HugeInteger& operator--();
	const HugeInteger& operator+=(const HugeInteger& H);
	const HugeInteger& operator-=(const HugeInteger& H);
	const HugeInteger& operator/=(const HugeInteger& H);
	const HugeInteger& operator%=(const HugeInteger& H);
	const HugeInteger& operator*=(HugeInteger& H);
	bool operator>=(const HugeInteger& H);
	bool operator>(const HugeInteger& H)const;
	bool operator<=(const HugeInteger& H);
	bool operator<(const HugeInteger& H)const;
	bool operator==(const HugeInteger& H);
	HugeInteger operator-(const HugeInteger& H)const;
	HugeInteger operator-();	
	const HugeInteger operator*(HugeInteger& H);
	const HugeInteger operator%(const HugeInteger& H)const;
	const HugeInteger operator/(const HugeInteger& H)const;
	int& operator[](int i);
	const int operator[](int i)const;
	~HugeInteger();

};

