class DisjointSet{
    public:
    vector<int> parent,size,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
    
    void UnionByRank(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    
    void UnionBySize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DisjointSet ds(V);
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                edges.push_back({j[1],{i,j[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        int sum=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i].second.first;
            int v=edges[i].second.second;
            int wt=edges[i].first;
            if(ds.findUpar(u)!=ds.findUpar(v)){
                sum+=wt;
                ds.UnionBySize(u,v);
            }
        }
        return sum;
    }
};
