#include<iostream>
using namespace std;
struct node
{
	int value;
	node *next;
};
class queue
{
private:
	node *head;
	node *temp;
	node *front;
	node *rear;
public:
	queue()
	{
		front=NULL;
		rear=front;
	}
	void inqueue()
	{
		if(rear==NULL)
		{
			rear=new node;
			cin>>rear->value;
			rear->next=NULL;
			front=rear;
			return;
		}
		else
		{
			rear->next=new node;
			cin>>rear->next->value;
			rear=rear->next;
			rear->next=NULL;
			return;
		}
	}
	void dequeue()
	{
		if(front==NULL)
		{
			rear=NULL;
			return;
		}
		else
		{
			temp=front;
			front=front->next;
			delete temp;
		}
	}
	void print()
	{
		temp=front;cout<<endl;

		while(temp!=NULL)
		{
			cout<<temp->value;
			temp=temp->next;
		}
	}
};
int main()
{
	queue q1;
	q1.inqueue();
	q1.inqueue();
	q1.inqueue();
	q1.print();
	q1.dequeue();
	q1.dequeue();
	q1.print();
}