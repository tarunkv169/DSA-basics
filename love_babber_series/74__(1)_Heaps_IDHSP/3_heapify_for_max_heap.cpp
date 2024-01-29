// heapify algo for max_heap -------(agar koi node heap property follow nhi kr rha ta heapify follow krwonda hai)is a process
// of rearranging the elements of a binary tree
// to maintain the heap propery                  T.C = O(logn)

#include<iostream>
using namespace std;


// 3. heapify func
void heapify_max(int arr[],int size,int i)
{
     // 4. letting parent node as largest 
     int largest_index=i;

     int leftchild_index=2*i;
     int rightchild_index=2*i+1;

     if(leftchild_index < size && arr[largest_index] < arr[leftchild_index] )
     {  //5. if leftchild larger than parent 
        largest_index=leftchild_index;
     }

     if(rightchild_index < size && arr[largest_index] < arr[rightchild_index])
     {  //6. if rightchild larger than leftchild(now leftchild is larger from above if (if condi) satisfy)
        largest_index=rightchild_index;
     }

     //  
     if(largest_index != i)
     {  //7. parent ko largerchild se replace kr dia
        swap(arr[i],arr[largest_index]);
        //8. passing largerparent for next subtree
        heapify_max(arr,size,largest_index);
     }
     
}

int main()
{

    // 1.   declaring arr(rep of heap) with its size
    int arr[6]={-1,54,53,55,52,50};  // 6 size---1 for -1 as indexing from 1
    int n=5;

    // 2.   processing/traversing leaving leaf nodes(leaf nodes donot have childs)(as leaf nodes are form ((n/2)+1)th index to (n)th index)
    for(int i=n/2;i > 0;i--)
    {
        heapify_max(arr,n,i);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;

    
}