#include<stdio.h>
int main()
{
    int a,b,i,j,temp;
    printf("Enter no of process : ");
    scanf("%d",&a);
    printf("Enter no of blocks : ");
    scanf("%d",&b);
    printf("Enter processes in order :\n");
    int p[a],bl[b],b_index[b],bcopy[b],remain[b];
    for(i=0;i<a;i++)
    {
        printf("P%d : ",i+1);
        scanf("%d",&p[i]);
    }
    printf("Enter block in order");
    for(i=0;i<b;i++)
    {
        printf("B%d : ",i+1);
        scanf("%d",&bl[i]);
    }
    for(i=0;i<b;i++)
    {
        b_index[i]=i+1;
        remain[i]=bcopy[i]=bl[i];
    }
    int pflag[10]={0},bflag[10]={0};
    //sorting
    for(i=0;i<b;i++)
    {
        for(j=0;j<b-i-1;j++)
        {
            if(bl[j]<bl[j+1])
            {
            temp=bl[j];
            bl[j]=bl[j+1];
            bl[j+1]=temp;
            temp=b_index[j];
            b_index[j]=b_index[j+1];
            b_index[j+1]=temp;
            }
        }
    }
    printf("Process name\tProcess size\tBlock name\tTotal space\twastage\n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            if(p[i]<bl[j] && bflag[j]==0)
            {

                remain[j]=(bl[j]-p[i]);
                printf("P%d\t\t%d\t\tB%d\t\t%d\t\t%d\t\t\n",i+1,p[i],j+1,bl[j],remain[j]);
                pflag[i]=bflag[j]=1;
                break;
            }
        }
        if(pflag[i]==0)
        {
            printf("P%d\t\t%d\t\t-\t\t -\t\t -\n",i+1,p[i]);
        }
    }
}
