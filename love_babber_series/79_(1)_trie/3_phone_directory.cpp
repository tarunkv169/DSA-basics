// the prefix as ‘str’. One special property of the search function is that when o
// user searches for @ contact from the contact list then suggestions (contacts

// with prefix as the string entered so for) are shown after the user enters each
// character.


// ‘You are given a list/array of strings which denotes the
// contacts that exist in your phone directory. The search
// query on a string ‘str’ which is @ query string displays all
// the contacts which are present in the given directory with
// the prefix as ‘str’. One special property of the search
// function is that when a user searches for a contact from the
// contact list then suggestions (contacts with prefix as the
// string entered so for) are shown after the user enters each
// character.


#include<iostream>
#include<string>
#include<vector>
using namespace std;

class trienode
{
    public:
      char data;
      trienode* children[26];
      bool isterminal;

      trienode(char ch)
      {
        data = ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isterminal=false;
      }

};

class trie
{
   public:
    trienode* root;
    
    trie()
    {
      root=new trienode('\0');
    }

    void insertUtil(trienode* root,string word)
    {
        if(word.length()==0)
        {
            root->isterminal = true;
            return;
        }

        int index = word[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else{
            child = new trienode(word[0]);
            root->children[index]=child;
        }

        insertUtil(child,word.substr(1));
    }


    void insertword(string word)
    {
        insertUtil(root,word);
    }

    
    vector<string> print_all_suggestions(trienode* curr, string prefix)
    {
        vector<string> temp;
        if(curr->isterminal)
        {
            temp.push_back(prefix);
        }
        
        
              for(char ch='a';ch <='z';ch++)
              {

                trienode* next = curr->children[ch-'a'];
                if(next!=NULL)
                {
                   string newPrefix = prefix + ch;
                   vector<string> suggestions = print_all_suggestions(next, newPrefix);
                   temp.insert(temp.end(), suggestions.begin(), suggestions.end());
                }
        }

        return temp;

    }

    vector<vector<string>> get_suggestions(string query)
    {
        // prev taking the parent starting with root , then proceed by curr as prev
        trienode* prev = root;
        // to keep track whether this prefix is preset or not
        string prefix = "";
        // to get output
        vector<vector<string>> output;
        
        // traversing the query string for which we have to find in our contact list
        for(int i=0;i<query.length();i++)
        {
            char lastchar = query[i];

            prefix.push_back(lastchar);
            
            // to check lastchar(first of query) whether it is present in our trie
            trienode* curr = prev->children[lastchar-'a'];
            // not found then break go out of loop
            if(curr==NULL)
            {
                break;
            }

            // if found then print all suggestions related to that lastchar of our query
            vector<string> temp = print_all_suggestions(curr, prefix);
            output.push_back(temp);
            prev = curr;
        }

        return output;
    }


};

int main()
{
   trie* t = new trie();

   vector<string> arr = {"cading", "codchief", "codmaster", "cothalwa"};

   for(int i=0;i<4;i++)
   {
      t->insertword(arr[i]);
   }


   string query = "cod";

   vector<vector<string>> suggestions = t->get_suggestions(query);
   for (int i = 0; i < suggestions.size(); i++) {
       for (int j = 0; j < suggestions[i].size(); j++) {
           cout << suggestions[i][j] << " ";
       }
       cout << endl;
   }


  return 0;


}
