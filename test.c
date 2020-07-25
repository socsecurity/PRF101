#include <stdio.h>

void sortE(int nums[25],int l,int r){
    int i, j, pivot, temp;
    if(l<r){
        pivot=l;
        i=l;
        j=r;
        while(i<j){
            while(nums[i]>=nums[pivot]&&i<r) i++;
            while(nums[j]<nums[pivot]) j--;
            if(i<j){
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
        temp=nums[pivot];
        nums[pivot]=nums[j];
        nums[j]=temp;
        sortE(nums,l,j-1);
        sortE(nums,j+1,r);
    }
}
int main(){
    int nums[25] = {1,3,2,5,3,7,4,2,1,3};
    int n = 10;
    sortE(nums,0,n-1);
    for (int i =0; i<n;i++) printf("%d ", nums[i]);
    return 0;
}
