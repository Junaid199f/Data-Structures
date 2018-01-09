#include<iostream>
using namespace std;
class queue
{
private:
	int *head;
	int *front;
	int *rear;
	int *temp;
	int noofelements;
public:
	queue()
	{
		head=new int[6];
		front=rear=head;
		noofelements=0;
	}
	void enqueue()
	{
		if(rear==head && noofelements==0)
		{
			cin>>*rear;
			noofelements++;
			return;
		}
		else if(rear==(head+5) && noofelements<=6)
		{
			rear=(head+0);
			cin>>*rear;
			noofelements++;
		}
		else if(rear!=(head+5) && noofelements<6)
		{
			rear++;
			cout<<"enter value"<<endl;
			cin>>*rear;
			noofelements++;
			return;
		}
		else if(noofelements>=6)
		{
			cout<<"Please Delete a Queue Element and then enqueue";
			return;
		}
	
		
	}
	void dequeue()
	{
		if(front==head && noofelements==0)
		{
			rear=head;
			return;
		}
		else if(front==(head+5))
		{
			front=(head+0);
			noofelements--;
		}
		else
		{
			front++;
			--noofelements;
		}
	}
	void print()
	{
		temp=front;
		if(noofelements==0)
		{
			cout<<"Nothing to show";
		}
		else if(front==rear)
		{
			cout<<*rear;
		}
		else if(noofelements<=6)
		{
		do
		{
			cout<<*temp;
			if(temp==(head+5))
			{
				temp=(head+0);
			}
			else
			{
			temp++;
			}
		}while(temp!=rear);
		cout<<*rear;
		}
	}

};
int main()
{
	queue q1;int opt;char sec;
	cout<<"Welcome";
	cout<<endl<<"Enter 1 For ENQueue ,2 for DeQueue , 3 for Print"<<endl;
	do{
		cin>>opt;
		switch(opt)
			{
		case 1:
		    {q1.enqueue();break;}
		case 2:
			{q1.dequeue();break;}
		case 3:
			{q1.print();break;}
		default:
		   { cout<<"Error";break;}
		}
		cout<<"Enter Y to Retry N to exit";
		cin>>sec;
	}while(sec=='y' || sec=='Y');
	
}