//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int decimalToBinary(int n)

    {

        int count=0;

        while(n>0)

        {

            if (n%2==1)

            {

                count++;

            }

            n=n/2;

        }

        return count;

    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            int n= decimalToBinary(arr[i]);
            mp[n].push_back(arr[i]);
        }
          int i=n-1;

        for (auto x : mp)

        {

            int index=x.first;

            reverse(mp[index].begin(), mp[index].end());

            for (auto y : mp[index])

            {

                arr[i]=y;

                i--;

            }

        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends