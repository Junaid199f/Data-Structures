#include<iostream>
using namespace std;
struct vertex;
struct edge
{
	int value;
	int weight;
	vertex *point;
	edge *next;
	bool check;
};
struct vertex
{
	int info;
	vertex *below;
	edge *next;
};

class vertexdata
{
private:
	
	vertex *current;
	int size;
public:
	vertex *head;
	vertexdata()
	{
		head=NULL;
		size=0;
	}
	void insertions()
	{
		if(head==NULL)
		{
			head=new vertex;
			head->next=NULL;
			head->below=NULL;
			cin>>head->info;
		}
		else
		{
			current=head;
			while(current->below!=NULL)
			{
				current=current->below;
			}
			current->below=new vertex;
			cin>>current->below->info;
			current->below->below=NULL;
			current->below->next=NULL;
		}
	}
	void print(vertex *temp)
	{
		while(temp!=NULL)
		{
			cout<<temp->info;
			temp=temp->below;
		}
	}
	void edgesinsertion(vertex *temp,int key)
	{
		while(temp!=NULL)
		{
			if(temp->info==key)
			{
				edge *ee=temp->next;
				if(temp->next==NULL)
				{
					temp->next=new edge;
				cout<<"enter the weight of edge";
				cin>>temp->next->weight;
				cout<<"Enter The Vertex Value to which it will point";
				cin>>temp->next->value;
				temp->next->next=NULL;
				return;
				}
				else
				{
				while(ee->next!=NULL)
				{
					ee=ee->next;
				}
				ee->next=new edge;
				cout<<"enter the weight of edge";
				cin>>ee->next->weight;
				cout<<"Enter The Vertex Value to which it will point";
				cin>>ee->next->value;
				ee->next->next=NULL;
				return;
			}
			}
			else
			{
				temp=temp->below;
			}
		}
	}
};
int main()
{
	vertexdata v1;
	v1.insertions();
	v1.insertions();
	v1.insertions();
	v1.insertions();
	v1.insertions();
	v1.insertions();
	v1.print(v1.head);
	v1.edgesinsertion(v1.head,1);
	v1.edgesinsertion(v1.head,1);
	v1.edgesinsertion(v1.head,2);

}