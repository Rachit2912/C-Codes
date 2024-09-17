#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int main() {

  // HASHMAPS :
  /*
    - T.C. wise it is a widely used d.s for insertion, deletion, etc.
    - it is used for key-value pair storage and mapping purposes
    - 2 types: map O(log(n)) :bst pr base hota h and order preserve rhta h
     and unordered map O(1) : hashtable pr based hota h but order random hota h
    - unordered_map<key,value> name;
  */

  unordered_map<string, int> m;
  // insertion k tarike :
  // 1. pair bnake
  pair<string, int> p = make_pair("rachit", 7);
  m.insert(p);
  pair<string, int> q("rj", 29);
  m.insert(q);

  // 2. directly
  m["mera"] = 1;

  // first baar creation hoga then updation hi hoga only

  // searching :
  cout << m.at("rachit") << endl;
  cout << m["mera"] << endl;

  cout << m.at("unknown_key") << endl;
  // ye chiz error degi bcz ye key mapping me kahi h hi nhi
  cout << m["unknown_key"] << endl;
  // pr ye chiz ek nyi entry bna legi for this specific key and it'll map this
  // key to 0

  // size checking :
  cout << m.size() << endl;

  // to check if a key is there or not :
  cout << m.count("bro") << endl;
  // 0 for absence and 1 for presence

  // erase :
  m.erase("mera");

  // iteration :
  // for loop :
  for (auto i : m) {
    cout << i.first << " " << i.second << endl;
  }

  // using iterator :
  unordered_map<string, int>::iterator it = m.begin();
  while (it != m.end()) {
    cout << it->first << " " << it->second << endl;
    it++;
  }

  // bucket array : jis array me key value pairs store hote h

  // HASH FUNCTIONS : combination of hash code and compression fn.
  // hash code : different type of d.s. ko map krne k lye in an array jo fn. use
  // hota h vo compression fn. : to map hash code to array index

  // COLLISION :
  // jb 2 diff. chize 1 hi index pr bethne jaye ya map hone jaye tb collision
  // hoga collision handling : (i) closed hashing : ll se jod do sbko or uss
  // index pr ll ka head aa jayega (ii) open addressing : next vacant jgh pr dal
  // do later wali chiz ko linear probing : isme fn. linearly add hota rhta h
  // quadratic probing : isme fn. square ya power 2 se add hota rhta h

  // COMPLEXITY ANALYSIS :
  // if total no. of words is 'n' and word length is 'k' then it'll take O(k)
  // but we assume that n>>k then it'll become O(1) n : total no. of mappings ;
  // b : boxes available in array n/b : load factor ; we try to keep it less
  // than 0.7

  return 0;
}

// MAX FREQUENCY NUMBER :
int maximumFrequency(vector<int> &arr, int n) {
  unordered_map<int, int> count;
  int maxFreq = 0;
  int maxAns = 0;

  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
    maxFreq = max(maxFreq, count[arr[i]]);
  }

  for (int i = 0; i < n; i++) {
    if (maxFreq == count[arr[i]]) {
      maxAns = arr[i];
      break;
    }
  }

  return maxAns;
}