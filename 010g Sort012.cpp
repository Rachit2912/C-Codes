//Sort 012
//1st Sum Approach

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
    int s=0,o=0,n=nums.size();
    for(int i=0;i<n;i++){
      s+=nums[i];
      if(nums[i]==1){o++;}
    }

   int t=s-o;
   int z=n-o-(t/2);

   for(int i=0;i<n;i++){
      if(i<z){nums[i]=0;}
      else if(i>=z && i<z+o){nums[i]=1;}
      else{nums[i]=2;}
   }
    }
};



//2nd index approach
class Solution {
public:
void sortColors(vector<int>& nums) {
vector counts(3,0);
for(int i=0;i<nums.size();i++){
counts[nums[i]]+=1;
}
int j=0;
for(int i=0;i<3;i++){
while(counts[i]!=0){
nums[j] = i;
counts[i]--;
j++;
}
}
}
};



//3rd 3pointer approach/ 3 way partitioning
class Solution {
public:

    void sortColors(vector<int>& nums) {
        int i=0,p=0,h=nums.size()-1;
        while(i<=h){
            if(nums[i]==0){
                swap(nums[i],nums[p]);
                p++;i++;
            }

            else if(nums[i]==2){
                swap(nums[i],nums[h]);
                h--;
            }

            else if(nums[i]==1){
                i++;
            }
        }
    }
};
