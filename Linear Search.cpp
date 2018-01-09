#include<iostream>
using namespace std;
bool linsearch(int ar[],int val,int count)
{
	for(int i=0;i<count;i++)
	{
		if(ar[i]==val)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int arr[5];
	int count=5;
	int value;
	cout<<"Please Enter The Items Of Array";
	for(int i=0;i<count;i++)
	{
		cin>>arr[i];
	}
	cout<<endl<<"Please Enter The Values";
	cin>>value;
	bool check=linsearch(arr,value,count);
	if(check==true)
	{
		cout<<"Item Found";
	}
	else
		cout<<"Item Not Found";
}