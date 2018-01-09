#include<iostream>
using namespace std;
struct node
{
	int value;
	node *left;
	node *right;
	int LTH;
	int RTH;
};
class bst
{
private:
	int count;
	int key;
	node *del;
	node *t;
public:
		node *root;
		node *dummy;
	bst()
	{
		key=0;
		root=new node;
		dummy=new node;
			cout<<"Enter Value to Add";
			cin>>root->value;
			root->left=dummy;
			root->LTH=1;
			root->right=dummy;
			root->RTH=1;
		dummy->left=root;
		dummy->RTH=0;
		dummy->LTH=0;
		dummy->right=dummy;
		dummy->value=0;
			cout<<dummy->left->value;
	}
	void insert()
	{
		
		
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
			if(temp->LTH!=1)
			{
				insertbst(temp->left);
			}
			else if(temp->LTH==1)
			{
				{cout<<temp->value;
				cout<<"Left Called";
				t=new node;
				t->value=key;
				t->left=temp->left;
				t->right=temp;
				t->LTH=1;
				t->RTH=1;
				temp->left=t;
				temp->LTH=0;
				return;
				}
			}
		}
		if(key>temp->value)
		{
			if(temp->RTH!=1)
			{
				insertbst(temp->right);
			}
			else if(temp->RTH==1)
			{
				cout<<temp->value;
				cout<<"Right Called";
				t=new node;
				t->value=key;
				t->right=temp->right;
				t->left=temp;
				t->LTH=1;
				t->RTH=1;
				temp->right=t;
				temp->RTH=0;
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
void Inorder(node* temp) 
{ 	
	cout<<"enter";
	while(  ( temp=inordertraverse(temp) ) != dummy )
	
		cout << temp->value<<endl;
} 

	node* inordertraverse(node *temp)
	{
		if(temp->RTH==1)
		{
			return(temp->right);
		}
		else
		{
		temp=temp->right;
		while(temp->LTH==0)
		{
			temp=temp->left;
		}
		return temp;
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
int opt;char ch;
cout<<"Welcome To Threader Binary Tree.Please Select Options From Here";
cout<<endl<<"1 For Insertion"<<endl<<"2 for Deletion"<<endl<<"3 For Traversal";
do{
cin>>opt;
if(opt==1)
{
b1.insert();
}
else if(opt==2)
{
	b1.deletesimp();
}
else if(opt==3)
{
b1.Inorder(b1.dummy);
}
else
{
cout<<"Error!!!!";
}
cout<<endl<<"Do You Want To Select Option Again Enter Y to Yes N To No";
cin>>ch;
}while(ch=='y' || ch=='Y');


}	