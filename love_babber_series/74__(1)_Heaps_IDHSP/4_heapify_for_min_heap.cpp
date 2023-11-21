#include<iostream>
using namespace std;

void heapify_min(int arr[], int size ,int i)
{
   int smallest_index=i;
   int leftchild_index = 2*i;
   int rightchild_index = (2*i)+1;

   if( leftchild_index < size && arr[smallest_index]> arr[leftchild_index])
   {
      smallest_index=leftchild_index;
   }

   if( rightchild_index < size && arr[smallest_index]> arr[rightchild_index])
   {
      smallest_index=rightchild_index;
   }

   if(smallest_index!=i)
   {
     swap(arr[i],arr[smallest_index]);
     heapify_min(arr,size,smallest_index);
   }
}

int main()
{
    int arr[6]={-1,30,60,50,40,20};
    int n=5;

    for(int i=n/2;i>0;i--)
    {
        heapify_min(arr,n,i);
    }

    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}