#include <iostream>
#include <string>
#include <vector>
using namespace std;

// permutations of a string 
/*
print all permutations like str = "abc" 
then its permutations will be abc,acb,bca,bac,cba,cab

isme 1 index lenge jo sbki positions note krta rhega 
phir vo jaha pr hoga wha se 1-1 krke saare characters swap krta rhega and yhi process recursively chlta rhega and index++ hota rhega and at the end jb index end me hoga tb sb end ho jayega 
*/

void Strperm(string str,vector<string>& ans,int index){

    // base case :
    if (index >= str.length()){
        ans.push_back(str);
        return ;
    }

    // recursive call : 
    for (int i=index;i<str.length();i++){
        swap(str[index],str[i]);
        Strperm(str,ans,index+1);
        swap(str[index],str[i]);
    }
    
}



int main() {
string str = "abc";
int index = 0;
vector<string> ans;
Strperm(str,ans,index);

for (auto i: ans) cout << i << endl;




return 0;
}