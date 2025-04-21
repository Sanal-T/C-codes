#include<stdio.h>
int main()
{
    //find the largest of any number of numbers
    int l=largest();
    //find the sum of digits
    int s=SOD();
    //find fibonacci series
    //f=fibonacci();
    //Factorial and prime
    int p=fp();
}
int largest()
{
    int n[10],i=0,k;
    printf("Enter the Number of Elements ");
    scanf("%d",&k);
    printf("Enter the %d Numbers :\n",k);
    while(i<k)
    {
        scanf("%d",&n[i]);
        i++;
    }
    int largest=0;
    for(i=0;i<k;i++)
    {
        if(n[i]>largest)
        {
            largest=n[i];
        }
    }
    printf("largest number is %d",largest);
    return largest;
}
int SOD()
{
    int n,sum=0,temp;
    printf("Enter the number: ");
    scanf("%d",&n);
    while(n!=0)
    {
        temp=n%10;
        sum=sum+temp;
        n=n/10;
    }
    return sum;
}
int fp()
{
    int n,i,fact=1,prime,a[2];
    int temp=1;
    a[1]=1;
    printf("Enter the number :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    printf("%d\n",fact);
    a[0]=fact;
    for(i=2;i<=(n/2);i++)
    {
        if((n%i)==0)
        {
            temp=0;
            a[1]=0;
            break;
        }
    }
    return a[1];
}
