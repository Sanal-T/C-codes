#include<stdio.h>
int main()
{
    //find the largest of any number of numbers
    int l=largest();
    //find the sum of digits
    //s=SOD();
    //find fibonacci series
    //f=fibonacci();
    //Factorial and prime
    //p[]=fp();
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
