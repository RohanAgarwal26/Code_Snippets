class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int timer=1;
    void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,int low[],int tin[],int c,int d,int &res){
        vis[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        for(auto i:adj[node]){
            if(i==parent) continue;
            if(!vis[i]){
                dfs(i,node,adj,vis,low,tin,c,d,res);
                low[node]=min(low[node],low[i]);
                if(low[i]>tin[node]){
                    if(i==d && node==c || i==c && node==d) res=1;
                }
            }
            else{
                low[node]=min(low[node],low[i]);
            }
        }
    }
    int isBridge(int n, vector<int> adj[], int c, int d) 
    {
        vector<int> vis(n,0);
        int low[n],tin[n];
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                 dfs(i,-1,adj,vis,low,tin,c,d,res);
            }
        }
        return res;
    }
};
