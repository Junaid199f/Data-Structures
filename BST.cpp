#include<iostream>
using namespace std;
struct node
{
	int value;
	node *left;
	node *right;
};
class bst
{
private:
	int count;
	int key;
	node *del;
public:
	int lval;
	int rval;
		node *root;
	bst()
	{
		key=0;
		lval=rval=0;
		root=NULL;
	}
	void height()
	{
		left(root);
		right(root);
		if(rval>lval)
			cout<<rval;
		else
			cout<<lval;
	}
	void left(node *temp)
	{
		if(temp->left!=NULL)
		{
			if(temp->left!=NULL)
			{lval++;
			}
			left(temp->left);
		}
		if(temp->right!=NULL)
		{
			if(temp->value<root->value)
			{
				lval++;
			}
			left(temp->right);
		}
	}
	void right(node *temp)
	{
		if(temp->right!=NULL)
		{
			if(temp->right!=NULL)
			{rval++;
			}
			right(temp->right);
		}
		if(temp->left!=NULL)
		{
			if(temp->value>root->value)
			{
				rval++;
			}
			right(temp->left);
		}
	}
	void insert()
	{
		if(root==NULL)
		{
			root=new node;
			cout<<"Enter Value to Add";
			cin>>root->value;
			root->left=root->right=NULL;
		}
		else
		{
		cout<<"Enter Value to Add";
		cin>>key;
		insertbst(root);
		return;
		}
	}
	void insertbst(node *temp)
	{
		if(key<temp->value)
		{
			if(temp->left!=NULL)
			{
				insertbst(temp->left);
			}
			else if(temp->left==NULL)
			{
				cout<<"Left Called";
				temp->left=new node;
				temp->left->value=key;
				temp->left->left=temp->left->right=NULL;
				return;
			}
		}
		else if(key>temp->value)
		{
			if(temp->right!=NULL)
			{
				insertbst(temp->right);
			}
			else if(temp->right==NULL)
			{
				cout<<"Right Called";
				temp->right=new node;
				temp->right->value=key;
				temp->right->left=temp->right->right=NULL;
				return;
			}
		}
	}
	void deletesimp()
	{
		cout<<"Please Enter The Value To Delete";
		cin>>key;
	 deletebst(root);
	}	
    void deletebst(node *temp)
{
	//..................For Root.............................//
	if((key==root->value) &&(root->left==NULL) &&(root->right==NULL))
	{
		cout<<"Only Root Exists So it cannot be deleted";
	}
	if(key==root->value)
	{
		key=root->value;
	extra(root); 
    key=temp->right->value;
	return;
	}
//--------------------For Left..............................//
if(key<temp->value)
{
if((temp->left->value==key)&&(temp->left->left==NULL)&&(temp->left->right==NULL))
{
del=temp->left;
temp->left=NULL;
delete del;
}
//Case 2
else if((temp->left->value==key)&&(temp->left->left==NULL)&&(temp->left->right!=NULL))
{
del=temp->left;
temp->left=del->right;
delete del;
}
else if((temp->left->value==key)&&(temp->left->right==NULL)&&(temp->left->left!=NULL))
{
del=temp->left;
temp->left=del->left;
delete del;
}
//------------------------Case 3--------------------------
else if((temp->left->value==key)&&(temp->left->left!=NULL)&&(temp->left->right!=NULL))
{
	cout<<"Enter into case 3";
	key=temp->left->value;
	extra(temp->left); 
	temp->left->value=key;
	return;
}
else
{
deletebst(temp->left);
}
}
//--------------------For Right..............................//
if(key>temp->value)
{
if((temp->right->value==key)&&(temp->right->left==NULL)&&(temp->right->right==NULL))
{
del=temp->right;
temp->right=NULL;
delete del;
}
//Case 2
else if((temp->right->value==key)&&(temp->right->left==NULL)&&(temp->right->right!=NULL))
{
del=temp->right;
temp->right=del->right;
delete del;
}
else if((temp->right->value==key)&&(temp->right->right==NULL)&&(temp->right->left!=NULL))
{
del=temp->right;
temp->right=del->left;
delete del;
}
//---------------Case 3-----------------------
else if((temp->right->value==key)&&(temp->right->left!=NULL)&&(temp->right->right!=NULL))
{
	cout<<"Enter into case 3";
	key=temp->right->value;
	extra(temp->right); 
	temp->right->value=key;
	return;
}
else
{
deletebst(temp->right);
}
}
}
void extra(node *temp1)
{
	if(temp1->left!=NULL)
	{
		extra(temp1->left);
	}
	if((key>temp1->left->value)&&(temp1->left->left==NULL))
	{
		key=temp1->left->value;
		deletebst(root);
	}
	else 
	{
		cout<<"here the problem";
		 extra(temp1->left);
	}
}
	void traverse(node *temp)
	{
		
		if(temp->left!=NULL)
		{
			traverse(temp->left);
		}
		cout<<temp->value;
		cout<<endl;
		if(temp->right!=NULL)
		{
			traverse(temp->right);
		}
	}
	void search(node *temp)
	{
		if(key<temp->value)
		{
			if(temp->left!=NULL)
			{
				search(temp->left);
			}
		}
		else if(key>temp->value)
		{
			if(temp->right!=NULL)
			{
				search(temp->right);
			}
		}
		else if(key==temp->value)
		{
			cout<<"Dear User! The Item Found Successfully";
			cout<<endl;
			return;
		}
	}
	};
int main()
{
	bst b1;
	b1.insert();
	b1.insert();
	b1.insert();
	b1.insert();
	b1.insert();
	b1.traverse(b1.root->left);
	b1.height();
}