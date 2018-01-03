#include <iostream>
using namespace std;
const int MAX_PROCESS=5;
const int MAX_MEMEORY=5;
typedef struct{
    int size;
    int ID;
    int _alloc;
}MEM_PROCESS;
void Quick_sort(MEM_PROCESS[],int p,int r);
int Partition(MEM_PROCESS[],int p,int r);
void swap(MEM_PROCESS &a,MEM_PROCESS &b);
int main()
{
    int i,j,fragment[MAX_MEMEORY],total_fragment=0;
    MEM_PROCESS memory[MAX_MEMEORY],process[MAX_PROCESS];
    for ( i = 0; i < MAX_PROCESS && i < MAX_MEMEORY; ++i) {
        memory[i].ID=i+1;
        process[i].ID=i+1;
        memory[i]._alloc=-1;
        process[i]._alloc=-1;
        fragment[i]=-1;
    }
    for ( i = 0; i < MAX_PROCESS; ++i) {
        printf("process[%d] size = ",process[i].ID);
        cin>>process[i].size;
//        printf("\n");
    }
    printf("\n");
    for ( i = 0; i < MAX_MEMEORY; ++i) {
        printf("memory[%d] size = ",memory[i].ID);
        cin>>memory[i].size;
//        printf("\n");
    }
    Quick_sort(memory,0,MAX_MEMEORY-1);
    Quick_sort(process,0,MAX_PROCESS-1);
    printf("\n");


    for (j = 0,i=0;i<MAX_MEMEORY && j<MAX_PROCESS;i++, ++j) {
        while(process[i].size > memory[j].size)
            j++;
        process[i]._alloc=memory[j].ID;
        memory[j]._alloc=process[i].ID;
        total_fragment+=fragment[i]=memory[j].size-process[i].size;

    }

    printf("\n");
    for (i = 0; i < MAX_MEMEORY ; ++i) {
        if(process[i]._alloc!=-1){
            printf("process[%d] size=%d alloc = %d ",process[i].ID,process[i].size,process[i]._alloc);
            printf("Memory fragment = %d\n",fragment[i]);
        } else{
            printf("process[%d] not allocated -- size = %d\n",process[i].ID,process[i].size);
        }
        if(memory[i]._alloc==-1)
            total_fragment+=memory[i].size;
    }
    printf("Total memory fragment is %d\n",total_fragment);
    return 0;

}
void Quick_sort(MEM_PROCESS array[],int p,int r){
    int q;
    if(p<r){
        q=Partition(array,p,r);
        Quick_sort(array,p,q-1);
        Quick_sort(array,q+1,r);
    }
}
int Partition(MEM_PROCESS array[],int p,int r){
    int i=p-1,j;
    MEM_PROCESS x=array[r];
    for ( j = p; j <= r-1; ++j) {

            if (x.size >= array[j].size) {
                i++;
                swap(array[i], array[j]);
            }
    }
    swap(array[i+1],array[r]);
    return i+1;
}
void swap(MEM_PROCESS &a,MEM_PROCESS &b){
    MEM_PROCESS temp=a;
     a=b;
    b=temp;
}