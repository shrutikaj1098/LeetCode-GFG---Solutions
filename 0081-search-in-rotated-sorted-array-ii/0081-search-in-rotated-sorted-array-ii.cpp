class Solution {
public:
    int BS(vector<int>&A,int N, int s, int e, int k)
    {
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(A[mid]==k) return mid;
            else if(A[mid]<k)s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
    bool search(vector<int>& A, int Key) {
        int N=A.size();
        int s=0,e=N-1,smallest=-1,mid=0;
        sort(A.begin(),A.end());
        while(s<=e)
        {
            if(A[s]<=A[e])
            {
                smallest=s;
                break;
            }
            mid=s+(e-s)/2;
            int next=(mid+1)%N;
            int prev=(mid+N-1)%N;
            if(A[mid]<=A[prev] && A[mid]<=A[next]) smallest=mid;
            else if(A[s]<=A[mid])
            {
                s=mid+1;
            }
            else if(A[mid]<=A[e])
            {
                e=mid-1;
            }
        }
        int t=BS(A,N,0,mid-1,Key);
        int m=BS(A,N,mid,N-1,Key);
        if(t==-1 && m==-1) return 0;
        else return 1;
    }
};