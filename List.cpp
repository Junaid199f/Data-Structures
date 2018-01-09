#include<iostream>
using namespace std;
class List
{
private:
	int *p;
	int current;
	int length;
	int size;
	int te;
public:
List()
	{
		current=0;
		te=0;
	}
bool empty()
{
	if(current==0)
		return true;
	else 
		return false;
}
bool full()
{
	if(current==length)
return true;
	else
		return false;
}
void next()
{  cout<<*p;
	if(p<&p[current-1])
	{
		p++;
	}
	else
		cout<<"You are out of bound";
	te++;
	cout<<*p;
}
void back()
{  //cout<<*p;
	if(p>=&p[0])
	{
		p--;
	}
	else
		cout<<"You are out of bound";
	te--;
	cout<<*p;
}
void start()
{if(p==&p[current])
	{
		p[0];
	}
	else
	{
	for(int i=te;i>=0;i++)
	{
		p--;
	}
}
	cout<<" start"<<*p;
}
void tail()
{
	
		for(int i=te;i<current;i++)
		{
			p++;
		}
		cout<<"tail"<<*p;
}
int getlength()
	{
		return length;
	}
void createlist()
{
	cout<<"Enter No of Items of List";
	cin>>length;
	p=new int[length];
}
void clear()
{
	delete []p;
	cout<<"List Deleated";
	cout<<endl;
}
int get(int place)
{
	return *(p+place);
}
void update(int index,int x)
{
	if(index<length)
	{
	*(p+index)=x;
	current++;size++;
	}
	else
		cout<<"Wrong index";
}
void copy(int *a)
{
	for(int i=0;i<current;i++)
	{
		*(a+i)=*(p+i);
	}
}
int find(int X)
{
	int j;
	for(j=0;j<current+1;j++)
	{ if( *(p+j) == X ) 
	break;
}
	if( j < current+1 ) 
     return 1;
	else
	return 0;
	}
void show()
{
	
	for(int i=0;i<current;i++)
	{
		cout<<get(i);
		cout<<endl;
	}
}
void add(int x,int val)
{
	if(current==length)
	{
		cout<<"All The Elements ARe Filled Sorry!"<<endl;
	
	}
	else
	{
	int *q;
	int *r,*temp;
	q=p;r=p;
	for(int i=0;i<x-1;i++)
	{
		q++;
	}
	for(int i=0;i<current-1;i++)
	{
r++;
	}
	temp=r;
	temp++;
	while(1)
	{   if(x==length)
	{*temp=*r;
		break;
	}
		if(*r==*q)
		{
			break;
		}
		else
		{
			*temp=*r;
			temp--,r--;
		}
	}*(r+1)=val;current++;}
}
void remove(int pla)
{
int *q;
	int *r,*temp;
	q=p;r=p;
	for(int i=0;i<pla-1;i++)
	{
		q++;
	}
	for(int i=0;i<current-1;i++)
	{
		r++;
	}
	temp=q;
	temp++;

		while(1){if(*r==*temp){
		*q=*temp;
		q++;temp++;break;}
		else if(*r!=*temp)
		{*q=*temp;
		q++;temp++;
		}}		
	current=current-1;
}
	};
int main()
{List l;int in,val;char sel;int v,c;
	cout<<"Welcome"<<endl;
	cout<<"Creating list   : note index starts form 0 not 1:"<<endl;
	l.createlist();
	cout<<"List Created"<<endl<<"Taking Values";
	do
	{cout<<"Enter index";
	cin>>in;
	cout<<endl<<"Enter Value";
	cin>>val;
		l.update(in,val);
		cout<<endl<<"Enter y to update more n to not";
		cin>>sel;
	}while(sel=='y' || sel=='Y');
	l.show();cout<<endl;
	cout<<endl<<"Enter The index where to put the value";
	cin>>v;
	cout<<endl<<"Enter The Value";
	cin>>c;
	l.add(v,c);
	l.show();
		cout<<endl<<"Enter The index where to remove the value";
	cin>>v;

	l.remove(v);
	l.show();
		l.next();
		l.back();
		l.start();
		l.tail();
	system("pause");
}