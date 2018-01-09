#include<iostream>
using namespace std;
struct node
{
int value;
node *next;
};
class List
{
private:
	node *head;
	node *current;
	int size;
	int key;
public:
	List()
	{  size=0;
	head=NULL;
	key=0;
	}
	void insertion()
	{
		node *temp;
		node *temp1;
		if(head==NULL)
		{
		head=new node;
		cout<<"Enter The Value Of Node "<<"=";
		cin>>head->value;
		head->next=NULL;
		size++;return;
		}
		else if(size==1)
		{
			current=new node;
					cout<<endl<<"Enter The Value Of Node#"<<"=";
			cin>>current->value;
			current->next=head;
			head=current;
			head->next->next=NULL;
			size++;return;
		}
		else
		{
			cout<<endl<<"Enter After Which Node You Have To Add a New Node = ";
			cin>>key;
			temp=head;
			while(temp!=NULL)
			{
				if(temp->value==key)
				{
					temp1=new node;
					cout<<endl<<"Enter The Value Of Node#"<<size+1<<"=";
					cin>>temp1->value;
					temp1->next=temp->next;
					temp->next=temp1;size++;
					return;
				}
				else
				{
					temp=temp->next;
				}

			}
		}
		cout<<"Sorry You Have Entered Wrong Value";
	}
	void print()
	{  node *temp;temp=head;int counter=1;
		while(temp!=NULL)
		{
			cout<<endl<<"Node #"<<counter<<" = "<<temp->value;
			temp=temp->next;
			counter++;
		}
	}
	void deletion()
	{
		node *temp;temp=head;int a=0;node *temp1;
		cout<<endl<<"Enter After Which Node You Have To  Delete a New Node = ";
		cin>>key;
		
			while(temp!=NULL)
			{
		if(size==1 && head->value==key)
			{
			node *del;
			del=head;
			head=NULL;
			delete del;
			return;
		    }
			else if(size>1 && head->value==key)
			{
				node *del;
				temp=temp->next;
				del=head;
				head=temp;
				delete del;
				return;

			}	
			if(temp->next->value==key)
			{
				if(temp->next->next!=NULL)
				{node * del;del=temp->next;
				temp->next=temp->next->next;
					cout<<"temp1->next==temp1";size--;
					delete del;
					return;
				}
				
				else if(temp->next->next==NULL)
				{
				node *del;del=temp->next;	
				temp->next=NULL;
					cout<<"temp1->next==temp->next";size--;
					delete del;
					return;
				}
			
			}
			temp=temp->next;
}
		
	}
	void emptiness()
	{
		if(head==NULL)
			cout<<"The List is empty"<<endl;
		else
			cout<<"The List is not empty"<<endl;
	}
	void searching()
	{
		cout<<endl<<"Enter The Value to Find In Nodes"<<" = ";
		cin>>key;
		node *temp;temp=head;
		while(temp!=NULL)
		{
			if(temp->value==key)
			{
				cout<<"Value Found";
				return;
			}
	      temp=temp->next;
		}
		if(temp==NULL)
		{
			cout<<"Value Not Found";
		}
	}
};
int main()
{
	List linked_list;char opt;char ch;
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
		{linked_list.insertion();break;
		}
		case '2':
			{linked_list.deletion();break;
		}
			case '3':
			{linked_list.print();break;
		}
			case '4':
				{linked_list.emptiness();break;
		}
		   case '5':
			   {linked_list.searching();break;
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