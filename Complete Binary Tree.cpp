#include<iostream>
using namespace std;
struct node
{
	int value;
	node *left;
	node *right;
	
};
class cbt
{
private:

    node *ttemp;
	int count;
	int height;
	int key;
	int zzz;
	node *del;
public:
		node *root;
		 int jumps;
	cbt()
	{
		root=NULL;
		jumps=count=height=key=0;
	}
	void insertion(node *temp)
	{
		if(root==NULL)
		{
			root=new node;
			cout<<"Enter The Value";
			cin>>root->value;
			root->right=root->left=NULL;
			count++;
			key=root->value;
			return;
		}
		if(temp->left!=NULL)
		{
			jumps++;
			insertion(temp->left);
		}
		
		{
		if(jumps<=height)
		{
			if(count==(pow(2,(height+1))-1))
			{
				temp=root;
				while(temp->left!=NULL)
				{
					temp=temp->left;
				}
				temp->left=new node;
				cout<<"Enter The Value";
				cin>>temp->left->value;
				temp->left->left=temp->left->right=NULL;
				height++; 
				count++;
				
				return;
			}
		}
		if((temp->left!=NULL)&&(temp->right==NULL))
		{
			temp->right=new node;
			cout<<"Enter The Value";
			cin>>temp->right->value;
			temp->right->left=temp->right->right=NULL;
			count++;
			return;
		}
		if((jumps==height-1)&&(temp->left==NULL))
		{cout<<"enter";
			temp->left=new node;
			cout<<"Enter The Value";
			cin>>temp->left->value;
			temp->left->left=temp->left->right=NULL;
			count++;
			return;
		}
		
		}
		if(temp->right!=NULL)
		{
			jumps++;
			insertion(temp->right);
			
		}
		jumps--;
	}
	void print(node *temp)
	{
		if(temp->left!=NULL)
		{
			print(temp->left);
		}
		cout<<temp->value;
		if(temp->right!=NULL)
		{
			print(temp->right);
		}
	}
	void deletion(node *temp)
	{
		
		
		if(temp->right!=NULL)
		{
			
			deletion(temp->right);
		}
		if((temp->value>key) &&(temp->right==NULL))
		{
			zzz=temp->value;
			prefinder(root);
			
			del=ttemp->right;
			root->value=temp->value;
			delete del;
			ttemp->right=NULL;
			count--;
			return;
		}
		if(temp->left!=NULL)
		{
			deletion(temp->left);
		}
	}
		void prefinder(node *temp)
	{
		if(root->value==zzz)
		{
			ttemp=root;
			return;
		}
		while(temp->left!=NULL)
		{
			if(temp->left->value==zzz)
		{
			ttemp=temp;
			return;
		}
			temp=temp->left;
		}
		temp=root;
		while(temp->right!=NULL)
		{
			if(temp->right->value==zzz)
		{
			ttemp=temp;
			return;

		}
			temp=temp->right;
		}
		
	
	}
	void percolateup(node *temp)
	{
		if(temp->left!=NULL)
		{
			percolateup(temp->left);
		}
		if((temp->left!=NULL)&&(temp->right!=NULL))
		{
			if(temp->value<temp->left->value)
			{
				int samp=temp->value;
				temp->value=temp->left->value;
				temp->left->value=samp;
			}
			if(temp->value>temp->left->value)
			{
				int samp=temp->value;
				temp->value=temp->right->value;
				temp->right->value=samp;
			}
		}
		if(temp->right!=NULL)
		{
			percolateup(temp->right);
		}
	}
};
int main()
{
	cbt c1;
		c1.jumps=0;
		c1.insertion(c1.root);
		c1.jumps=0;
		c1.insertion(c1.root);
		c1.jumps=0;
		c1.insertion(c1.root);
		c1.jumps=0;
		c1.insertion(c1.root);
		c1.jumps=0;
		c1.insertion(c1.root);
		c1.jumps=0;
		c1.insertion(c1.root);
		c1.jumps=0;
		c1.insertion(c1.root);
		c1.jumps=0;
		c1.insertion(c1.root);
		c1.jumps=0;
		c1.insertion(c1.root);
	c1.print(c1.root);
	c1.percolateup(c1.root);
	c1.percolateup(c1.root);

	cout<<endl;
	c1.print(c1.root);
	c1.deletion(c1.root);
	cout<<endl;
	cout<<endl;
	c1.print(c1.root);
}