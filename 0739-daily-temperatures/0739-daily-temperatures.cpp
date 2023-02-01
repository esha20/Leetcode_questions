class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int x;
        //going to deal with it like next greater ele in stack problem.
        stack<int> s;
        s.push(-1);
        
        //starting the loop from the end i.e. the size of the temperature array-1.
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            //for every ele in the vector of temp
            
            //look for the next greater element's index.
            while(s.top()!=-1 && temperatures[i] >= temperatures[s.top()]){
                s.pop();
            }
            (s.top()==-1)?ans[i]=0 : ans[i] = s.top()-i;
            s.push(i);
        }
        return ans;
    }
};