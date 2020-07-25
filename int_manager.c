#include <stdio.h>

int snt[100000];

//"a" = append(Write continue from last)
//"w" = write from begin
//"r+" = "w+" = write + read
void menu(); // menu
void init();

int sntf(int n, int nums[]){
    for (int i=0; i<n; i++ ){
        if (snt[nums[i]]==1) return i;
    }
    return -1;
}

void inputdata(int *n,int nums[]);//----------------------------------------------------------------------------
void getData(char* fname,int *n,int nums[]);//default-done//-------------------------------------------------------
void update(char *fname, int n, int nums[]);//default-done//--------------------------------------------------
int sumAll(char *fname, int n, int nums[]);//func1: Tong - Ha
int numsofOdd(char *fname, int n, int nums[]);//func2: So Le - Ha
int numsofEven(char *fname, int n, int nums[]);//func3: So Chan - Ha
int averageAll(char *fname, int n, int nums[]);//func4: Trung binh cong -Ha
int songuyento(char *fname, int n, int nums[]);//func5: So nguyen to- Cam------------------------
void sortA(int nums[25],int l,int r);//func6: Sort Ascending-done (Sort tang) - Cam---------------
void sortD(int nums[25],int l,int r);//func7: Sort Decreasing-done (Sort giam) - Cam-------------------
void searchP(char *fname, int n, int nums[], int key);// func8: Search Position(s) of 1 num-Quan
void print(int n, int nums[]);//func9: print to Screen-Quan
void rmNum(char *fname, int *n, int nums[], int key);//func10: Remove the number(s)-Quan
void addNum(char *fname, int *n, int nums[]);//func11: Add the num(s)-Quan

int main(){
    int n=0,choose;
    char inp[] = "database.txt";
    char log[] = "log.txt";
    int nums[10000];

    do
    {
        menu();
        scanf("%d",&choose);
        switch (choose){
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;   
        case 4:
            /* code */
            break;   
        case 5:
            /* code */
            break;   
        case 6:
            /* code */
            break;   
        case 7:
            /* code */
            break;   
        case 8:
            /* code */
            break;   
        case 9:
            /* code */
            break;    
        case 10:
            /* code */
            break;
        case 11:
            /* code */
            break;
        case 12:
            /* code */
            break;
        case 13:
            /* code */
            break;   
        case 14:
            /* code */
            break;   
        default:
            break;
        }
    } while (choose>0 && choose<17);
    

    getData(inp, &n, nums);
    update(inp, n, nums);
    return 0;
}


void init(){
    snt[0]=0;
    snt[1]=0;
    for (int i=2;i<100000; i++) snt[i] =1; 
    for (int i=2; i<100; i++ ){
        if (snt[i]==1){
            for (int j=2; j<100; j++) snt[i*j] = 0;
        }
    }
}
void menu(){
    
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

void inputdata(int *n,int nums[]){
    int ch, n1, i=++(*n);
    printf("1.Input from start\n2.Input data continue\nChoose; ");
    scanf("%d", &ch);
    if (ch==1) (i) = 0;
    printf("Input n: ");
    scanf("%d", n1);
    (*n) = i+ n1;
    for (int j=i; j < i+n1; j++){
        scanf("%d", &nums[j]);
    }
    printf("------------DONE--------------\n");
}


void sortA(int nums[25],int l,int r){
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
        sortA(nums,l,j-1);
        sortA(nums,j+1,r);
    }
}

void sortD(int nums[25],int l,int r){
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
        sortD(nums,l,j-1);
        sortD(nums,j+1,r);
    }
}

int songuyento(char *fname, int n, int nums[]){
    int count=0, c = sntf(n,nums);
    FILE* f = fopen("log.txt", "a");
    fprintf(f,"Find ""snt"" from list; \n");
    printf(f,"Find ""snt"" from list; \n");
    if (c<=-1) printf("None!\n");
    else
        for (int i=0; i<n; i++ ){
            if (snt[nums[i]]==1){
                count++;
                printf("%d(Pos: %d)\n", nums[i], i);
                fprintf(f,"%d(Pos: %d)\n", nums[i], i);
            }
        }
    fclose(f);
    return count;
}
