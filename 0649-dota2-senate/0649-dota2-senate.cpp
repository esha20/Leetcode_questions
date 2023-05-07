class Solution {
public:
    string predictPartyVictory(string senate) {
        int n= senate.length();
        queue <int> rad;
        queue <int> dire;
        
        //prepare the queues for radiant and dire 
        for(int i=0;i<n;i++){
            if(senate[i] == 'R')    rad.push(i);
            else
                dire.push(i);
        }
        
        while(!rad.empty() && !dire.empty()){
            if(rad.front() < dire.front()){
                //radiant defeats dire
                rad.pop();
                dire.pop();
                rad.push(n);
                n++;
            }
            else{
                rad.pop();
                dire.pop();
                dire.push(n);
                n++;
            }
        }
        if(!rad.empty()){
            return "Radiant";
        }
        return "Dire";
    }
};