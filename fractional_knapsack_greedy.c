#include<stdio.h>
void knapsack(int n,float weight[],float profit[],float capacity)
{
    float x[20],total_profit=0;
    int i,j,u;
    u=capacity;
    for(i=0; i<n; i++)
    {
        x[i]=0.0;
    }
    for(i=0; i<n; i++)
    {
        if(weight[i]>u)
        {
            break;
        }
        else
        {
            x[i]=1.0;
            total_profit=total_profit+profit[i];
            u=u-weight[i];
        }
    }
    if(i<n)
        x[i]=u/weight[i];

    total_profit=total_profit+(x[i]*profit[i]);
    printf("\nMaximum profit is=%f",total_profit);
}
int main()
{
    float weight[20],profit[20],capacity,ratio[20],temp;
    int num,i,j;
    printf("Enter the number of objects=");
    scanf("%d",&num);
    printf("\nEnter the weights & profits of objects=");
    for(i=0; i<num; i++)
    {
        scanf("%f %f",&weight[i], &profit[i]);
    }
    printf("\nEnter the capacity of knapsack=");
    scanf("%f",&capacity);
    printf("\nValue per weight=");
    for(i=0; i<num; i++)
    {
        ratio[i]=profit[i]/weight[i];
        printf("%f ",ratio[i]);
    }
    for(i=0; i<num; i++)
    {
        for(j=i+1; j<num; j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }
        }
    }
    knapsack(num,weight,profit,capacity);
}
