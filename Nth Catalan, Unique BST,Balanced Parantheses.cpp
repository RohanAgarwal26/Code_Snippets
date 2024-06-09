//unique bst and catalan number is no of bst uniquely structured from n nodes 
class Solution
{
    public:
    int mod=1e9+7;
    //Function to find the nth catalan number.
    int solve(int open,int close,vector<vector<int>>& dp){
        if(open<0 || close<0){
            return 0;
        }
        if(open==0 && close==0){
            return 1;
        }
        if(dp[open][close]!=-1) return dp[open][close];
        int c=0,o=0;
        if(close>open){
            c=solve(open,close-1,dp);
        }
        o=solve(open-1,close,dp);
        return dp[open][close]=(o+c)%mod;
    }
    int findCatalan(int n) 
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // return solve(n,n,dp)%mod;
        dp[0][0]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0) continue;
                int c=0,o=0;
                if(j>i){
                    c=dp[i][j-1];
                }
                if(i>0) o=dp[i-1][j];
                dp[i][j]=(o+c)%mod;
            }
        }
        return dp[n][n];
    }
};
