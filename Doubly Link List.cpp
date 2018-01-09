#include<iostream>
using namespace std;
struct node
{
	node *previous;
	node *next;
	int value;
};
class dlinkedlist
{
private:
	int size;
	node *current;
	node *head;
	node *temp;
	int count;
	int key;
public:
	dlinkedlist()
	{
		head=NULL;
		count=0;
		size=0;
		key=0;
	}
	void insert()
	{temp=head;current=NULL;
		if(head==NULL)
		{
			head=new node;
			cout<<"Enter The First Node";
			cin>>head->value;
			head->previous=NULL;
			head->next=NULL;
			size++;return;
		}
		else if(head->next==NULL)
		{
			current=new node;
			cout<<"Enter The "<< size<<" node ";
			cin>>current->value;
			current->next=head;
			current->previous=NULL;
			head=current;
			current=NULL;
			size++;return;
		}
		cout<<"ENTER THE VALUE AFTER WHICH YOU WANT TO ADD NODE";
		cin>>key;
		temp=head;
		while(temp!=NULL)
		{
			if(temp->value==key)
			{
				if(temp->next!=NULL)
				{
				current=new node;
				cout<<"Enter Value";
				cin>>current->value;
				current->next=temp->next;
				temp->next->previous=current;
				temp->next=current;
				current->previous=temp;size++;
				return;
			    }
			 	else if(temp->next==NULL)
				{
					current=NULL;
	          	current=new node;
				cout<<"Enter Value";
				cin>>current->value;
				temp->next=current;
				current->previous=temp;
				current->next=NULL;size++;
				return;
			   }
			}
			temp=temp->next;
	        }

	}
	void deletion()
	{
		temp=head;
		cout<<"Enter The Value Of Node you have to delete";
		cin>>key;
		if(head->value==key && size==1)
		{
			node *del;
			del=head;
			head=NULL;
			delete del;size--;
			return;
		}
		else if(head->value==key && size>1)
		{
			node *del;
			del=head;
			head=head->next;
			head->previous=NULL;
			delete del;size--;
			return;
		}
		while(temp!=NULL)
		{
			if(temp->next->value==key)
			{
				if(temp->next->next!=NULL)
				{ node *del;del=temp->next;
					temp->next=temp->next->next;
					temp->next->previous=temp;
					delete del;size--;
					return;
				
				}
				else if(temp->next->next==NULL)
				{ node *del;del=temp->next;
				temp->next=NULL;
				delete del;size--;
					return;
				}
			}
			temp=temp->next;
		}
	}
	void print()
	{
	temp=head;
		while(temp!=NULL)
		{
			cout<<temp->value<<endl;
			temp=temp->next;
		}
	}
	void emptiness()
	{
		if(head==NULL)
		{
			cout<<"The List is Empty";
		}
		else
			cout<<"The List is not empty";
	}
	void search()
	{temp=head;

		cout<<"Enter The element to search in the nodes";
		cin>>key;
		while(temp!=NULL)
		{
			if(temp->value==key)
			{
				cout<<"Value Found";
				return;
			}
			temp=temp->next;
		}
		cout<<"Value not found";
	}
};
int main()
{	dlinkedlist d1;
char opt;char ch;
	do
	{system("CLS");
		cout<<"WELCOME TO LINKED LIST MENU BAR"<<endl;
		cout<<"Select Any of the Option you Need ::"<<endl;
		cout<<"1 for Insertion "<<endl;
		cout<<"2 for Deletion "<<endl;
		cout<<"3 for Printing "<<endl;
		cout<<"4 for Checking ther list is empty or not "<<endl;
		cout<<"5 for Searching "<<endl;
		cout<<"6 for exit "<<endl;
		cin>>opt;
		switch(opt)
		{
			case '1':
		{d1.insert();break;
		}
		case '2':
			{d1.deletion();break;
		}
			case '3':
			{d1.print();break;
		}
			case '4':
				{d1.emptiness();break;
		}
		   case '5':
			   {d1.search();break;
		}
		   case '6':
			   {break;break;
			   }
		   default:
			   {
				   cout<<"Error";break;
			   }
		}
		cout<<endl<<"Enter 1 for going back to menu else press any key to exit";
		cin>>ch;
	}while(ch=='1');
	
}