#include "079 Trie Basics .cpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// PHONE DIRECTORY IMPLEMENTATION :
/*
- approach : using trie :
- 2 vars rkhenge : prefixstr & lastcharofprefix & dono root pr honge starting me
- fir jese hi prefixstr me 1-1 char aata rhega wese lastcharofprefix update hota
rhega and wha se poore trie me jitne bhi suggestions milenge, use print kr denge
- T.C. : m words k liye har 1 char : n*m check krna to O((n*m)*(m))
- S.C : O(m*n)
- m : avg. word length and n : no. of entries
*/

void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix) {
  if (curr->isTerminal) {
    temp.push_back(prefix);
  }

  for (char ch = 'a'; ch <= 'z'; ch++) {
    TrieNode *next = curr->children[ch - 'a'];
    if (next != NULL) {
      prefix.push_back(ch);
      printSuggestions(next, temp, prefix);
      prefix.pop_back();
    }
  }
}

vector<vector<string>> getSuggestions(string str, Trie *t) {
  TrieNode *prev = t->root;
  vector<vector<string>> output;
  string prefix = "";

  for (int i = 0; i < str.length(); i++) {
    char last_ch = str[i];
    prefix.push_back(last_ch);

    // check for last_ch :
    TrieNode *curr = prev->children[last_ch - 'a'];

    // if not found :
    if (curr == NULL) {
      break;
    }

    // if found :
    vector<string> temp;
    printSuggestions(curr, temp, prefix);

    output.push_back(temp);
    temp.clear();
    prev = curr;
  }
  return output;
}

vector<vector<string>> phoneDirectory(vector<string> &contactlist,string &queryStr) {
  Trie *t = new Trie();

  // insert all contacts in trie :
  for (int i = 0; i < contactlist.size(); i++) {
    string str = contactlist[i];
    t->insertInTrie(str);
  }

  // return ans :
  return getSuggestions(queryStr, t);
}