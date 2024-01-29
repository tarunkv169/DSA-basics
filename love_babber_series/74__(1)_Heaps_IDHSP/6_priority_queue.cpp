//priority queue: in this we implement the priority queue using heap(what we have learnt at back max-heap or min-heap etc)
// by using max-heap-----> we implement the priority queue in which (higher the value) (higher the priority)
// by using min-heap-----> we implement the priority queue in which (lower the value) (higher the priority)

//  priority_queue<int> is a data structure useful for creation of either max_heap or min_heap



#include<iostream>
#include<queue>
using namespace std;

void max_heap_using_pq()
{
    priority_queue<int> pq;
    cout<<"enter the no. of nodes "<<endl;
    int n;
    cin>>n;
    cout<<"enter the elements to put into node "<<endl;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        pq.push(num);
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
}

void min_heap_using_pq()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    cout<<"enter the no. of nodes "<<endl;
    int n;
    cin>>n;
    cout<<"enter the elements to put into node "<<endl;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        pq.push(num);
    }

    while(!pq.empty())
    {
        cout<<"top element is "<<pq.top()<<" ";
        pq.pop();
    }
}

int main()
{
   max_heap_using_pq();
   cout<<endl;
   min_heap_using_pq();
    
    
}


