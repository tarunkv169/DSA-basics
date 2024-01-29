// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// class TrieNode {
// public:
//     char data;
//     TrieNode* children[26];
//     bool isTerminal;

//     TrieNode(char ch) {
//         data = ch;
//         for (int i = 0; i < 26; i++) {
//             children[i] = nullptr;
//         }
//         isTerminal = false;
//     }
// };

// class Trie {
// public:
//     TrieNode* root;

//     Trie() {
//         root = new TrieNode('\0');
//     }

//     void insertWord(string word) {
//         TrieNode* current = root;
//         for (char ch : word) {
//             int index = ch - 'a';
//             if (current->children[index] == nullptr) {
//                 current->children[index] = new TrieNode(ch);
//             }
//             current = current->children[index];
//         }
//         current->isTerminal = true;
//     }

//     vector<string> getSuggestions(string query) {
//         TrieNode* current = root;
//         vector<string> suggestions;

//         for (char ch : query) {
//             int index = ch - 'a';
//             if (current->children[index] == nullptr) {
//                 // No matching prefix found
//                 return suggestions;
//             }
//             current = current->children[index];
//         }

//         // DFS to collect all suggestions starting from the current node
//         collectSuggestions(current, query, suggestions);

//         return suggestions;
//     }

// private:
//     void collectSuggestions(TrieNode* node, string currentPrefix, vector<string>& suggestions) {
//         if (node->isTerminal) {
//             suggestions.push_back(currentPrefix);
//         }

//         for (int i = 0; i < 26; i++) {
//             if (node->children[i] != nullptr) {
//                 char ch = 'a' + i;
//                 collectSuggestions(node->children[i], currentPrefix + ch, suggestions);
//             }
//         }
//     }
// };

// int main() {
//     Trie trie;

//     vector<string> contacts = {"john", "jane", "jacob", "jackson", "jackie", "julia"};

//     for (const string& contact : contacts) {
//         trie.insertWord(contact);
//     }

//     string query = "ja";
//     for (char ch : query) {
//         vector<string> suggestions = trie.getSuggestions(query);
//         cout << "Suggestions for '" << query << "': ";
//         for (const string& suggestion : suggestions) {
//             cout << suggestion << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }





#include <iostream>
#include <string>
#include <vector>

using namespace std;

class trienode {
public:
    char data;
    trienode* children[26];
    bool isterminal;

    trienode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isterminal = false;
    }
};

class trie {
public:
    trienode* root;

    trie() {
        root = new trienode('\0');
    }

    void insertUtil(trienode* root, string word) {
        if (word.length() == 0) {
            root->isterminal = true;
            return;
        }

        int index = word[0] - 'a';
        trienode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        }
        else {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertword(string word) {
        insertUtil(root, word);
    }

    vector<string> print_all_suggestions(trienode* curr, string prefix) {
        vector<string> temp;

        if (curr->isterminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            trienode* next = curr->children[ch - 'a'];
            if (next != nullptr) {
                string newPrefix = prefix + ch;
                vector<string> suggestions = print_all_suggestions(next, newPrefix);
                temp.insert(temp.end(), suggestions.begin(), suggestions.end());
            }
        }

        return temp;
    }

    vector<vector<string>> get_suggestions(string query) {
        trienode* prev = root;
        string prefix = "";
        vector<vector<string>> output;

        for (int i = 0; i < query.length(); i++) {
            char lastchar = query[i];
            prefix.push_back(lastchar);

            trienode* curr = prev->children[lastchar - 'a'];
            if (curr == nullptr) {
                break;
            }

            vector<string> temp = print_all_suggestions(curr, prefix);
            output.push_back(temp);
            prev = curr;
        }

        return output;
    }
};

int main() {
    trie* t = new trie();

    vector<string> arr = {"cading", "codchief", "codmaster", "cothalwa"};

    for (const string& word : arr) {
        t->insertword(word);
    }

    string query = "cod";

    vector<vector<string>> suggestions = t->get_suggestions(query);
    for (const auto& suggestionList : suggestions) {
        for (const auto& suggestion : suggestionList) {
            cout << suggestion << " ";
        }
        cout << endl;
    }

    return 0;
}
