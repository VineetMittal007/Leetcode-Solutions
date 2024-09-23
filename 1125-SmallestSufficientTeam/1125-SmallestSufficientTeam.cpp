class Solution {
public:
    int n;
    unordered_map<string,int>mp;
    vector<int>res;
    int sz=INT_MAX;
    unordered_map<string,int>dp;
    void solve(int id,int mask,vector<int>&sp,vector<int>&z){
        if(id>=n){
            if(sz>z.size()){
                res=z;
                sz=z.size();
            }
            return;
        }
        if(mask & (1<<id)){
            solve(id+1,mask,sp,z);
            return;
        }
        for(int i=0;i<sp.size();i++){
            if(sp[i]&(1<<id)){
                int new_mask=(mask|sp[i]);
                z.push_back(i);
                solve(id+1,new_mask,sp,z);
                z.pop_back();
            }
        }
        return;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        this->n=req_skills.size();
        int i=0;
        for(auto it:req_skills){
            mp[it]=i;
            i++;
        }
        vector<int>sp;
        for(auto it:people){
            int temp=0;
            for(auto s:it){
                temp+=(1<<mp[s]);
            }
            sp.push_back(temp);
        }
        vector<int>z;
        solve(0,0,sp,z);
        return res;
    }
};