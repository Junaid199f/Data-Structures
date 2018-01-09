#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
void mergesort(int[],int,int);
void merge(int[],int,int,int);
void main()
{
int a[10],p,r,i,n;
system("cls");
cout<<"Enter the number of elements";
cin>>n;
p=0;
r=n-1;
cout<<"Enter the array";
for(i=0;i<n;i++)
{
     cin>>a[i];
}
mergesort(a,p,r);
cout<<"The sorted array is:";
for(i=0;i<n;i++)
{
     cout<<"\n"<<a[i];
}
//getch();
}
void mergesort(int a[], int low, int high)  { 
       if(low == high)  
            return; 
       int length = high-low+1; 
       int pivot = (low+high) / 2; 
	   mergesort(a, low, pivot); 
	   mergesort(a, pivot+1, high); 
       
	   int *working = new int[length]; 
       for(int i = 0; i < length; i++)  
           working[i] = a[low+i]; 
	   int m1 = 0;    
	   int m2 = pivot-low+1;  
	   for(int i = 0; i < length; i++) { 
       
		   if(m2 <= high-low)  

			   if(m1 <= pivot-low)  

				   if(working[m1] > working[m2])  

					   a[i+low] = working[m2++];   

				   else  

					   a[i+low] = working[m1++]; 

			   else  

				   a[i+low] = working[m2++]; 

		   else  

			   a[i+low] = working[m1++]; 
       } 
} 

