#include<iostream>
using namespace std;
class hashfun
{
private:
	int *top;
	int *temp;
	int total;
	int value;
	int count;
	int pre;
	int *temp2;
public:
	hashfun()
	{
		count=0;
		cout<<"Enter How many items you want in a heap";
		cin>>total;
		pre=total;
		top=new int[total];
		for(int i=0;i<total;i++)
		{
			top[i]=-1;
		}

	}
	void insert(int value)
	{

		int chk=total/2;
		if(count==chk)
		{
			rehash();
			return;
		}

		int i=value%total;
		if(i==total-1)
		{
			if(top[i]!=-1)
			{
				i=0;
			}
			else if(top[i]==-1)
			{
			top[i]=value;
			return;
			}
		}
		while(i!=total-1)
		{
			cout<<i;
			if(top[i]==-1)
			{
				count++;
				top[i]=value;
				return;
			}
			else if(top[i]!=-1)
			{
				i++;
			}
		
			
		}
		
	}
	void deletion()
	{
	}
	void print()
	{
		cout<<endl<<"Here is"<<endl;
		for(int i=0;i<total;i++)
		{
			cout<<top[i];
		}
	}
	void search()
	{
		cout<<"Dear User!! Please Enter The Value to Search";
		cin>>value;
		int i=value%total;
		if(count==0)
		{
			cout<<"Hash is Empty";
			return;
		}
		if(i==total-1)
		{
			if(top[i]==value)
			{
                    cout<<"Item Successfully Found";
				return;
			}
			else
			{
				i=0;
			}
		}
		while(i!=total-1)
		{
			if(top[i]==value)
			{
				cout<<"Value Found";
				return;
			}
			else
			{
				i++;
			}
		}
	}
	void rehash()
	{
		int cc;
		cout<<"Rehash Called";
		total=total*2;
          while(1)
		{
		if(primefinder(total)==true)
		{
			break;
		}
		else
			total++;
		}
		temp=new int[total];
		for(int i=0;i<total;i++)
		{
			temp[i]=-1;
		}
		temp2=top;
		top=temp;
		for(int i=0;i<pre;i++)
		{
			if(temp2[i]!=-1)
			{
				insert(temp2[i]);
			}
		}
		delete temp2;

	}
	bool primefinder(int t)
	{int count=0;
	cout<<"Enter";
		for(int a=1;a<=t;a++)
               {
                if(t%a==0)
                   {
                  count++;
                   }
               }
       if(count==2)
         {
		    return true;
         }
       else
         {
		    return false;
         }
 
           }
};
int main()
{
	int val;
	hashfun h1;
	for(int i=0;i<6;i++)
	{
		cin>>val;
		h1.insert(val);
	}
	
	h1.print();

}