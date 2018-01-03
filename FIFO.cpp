#include<iostream>
using namespace std;
typedef struct {
    int P_ID;
    int burst_time;
    int completition_time;
    int waiting_time;
    int turnaround_time;
}Process;
int main(){
    int MAX;
    cin>>MAX;
    Process process[MAX];
    float awat=0,atat=0;

    for (int i = 0; i < MAX; ++i) {
        printf("\nEnter burst time for process [%d]",i+1);
        cin>>process[i].burst_time;
        process[i].P_ID=i+1;
    }

    for (int i = 0; i < MAX; ++i) {
        process[i].waiting_time=0;
        for (int j = 0; j < i; ++j) {
            process[i].waiting_time+=process[j].burst_time;
        }
        process[i].turnaround_time=process[i].waiting_time+process[i].burst_time;
        atat+=process[i].turnaround_time;
        awat+=process[i].waiting_time;
    }
    awat/=MAX;
    atat/=MAX;
    for (int i = 0; i < MAX; ++i) {
        printf("\nprocess[%d] burst = %d wat = %d tat = %d",
               process[i].P_ID,process[i].burst_time,process[i].waiting_time,process[i].turnaround_time);
    }
    printf("\nAverage Waiting time = %2.2f",awat);
    printf("\nAverage turnaround time = %2.2f",atat);
}