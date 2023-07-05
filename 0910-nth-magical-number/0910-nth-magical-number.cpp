
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long s=min(a,b);
        long e=n*s;
        int A=a,B=b;
        long mod=pow(10,9)+7;
        while(B>0)
        {
            long temp=A;
            A=B;
            B=temp%B;
        }
        long lcm=(a*b)/A;
        while(s<e)
        {
            long mid=s+(e-s)/2;
            if(mid/a +mid/b-mid/lcm <n) s=mid+1;
            
            else e=mid;
        }
        return (int)(s%mod);
    }
};