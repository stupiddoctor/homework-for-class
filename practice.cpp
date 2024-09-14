#include<iostream>
#include<cmath>
using namespace std;
/*int main()
{int x,y,sum;
x=5;
y=9;
int*p=&x;
cout<<&x<<'\n';
cout<<&*p<<'\n';
cout<<p<<'\n';
cout<<*p<<'\n';
x=29;
cout<<&x;
return 0;
}*/
//about the address
class base
{
	public:
		base(int a=0,int b=0,int c=0)
		{
			bx1=a;
			bx2=b;
			bx3=c;			
		}
		int bx1;
		friend base operator+(base a,base b);
		void sum(int a,int b)
		{
			bx1=bx1+a;
			bx2=bx2+b;
		}
	private:
		int bx2;
	protected:
		int bx3;
		
};//在base类中，bx1公有，bx2私有，bx3保护
class evol:public base
{
	public:
		evol(int a,int b,int c,int d)
		:base(a,b,c)
		{
			ex4=d;
		}
		void sum2(int a,int b)
		{
			sum(a,b);
		}
	
	private:
		int ex4;
		
};//evol公有继承
base operator+(base a,base b)
{
	base c;
	c.bx1=a.bx1+b.bx1;
	c.bx2=a.bx2+b.bx2;
	c.bx3=a.bx3+b.bx3;
	return c;
}
int main()
{
base B1(1,2,3);
evol E1(9,8,7,6);
B1=E1;
E1.sum2(5,3);
cout<<B1.bx1<<E1.bx1;
B1=B1+B1;
cout<<B1.bx1;
}