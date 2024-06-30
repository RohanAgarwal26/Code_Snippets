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
    
    bool UnionBySize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return false;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n),bob(n);
        int removedEdges=0;
        int usedalice=0,usedbob=0;
        for(auto i:edges){
            if(i[0]==3){
                bool aliceUnion=alice.UnionBySize(i[1],i[2]);
                bool bobUnion=bob.UnionBySize(i[1],i[2]);
                if(!aliceUnion && !bobUnion){
                    removedEdges++;
                }
                else{
                    if(aliceUnion) usedalice++;
                    if(bobUnion) usedbob++;
                }
            }
        }
        for(auto i:edges){
            if(i[0]==1){
                if(alice.UnionBySize(i[1],i[2])){
                    usedalice++;
                }
                else{
                    removedEdges++;
                }
            }
        }
        for(auto i:edges){
            if(i[0]==2){
                if(bob.UnionBySize(i[1],i[2])){
                    usedbob++;
                }
                else{
                    removedEdges++;
                }
            }
        }
        if(usedalice==n-1 && usedbob==n-1){
            return removedEdges;
        }
        return -1;
    }
};
