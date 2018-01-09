#include<iostream>
using namespace std;
struct node
{
node *left;
node *right;
int value;
};
class bst
{
private:
	int height;
	int size;
	node *del;
	int zzz;
	int l;
	int r;
	int gh;
	bool left;
	node *ttemp;
public:
	bst()
	{
		l=r=gh=0;
		root=NULL;
		key=0;
		zzz=0;
		left=false;
	}
	int key;
	node *root;
	void traverse(node *temp)
	{
		if(temp->left!=NULL)
		{
			traverse(temp->left);
		}
		cout<<temp->value;
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
		if(key>temp->value)
		{
		if(temp->right!=NULL)
		{
			search(temp->right);
		}
		}
		if(key==temp->value)
		{
			cout<<"The Item Found Successfully";
		}
	}
	void insert(node *temp)
	{
		if(root==NULL)
		{
			
			root=new node;
			root->value=key;
			root->left=NULL;
			root->right=NULL;
		}
		else if(key<temp->value)
		{
			if(temp->left!=NULL)
			{
				insert(temp->left);
			}
			else if(temp->left==NULL)
			{
				temp->left=new node;
				temp->left->value=key;
				temp->left->left=temp->left->right=NULL;
				
			}
		}
			else if(key>temp->value)
		{
			if(temp->right!=NULL)
			{
				insert(temp->right);
			}
			else if(temp->right==NULL)
			{
				temp->right=new node;
				temp->right->value=key;
				temp->right->left=temp->right->right=NULL;
			}
		}
		//................Check For AVL List......................//
		/*{
			int bal=heightbst(root->left)-heightbst(root->right);
			if(bal==-1 || bal==0 || bal==1)
			{
				return;
			}
			else
			{
				node *temp1=root;
				if(key>root->value)
				{
					if(key>root->right->value)
					{
						temp->previous->previous->left=temp->previous;
					}
				}
			}
			
		}*/
		avlinsert(root);
	}
	void deletebst(node *temp)
	{
		//.................For Root............................//
		if(key==root->value)
		{
			if((root->left==NULL) &&(root->right==NULL))
			{
				root=NULL;
			}
			else if((root->left!=NULL) &&(root->right!=NULL))
			{
               key=root->value;
			   casethree(root);
			   root->value=key;
			}
			else if((root->left==NULL) &&(root->right!=NULL))
			{
				root->value=root->right->value;
				
			}
			else if((root->left!=NULL) &&(root->right==NULL))
			{
				root->value=root->left->value;
				del=root->left;
				root->left=NULL;
				delete del;
			}
		}
		//.................For Left............................//
		if(key<temp->value)
		{
			//...................Case 1................................//
			if((temp->left->value==key)&&(temp->left->left==NULL)&&(temp->left->right==NULL))
			{
				del=temp->left;
				temp->left=NULL;
				delete del;
			}
		   //...................Case 2................................//
			else if((key==temp->left->value)&&(temp->left->left!=NULL)&&(temp->left->right==NULL))
			{
				del=temp->left;
				temp->left=del->left;
				delete del;
			}
			else if((key==temp->left->value)&&(temp->left->left==NULL)&&(temp->left->right!=NULL))
			{
				
				del=temp->left;
				temp->left=del->right;
				delete del;
			}
			//...................Case 3................................//
			else if((key==temp->left->value)&&(temp->left->left!=NULL)&&(temp->left->right!=NULL))
			{
				key=temp->left->value;
				casethree(temp->left);
				temp->left->value=key;
				return;
			}
			else
			{
				deletebst(temp->left);
			}
		}
		//.................For Right............................//
		if(key>temp->value)
		{
			//...................Case 1................................//
			if((temp->right->value==key)&&(temp->right->left==NULL)&&(temp->right->right==NULL))
			{cout<<"Enter";
				del=temp->right;
				temp->right=NULL;
				delete del;
			}
		   //...................Case 2................................//
			else if((key==temp->right->value)&&(temp->right->left!=NULL)&&(temp->right->right==NULL))
			{
				del=temp->right;
				temp->right=del->left;
				delete del;
			}
			else if((key==temp->right->value)&&(temp->right->left==NULL)&&(temp->right->right!=NULL))
			{
				
				del=temp->right;
				temp->right=del->right;
				delete del;
			}
			//...................Case 3................................//
			else if((key==temp->right->value)&&(temp->right->left!=NULL)&&(temp->right->right!=NULL))
			{
				key=temp->right->value;
				casethree(temp->right);
				temp->right->value=key;
				return;
			}
			else
			{
				deletebst(temp->right);
			}
		}
	}
	void casethree(node *temp1)
	{
		if((key>temp1->left->value) && (temp1->left->left==NULL))
		{
			key=temp1->left->value;
			deletebst(root);
		}
		else
		{
			casethree(temp1->left);
		}
	}
	int heightbst(node* temp) 
{
   if (temp==NULL) 
       return 0;
   else
   {
	   int left = heightbst(temp->left);
       int right = heightbst(temp->right);
       if (left>right) 
           return(left+1);
       else return(right+1);
   }

} 
	void avlinsert(node *temp)
	{
		
		if(temp->left!=NULL)
		{ttemp=temp;
			avlinsert(temp->left);
			
		}
		if(temp->right!=NULL)
		{ttemp=temp;
			avlinsert(temp->right);
			
		}

		///////.Checking Cases For AVL TREE..................//tempd->right=ttemp->left->right;
		{
			int chk=heightbst(temp->left)-heightbst(temp->right);
			if(chk>1)
			{
				if(temp==root)
				{
					case1(temp);
				}
				else
				{
				zzz=temp->value;
				prefinder(root);
				case1(temp);
				}
				
			}
			if(chk<-1)
			{
				zzz=temp->value;
				prefinder(root);
				case4(temp);
			}
			
		}
		////////////////////////////////////////////////////////////////////////////////////////
		
	}
	void case1(node *temp)
	{
		if(temp==root)
		{
			node *y=root;
			root=root->left;
			y->left=root->right;
			root->right=y;
			return;
		}
		if(left==true)
		{
			node *y=temp;
			ttemp->left=temp->left;
			y->left=ttemp->left->right;
			ttemp->left->right=y;
		}
		else if(left==false)
		{
			node *y=temp;
			ttemp->right=temp->left;
			y->left=ttemp->right->left;
			ttemp->right->right=y;
		}
		
	}
	void case4(node *temp)
	{
		
		if(temp==root)
		{
			node *y=root;
			root=root->right;
			y->right=root->left;
			root->left=y;
			return;
		}
		if(left==true)
		{
			node *y=temp;
			ttemp->left=temp->right;
			y->right=ttemp->right->left;
			ttemp->left->left=y;
		}
		else if(left==false)
		{
			node *y=temp;
			ttemp->right=temp->right;
			y->right=ttemp->right->left;
			ttemp->right->left=y;
		}
		//////////////////Check For Case 2//////////////////////////
		int c=heightbst(ttemp->left)-heightbst(ttemp->right);
		if(c<-1)
		{
			zzz=ttemp->value;
			prefinder(root);
			node *y=ttemp->right;
			ttemp->right=ttemp->right->right;
			y->right=ttemp->right->left;
			ttemp->right->left=y;
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
			left=true;
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
			left=false;
			ttemp=temp;
			return;

		}
			temp=temp->right;
		}
		
	
	}
	void avldeletion(node *temp)
	{

	}
};
int main()
{
	bst b1;
	for(int i=0;i<3;i++)
	{
	cin>>b1.key;
	b1.insert(b1.root);
	}
	b1.traverse(b1.root);
	cout<<endl;
	cout<<endl;
	cout<<b1.root->value;
	cout<<b1.root->left->value;
	cout<<b1.root->right->value;
		
	
}