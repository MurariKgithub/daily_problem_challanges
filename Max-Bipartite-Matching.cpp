class Solution{
vector<int> assigneJobs;
 vector<bool> vis;
private:
    bool isassignable(int person ,vector<vector<int>>& grid){
        for(int job=0 ;job<grid[0].size() ;job++){
            if(!vis[job] && grid[person][job]){
                vis[job] = 1;
                if(assigneJobs[job]==-1 || isassignable(assigneJobs[job],grid)){
                    assigneJobs[job] = person;
                    return true;
                }
            }
        }
        return false;
    }
public:
	int maximumMatch(vector<vector<int>>&grid){
	    int ans =0;
	    assigneJobs = vector<int>(grid[0].size(),-1);
	    for(int i=0 ;i<grid.size() ;i++){
	        vis = vector<bool>(grid[0].size(),false);
	        if(isassignable(i,grid)) ans++;
	    }
	
	    return ans;
	}
  }
