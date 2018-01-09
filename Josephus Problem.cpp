#include<iostream>
using namespace std;
struct node
{
	node *next;
	int value;
};
class random
{
private:
	node *head,*temp,*current,*del;
	int key,value,size;
public:
	random()
	{
		head=NULL;
		temp=head;
	}
	void insert()
	{
		if(head==NULL)
		{
			head=new node;
			cin>>head->value;
			head->next=head;
			size++;return;
		}
		temp=head;
		cout<<"Enter the value to put after the node";
		cin>>key;
		do
		{
			if(temp->value==key)
			{
				current=new node;
				cin>>current->value;
				current->next=temp->next;
				temp->next=current;
				size++;
				return;
			}
			temp=temp->next;
		}while(temp!=head);
	}
	void print()
	{temp=head;
	cout<<"The List is ";
		do
		{
			cout<<temp->value;
			temp=temp->next;
		}while(temp!=head);
	}
	void remove()
	{
for(int i=0;i<4;i++)
		{
if(head!=NULL)
{temp=head;value=3;
for(int i=0;i<value;i++)
{temp=temp->next;}
while(temp->next!=head)
{
	del=temp->next;
	temp->next=del->next;
	delete del;
	temp=temp->next;
}	
}
		
		}
}
		void pprint()
	{
		temp=head;
	cout<<"The List is ";
		do
		{
			cout<<temp->value;
			temp=temp->next;
		}while(temp!=head);
	}

};
int main()
{
	random rr;
	for(int i=0;i<5;i++)
	{
	rr.insert();
	}
	rr.remove();
	rr.pprint();
}