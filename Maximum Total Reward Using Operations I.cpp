class Solution {
public:
    int dp[2001][4001];
    int solve(int idx,int sum,vector<int>&arr,int n){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int pick=0;
        if(sum<arr[idx]){
            pick=arr[idx]+solve(idx+1,sum+arr[idx],arr,n);
        }
        int notpick=solve(idx+1,sum,arr,n);
        return dp[idx][sum]=max(pick,notpick);
    }
    int maxTotalReward(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,arr,n);
    }
};
