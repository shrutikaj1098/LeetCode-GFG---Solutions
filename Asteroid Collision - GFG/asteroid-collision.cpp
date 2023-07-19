//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> st;
        
        for (int asteroid : asteroids) {
            int flag = 1;
            while (!st.empty() && (st.top() > 0 && asteroid < 0)) {
                // If the top asteroid in the stack is smaller, then it will explode.
                // Hence pop it from the stack, also continue with the next asteroid in the stack.
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                }
                // If both asteroids are the same size, then both asteroids will explode.
                // Pop the asteroid from the stack; also, we won't push the current asteroid to the stack.
                else if (abs(st.top()) == abs(asteroid)) {
                    st.pop();
                }

                // If we reach here, the current asteroid will be destroyed
                // Hence, we should not add it to the stack
                flag = 0;
                break;
            }
            
            if (flag) {
                st.push(asteroid);
            }
        }
        
        // Add the asteroids from the stack to the vector in the reverse order.
        vector<int> remainingAsteroids (st.size());
        for (int i = remainingAsteroids.size() - 1; i >= 0; i--){
            remainingAsteroids[i] = st.top();
            st.pop();
        }
        
        return remainingAsteroids;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends