//Sort 012
//Sum Approach


//#include<stdio.h>
void sort012(int arr[], int n)
{
   int s=0,o=0;
   for(int i=0;i<n;i++){
      s+=arr[i];
      if(arr[i]==1){o++;}
   }
   printf("%d\n",s);
   int t=s-o;
   int z=n-o-(t/2);
   printf("z is %d, o is %d, t is %d\n",z,o,t/2);

   for(int i=0;i<n;i++){
      if(i<z){arr[i]=0;}
      else if(i>=z && i<z+o){arr[i]=1;}
      else{arr[i]=2;}
   }
   
   for(int i=0;i<n;i++){
      printf("%d ",arr[i]);

      }   }

int main() {
   int arr[10]={0,1,1,2,2,0,1,1,2,0};
    sort012(arr,10);
}
