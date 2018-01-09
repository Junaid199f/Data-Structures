#include<iostream>
using namespace std;
bool binsearch(int arr[],const int val,int count)
{
	int first=0;
	int last=count-1;
	while(first<=last)
	{
      int mid=(first+last)/2;
	 if(arr[mid]>val)
	 {
		 first=mid+1;
	 }
	 else if(arr[mid]<val)
	 {
		 last=mid-1;
	 }
	 else
		 return true;
	}
	return false;
}
int main()
{
	int ar[5];
	int count=5;
	int value;
cout<<"Please Enter The Values";
for(int i=0;i<count;i++)
{
	cin>>ar[i];
}
cout<<"Please Enter The Item To Search";
cin>>value;
bool chk=binsearch(ar,value,count);
if(chk==true)
{
	cout<<"Item Found";
}
else
	cout<<"Error";
}