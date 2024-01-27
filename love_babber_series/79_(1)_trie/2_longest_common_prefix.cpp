// You are given on array ‘ARR’ consisting of °N" strings. Your tosk is to find the longest common
// prefix among all these strings. If there is no common prefix, you have to return an empty
// string. .

// A prefix of a string can be defined as « substring obtained after removing some or all
// characters from the end of the string.





// ********************************************************************        using loops





// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;

// class prefix
// {
//     public:
      
//       string lcp(vector<string> &arr)
//       {
//         char ch;
//         string ans="";
//         bool match = true;
//         for(int i =0;i<arr.size();i++)
//         {
//             ch = arr[0][i];

//             for(int j = 1;j<arr.size();j++)
//             {
//                  if(arr[j].size()<i || ch!=arr[j][i])
//                  {
//                     match = false;
//                      break;
//                  }
                
//             }


//             if(match==false)
//              {
//                 break;
//              }
//              else{
//                  ans.push_back(ch);
//              }

//         }


//          return ans;

//       }
// };


// int main()
// {
//     vector<string> arr = {"coding","codchief","codmaster","codhalwa"};

//     prefix obj;

//     cout<<"longest common prefix is       "<<obj.lcp(arr)<<endl;
// }










// ********************************************************************        using trie





#include<iostream>
#include<string>
using namespace std;

class trienode
{
public:
    char data;
    trienode* children[26];
    int charcount;
    bool isterminal;

    trienode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        charcount = 0;
        isterminal = false;
    }

};

class trie
{
public:
    trienode* root;

    trie()
    {
        root = new trienode('\0');
    }

    void insertUtil(trienode* root, string word)
    {
        if (word.length() == 0)
        {
            root->isterminal = true;
            return;
        }

        int index = word[0] - 'a';
        trienode* child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
            root->charcount++;
        }

        insertUtil(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertUtil(root, word);
    }






    string lcp(string first_string, string &ans)
    {

        for (int i = 0; i < first_string.length(); i++)
        {
            char ch = first_string[i];

            if (root->charcount == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isterminal)
            {
                break;
            }
        }

        return ans;
    }
};

int main()
{
    trie* t = new trie();




    string arr[4] = {"coding", "codchief", "codmaster", "codhalwa"};

    for (int i = 0; i < 4; i++)
    {
        t->insertword(arr[i]);
    }




    string first_string = arr[0];
    string ans = "";

    cout << "Longest common prefix is " << t->lcp(first_string, ans) << endl;

    return 0;
}
