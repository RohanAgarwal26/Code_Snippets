class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<vector<int>>& adj,vector<int>&vis,stack<int> &st){
	    vis[node]=1;
	    for(auto i:adj[node]){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	void dfs1(int node,vector<int> adj[],vector<int>&vis){
	    vis[node]=1;
	    for(auto i:adj[node]){
	        if(!vis[i]){
	            dfs1(i,adj,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        for(auto &i:vis) i=0;
        vector<int> adjRev[V];
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                adjRev[j].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(vis[node]) continue;
            cnt++;
            dfs1(node,adjRev,vis);
        }
        return cnt;
    }
};
