#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

void powerSet(vector<int> nums, vector<int> output, int i, vector<vector<int>> &ans){

        // base case :
        if(i >= nums.size()) {
           ans.push_back(output);
            return;
        }

       // exclusion : 
       powerSet(nums,output,i+1,ans);

       // inclusion :
       int selectedElement = nums[i]; 
       output.push_back(selectedElement);
       powerSet(nums,output,i+1,ans);

}


void subsequences(string str, string output, int index, vector<string>& ans){
    
    // base case :
    if(index >= str.length()){
        ans.push_back(output);
        return;
    }

    // exclusion :
    subsequences(str, output, index+1, ans);

    // inclusion :
    char element = str[index];
    output.push_back(element);
    subsequences(str, output, index+1, ans);

}





int main() {

// making power set of a given set using recursion
/*
isme poora game include and exclude ka hai 
start me poora array or empty set lenge jo ki aapka i/p and o/p array hoyega respectively 
usme 1 baar first element include karenge or 1 baar exclude karenge
uske baad unn 2 cases ke andar next wale element ko include and exclude karenge jisse ki total 4 cases banenge
or aise hi chalta rahega jab tak ki poora array traverse na karle jo ki recursion se solve ho jayega  
isse saare cases cover ho jayenge or poora power set ban jayega 

*


vector<int> nums ={13,5,77};   // i/p array 

vector<vector<int>> ans;    // final ans. array
vector<int> output;     // o/p array 
int i = 0;          // index
powerSet(nums,output,i,ans);       // fn. called 

// printing the elements of ans. array 
cout<< "Power set is : " ;
  for (int i = 0; i < ans.size(); i++) 
    { 
        for (int j = 0; j < ans[i].size(); j++) 
        { 
            cout << ans[i][j] << " "; 
        }     
        cout << endl; 
    } 
cout<< endl;



// subsequences of string 
/*
same as power set of a string 
like str = 'abc' : then sub sequences of str will be : {},a,b,c,ab,bc,ca,abc
approach will be same as inclusion and exclusion principle for power set 
*/

string str = "abc" ;
string output = "";
int i = 0;
vector<string>ans;
subsequences(str, output, i,ans);

// printing the elements of ans. array 
cout<< "Subsequences are : " ;
  for (int i = 0; i < ans.size(); i++) 
    { 
        for (int j = 0; j < ans[i].size(); j++) 
        { 
            cout << ans[i][j] << " "; 
        }     
        cout << endl; 
    } 
cout<< endl;


return 0;
}