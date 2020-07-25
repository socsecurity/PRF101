#include <stdio.h>

//"a" = append(Write continue from last)
//"w" = write from begin
//"r+" = "w+" = write + read
void menu(); // menu
void intructions(); // huong dan su dung
void getData(char* fname,int *n,int nums[]);//default-done
void update(char *fname, int n, int nums[]);//default-done
int sumAll(char *fname, int n, int nums[]);//func1: Tong - Ha
int numsofOdd(char *fname, int n, int nums[]);//func2: So Le - Ha
int numsofEven(char *fname, int n, int nums[]);//func3: So Chan - Ha
int averageAll(char *fname, int n, int nums[]);//func4: Trung binh cong -Ha
int* divisible(char *fname, int n, int nums[]);//func5: Chia het cho - Cam
void sortA(int nums[25],int l,int r);//func6: Sort Ascending-done (Sort tang) - Cam
void sortD(int nums[25],int l,int r);//func7: Sort Decreasing (Sort giam) - Cam
void searchP(char *fname, int n, int nums[], int key);// func8: Search Position(s) of 1 num-Quan
void print(int n, int nums[]);//func9: print to Screen-Quan
void rmNum(char *fname, int *n, int nums[], int key);//func10: Remove the number(s)-Quan
void addNum(char *fname, int *n, int nums[]);//func11: Add the num(s)-Quan
void backUp(char *fname, int n, int nums[]);//func12: Sao luu- Cam
void restore(char *fname, int *n, int nums[]);//func13: Khoi phuc-Cam

int main(){
    int n=0;
    char inp[] = "database.txt";
    char out[] = "database_1.txt";
    int nums[10000];

    getData(inp, &n, nums);
    update(inp, n, nums);
    return 0;
}

void getData(char* fname,int *n, int nums[]){
    FILE* f = fopen(fname, "r");
    if (f!=NULL){
        while (fscanf(f, "%d%*c", nums[(*n)])==1){
            (*n)++;
        }
    fclose(f);
    }
}

void update(char* fname,int n, int nums[]){
    FILE* f = fopen(fname,"w");
    for (int i; i<n; i++){
        fprintf(f, "%d ", nums[i]);
    }
    fclose(f);
}


void sortE(int nums[25],int l,int r){
    int i, j, pivot, temp;
    if(l<r){
        pivot=l;
        i=l;
        j=r;
        while(i<j){
            while(nums[i]<=nums[pivot]&&i<r) i++;
            while(nums[j]>nums[pivot]) j--;
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