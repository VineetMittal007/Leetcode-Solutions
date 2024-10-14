class Solution {
public:
    string s;
    string p;
    unordered_map<int,int>mp;
    int solve(int idx1, int idx2,vector<vector<int>>&dp){
        if(idx2==p.size()){
         int count=0;
         for(int i=idx1;i<s.size();i++){
            if(mp.find(i)!=mp.end())
            count++;
         }
        return count;
        }
        if(idx1==s.size())
        return -1e5;
        if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
        int ans=-1e6;
        if(mp.find(idx1)!=mp.end())
        ans=max(ans,1 +solve(idx1+1,idx2,dp));
        if(s[idx1]!=p[idx2])
        ans=max(ans,solve(idx1+1,idx2,dp));
        else
        ans=max(ans,solve(idx1+1,idx2+1,dp));
        return dp[idx1][idx2]=ans;
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
          int n=source.size();
          int m=pattern.size();
        for(auto it:targetIndices){
            mp[it]++;
        }

        s=source;
        p=pattern;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int x= solve(0,0,dp);
        return x<0 ?0 :x;
    }
};