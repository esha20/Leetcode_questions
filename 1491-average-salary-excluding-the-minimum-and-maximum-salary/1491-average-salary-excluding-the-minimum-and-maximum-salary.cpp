class Solution {
public:
    double average(vector<int>& salary) {
        int maxi =0,mini=INT_MAX;
        double avg=0,sum=0;
        for(int i=0;i<salary.size();i++){
            if(salary[i] > maxi)    maxi = salary[i];
            if(salary[i] < mini)    mini = salary[i];
            sum +=salary[i];
        }
        avg = sum - (maxi + mini);
        avg /= (salary.size()-2);
        return avg;
    }
};