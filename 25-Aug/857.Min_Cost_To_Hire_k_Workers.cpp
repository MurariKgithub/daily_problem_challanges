class Solution {
public:
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        vector<pair<double,int>> CostArr;
        
        for(int i=0 ;i<n ;i++){
            double a= wage[i],b =quality[i]; 
            CostArr.push_back({a/b,i});
        }
        sort(CostArr.begin(),CostArr.end());
        // for(int i=0 ;i<n ;i++)  cout<<CostArr[i].first<<" "<<CostArr[i].second<<endl;
        priority_queue<int> pq;
        int sum=0;
        for(int i=0 ;i<k ;i++){
            pq.push(quality[CostArr[i].second]);
            sum+=quality[CostArr[i].second];
        }
        double MinCost = sum*CostArr[k-1].first;
        for(int i=k ;i<n ;i++){
            double dcost =0,ratio=CostArr[i].first;
            pq.push(quality[CostArr[i].second]);
            if(!pq.empty()){
                sum-=pq.top();
                sum+=quality[CostArr[i].second];
                pq.pop();
            }
            dcost = sum*CostArr[i].first;
            // cout<<dcost<<" "<<wage[i]<<endl;
            MinCost = min(MinCost,dcost);
        }
        return MinCost;
    }
};
