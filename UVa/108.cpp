/*
*****************************************************************************************
*                               UVA practice problem                                    *
*                                                                                       *
*****************************************************************************************
  UVA 108 - Maximum Sum
*/

#include <bits/stdc++.h>
using namespace std;
int N, Matrix[110][110];

// KADEN's algorithm
int maximum_sum_sub_array(int arr[], int n)
{
    // if all the elements are negative MSSD is the maximum element
    int neg=0, i, mx;

    for(i=0; i<n; i++)
    {
        if(arr[i]<0) neg++;
        if(i==0) mx=arr[i];
        mx=max(mx, arr[i]);
    }
    if(neg==i) return mx;

    // if there is at most one positive number
    int sum=0, ans=INT_MIN;

    for(i=0; i<N; i++)
    {
        sum+=arr[i];
        // if sum is negative update sum as 0
        // else compare with ans
        // if sum > ans update ans=sum
        if(sum<0) sum=0;
        ans=max(ans, sum);
    }
    return ans;
}

void maximum_sum_sub_rectangle()
{
    int Left, Right, temp[N], sum, ans=INT_MIN;

    // starting from left
    for(Left=0; Left<N; Left++)
    {
        // setting 0 for all indexes of temp array
        memset(temp, 0, sizeof(temp));
        // for each column
        for(Right=Left; Right<N; Right++)
        {
            int i;
            // summing the columns with immediate columns
            for(i=0; i<N; i++)
                temp[i]+=Matrix[i][Right];

            // applying KADEN's algorithm to find the MSSD of temp array
            sum = maximum_sum_sub_array(temp, i);

            // if sum > ans ans = sum
            ans = max(ans, sum);
        }
    }
    // print the maximum sum sub rectangle
    printf("%d\n", ans);
}

int main()
{
    while(scanf("%d", &N)==1) {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &Matrix[i][j]);

        // this function print the MSRD
        maximum_sum_sub_rectangle();
    }

    return 0;
}
