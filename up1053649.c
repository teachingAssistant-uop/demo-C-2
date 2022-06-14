#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500
#define H 1000

struct maxsubarray{
int leftpos;
int rightpos;
int maxcount;
};



unsigned int am = 1053649;
int arr1[N];
int arr2[H];
int start ;
int finish;
int i,j,k,l,m,s;
clock_t str,end ;
int count=0;
void N3(int arr[], int y);


void N2b(int arr[],int y);
void N2a(int arr[],int y);
void N1(int arr[],int y);
struct maxsubarray  NlogN(int arr[],int left,int right);
struct maxsubarray crossed(int arr[],int left,int m,int right);
int Max(int a , int b);
int Max3(int a,int b,int c);




int main(){

srand(am);

for( i=0;i<N;i++){

    arr1[i]=rand()%201 - 100;
}

for(i=0;i<H;i++){

    arr2[i]=rand()%201 - 100;
}
double timetaken;


str=clock();
N3(arr1,N);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("The time taken to execute N3 with %d elements is  %f\n",N,timetaken);
printf("The number of operations is %d\n\n",count);

str=clock();
N3(arr2,H);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("The time taken to execute N3 with %d elements is %f\n",H,timetaken);
printf("The number of operations is %d\n\n",count);


str=clock();
N2a(arr1,N);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("The time taken to execute N2a with %d elements is %f\n",N,timetaken);
printf("The number of operations is %d\n\n",count);

str=clock();
N2a(arr2,H);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("The time taken to execute N2a with %d elements is %f\n",H,timetaken);
printf("The number of operations is %d\n\n",count);



str=clock();
N2b(arr1,N);
end=clock()-str;
timetaken = ((double)end)/CLOCKS_PER_SEC;
printf("The time taken to execute N2b with %d elements is %f\n",N,timetaken);
printf("The number of operations is %d\n\n",count);

str=clock();
N2b(arr2,H);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("The time taken to execute N2b with %d elements is  %f\n",H,timetaken);
printf("The number of operations is %d\n",count);
printf("\n");


count=0;
str=clock();
struct maxsubarray array1=NlogN(arr1,0,N-1);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("               0(NlogN)              \n");
printf("start = %d finish = %d and maxcount = %d\n",array1.leftpos,array1.rightpos,array1.maxcount);
printf("The time taken to execute Nlogn with %d elements is  %f\n",N,timetaken);
printf("The number of operations is %d\n\n",count);


count=0;
str=clock();
struct maxsubarray array2=NlogN(arr2,0,H-1);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("               0(NlogN)              \n");
printf("start = %d finish = %d and maxcount = %d\n",array2.leftpos,array2.rightpos,array2.maxcount);
printf("The time taken to execute Nlogn with %d elements is %f\n",H,timetaken);
printf("The number of operations  is %d\n",count);
printf("\n");


str=clock();
N1(arr1,N);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("The time taken to execute N1 with %d elements is %f\n",N,timetaken);
printf("The number of operations is %d\n\n",count);


str=clock();
N1(arr2,H);
end= clock()-str;
timetaken=((double)end)/CLOCKS_PER_SEC;
printf("The time taken to execute N1 with %d elements is %f\n",H,timetaken);
printf("The number of operations is %d\n",count);


  return 0;
}

int Max(int a , int b){
count+=2;
if(a>b){
    return a;
}
return b;

}

int Max3(int a,int b,int c){
count++;
return Max(Max(a,b),c);

}

void N3(int arr[],int y){
count=0;
start=0;
finish=0;
m=0;
count+=4;
int maxcount= 0;
for( j=0;j<y;j++){
    count+=2;
    for( k=j;k<y;k++){
        s=0;
        count+=4;// ðåñéëáìâÜíåé êáé ôçí óýãêñéóç ôçò if  áðü êÜôù.
        for(l=j;l<=k;l++){
            s=s+arr[l];
            count+=3;

        }
        if(s>m){
            m=s;
            count+=4;
            start = j;
            finish= k;
            maxcount = m;
        }

    }

}
printf("               0(N^3)              \n");
printf("start = %d finish= %d and maxcount = %d\n",start,finish,maxcount);


}
void N2a(int arr[],int y){
    count =0 ;
    int z[y];
    int maxcount=0;
    z[0]=arr[0];
    count+=3;
    for(i=1;i<y;i++){
            count+=3;
                z[i]= z[i-1]+arr[i];

            }
    m=0;
    count++;
    for(j=0;j<y;j++){
            count+=2;
            for(k=j;k<y;k++){
                    count+=5;//ðåñéëáìâÜíåé üëåò ôéò ðñÜîåéò ðïõ èá åêôåëåóôïýí óßãïõñá óå áõôÞ ôç for loop
                if(j==0){
                    s=z[k];
                }else{
             s=z[k]-z[j-1];
                }

             if(s>m){
                m=s;
                count+=4;
                start = j;
                finish= k;
                maxcount=m;
             }

            }
    }
     printf("               0(N^2) with extra array             \n");
     printf("start = %d finish= %d and maxcount = %d\n",start,finish,maxcount);
}

void N2b(int arr[],int y){

    int maxcount=0;
    start=0;
    finish=0;
    count=0;
    int sum = 0;
    m=0;
    count+=5;
    for(j=0;j<y;j++){
            sum=0;
            count+=3;
            for(k=j;k<y;k++){

                sum = sum + arr[k];
                    count+=4;
                if(sum>m){
                    m=sum;
                    count+=4;
                    start = j;
                    finish= k;
                    maxcount=m;
                    }
                }
            }
     printf("               0(N^2) without extra array              \n");
     printf("start = %d finish= %d and maxcount = %d\n",start,finish,maxcount);

}


struct maxsubarray NlogN(int arr[],int left,int right){

struct maxsubarray ar1;
struct maxsubarray ar2;
struct maxsubarray ar3;

count+=4;
if(left==right){

        ar1.leftpos=left;
        ar1.rightpos=right;
        ar1.maxcount=arr[left];
        count+=4;
        return ar1;

     }
     int m=(left+right)/2;

    ar1=NlogN(arr,left,m);
    ar2=NlogN(arr,m+1,right);
    ar3=crossed(arr,left,m,right);
    count+=4;
    int max=Max3(ar1.maxcount,ar2.maxcount,ar3.maxcount);
    count+=2;
    if(max==ar1.maxcount){
            count++;
        return ar1;
    }
    count++;
    if(max==ar2.maxcount){
        count++;
        return ar2;
    }
    count++;
    return ar3;


}
struct maxsubarray crossed(int arr[],int left,int m,int right){
struct maxsubarray ar1;

int sum=0;
int i;
int left_sum = 0;
count+=4;
    for ( i = m; i >= left; i--)
    {
        count+=4;
        sum = sum + arr[i];
        if (sum > left_sum){
          left_sum = sum;
          ar1.leftpos=i;
        count+=2;
        }
    }


    sum = 0;
    int right_sum = 0;
    count+=2;
    for (i = m+1; i <= right; i++)
    {
        count+=4;
        sum = sum + arr[i];
        if (sum > right_sum){
          right_sum = sum;
          ar1.rightpos=i;
        count+=2;
    }
    }
        ar1.maxcount=left_sum+right_sum;
        count+=2;
    return ar1;

}

void N1(int arr[],int y){
    int q=0;
    int current_max=arr[0];
    int total_max=arr[0];
    start=0;
    finish=0;
    count=0;
    count+=5;
    for(i=1;i<y;i++){
            count+=5;
       if(arr[i]>arr[i]+current_max){
            current_max=arr[i];
            q=i;
            count++;


       }else{
            current_max=current_max + arr[i];

       }

        if (current_max>total_max){
            count+=3;
            if(q){
           count++;
           start=q;

            }
           total_max=current_max;
           finish=i;

        }

    }
    printf("               0(N)              \n");
    printf("start=%d finish= %d and max count = %d\n",start,finish,total_max);
}











