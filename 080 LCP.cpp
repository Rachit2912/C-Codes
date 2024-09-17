#include <iostream>
#include <string>
#include <vector>
#include <xerrc.h>
using namespace std;

// LONGEST COMMON PREFIX :
/*
- an array of strings is given & we have to find longest common prefix amongst
them
- approach #1 : brute force :
- pehle string uthalo and uske hr 1 char. ko baaki sbhi strings me compare krdo
and dekhlo
- agr h to ans me add krdo nhi to break
- T.C : O(m*n)
- S.C: O(m)
*/

string longestCommonPrefix(vector<string> &arr, int n) {
  string ans = "";
  for (int i = 0; i < arr[0].length(); i++) {
    char ch = arr[0][i];

    bool match = true;

    for (int j = 1; j < n; j++) {
      if (arr[j].size() < i || ch != arr[j][i]) {
        match = false;
        break;
      }
    }

    if (match == false) {
      break;
    } else {
      ans.push_back(ch);
    }
  }
  return ans;
}


/*
- approach 2 : using tries:
- insert all strings in a trie 
- jha tk no(childs) == 1 ho wha tk apna ans h 
- T.C : O(m*n)
- S.C : O(m*n)
*/

class TrieNode{
    public:
    char data ;
    TrieNode* children[26];
    int childCount ; 
    bool isTerminal ;

    TrieNode(char ch ){
        data = ch;
        for (int i =0; i<26; i++) {
            children[i] = NULL;
        }
        childCount =0 ;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root ;

    Trie(char ch){
        root = new TrieNode(ch);
    }

    // insertion :
  void insertInTrie_rcrsn(TrieNode *root, string word) {

    // base case : word completion
    if (word.length() == 0) {
      root->isTerminal = true;
      return;
    }

    // assumption : word will be in UPPERCASE :
    int index = word[0] - 'a';
    TrieNode *child;

    // present h :
    if (root->children[index] != NULL) {
      child = root->children[index];
    }

    // absent :
    else {
      child = new TrieNode(word[0]);
      root->children[index] = child;
      root->childCount++ ;
    }

    // recursive step :
    insertInTrie_rcrsn(child, word.substr(1));
  }

  // insertion main fn. :
  void insertInTrie(string word) { insertInTrie_rcrsn(root, word); }


  // longest common prefix :
  void lcp(string str, string &ans){
    for (int i = 0; i<str.length(); i++) {
        char ch = str[i];
        if (root->childCount == 1) {
            ans.push_back(ch);

            // aage bdho : 
            int index = ch - 'a';
            root = root->children[index];
        }
        else {
            break;
        }

        if (root->isTerminal) {
            break;
        }
    }
  }
};

string longestCommonPrefixapp2(vector<string> &arr, int n){

    Trie *t = new Trie('\0');

    // insert krdo all strings in trie : 
    for (int i = 0; i<n; i++) {
        t->insertInTrie(arr[i]) ;
    }

    string first = arr[0];
    string ans = "";
    
    t->lcp(first, ans);
    return ans;

}