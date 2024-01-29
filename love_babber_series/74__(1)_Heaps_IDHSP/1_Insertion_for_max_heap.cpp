//  insertion for max heap             T.c = O(logn)

#include<iostream>
using namespace std;

class heap
{
    public:
    int arr[100];        // 1. declaring array and size
    int size;

    heap()               // 2. intializing values using constructor ---taking use of constructor
    {
        arr[0]=-1;        // 3.intialize arr first 0th index with -1 as we want to start insertion from 1st index
        size=0;           // 4. intially size of arr is 0 no element
    }

    void insertion(int val)
    {
         size=size+1;       // 5. increament size of array for insertion
         int new_value_index=size;    // 6. give that size to index
         arr[new_value_index]=val;    // 7. inserting value at that increased index(size)

         while(new_value_index > 1)   // 8. only root node na ho
         {
            int parentindex=new_value_index/2;     // 9. finding parent of that child node

            if(arr[parentindex]<arr[new_value_index])   //10. checking parent should greater than child for max heap
            {
                swap(arr[parentindex],arr[new_value_index]);     //11. if not than swap
                new_value_index=parentindex;                     //12. giving index of parent to child that swapped for sake of greatervalue
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
    heap h1;      // constructur called intialize our values---great use of constructor

    h1.insertion(60);
    h1.insertion(30);
    h1.insertion(50);
    h1.insertion(20);
    h1.insertion(70);
    h1.insertion(40);
    h1.insertion(55);

    h1.print();

    return 0;
}