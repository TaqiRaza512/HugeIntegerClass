#include "HugeInteger.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
HugeInteger::HugeInteger()
{
	this->size = 0;
	this->IsNeg = false;
	this->Ds = nullptr;
}
HugeInteger::HugeInteger(int num)
{
	int count = 0;
	if (num != 0)
	{
		size = 1;
		Ds = new int[size];
		int j = 0;
		Ds[j] = num;
	}
	else if (num == 0)
	{
		this->size = 1;
		Ds = new int(num);
		this->Ds[0]=num;
	}
	if (num>=0)
	{
		IsNeg = false;
	}
	else
	{
		IsNeg = true;
	}
}
HugeInteger::HugeInteger(const HugeInteger& H)
{
	this->size = H.size;
	this->IsNeg = H.IsNeg;
	this->Ds = new int[size];
	for (int i = 0; i < H.size; i++)
	{
		this->Ds[i] = H.Ds[i];
	}
}
HugeInteger::HugeInteger(ifstream& Rdr)
{
	SetInteger(Rdr);
}
const HugeInteger& HugeInteger::operator=(const HugeInteger& H)
{
	if (this == &H)
	{
		return *this;      
	}               
	SetInteger(H);
	return H;	
}
void HugeInteger::SetInteger(ifstream& Rdr)
{
	string aline;
	char sign;
	Rdr >> sign;
	if (sign == '+')
	{
		IsNeg = false;
	}
	else
	{
		IsNeg = true;
	}
	Rdr >> aline;
	this->size = aline.size();
	this->Ds = new int[this->size];
	for (int i = 0; i <size; i++)
	{
		this->Ds[i] = aline[size - 1 - i] - '0';
	}
}
void HugeInteger::SetInteger(const HugeInteger& H)
{
	this->size = H.size;
	this->IsNeg = H.IsNeg;
	this->Ds = new int[size];
	for (int i = 0; i < H.size; i++)
	{
		this->Ds[i] = H.Ds[i];
	}
}
ifstream& operator>>(ifstream& Rdr, HugeInteger& H)
{
	H.SetInteger(Rdr);
	return Rdr;
}
istream& operator>>(istream& cin, HugeInteger& H)
{

	string aline;
	char sign;
	cin >> sign;
	if (sign == '+')
	{
		H.IsNeg = false;
	}
	else
	{
		H.IsNeg = true;
	}
	cin>> aline;
	H.size = aline.size();
	H.Ds = new int[H.size];
	for (int i = 0; i < H.size; i++)
	{
		H.Ds[i] = aline[H.size - 1 - i] - '0';
	}
	return cin;
}
ostream& operator<<(ostream& Out, const HugeInteger& H)
{
	cout << (H.IsNeg ? '-' : '+');
	for (int i= 0;i<H.size;i++)
	{
		cout << H.Ds[H.size-1-i];
	}
	return Out;
}
HugeInteger HugeInteger ::AddQuantityWise(const HugeInteger& H2)const
{
	HugeInteger HI; 
	int carry=0;
	HI.Ds = new int[this->size + 1];
	HI.size = this->size + 1;
	for (int i=0;i<HI.size;i++)
	{
		HI[i] = ((*this)[i] + H2[i]+carry)%10;
		carry= ((*this)[i] + H2[i]+carry)/10;
	}

    HI.Trim();
	return HI;
}
HugeInteger HugeInteger::SubQuantityWise(const HugeInteger& H2)const
{
	HugeInteger R;
	R.size = this->size;
	R.Ds = new int[R.size];
	int carry=0;
	for (int ri=0;ri<R.size;ri++)
	{
		if ((*this)[ri]-H2[ri]-carry<0)
		{
			R[ri] = (*this)[ri] - H2[ri] - carry+10;
			carry = 1;
		}
		else
		{
			R[ri] = (*this)[ri] - H2[ri] - carry;
			carry = 0;
		}
	}
	R.Trim();
	return R;
}
bool HugeInteger::EqualQuantityWise(const HugeInteger& H)const
{
	return!this->GrtThanQuantityWise(H) && !this->LessThanQuantityWise(H);
}
bool HugeInteger::LessThanQuantityWise(const HugeInteger& H2)const
{
	if (this->size>H2.size)
	{
		return false;
	}
	else if (this->size < H2.size)
	{
		return true;
	}
	else 
	{
		for (int ri = this->size-1; ri >=0;ri--)
		{
			if ((*this)[ri]<H2[ri])
			{
				return true;
			}
			else if((*this)[ri] > H2[ri])
			{
				return false;
			}
		}
	}
	return false;
}
bool HugeInteger::GrtThanQuantityWise(const HugeInteger& H)const
{
	return(H.LessThanQuantityWise(*this));
}
HugeInteger HugeInteger ::operator+(const HugeInteger& H2)
{
	HugeInteger Res;
	this->Trim();
	if (this->IsNeg==H2.IsNeg)
	{
		if ((*this).GrtThanQuantityWise(H2))
		{

			Res = (*this).AddQuantityWise(H2);
		}
		else
		{
			Res = (H2).AddQuantityWise(*this);
		}
		Res.IsNeg = (*this).IsNeg;
	}
	else
	{
		if ((*this).GrtThanQuantityWise(H2))
		{

			Res = (*this).SubQuantityWise(H2);
			Res.IsNeg = (*this).IsNeg;
		}
		else
		{
			Res = (H2).SubQuantityWise(*this);
			Res.IsNeg = H2.IsNeg;
		}
	}
	return Res;

}
HugeInteger HugeInteger ::operator-()
{
	(*this).IsNeg = !(*this).IsNeg;
	return *this;
}
HugeInteger HugeInteger ::operator-(const HugeInteger& H2)const
{
	HugeInteger R = H2;
	R = -R;
	HugeInteger C = *this;
	C = C + R;
	return C;
}
const HugeInteger& HugeInteger::operator+=(const HugeInteger& H)
{
	*this = *this + H;
	return *this;
}
const HugeInteger& HugeInteger::operator*=(HugeInteger& H)
{
	*this = *this * H;
	return *this;

}
const HugeInteger& HugeInteger::operator%=(const HugeInteger& H)
{
	*this = *this % H;
	return *this;

}
const HugeInteger& HugeInteger::operator/=(const HugeInteger& H)
{
	*this = *this / H;
	return *this;

}
const HugeInteger& HugeInteger::operator-=(const HugeInteger& H)
{
	HugeInteger R;
	R = *this - H;
	return R;
}
bool HugeInteger::operator<=(const HugeInteger& H)
{
	if ((*this)== H)
		return true;
	if(this->IsNeg && H.IsNeg)
		return((H).LessThanQuantityWise(*this));
	if (!this->IsNeg && !H.IsNeg)
		return((*this).LessThanQuantityWise(H));
	if (!this->IsNeg && H.IsNeg)
		return false;
	if (this->IsNeg && !H.IsNeg)
		return true;

}
bool HugeInteger::operator<(const HugeInteger& H)const
{
	
	if (this->IsNeg && H.IsNeg)
		return((H).LessThanQuantityWise(*this));
	if (!this->IsNeg && !H.IsNeg)
		return((*this).LessThanQuantityWise(H));
	if (!this->IsNeg && H.IsNeg)
		return false;
	if (this->IsNeg && !H.IsNeg)
		return true;

}
bool HugeInteger::operator>=(const HugeInteger& H)
{
	if ((*this) == H)
		return true;
	
	if (this->IsNeg && H.IsNeg)
		return((*this).LessThanQuantityWise(H));
	if (!this->IsNeg && !H.IsNeg)
		return((H).LessThanQuantityWise(*this));
	if (!this->IsNeg && H.IsNeg)
		return true;
	if (this->IsNeg && !H.IsNeg)
		return false;

}
bool HugeInteger::operator>(const HugeInteger& H)const
{
	//-2 4
	if (this->IsNeg && H.IsNeg)
		return((*this).LessThanQuantityWise(H));
	if (!this->IsNeg && !H.IsNeg)
		return((H).LessThanQuantityWise(*this));
	if (!this->IsNeg && H.IsNeg)
		return true;
	if (this->IsNeg && !H.IsNeg)
		return false;

}
bool HugeInteger::operator==(const HugeInteger& H)
{
	if (this->IsNeg==H.IsNeg && this->size==H.size)
	{
		if (this->EqualQuantityWise(H))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}

const HugeInteger HugeInteger::operator++(int d)
{
	HugeInteger R(1),B=*this;
	*this = R + *this;
	this->Trim();
	return B;
}
const HugeInteger& HugeInteger ::operator++()
{
	HugeInteger R(1);
	*this = R + *this;
	this->Trim();
	return *this;
}
const HugeInteger HugeInteger::operator--(int d)
{
	HugeInteger R(1), B = *this;
	*this = R - *this;
	this->Trim();
	return B;
}
const HugeInteger& HugeInteger ::operator--()
{
	HugeInteger R(1);
	*this = R - *this;
	this->Trim();
	return *this;
}

const HugeInteger HugeInteger::SimpleMult(const HugeInteger& H)const
{
	HugeInteger R;

	HugeInteger A, B = H;
	if (*this<(H))
	{
		B = H;
		A = *this;
	}
	else
	{
		B = *this;
		A = H;
	}
	for (HugeInteger I(1);I<=B;++I)
	{
		R = R + (A);

	}
	if (this->IsNeg && H.IsNeg)
	{
		R.IsNeg = false;
	}
	else if (!this->IsNeg && !H.IsNeg)
	{
		R.IsNeg = false;
	}
	else
	{
		R.IsNeg = true;
	}
	return R;
	R.Trim();
}
const HugeInteger HugeInteger::operator*(HugeInteger& H)
{
	HugeInteger Zero(0);
	if (*this==Zero or H==Zero)
	{
		return Zero;
	}
	HugeInteger THIS=*this;
	HugeInteger h=H;

	HugeInteger R=*this;
	R.IsNeg = false;

	HugeInteger C(1);
	HugeInteger T(0);


	if (R==Zero or h==Zero)
	{
		return Zero;
	}
	
	do
	{
		while ((C+C<= h))
		{

			R+= R;
			C += C;

		}
		h = h - C;
		T += R;
		R = *this;
		R.IsNeg = false;
		C = 1;	
	} while (h-1>Zero);


	if (this->IsNeg ==H.IsNeg)
	{
		T.IsNeg = false;
	}		
	else 
	{
		T.IsNeg = true;
	}
	return T;
}

const HugeInteger HugeInteger::operator%(const HugeInteger& H)const
{
	HugeInteger Dividend = *this;
	HugeInteger Divisor= H;
	if (Dividend<(H))
	{
		return Dividend;
	}
	while (Dividend>=Divisor)
	{
		Dividend =Dividend-Divisor;
	}
	return Dividend;

}

const HugeInteger HugeInteger::operator/(const HugeInteger& H)const
{
	HugeInteger THIS = *this;
	HugeInteger h = H;


	HugeInteger count(1);
	HugeInteger temp(0);
	HugeInteger C(0);

	THIS.IsNeg = false;
	h.IsNeg = false;
	HugeInteger R = h;
	HugeInteger singleAdd = h;

	do
	{
		while ((R + R <= THIS))
		{
			R = R + R;
			count = count + count;
		}
		C = count+C;
		THIS = THIS-R ;
		R = h;
		count = 1;

	}while ((THIS>temp));

	count = C-1;
	if (count.IsNeg)
	{
		count.IsNeg = false;
	}
	R.Trim();
	if (this->IsNeg && H.IsNeg)
	{
		count.IsNeg = false;
	}
	else if (!this->IsNeg && !H.IsNeg)
	{
		count.IsNeg = false;
	}
	else
	{
		count.IsNeg = true;
	}
	return count;
}

int& HugeInteger::operator[](int i)
{
	return this->Ds[i];
}
void HugeInteger::Trim()
{
	for (int ri=size-1;ri>=1;ri--)
	{
		if ((*this)[size-1]==0)
		{
			int* ptr = new int[size - 1];
			for (int c=0;c<size-1;c++)
			{
				ptr[c] = Ds[c];
			}
			delete []Ds;
			Ds = ptr;
			this->size--;		
		}
	}
	
}
const int  HugeInteger::operator[](int i)const
{
	if (i >= this->size)
	{
		return 0;
	}
	else
	{
		return this->Ds[i];
	}
}
HugeInteger::~HugeInteger()
{
	//delete[] Ds;
}
