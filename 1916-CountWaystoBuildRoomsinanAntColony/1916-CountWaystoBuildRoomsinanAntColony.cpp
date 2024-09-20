class Solution {
public:
    typedef long long ll;
    ll fact[100005],invfact[100005],dp[100005],dp1[100005];
    const int mod=1e9+7;

    ll binpow(ll x, ll y)
    {
        if(y==0) return 1;
        ll ans=1LL;
        if(y%2!=0) ans=x;
        ll k=binpow(x,y/2);
        ans*=k;
        ans=ans%mod;
        ans*=k;
        ans=ans%mod;

        return ans;
    }

    void run(ll  n)
    {
        fact[0]=1LL;
        for(ll i=1; i<=n; i++)
        {
            fact[i]=(fact[i-1]*i)%mod;
            invfact[i]=binpow(fact[i],mod-2);
        }
    }

    void dfs(int node, int par, vector<int>v[])
    {
        dp[node]=1; dp1[node]=1; 
        ll total=0;
        for(int i=0; i<v[node].size(); i++)
        {
            ll child=v[node][i];
            if(child!=par)
            {
                dfs(child,node,v);
                total+=dp1[child];
                dp[node]=(fact[total]*dp[node])%mod;
                dp[node]=(dp[node]*dp[child])%mod;
                dp[node]*=(invfact[dp1[child]]); dp[node]%=mod;
                dp[node]*=(invfact[total-dp1[child]]); dp[node]%=mod;
            }
        }
        dp1[node]+=total;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n=prevRoom.size(); run(n+2); 
        invfact[0]=invfact[1];
        fact[0]=1;
        vector<int>v[n+1];
        for(int i=1; i<n; i++)
        {
            v[prevRoom[i]].push_back(i);
            v[i].push_back(prevRoom[i]);
        }

        dfs(0,-1,v);
        return dp[0];
    }
};