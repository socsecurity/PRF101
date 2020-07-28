#include <stdio.h>
#include <windows.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

int snt[100000];

//"a" = append(Write continue from last)
//"w" = write from begin
//"r+" = "w+" = write + read
void menu(); // menu
void init();

void interupt(){
    printf("Press Enter to continue...");
    while (getchar()==1); getchar();
}

void gotoxy(int x, int y){
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

int sntf(int n, int nums[]){
    for (int i=0; i<n; i++ ){
        if (snt[nums[i]]==1) return i;
    }
    return -1;
}

void inputdata(int *n,int nums[]);//----------------------------------------------------------1
void getData(char* fname,int *n,int nums[]);//default-----------------------------------------0
void update(char *fname, int n, int nums[]);//default-----------------------------------------0
int sumAll(int n, int nums[]);//Tong - Ha//---------------------------------------------------3
int numsofOdd(int n, int nums[]);// So Le - Ha------------------------------------------------10
double averageAll(int n, int nums[]);//Trung binh cong -Ha------------------------------------9
int songuyento(int n, int nums[]);//So nguyen to- Cam-----------------------------------------11
void sortA(int nums[25],int l,int r);//Sort Ascending-done (Sort tang) - Cam------------------7
void sortD(int nums[25],int l,int r);//Sort Decreasing-done (Sort giam) - Cam-----------------8
int searchP(int n, int nums[], int x);//Search Position(s) of 1 num-Quan----------------------6
void print(int n, int nums[]);//print to Screen-Quan------------------------------------------2
void rmNum(int *n, int nums[], int key);//Remove the number(s)-Quan---------------------------5
void addNum(int *n, int nums[], int pos, int x);//Add the num(s)-Quan-------------------------4

int main(){
    ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
    FILE* f = fopen("log.txt", "a");
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    fprintf(f, "Time when use Program: %s", asctime(timeinfo));
    int n=0,choose=0, resinINT;
    double resinDOU;
    int x, pos;
    char inp[] = "database.txt", save;
    int nums[10000];
    getData(inp, &n, nums);
    do
    {
        system("cls");
        menu();
        init();
        fflush(stdin);
        scanf("%d",&choose);
        fprintf(f, "Choosen: %d\n", choose);
        switch (choose){
        case 1:
            inputdata(&n, nums);
            break;
        case 2:
            print(n, nums);
            break;
        case 3:
            resinINT = sumAll(n, nums);
            printf("Result is %d\n", resinINT);
            fprintf(f,"Result is %d\n", resinINT);
            break;   
        case 4:
            
            printf("Nhap so muon chen: ");
            fflush(stdin);
            scanf("%d", &x);
            do{
                printf("Nhap vi tri muon chen: ");
                fflush(stdin);
                scanf("%d",&pos);
                if (pos>n||pos<0) printf("Yeu cau nhap lai\n");
            } while (pos>n||pos<0);
            addNum(&n, nums, pos, x);
            printf("Done!\n");
            break;   
        case 5:
            do{
                printf("Nhap vi tri muon xoa: ");
                fflush(stdin);
                scanf("%d", &pos);
                if (pos>n||pos<0) printf("Yeu cau nhap lai\n");
            } while (pos>n||pos<0);
            rmNum(&n, nums, pos);
            break;   
        case 6:
            printf("So nguyen x can tim la: ");
            fflush(stdin);
            scanf("%d", &x);
            searchP(n,nums,x);
            break;   
        case 7:
            sortA(nums, 0, n-1);
            printf("Done!\n");
            break;   
        case 8:
            sortD(nums, 0, n-1);
            printf("Done!\n");
            break;   
        case 9:
            resinDOU = averageAll(n, nums);
            printf("Result is %0.4lf\n", resinDOU);
            fprintf(f,"Result is %0.4lf\n", resinDOU);
            break;    
        case 10:
            numsofOdd(n,nums);
            break;
        case 11:
            songuyento(n,nums);
            break;  
        default:
            break;
        }
        if (choose>0 && choose<12) interupt();
    } while (choose>0 && choose<12);
    gotoxy(27, 16);
    printf("Do you want to save ?(Y/n); ");
    fflush(stdin);
    scanf("%c", &save);
    if (save=='Y' || save == 'y') update(inp, n, nums);
    fclose(f);
    system("cls");
    gotoxy(50, 13);
    printf("Have a nice day!");
    while (getchar()==1); getchar();
    return 0 ;
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
    gotoxy(23, 1);
    printf("%s\n","----------------------PROGRAM CONTROL LIST OF NUMBERS----------------------");
    gotoxy(23, 2);
    printf("%s\n","|| 1.Input data from keyboard");
    gotoxy(23, 3);
    printf("%s\n","|| 2.Print to Screen");
    gotoxy(23, 4);
    printf("%s\n","|| 3.Sum of All");
    gotoxy(23, 5);
    printf("%s\n","|| 4.Add a number");
    gotoxy(23, 6);
    printf("%s\n","|| 5.Remove a number");
    gotoxy(23, 7);
    printf("%s\n","|| 6.Search Position of number");
    gotoxy(23, 8);
    printf("%s\n","|| 7.Sort Ascending\n");
    gotoxy(23, 9);
    printf("%s\n","|| 8.Sort Decreasing");
    gotoxy(23, 10);
    printf("%s\n","|| 9.Average of All");
    gotoxy(23, 11);
    printf("%s\n","|| 10.Num of Odds");
    gotoxy(23, 12);
    printf("%s\n","|| 11.Num of primes");
    gotoxy(23, 13);
    printf("%s\n","|| 12.Exit.");
    gotoxy(23, 14);
    printf("%s\n","---------------------------------------------------------------------------");
    gotoxy(23+10, 15);
    printf("%s","Choose: ");
}

void getData(char* fname,int *n, int nums[]){
    FILE* f = fopen(fname, "r");
    if (f!=NULL){
        while (fscanf(f, "%d", &nums[(*n)++])==1);
    fclose(f);
    }
    (*n)--;
}

void update(char* fname,int n, int nums[]){
    FILE* f = fopen(fname,"w");
    for (int i=0; i<n; i++){
        fprintf(f, "%d ", nums[i]);
    }
    fclose(f);
}

void inputdata(int *n,int nums[]){
    int ch, n1, i=(*n);
    printf("  1.Input from start\n  2.Input data continue\n  Choose; ");
    fflush(stdin);
    scanf("%d", &ch);
    if (ch==1) (i) = 0;
    printf("    Input n: ");
    fflush(stdin);
    scanf("%d", &n1);
    (*n) = i+ n1;
    for (int j=i; j < i+n1; j++){
        fflush(stdin);
        printf("    Num %d(th): ", j+1);
        scanf("%d", &nums[j]);
    }
    printf("Done!\n");
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

int songuyento(int n, int nums[]){
    int count=0, c = sntf(n,nums);  
    printf("Find ""snt"" from list; \n");
    if (c<=-1) printf("None!\n");
    else
        for (int i=0; i<n; i++ ){
            if (snt[nums[i]]==1){
                count++;
                printf("%d(Pos: %d)\n", nums[i], i);
            }
        }
    return count;
}

int sumAll(int n, int* nums){
    int s=0;
    for (int i=0; i<n;i++) s +=nums[i];
    return s;
}

int numsofOdd(int n, int nums[]){
    int count=0, a[1000];
    for (int i=0; i<n; i++ ){
        if (nums[i]%2==1){
            a[count++]=i;
        } 
    }
    printf("Have %d odd(s): ", count);
    for (int e = 0; e< count ; e++) printf("%d ", nums[a[e]]);
    printf("\n");
    return count;
}

double averageAll(int n, int nums[]){
    return (double)sumAll(n,nums) / (double) n;
}

int searchP(int n, int nums[], int x){
    for(int i=0; i<n; i++){
        if(nums[i]==x)  {
            printf("Position of X is %d!\n", i+1);
            return i;
        }
    }
    printf("No exist!\n");
    return -1;
}

void print(int n, int nums[]){
    int i;
    printf("Have %d nums: ", n);
    for(i=0; i<n; i++){
        printf("%-5d", nums[i]);
    }
    printf("\n");
}

void rmNum(int* n, int nums[],int pos){
    if(pos-1>=0 && pos-1<*n){
        for(int i=pos-1; i<*n; i++){
            nums[i]=nums[i+1];
        }
    (*n)--;
    }
}

void addNum(int *n, int nums[], int pos, int x){
    *n=*n+1;
    for(int i=*n; i>(pos-1); i--){
        nums[i] = nums[i-1];
    }
    nums[pos-1]=x;
    printf("Done!\n");
}