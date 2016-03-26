#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class bignum {

	string value;
	bool isPositive;

public:

	bignum(int n) 
	{
		if(n<0)
			isPositive = false;
		else
			isPositive = true;					//sign of the number
		value = "";
		n = abs(n);
		while(n!=0)
		{
			value = (char)((n%10)+'0') + value;
			n/=10;
		}
	}

	bignum(string s)
	{
		if(s[0]=='-')			//negative number
		{
			isPositive = false;
			for(int i=1;i<s.length();i++)
			{
				if(s[i]<'0' or s[i]>'9')
				{
					value = "";
					break;
				}
				value += s[i];
			}
		}
		else
		{
			isPositive = true;
			for(int i=0;i<s.length();i++)
			{
				if(s[i]<'0' or s[i]>'9')
				{
					value = "";
					break;
				}
				value += s[i];
			}
		}														//positive

		for(int i=0;i<value.length();i++);
			//delete the beginning zeroes;
	}


	bignum() 
	{
		value = "";
		isPositive = true;
	}

	~bignum() {
		value = "";				//for nothing 
	}

	bool operator==(const bignum b)				//comaparing 2 bignums
	{
		if(isPositive == b.isPositive and value == b.value)
			return true;
		else
			return false;
	}

	bool operator==(int b)			//comparing bignum and int
	{
		if(b>0 and isPositive==false)
			return false;
		else if(b<0 and isPositive==true)
			return false;

		b = abs(b);			//comapring negative numbers

		for(int i=value.length()-1;i>=0 and b!=0 ;i--,b/=10)
		{
			if(b%10 != int(value[i] - '0'))
				return false;
		}
		if(b==0)
			return true;
		return false;
	}

	void print()
	{
		if(value=="")
			return;
		if(!isPositive)
			cout<<"-";
		cout<<value<<endl;
	}
};

int main()
{
	bignum a("125"),b(125),c("-234");
	a.print();
	b.print();
	c.print();
	bool checks[] = {a==b,b==c,c==-234};
	//comapring bignums and numbers
	cout<<checks[0]<<checks[1]<<checks[2]<<endl;
}