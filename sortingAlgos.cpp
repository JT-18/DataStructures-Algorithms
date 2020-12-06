#include<iostream>
#include<limits.h>
using namespace std;

void bubblesort(int a[],int n)
{
	for(int i = 0;i<n;i++)	//Reperesents a Pass.
	{
		int flg = 0;		//For making the algo adaptive to sorted array.If array is sorted no swap will occur
		for(int j = 0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				flg = 1;
			}
		}
		if(flg == 0)
			break;
	}
}


void insertionsort(int a[],int n)
{
	for(int i = 1;i<n;i++)	//Represent the boundary b/w sorted and unsorted part.
	{
		int x = a[i];
		int j = i - 1;
		while(a[j]>x && j>-1)	
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}

void selectionsort(int a[],int n)
{
	int i,j,k;
	i=j=k=0;
	for(int i = 0;i<n-1;i++)		//for passes
	{
		k = j = i;
		while(j<n)					//for finding min element
		{
			if(a[j] < a[k])
			{
				k = j;
			}
			j++;
		}
		int tmp = a[k];
		a[k] = a[i];
		a[i] = tmp;
	}
}

int partition(int a[],int l,int h)
{
	int piv = a[l];
	int i=l,j=h;
	
	do
	{
		do{i++;}while(a[i] <= piv);
		do{j--;}while(a[j] > piv);
		if(i<j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}while(i<j);
	int tmp = a[l];
	a[l] = a[j];
	a[j] = tmp;
	return j;
}

void quicksort(int a[],int l,int h)
{

	if(l<h)
	{
		int j = partition(a,l,h);
		quicksort(a,l,j);
		quicksort(a,j+1,h);
	}
}

void merge(int a[],int l,int mid,int h)
{
	int b[h+1];
	int i = l,j = mid+1,k = l;
	while(i <= mid && j <= h)	//For merging 2 sorted arrays until one ends.
	{
		if(a[i]<a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	
	for(;i<=mid;i++)	//For appending the remaining elements before mid.
	{
		b[k++] = a[i];
	}
	
	for(;j<=h;j++)		//For appending the remaining elements after mid.
	{
		b[k++] = a[j];
	}
	
	for(i = l;i<=h;i++)a[i] = b[i];		//For copying all elements from tmp array back into passed array.
}

void mergesort(int a[],int l,int h)
{
	if(l<h)		//Fails if l == h ie pointing on same element.
	{
		int mid = (l+h)/2;	
		mergesort(a,l,mid);		//sort 1st half of the array.
		mergesort(a,(mid+1),h);	//sort 2nd half of the array.
		merge(a,l,mid,h);		//merge the 2 sorted halfs.
	}
}


int main()
{
	int arr[] = {8,7,5,3,2,INT_MAX};
	int n = sizeof(arr)/sizeof(arr[0]);
	//bubblesort(arr,n);
	//insertionsort(arr,n);
	//selectionsort(arr,n);
	//mergesort(arr,0,n-1);
	quicksort(arr,0,n-1);
	printf("Array Data :");
	for(int i=0;i<n-1;i++)
	{
		cout<<arr[i]<<" ";
	}
}
