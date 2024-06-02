#include<stdio.h>
#include<stdlib.h>

// structure to represent an item
typedef struct{
     int profit;
     int weight;
     float ratio;
}item;

//comparison of item according to profit and weight ratio and sort items in decending order

int compare(const void*a,const void*b){
    item *item1 = (item*)a;
    item *item2 = (item*)b;
    if(item1->ratio < item2->ratio) return 1;
    if(item1->ratio > item2->ratio) return -1;
    return 0;
}

//function to find maximum profit within the weight limit

float fractional_knapsack(item items[],int n,int capacity)
{
    qsort(items,n,sizeof(item),compare);

    int currentweight =0;
    float finalvalue = 0.0;
   
    for(int i=0;i<n;i++){
        if(currentweight + items[i].weight <= capacity)
        {
            currentweight += items[i].weight;
            finalvalue += items[i].profit;
        }
        else{
           int remaining_weight = capacity - currentweight;
           finalvalue += items[i].profit*((float)remaining_weight/items[i].weight);
           break;//knapsack is full
        }
    }
    return finalvalue;
}

int main()
{
    int n,capacity;
    printf("enter the number of items:");
    scanf("%d",&n);
    
    item items[n];
    printf("enter the profit and weight of the items:\n");
    for(int i=0;i<n;i++)
    {
        printf("item %d profit:",i+1);
        scanf("%d",&items[i].profit);
        printf("item %d weight:",i+1);
        scanf("%d",&items[i].weight);
        items[i].ratio = (float)items[i].profit/items[i].weight;
    }

    printf("enter the maximum capacity of truck:");
    scanf("%d",&capacity);

    int maxprofit = fractional_knapsack(items,n,capacity);
    printf("the maximum profit is : %d",maxprofit);


}