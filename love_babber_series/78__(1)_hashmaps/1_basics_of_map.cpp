// why mapping is used 

                               // if we need to find out max occurance of a char from a string we can simply do as below:-------

// #include<iostream>
// #include<string.h>
// using namespace std;

// class maxoccur
// {
//    public:

//       int chararray[25]={0};
//       void chararraycount(string s)
//       {
//          for(int i=0;i<s.length();i++)
//          {
//              char ch = s[i];
//              int no;
//              if('a'<=ch || ch<='z')
//              {
//                   no = ch-'a';
//              }
//              else
//              {
//                   no = ch-'A';
//              }
             
//              chararray[no]++;
//          }
//       }

//       void maxoccured_ele()
//       {
//         int max = chararray[0];
//         int ans;

//         for(int i=0;i<25;i++){
//             if(chararray[i]>max){
//                 max = chararray[i];
//                 ans = i;
//             }
//         }

//         char finalans = 'a'+ans;
//         cout<<finalans<<endl;
//       }


// };

// int main(){
//    string s = "tesTttTsampl";
//    maxoccur obj1;
//    obj1.chararraycount(s);
//    obj1.maxoccured_ele();

//    return 0;
// } 

                                  // but if we need to find out max occurance of a word from a string then in this case mapping is used
                                  // now mapping is of two types----1.ordered_map (T.C=O(logn) & map in order)----------2.unordered_map (T.C=O(1) & map in unorder)

// some functionalities
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{                 //key  value
    unordered_map<string,int> un;

    //             insertion
          pair<string,int> p1 = make_pair("tarun",5);
          un.insert(p1);
          //or
          pair<string,int> p2("kumar",5);
          un.insert(p2);
          //or
          un["sharma"]=5;

    //             updation
          un["sharma"]=6;

    //             search
          cout<<un["sharma"]<<endl;
          // cout<<un.at("ji")<<endl;  it will give an error as not ji is inserted
          cout<<un["ji"]<<endl;         // here in this way ji is insert now with default value 0
          cout<<un.at("ji")<<endl;      // this time ji will show its value

    //              size
          cout<<un.size()<<endl;

    //              tocheck presence
          cout<<un.count("ji")<<endl;

    //              erase any key and value
          un.erase("ji");
          cout<<un.size()<<endl;

    //              iterator
          unordered_map<string,int>:: iterator it = un.begin();

          while(it != un.end())
          {
             cout<<it->first<<" "<<it->second<<endl;
             it++;
          }

}

