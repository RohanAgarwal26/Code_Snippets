int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    queue<pair<int,pair<int,int>>> pq;
	    int x = KnightPos[0]-1, y = KnightPos[1]-1;
	    int delrow[8]={-1,-2,-2,-1,+1,+2,+2,+1};
	    int delcol[8]={-2,-1,+1,+2,+2,+1,-1,-2};
	    vector<vector<int>> vis(n,vector<int>(n,0));
	    pq.push({0,{x,y}});
	    vis[x][y]=1;
	    while(!pq.empty()){
	        int row=pq.front().second.first;
	        int col=pq.front().second.second;
	        int steps=pq.front().first;
	        pq.pop();
	        if(row==TargetPos[0]-1 && col==TargetPos[1]-1) return steps;
	        for(int i=0;i<8;i++){
	            int nrow=row+delrow[i];
	            int ncol=col+delcol[i];
	            if(nrow>=0 && ncol>=0 && ncol<n && nrow<n && !vis[nrow][ncol]){
	                pq.push({steps+1,{nrow,ncol}});
	                vis[nrow][ncol]=1;
	            }
	        }
	    }
	    return -1;
	}
