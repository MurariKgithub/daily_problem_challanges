using ll = long long;
class Solution {
  public:
  void dfs(int node,ll &sum,ll ans,vector<vector<int>>& adjls,vector<int> &vis,vector<int> &arr,bool flag){
    vis[node] =1 ;
    ans = (flag ==0)? ans+arr[node-1]:ans-arr[node-1];
    
        if(ans<arr[node-1]){
            ans = arr[node-1];
            flag=0;
        }
    
    if(adjls[node].empty()) sum = max(sum,ans);
    // cout<<ans<<" "<<sum<<" "<<node<<endl;
    for(auto it:adjls[node]){
        // cout<<it<<endl;
        if(!vis[it]){
            dfs(it,sum,ans,adjls,vis,arr,!flag);
        }
    }
}

    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        set<int> s;
        for(int i=0;i<N;i++)
        {
            s.insert(P[i]);
        }
        //Step-2 ..Find out leaf nodes from s 

        vector<int> leaf_node;

        for(int i=1;i<=P.size();i++)
        {
            if(!s.count(i))
            { leaf_node.push_back(i);
            }

        }
        //Step-3 ..Traverse from leaf to root and store max at each and every time visited new node

        long long ans = LLONG_MIN;
        for(int leaf : leaf_node)

        {
            int curr_node = leaf;
            long long sum = 0;
            //-1 indicate the root

            while(curr_node!=-1)

            {

                sum = -sum;

                sum+=A[curr_node-1];

                

                ans = max(ans,sum);

                curr_node = P[curr_node-1];

            }

        }

        

        return ans;
    }
};
