// deletion for max heap         T.c = O(logn)

#include<iostream>
using namespace std;

class heap
{
    public:
      int arr[100];
      int size;

      heap()
      {
        arr[0]=-1;
        size=0;
      }
      
      void insertion(int val)
      {
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1)
        {
            int parent=index/2;

            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            {
              return ;
            }
        }
      }

      void deletion()
      {
        //             1.     swap first(root) node with last(leaf)node(which we want to delete)
        swap(arr[1],arr[size]);

        //             2.     remove the last node(which is root node(after swapping)) now our root node is deleted
        size--;

        //             3.     propegate the node to its right position acc to(max or min heap) here it is max heap
        //                    ****heapify algo****studing later
              
        //    start traversing whole max heap

        int i=1;   //we start indexing of arr(represention of c.b.t) from 1
        while(i<size)
        {
          int leftchild_index=2*i;
          int rightchild_index=2*i+1;

          if(leftchild_index < size && arr[i] < arr[leftchild_index])
          {
             swap(arr[i],arr[leftchild_index]);
             i = leftchild_index;
          }
          else if(rightchild_index < size && arr[i] < arr[rightchild_index])
          {
             swap(arr[i] , arr[rightchild_index]);
             i = rightchild_index;
          }
          else
          {
             return ;
          }

        }

        
      }


      void print()
      {
        for(int i=0;i<=size;i++)
        {
          cout<<arr[i]<<" ";
        }
      }
      

};


int main()
{
   heap h1;    

    h1.insertion(60);
    h1.insertion(30);
    h1.insertion(50);
    h1.insertion(20);
    h1.insertion(70);
    h1.insertion(40);
    h1.insertion(55);

    h1.print();

    h1.deletion();

    h1.print();

    return 0;

}