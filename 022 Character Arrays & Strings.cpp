#include<iostream>
using namespace std;


int  main(){

//char array is string
char ch[20];
cin>>ch;
cout<<ch<<endl;

//at the end there will be a null character attached '\0' to note the ending of a string
//if there are multiple null characters are there then the 1st null character will be considered as an ending point of the string

char ech[20] = "rachit";
// ech[2]='\0';
cout<<ech;

//length of a string function
int getLength(char ech[]){
int i=0;
for(i=0;ech[i]!='\0';i++){
}
return i;
}

//reverse a string
void reverseString(vector<char>& s) {
    int st=0,e=s.size()-1;
    while(st<e){
        swap(s[st++],s[e--]);
    }
}

//string palindrome with special characters involved
#include <bits/stdc++.h> 

char tolower(char a){
    if(a >= 'a' && a<= 'z'){
        return a;
    }

    else{
        a = a-'A'+'a';
        return a;
    }
}


bool checkPalindrome(string s)
{
    int st = 0 ;
    int e = s.size()-1 ;
    while (st <= e){
        if(isalnum(s[st]) && isalnum(s[e])){
            if(tolower(s[st])==tolower(s[e])){
                st++;e--;
            }

            else if(s[st]!=s[e])
            return 0;
        }

        else{
            if(!isalnum(s[st])) 
            st++;

            if(!isalnum(s[e]))
            e--;
        }
    }
    return 1;
}

//valid palindrome
class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}
};


// STRINGS
//reverse the order of words in a string
string reverse(string s,int st,int e){
while(st<=e){
    swap(s[st],s[e]);
    st++;e--;
}
return s;
}

string s = "Rachit Joshi";

//poori string ko reverse kar diya
s=reverse(s,0,s.length()-1);


//ab ek ek word ko reverse karna hain 
int st=0;
int e=s.length();
for(int i=0;i<=e;i++){
    if((s[i]==' ')||(s[i]=='\0')){
        s=reverse(s,st,i-1);
        st=i+1;
}
}
cout<<s;



//maximum occuring character in a string
#include<bits/stdc++.h>

char highestOccurringChar(char arr[]) {
    int cnt[26]={};
    for(int i=0;arr[i]!='\0';i++){
        int temp=arr[i];
        cnt[temp-'a']++;               
    }

int max=cnt[0];
int j=0;
for(int i=0;i<26;i++){ if(cnt[i]>max){max=cnt[i];j=i;}}
    char ans=j+'a';
    return ans;
}


// remove all occurences of a substring
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part) <s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};


// Permutation in string 
// first principle code
class Solution {
public:

    bool arreq(int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]) return 0;
        }
        return 1;
    }

    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length()) return 0;

        int count1[26]={};
        for(int i=0;i<s1.length();i++){
            count1[s1[i]-'a']++ ;
        }
        
        for(int i=0;i<=s2.length()-s1.length();i++){
            int count2[26]={};
            for(int j=i;j<s1.length()+i;j++){
                count2[s2[j] - 'a']++ ;
            }
            if(arreq(count1,count2)) return 1;
        }

        return 0;
    }
};

//optimised with usage of STL
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26),c2(26);
        for(char c:s1) c1[c-'a']++ ;
        for(int i=0;i<s2.length();i++) {
            c2[s2[i]-'a']++ ; 
            if(i >= s1.length()) c2[s2[i-s1.length()]-'a']-- ;
            if(c1 == c2) return 1;
        }
        return 0; 
    }
};


//Remove All Adjacent Dupplicates
// 1) using stack operations
class Solution {
public:
	string removeDuplicates(string s) {

		string ans;
		ans.push_back(s[0]);

		for(int i=1 ; i<s.length() ; i++){

			if(!ans.empty() && s[i] == ans.back()){
				ans.pop_back();
			}
			else{
				ans.push_back(s[i]);
			}
		}

		return ans;
	}
};

// 2) in a single run using 2 variables
class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size(),i=0;
        for(int j=0;j<n;++i,++j){
            s[i]=s[j];
            if(i>0 and s[i-1]==s[i])
                i-=2;
        }
        return s.substr(0,i);
    }
};



// String Compression
// 1) Basic Principle Code
class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,store=0;
        while(i<chars.size()){
            int count =1;
            while(i+count<chars.size() && chars[i+count]==chars[i]){
                count++ ;
            }
            chars[store++] = chars[i] ;

            if(count > 1) {
                for(char c: to_string(count)){
                    chars[store++] = c ;
                }
            }
            i+=count ;   
    }
    return store;
    }
};




//2) Optimised code by usage of STL
class Solution {
public:
    int compress(vector<char>& chars) {
	int i = 0;
	for(int j = 1, count = 1; j <= chars.size(); j++, count++) {
		if(j == chars.size() || chars[j] != chars[j - 1]) {
			chars[i++] = chars[j - 1];  
			if(count >= 2) 
				for(char digit : to_string(count)) 
					chars[i++] = digit;
			count = 0;
		}
	}
	return i;
}
};






return 0;
}