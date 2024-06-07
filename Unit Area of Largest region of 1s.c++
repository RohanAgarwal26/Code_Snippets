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
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1 && grid[0][0]==0) return 0; 
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                for(int d1=-1;d1<=1;d1++){
                    for(int d2=-1;d2<=1;d2++){
                        int nrow=i+d1;
                        int ncol=j+d2;
                        if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && grid[nrow][ncol]==1){
                            int adjnode=nrow*m+ncol;
                            int node=i*m+j;
                            if(ds.findUpar(adjnode)!=ds.findUpar(node)){
                                ds.UnionBySize(adjnode,node);
                            }
                        }
                    }
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<n*m;i++){
            maxi=max(maxi,ds.size[ds.findUpar(i)]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt>0 ? maxi: 0;
    }
};
