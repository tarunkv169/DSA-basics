#include<iostream>
using namespace std;


void heapify_max(int arr[],int size,int i)
{
    int largest = i;
    int leftchild_index=2*i;
    int rightchild_index=2*i+1;

    if(leftchild_index<=/*=sign*/size && arr[largest]<arr[leftchild_index])
    {
        largest=leftchild_index;
    }
    
    if(rightchild_index <=/*=sign*/size && arr[largest]<arr[rightchild_index])
    {
        largest=rightchild_index;
    }

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify_max(arr,size,largest);
    }
}


void heap_sort(int arr[], int n)
{
       int size=n;
       while(size > 1)
       {
         //             1.     swap first(root) node with last(leaf)node(which we want to delete)
        swap(arr[1],arr[size]);

        //             2.     remove the last node(which is root node(after swapping)) now our root node is deleted
        size--;

        //             3.     propegate the node to its right position acc to(max or min heap) here it is max heap
        //                    ****heapify algo****studing later
        
        heapify_max(arr,size,1);
       }
}

int main()
{
    
    int arr[6]={-1,54,53,55,52,50};  
    int n=5;
    
    // 1. creation of max heap using heapify
    for(int i=n/2;i > 0;i--)
    {
        heapify_max(arr,n,i);
    }
    cout<<"printing max_heap"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }



    // 2. sorting this max heap using heap_sort
    heap_sort(arr,n);
    cout<<"printing sorted max_heap"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}