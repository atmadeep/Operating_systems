#include<stdio.h>
int main()
{
    int i, j , k, min, reference[25], frame[10], m[10], flag[25], length, n_f, page_fault=0, freq=1;
    printf("Enter the length of reference string -- ");
    scanf("%d",&length);
    printf("Enter the reference string -- ");
    for(i=0;i<length;i++)
    {
        scanf("%d",&reference[i]);
        flag[i]=0;
    }
    printf("Enter the number of n_f -- ");
    scanf("%d",&n_f);

    for(i=0;i<n_f;i++)
    {
        m[i]=0;
        frame[i]=-1;
    }

    printf("\nThe Page Replacement process is -- \n");
    for(i=0;i<length;i++)
    {
        for(j=0;j<n_f;j++)
        {

            if(frame[j]==reference[i])
            {
                flag[i]=1;
                m[j]=freq;
                freq++;
            }
        }
        if(flag[i]==0)
        {
            if(i<n_f)
            {
                frame[i]=reference[i];
                m[i]=freq;
                freq++;
            }
            else
            {
                min=0;
                for(j=0;j<n_f;j++) //deciding which one to remove.
                    if(m[min] > m[j])
                        min=j;
                frame[min]=reference[i];
                m[min]=freq;
                freq++;
            }
            page_fault++;
        }
        for(j=0;j<n_f;j++)
            printf("%d\t", frame[j]);
        if(flag[i]==0)
            printf("PF No. -- %d" , page_fault);
        printf("\n");
    }
    printf("\nThe number of page faults using LRU are %d",page_fault);

}