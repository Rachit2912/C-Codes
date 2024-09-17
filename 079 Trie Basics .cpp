#include <cstddef>
#include <iostream>
using namespace std;

/*
TRIE :
- it's like a tree only with a root and many child
- agr 1 new word add krna h to, hm char. by char. jayenge or root se start
krenge jo char. already hoga usko skip krke next pr jayenge and jo char.
available nhi hoga usko whi k whi create kr denge
- to is d.s. me : data, child[26] & isTerminal dalna pdega bcz manlo 'time' word
dala h isme & search krte waqt hmne pucha ki 'tim' h kya isme to vo toh haa keh
dega
- islye terminal node h ya nhi h ye pta hona chahiye hme
- T.C : O(length of word ) for inserting and searching and removal also

- removal of a word :
- last char. tk jao or uska isTerminal ko false krke ajao

*/

// trieNode class :
class TrieNode {
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char ch) {
    data = ch;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

// trie class for insertion and searching :
class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode('\0'); }

  // insertion :
  void insertInTrie_rcrsn(TrieNode *root, string word) {

    // base case : word completion
    if (word.length() == 0) {
      root->isTerminal = true;
      return;
    }

    // assumption : word will be in UPPERCASE :
    int index = word[0] - 'A';
    TrieNode *child;

    // present h :
    if (root->children[index] != NULL) {
      child = root->children[index];
    }

    // absent :
    else {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    // recursive step :
    insertInTrie_rcrsn(child, word.substr(1));
  }

  // insertion main fn. :
  void insertInTrie(string word) { insertInTrie_rcrsn(root, word); }

  // searching :
  bool searchInTrie_rcrsn(TrieNode *root, string word) {

    // base case : word completion :
    if (word.length() == 0) {
      return root->isTerminal;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    // present h next char. :
    if (root->children[index] != NULL) {
      child = root->children[index];
    }

    // absent h :
    else {
      return false;
    }

    // recursive step :
    return searchInTrie_rcrsn(child, word.substr(1));
  }

  // searching main fn. :
  bool searchInTrie(string word) { return searchInTrie_rcrsn(root, word); }

  // Function to check if the root has any children or not.
  bool trieEmpty(TrieNode *root) {
    for (int i = 0; i < 26; i++) {
      if (root->children[i]) {
        return false;
      }
    }
    return true;
  }

  // removal :
  TrieNode *trieDelete(TrieNode *root, string word, int height = 0) {

    // Condition if the tree is empty
    if (!root) {
      return NULL;
    }

    // The final character of the word is being handled
    if (height == word.size()) {

      /*
          After removal of the given word/key, the last node is
          not the end of the word
      */
      if (root->isTerminal) {
        root->isTerminal = false;
      }

      // In case if the given word isn't prefix of any other word
      if (trieEmpty(root)) {
        delete (root);
        root = NULL;
      }
      return root;
    }

    /*
        In case it is not the last character, repeat for the child using
        ASCII value
    */
    int index = word[height] - 'a';
    root->children[index] = trieDelete(root->children[index], word, height + 1);

    /*
        In case the root does not have any child(its only child gets
        removed), then it is not the same for another word. The another
        word does not end here.
    */
    if (trieEmpty(root) && root->isTerminal == false) {
      // Node deleted
      delete (root);
      root = NULL;
    }
    return root;
  }
};

int main() {

  Trie *t = new Trie();
  t->insertInTrie("ABCD");
  cout << "present or not \"ABCD\" : " << t->searchInTrie("ABCD") << endl;
  cout << "present or not \"ABCDW\" : " << t->searchInTrie("ABCDW") << endl;

  return 0;
}