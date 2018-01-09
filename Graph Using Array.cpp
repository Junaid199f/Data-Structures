#include<iostream>
using namespace std;
struct vertices{
char info[20];
};
void joingraph(int ar[][3],int node1,int node2,int  wt)
{
	ar[node1][node2]=wt;
}
void removegraph(int ar[][3],int node1,int node2)
{
	ar[node1][node2]=1;
}
int main()
{
	vertices *data;
	int **adj;
	int vertix;
	cout<<"Please Enter The Number of Vertices";
	cin>>vertix;
	data=new vertices[vertix];
	cout<<"Vertix Created";
	adj=new int*[vertix];
	for(int i=0;i<vertix;i++)
	{
		adj[i]=new int[vertix];
	}
	cout<<"**Adjacency Matrix Created**"<<endl;
	cout<<"Enter Data For the Vertices";
	for(int i=0;i<vertix;i++)
	{
		cin>>data[i].info;
	}
	for(int i=0;i<vertix;i++)
	{
		for(int j=0;j<vertix;j++)
		{
			adj[i][j]=1;
		}
	}
	adj[1][2]=3;
	adj[2][0]=5;
	adj[2][1]=7;
	adj[1][0]=4;
	cout<<endl;
	for(int i=0;i<vertix;i++)
	{
		for(int j=0;j<vertix;j++)
		{
			if(adj[i][j]!=1)
			{
				cout<<adj[i][j]<<" ";
			}
			else 
				cout<<"1"<< " ";
		}
		cout<<endl;
	}
	
}