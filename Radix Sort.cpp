#include<iostream>
using namespace std;
void radixs(int ar[],int count,int no)
{
	

	int temp;int check;int check1;int temp1;int temp2;

	for(int i=0;i<count;i++)
	{   
		check=ar[i];
		for(int k=0;k<no;k++)
	{
		temp=check%10;
		check=check/10;
	}
		for(int j=i;j<count;j++)
		{
				check=ar[j];
		for(int l=0;l<no;l++)
	{
		check1=check%10;
		check=check/10;
	}
			if(check1<temp)
			{
				temp1=ar[j];
				ar[j]=ar[i];
				ar[i]=temp1;
			}
		}
	}
}
int main()
{
	int temp;int check=345;
int arr[5];

for(int i=0;i<5;i++)
{
	cin>>arr[i];
}
radixs(arr,5,2);
radixs(arr,5,2);
for(int i=0;i<5;i++)
{
	cout<<arr[i];
	cout<<endl;
}
radixs(arr,5,1);
for(int i=0;i<5;i++)
{
	cout<<arr[i];
	cout<<endl;
}
}q