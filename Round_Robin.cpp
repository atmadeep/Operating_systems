#include<iostream>
using namespace std;
typedef  struct{
    int P_ID;
    int remaining_time;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
}Process;
int main(){
    int MAX,i=0,completion_time=0,p_rem,T_Q;
    bool p_done= false;
    float total_wait=0.0,total_turnaround=0.0;
    cout<<"enter no of processes ";
    cin>>MAX;
    p_rem=MAX;
    Process process[MAX];
    printf("process burst time arrival time \n");
    for ( i = 0; i < MAX; ++i) {
        process[i].P_ID=i+1;
        printf("process[%d] ",process[i].P_ID);
        cin>>process[i].burst_time;
        cin>>process[i].arrival_time;
        process[i].remaining_time=process[i].burst_time;
        process[i].waiting_time=process[i].turnaround_time=0;
    }
    cout<<"enter time quantum ";
    cin>>T_Q;
    //initialization block done.
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    completion_time=0;i=0;
    while (p_rem!=0)
    {
        if(process[i].remaining_time<=T_Q && process[i].remaining_time>0)
        {
            completion_time+=process[i].remaining_time;
            process[i].remaining_time=0;
            p_done= true;  //process done.
        }
        else if(process[i].remaining_time>0)
        {
            process[i].remaining_time-=T_Q;
            completion_time+=T_Q;
            p_done=false;  //process not conplete.
        }
        if(process[i].remaining_time==0 && p_done)
        {
            p_rem--;
            total_turnaround+=( process[i].turnaround_time = completion_time-process[i].arrival_time);
            total_wait+=(process[i].waiting_time=process[i].turnaround_time-process[i].burst_time);

            printf("P[%d]\t|\t%d\t|\t%d\n",i+1,process[i].turnaround_time,process[i].waiting_time);
            total_wait+=completion_time-process[i].arrival_time-process[i].burst_time;
            total_turnaround+=completion_time-process[i].arrival_time;
            p_done=0;
        }
        if(i==MAX-1)
            i=0;
        else if(process[i+1].arrival_time<= completion_time)
            i++;
        else
            i=0;
    }

//end of processing by Round Robin.
    total_turnaround/=MAX;
    total_wait/=MAX;
    printf("\nAverage turnaround time %f\n",total_turnaround);
    printf("\nAverage waiting time %f\n",total_wait);
    return 0;
}
