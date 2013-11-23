#include<iostream>
#include<iomanip>
#define maxsize 20
using namespace std;
int num;
int array[maxsize];

void input()
{
	int i;
	cout<<"������Ҫ�������ֵ������"<<endl;
	cin>>num;
	cout<<"������Ҫ������������У�"<<endl;
	for(i=0;i<num;i++)
		cin>>array[i];
	cout<<"����ǰ���������£� "<<endl;
	for(i=0;i<num;i++)
		cout<<setw(4)<<array[i];
	   cout<<endl<<endl;
}
void output(int *array)
{
	int j;
	cout<<"�������������£�"<<endl;
	for(j=0;j<num;j++)
		cout<<setw(4)<<array[j];
	cout<<endl<<endl;
}

void bubblesort(int a[],int n)
{
	cout<<"��ð�����򷨣���С���󣩣�"<<endl;
	int i,j,temp;
	for(i=0;i<n;i++)
	  for(j=n-1;j>i;j--)
		if(a[j]<a[j-1])
		{
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
		}
}

int division(int a[],int left,int right)
{
	int base;
	base=a[left];
	while(left<right)
	{
	while(left<right&&a[right]>base)
		right--;
	a[left]=a[right];
	while(left<right&&a[left]<base)
		left++;
	a[right]=a[left];
	}
	a[left]=base;
	return left;
}
void quicksort(int a[],int left,int right)
{
	int i;
	if(left<right)
	{
	i=division(a,left,right);
	quicksort(a,left,i-1);
	quicksort(a,i+1,right);
	}
}

void insertsort(int a[],int n)
{
		cout<<"�ò������򷨣���С���󣩣�"<<endl;
	int i,j,k,temp;
	for(i=1;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
			if(a[i]>a[j])
				break;
		if(j!=i-1)
		{
			temp=a[i];
			for(k=i-1;k>j;k--)
				a[k+1]=a[k];
			a[k+1]=temp;
		}
	}
}
void choosesort(int a[],int num)
{
		cout<<"��ѡ�����򷨣���С���󣩣�"<<endl;
	int i,j,k,temp;
	for(i=0;i<num-1;i++)
	{
		k=i;
		for(j=i+1;j<num;j++)
	    if(a[k]>a[j])
			k=j;
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;	}
}
void shellsort(int a[],int n)
{
	int d,i,j,temp;
	d=n/2;
	while(d>=1)
	{
		for(i=d;i<n;i++)
		{
			temp=a[i];
			j=i-d;
			while(j>=0&&a[j]>temp)
			{
				a[j+d]=a[j];
				j=j-d;
			}
			a[j+d]=temp;
		}
		d=d/2;
	}
}

int main()
{
	int n=1,i;
	
	while(n)
	{
		input();
		cout<<"\t *********��ѡ�����е�����ʽ��********"<<endl;
		cout<<"\t 1��ð������"<<endl;
		cout<<"\t 2����������"<<endl;
		cout<<"\t 3��ֱ�Ӳ�������"<<endl;
		cout<<"\t 4��ѡ������"<<endl;
		cout<<"\t 5��ϣ������"<<endl;
		cout<<"\t 6���˳�"<<endl;
		cout<<"\t*****************************************"<<endl;
	 cin>>i;
	 switch(i)
	 {
	 case 1:bubblesort(array,num);break;
	 case 2:quicksort(array,0,num-1);break;//ע��д��ʱ��һ��Ҫע��left=0��right=num-1��
	 case 3:insertsort(array,num);break;
	 case 4:choosesort(array,num);break;
	 case 5:shellsort(array,num);break;
	 case 6:n=0;break;
	 }
	 output(array);
	}
	return 0;
}




