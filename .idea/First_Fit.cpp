#include<cstdio>
int main()
{
    int i,j,n,m;
    printf("Enter no of Blocks.\n");
    scanf("%d",&n);
    int memory[n];
    for(i=0;i<n;i++)
    {
        printf("block[%d] size",i+1);
        scanf("%d",&memory[i]);
    }
    printf("Enter no of Process.\n");
    scanf("%d",&m);
    int process[m];
    for(i=0;i<m;i++)
    {
        printf("process[%d] size",i+1);
        scanf("%d",&process[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(process[j]<=memory[i])
            {
                printf("Process %d allocated to %d.\n",j+1,memory[i]);process[j]=10000;
                break;
            }
        }
    }
    for(j=0;j<m;j++)
    {
        if(process[j]!=10000)
        {
            printf("Process %d is not allocated.\n",j+1);
        }
    }
}