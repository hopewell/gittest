#include<iostream>
using namespace std;

class fraction
{
private:
	int above;//分子
	int below;//分母
	void reduction();//约分
	fraction makeCommond(fraction );//通分
public:
	fraction ();
	fraction(int x,int y);
	fraction add(fraction );
	fraction sub(fraction);
	fraction mul(fraction);
	fraction div(fraction);
	fraction reciprocal();//求倒数
	bool equal(fraction);
	bool greaterThan(fraction);
	bool lessThan(fraction);
	void display();
	void input();
};
fraction::fraction()
{
	above=0;
	below=1;
}
fraction::fraction(int x,int y)
{
	this->above=x;
	this->below=y;
}

void fraction::input()
{
  cout<<"please input the fraction of above and below:"<<endl;
  //int a,b;
  cin>>above>>below;
  if(below==0)
  {
	  cout<<"the below is error,please input the below again"<<endl;
  cin>>below;
  }
 //fraction(above,below);
}
void fraction::display()
{
	cout<<"the fraction: "<<above<<"/"<<below<<endl;
}

void fraction::reduction()
{
	int a,b,temp;
	//cout<<"before reduction!"<<endl;
	//display();
	//cout<<"the fraction: "<<above<<"/"<<below<<endl;
	if(above==0)
		cout<<"can't reduction"<<endl;
	a=above;
	b=below;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	above=above/a;
	below=below/a;
//	cout<<"after reduction!"<<endl;
	//display();
}

fraction fraction::makeCommond(fraction c)
{
	int temp;
	int a,b;
	a=below;
	b=c.below;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	temp=below*(c.below)/a;
	//this->below=c.below=temp;
	above=above*temp/below;
	//c.above=(c.above)*temp/(c.below);
	below=temp;
	return fraction(above,below);
}
fraction fraction::add(fraction c)
{
	fraction temp;
	temp=makeCommond(c);
	c=c.makeCommond(temp);
	temp.above=above+c.above;
	temp.below=below;
	temp.reduction();
	return temp;
}
fraction fraction::sub(fraction c)
{
	fraction temp;
	temp=makeCommond(c);
	c=c.makeCommond(temp);
	temp.above=above-c.above;
	temp.below=below;
	temp.reduction();
	return temp;
}

fraction fraction::mul(fraction c)
{
	fraction temp;
	temp.above=above*(c.above);
	temp.below=below*(c.below);
	temp.reduction();
	return  temp;
}
fraction fraction::div(fraction c)
{
	fraction temp;
	temp.above=above*(c.below);
	temp.below=below*(c.above);
	temp.reduction();
	return  temp;
}

fraction fraction::reciprocal()//求解倒数出现问题
{
	
	int temp;
	temp=above;
	above=below;
	below=temp;
	//cout<<"after reciprocal:";
//	display();
	return fraction(above,below);
}

bool fraction::equal(fraction c)
{
	fraction temp;
	temp=this->div(c);
	if(temp.above=temp.below)
		return true;
}
bool fraction::greaterThan(fraction c)
{
	fraction temp;
	temp=this->div(c);
	if(temp.above>temp.below)
		return true;
}
bool fraction::lessThan(fraction c)
{
	fraction temp;
	temp=this->div(c);
	if(temp.above<temp.below)
		return true;
}
int main()
{
	fraction m,n,q;
	bool tm=false;
	m.input();
	//n.input();
	//m.display();
	m=m.reciprocal();
   // cout<<"after reciprocal: "<<endl;
  //  m.display();
	//n.input();
	//q=m.sub(n);
	m.display();

	return 0;
}




