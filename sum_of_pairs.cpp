#include <bits/stdc++.h>

using namespace std;

int main()
{
    printf("enter the size of array=");
    int num, X,i;

    scanf("%d",&num);
    scanf("%d",&X);
    int arr[num];
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+num);
    for(i=0;i<num;i++)
    {
        //binary search of search_num//
        int search_num=X-arr[i];
        int lb=0,ub=num-1,flag=0,mid;
        if(search_num>0)
        {
            while(lb<=ub)
            {
                mid=(lb+ub)/2;
                if(arr[mid]==search_num)
                {
                    flag=1;
                    break;
                }
                else if(arr[mid]>search_num)
                    ub=mid-1;
                else
                    lb=mid+1;
            }
        }
        if(flag==1&&mid!=i){
            printf("(%d,%d)\n",arr[i],arr[mid]);
        }
    }
    return 0;
}
