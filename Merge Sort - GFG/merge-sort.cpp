//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int nums[], int s, int e, int mid)
    {
         // Your code here
        int len1=mid-s+1;
        int len2=e-mid;
        vector<int>left(len1);
        vector<int>right(len2);
        int k=s;
        for(int i=0;i<len1;i++)
        {
            left[i]=nums[k++];
        }
        for(int i=0;i<len2;i++)
        {
            right[i]=nums[k++];
        }
        int leftindex=0;
        int rightindex=0;
        int mainindex=s;
        while(leftindex<len1 && rightindex<len2)
        {
            if(left[leftindex]<=right[rightindex])
            {
                nums[mainindex++]=left[leftindex++];
            }
            else
            {
                 nums[mainindex++]=right[rightindex++];
            }
        }
        while(leftindex<len1)
        {
            nums[mainindex++]=left[leftindex++];
        }
        while(rightindex<len2)
        {
            nums[mainindex++]=right[rightindex++];
        }
        left.clear();
        right.clear();
    }
    public:
    void mergeSort(int nums[], int s, int e)
    {
        //code here
        if(s>=e)
        {
            return;
        }
        int mid=s+(e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);

        merge(nums,s,e,mid);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends