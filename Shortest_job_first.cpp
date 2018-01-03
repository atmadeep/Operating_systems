#include <iostream>
using namespace std;
typedef struct{
    int P_ID;
    int burst;
    int wait;
    int turnaround;
}process;
void swap(process &a,process &b);
void Quick_sort(process array[],int p,int r);
int Partition(process array[],int p,int r);
int main(){
    int MAX;
    printf("enter no of processes");
    cin>>MAX;
    process array[MAX];
    float awat=0,atat=0;
    printf("Process_ID\tburst\n");
    for (int i = 0; i < MAX; ++i) {
        array[i].P_ID=i+1;
        printf("process[%d] = ",i+1);
        cin>>array[i].burst;
    }
    printf("\n");
    Quick_sort(array,0,MAX-1);
    array[0].wait=0;
    for (int i = 0; i < MAX; ++i) {
        array[i].wait=0;
        for (int j = 0; j <i ; ++j) {
            array[i].wait+=array[j].burst;
        }
        awat+=array[i].wait;
    }
    for (int i = 0; i < MAX; ++i) {
        array[i].turnaround=array[i].burst+array[i].wait;
        atat+=array[i].turnaround;
    }
    atat/=MAX;
    awat/=MAX;
    printf("Process\t|Burst\t|wait\t\t|turnaround\n");
    for (int i = 0; i <MAX ; ++i) {
        printf("%d\t|%d\t|%d\t\t|%d\t|\n",array[i].P_ID,array[i].burst,array[i].wait,array[i].turnaround);
    }
    printf("\nAverage waiting time = %2.2f",awat);
    printf("\nAverage turnaround time = %2.2f",atat);
}
void Quick_sort(process array[],int p,int r){
    int q;
    if(p<r){
        q= Partition(array,p,r);
        Quick_sort(array,p,q-1);
        Quick_sort(array,q+1,r);
    }
}
int Partition(process array[],int p,int r){
    process x=array[r];
    int i=p-1,j;
    for ( j = p; j <=r-1 ; ++j) {
        if(array[j].burst <= x.burst){
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[r]);
    return i+1;
}
void swap(process &a,process &b){
    process temp=a;
    a=b;
    b=temp;
}
