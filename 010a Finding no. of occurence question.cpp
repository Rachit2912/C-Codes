//MY value inside index approach
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

// MY general brain algo
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int s=arr.size();
        int c[1000]={0};
        for(int i=0;i<s;i++){
    if(i!=s-1){
    if((-1001<arr[i]) && (arr[i]<1001)){
        for(int j=i+1;j<s;j++){
            if(arr[i]==arr[j]){
                c[i]++;
                arr[j]=1002;
            }
        }
    }
    else{c[i]=1024;}
    }
else{
    if((-1001<arr[i]) && (arr[i]<1001)){
    }
    else{c[i]=1024;}
}
}
int flag=1;
for(int i=0;i<s-1;i++){
    if(c[i]!=1024){
    for(int j=i+1;j<s;j++){
        if(c[i]==c[j]){
            flag=0;
        }
    }
    }
}
if(flag){
    return true;
}
else{
    return false;
}
}
};