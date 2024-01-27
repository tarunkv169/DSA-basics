#include<iostream>
#include<string>
using namespace std;

class trienode
{
   public:
      // declaration of all the requirments
      char data;
      trienode* children[26];
      bool isterminal;

      // initialization of all the requirments
      trienode(char ch)
      {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isterminal = false;
      }
};

class trie
{
    public:
      // declaring obj pointer
      trienode* root;
      // intializing obj
      trie()
      {
        root= new trienode('\0');     
      }
       
       // function to insert
      void insertUtil(trienode* root,string word)
      {
        // base case--stopping criteria for recursion
        if(word.length()==0)
        {
            root->isterminal = true;
            return;
        }

        // index of first char in word so that we can start out insertion
        int index = word[0]-'a';
        // declaring upcomig root
        trienode* child;

        // if root already present i.e not null 
        if(root->children[index]!=NULL)
        {  // getting character index to make it root
            child = root->children[index];
        }
        else
        {  // making first char as root of next
            child = new trienode(word[0]);
            root->children[index]=child; // storing it as 
        }

        insertUtil(child,word.substr(1));   // recursive call
       }
       
       // another function to get word
      void insertword(string word)
      {
        insertUtil(root,word);
      }



      bool searchUtil(trienode* root,string word)
      {
         //base case
         if(word.length()==0)
         {
           return root->isterminal;
         }

         int index = word[0]-'a';
         trienode* child;

         if(root->children[index]!=NULL)
         {
            child = root->children[index];
         }
         else{
            return false;
         }

         return searchUtil(child,word.substr(1));
      }


      bool searchword(string word)
      {
        return searchUtil(root,word);
      }

};


int main()
{
    trie *t = new trie();

    t->insertword("tarun");
    t->insertword("taru");
    t->insertword("rohit");
    t->insertword("rohan");

    if(t->searchword("tarin"))
    {
      cout<<"word is present in our dictionary"<<endl;
    }
    else{
      cout<<"word is absent in our dictionary"<<endl;
    }

    return 0;

}





