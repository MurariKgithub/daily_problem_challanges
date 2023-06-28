double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) {
        vis.resize(n+1,0);
        dp.resize(n+1,-1e5);
        vector<pair<int,double>> adjls[n+1];
        for(int i=0 ;i<edges.size() ;i++){
            adjls[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjls[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        for(auto it:adjls[s]){
            pq.push({it.second,it.first});
            dp[it.first] = max(dp[it.first],it.second);
        }
        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            vis[node] = 1;
            
            for(auto it:adjls[node]){
                if(vis[it.first]) continue;
                
                double ans = prob*it.second;
                
                if(dp[it.first]<ans) pq.push({ans,it.first});
                dp[it.first] = max(dp[it.first],ans);
            }
        }
        return dp[e]==-1e5?0:dp[e];
    }
