#include <iostream>
#include <string>
#include <vector>
using namespace std;



// letter combinations of a keypad phone no.
/*
jese ki agar hm 23 type krenge on the the keypad phone then usse following combinations bn skte h : ad,ae,af,bd,be,bf,cd,ce,cf

isme same hi approach hi use krni h jo hm inclusion - exclusion wali use krte h vo
bss isme digit wise same approach use krni h 
like : 23 to pehle 2 lia usme include exclude krdo phir 3 pr aao usme phir include - exclude lgado to isse tumhare saare case include ho jayenge 
*/


void keypad(string digit, int index, string map[], string output, vector<string>& ans){
    
    if (digit.length() == 0) {
    return;
    }


    // base case :
    if (index >= digit.length()){
        ans.push_back(output);
        return;
        }

    // recursive call : 
    int num = digit[index] - '0';
    string mapValue = map[num];

    for(int i=0 ;i<mapValue.length(); i++){
        output.push_back(mapValue[i]);
        keypad(digit, index + 1, map, output, ans);
        output.pop_back();
    }

}

int main(){

string digit = "23";
int index = 0;
// keypad phone mapping 
string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
string output = "";
vector<string> ans;
keypad(digit,index,map,output,ans);

for (auto i: ans) cout << i << endl;

return 0;
}

