#include<iostream>
using namespace std;
class heap
{
private:
	int *top;
	int height;
	int size;
	int index;
	int value;
public:
	heap()
	{
		 cout<<"Enter Of Which Size You Want to create a heap::  ";
		 cin>>height;
		 size=pow(2,height);
		 top=new int[size];
		 index=1;
	}
	void insertheap()
	{
		cout<<"Please Enter The Value to Insert";
		cin>>value;
		top[index]=value;
		if(index<2)
		{
		index++;
		return;
		}
		else
		{int temp=index;
			while(temp!=1)
			{
			temp=temp/2;
		    if(top[temp]>top[index])
		    {
			int t;
			t=top[temp];
			top[temp]=top[index];
			top[index]=t;
		    }
			}
			index++;
			return;
		
		}
		
	}
	void deleteheap()
	{
		int temp=2;
		index--;
		top[1]=top[index];
		while(temp!=index)
		{
			if(top[1]>top[temp])
			{
				int t=top[1];
				top[1]=top[temp];
				top[temp]=t;
				temp=temp*2;
			}
		}

	}
	void print()
	{
		cout<<endl;
		for(int i=1;i<index;i++)
		{
			cout<<top[i]<<endl;
		}

	}
	void percolatedwon()
	{
	}
}h1;
int main()
{
	h1.insertheap();
	h1.insertheap();
	h1.insertheap();
	h1.insertheap();
	h1.insertheap();
	h1.insertheap();
	h1.insertheap();
	h1.print();
}