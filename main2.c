//gcc main2.c
//./a.exe
// this was my first project ever though it has less features than the C++ verions i thought might as well add it here :)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void hotel(int n1,int n2,int *B);
void yesorno(int n1,int n2,int *a,int *b,int A[n1][n2]);
int booking(int n1,int n2,int A[n1][n2],int *a,int *b);
void alreadyoc(int *a,int *b,int n1,int n2,int A[n1][n2]);
void available(int n1,int n2,int A[n1][n2]);
int notoc(int *a,int *b,int n1,int n2,int A[n1][n2]);

int main(){
int n1,n2,*c,B[2],ch[4];
int *a,*b,q,p;
a=&p;
b=&q;
hotel(n1,n2,B);
n1=B[0];
n2=B[1];
int A[n1][n2];
for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        A[i][j]=0;
    }
}
booking(n1,n2,A,a,b);
}
void hotel(int n1,int n2,int *B){
printf("Enter the number of floors in the hotel : ");
scanf("%d",&n1);
printf("Enter the number of rooms per floor : ");
scanf("%d",&n2);
B[0]=n1;
B[1]=n2;
}
int booking(int n1,int n2,int A[n1][n2],int *a,int *b){
printf("Enter the floor number in which you want to book a room(slect from 1 - %d) : ",n1);
scanf("%d",a);
*a=*a-1;
printf("enter the room numer you want to book(room number starts from 1 - %d) : ",n2);
scanf("%d",b);
*b=*b-1;
alreadyoc(a,b,n1,n2,A);
notoc(a,b,n1,n2,A);
}
int notoc(int *a,int *b,int n1,int n2,int A[n1][n2]){
    if(A[*a][*b]==0){
        A[*a][*b]=1;
        printf("Thank you! You have successfully booked the following room :\n");
        printf("%d floor %d room\n\n",*a+1,*b+1);
    }
    yesorno(n1,n2,a,b,A);
}
void yesorno(int n1,int n2,int *a,int *b,int A[n1][n2]){
    printf("do you want to book more rooms? (type: yes or no) : \n");
    fflush(stdin);
    char ch[5];
    char chh='a';
    fgets(ch,5,stdin);
    char yes[5]="yes\n\0";
    char no[4]="no\n\0";
     int q=strcmp(no,ch);
    int p=strcmp(yes,ch);
    if(p==0){
         booking(n1,n2,A,a,b);
    }
   
    else if(q==0){
        printf("thank you for booking! enjoy a great stay!");
        exit(0);
    }
    else{printf("wrong word dude\n");
    }
}
void alreadyoc(int *a,int *b,int n1,int n2,int A[n1][n2]){
    if(A[*a][*b]==1){
        printf("That is already occupied please try another room \n");
     available(n1,n2,A);
     booking(n1,n2,A,a,b);
    }
}
void available(int n1,int n2,int A[n1][n2]){
    printf("the available rooms are : \n");
    int x=0;
for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        if(A[i][j]!=1){
            x++;
            printf("in %d floor %d room is available \n",i,j);
        }
    }
}
if(x==0){
    printf("No Rooms are available! \nSorry there are no available rooms the moment right now! (thank you for using my code !)");
    exit(0);
}
}
