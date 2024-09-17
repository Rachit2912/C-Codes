//Find duplicates in an array question

//XOR approach
int findDuplicate(vector<int> &arr) 
{
    // Write your code here
	 int x=0;

    //take the XOR of all elements of array and store it in variable 'x'
     for(int i=0;i<nums.size();i++){
         x=x^nums[i];
     }   

    //take the XOR of no. ranged from 1 to n-1 with x
    //so x contains no. 1 to n-1 and an duplicate no. 'd'
    //so when we'll perform the xor of x with each no. from 1 to n-1 
    //they'll produce the zero and 0^d=d
    
     for(int i=1;i<nums.size();i++){
         x=x^i;
     }
    return x;
    }


//my index approach
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int pv[2000]={0};  
        int occ[2000]={0};
        int s=arr.size();

        for(int i=0; i<s;i++){   
            arr[i]+=1000;
            pv[arr[i]]++;
        }

        for(int i=0;i<2000;i++){
            if(pv[i]){
                occ[pv[i]]++;
                if(occ[pv[i]]>1){
                    return false;
                }
            }
        }
        return true;
    }
};


