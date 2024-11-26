class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        // vector<int> ans(n,2);
        priority_queue<pair<double, pair<int,int>>>pq;
        for(int i=0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                pq.push({(-1.0*A[i])/A[j], {A[i],A[j]}});
            }
            
        }
        // for(int i = 0; i < A.size(); i++)
        //     pq.push({-1.0*A[i]/A.back(), {A[i],A.back()}});
        // priority_queue<pair<double, pair<int,int>>>pq2=pq;
        // while(!pq2.empty()){
        //     pair<int,int> cur = pq2.top().second;
        //     pq2.pop();
        //     cout<<pq.top().first<<":"<<cur.first<<" "<<cur.second<<endl;
        // }
        while(--k){
            pair<int,int> cur = pq.top().second;
            pq.pop();
            // cur.second--;
            // pq.push({(-1.0*cur.first)/cur.second, {cur.first, cur.second}});
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};