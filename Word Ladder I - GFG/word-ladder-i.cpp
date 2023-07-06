//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int bfs(string beginWord, string endWord, vector<string>& wordList)
    {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty())
        {
            string str=q.front().first;
            int step=q.front().second;
            q.pop();
            if(str==endWord)return step;
            for(int i=0;i<str.length();i++)
            {
                char original=str[i];
                for(auto j='a';j<='z';j++)
                {
                    str[i]=j;
                    if(s.find(str)!=s.end())
                    {
                        q.push({str,step+1});
                        s.erase(str);
                    }
                }
                str[i]=original;

            }
        }
        return 0;
    }
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
         return bfs(beginWord,endWord,wordList);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends