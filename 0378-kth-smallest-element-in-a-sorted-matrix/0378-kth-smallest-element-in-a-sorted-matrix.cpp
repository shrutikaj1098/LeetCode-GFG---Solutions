class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
      int n=mat.size();
        int a[n*n],x=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        a[x]=mat[i][j];
        x++;
    }
  }
  sort(a,a+n*n);
  return a[k-1];
    }
};