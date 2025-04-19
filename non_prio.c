 #include<stdio.h>
int main()
{
    int a,b,i,j,t;
    float avgWT=0,avgTT=0;
    printf("Enter number of process:");
    scanf("%d",&a);
    int wt[a],tt[a],p[a],bt[a],prio[a];
    printf("Enter the burst time in order");
    for(b=0;b<a;b++){
        p[b] = b+1;
        printf("p%d:",b+1);
        scanf("%d",&bt[b]);
    }
    printf("Enter priority in order:");
    for(b=0;b<a;b++)
    {
        printf("p%d",b+1);
        scanf("%d",&prio[b]);
    }
    for(i=0;i<a-1;i++)
    {
        for(j=0;j<a-1-i;j++)
        {
            if(prio[j]>prio[j+1])
            {
                t=prio[j];
                prio[j]=prio[j+1];
                prio[j+1]=t;
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
   wt[0]=0;
    for(b = 1;b < a ;b++)
    {
        wt[b] = wt[b - 1] + bt[b - 1];
        avgWT += wt[b];
        printf("%f\n",avgWT);
    }
    avgWT/=a;

    for(b=0;b<a;b++)
    {
        tt[b]=wt[b]+bt[b];
        avgTT+=tt[b];
        printf("tt:%f\n",avgTT);
    }
    avgTT/=a;
    printf("average tt:%f\n",avgTT);
    printf("average wt:%f\n",avgWT);
    printf("PID\t\tTT\t\tWT\t\tPRIORITY\n");
    for(b=0;b<a;b++)
    {
            printf("p%d\t\t%d\t\t%d\t\t%d\n",p[b],tt[b],wt[b],prio[b]);

    }
    printf("\nGANT CHART\N");
    printf("\n------------------------------------------------------------------------------\n");
    for(b=0;b<a;b++)
    {
        printf("|\tp%d\t",b+1);
    }
    printf("|");
    printf("\n--------------------------------------------------------------------------------\n");
    for(b=0;b<a;b++){

        printf("%d\t\t",wt[b]);
    }
    printf("%d",tt[a-1]);

    return 0;
}
