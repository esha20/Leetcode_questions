class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int mincost=0;
        if(cost.size()==1){
            mincost=cost[0];
            return mincost;
        }
        for(int i=cost.size()-1;i>=0;i-=3){
            if(i==0){
                mincost+=cost[i];
            }
            else {
            mincost+=cost[i]+cost[i-1];
            }
        }
        return mincost;
    }
};