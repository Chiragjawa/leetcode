class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff=0; int fuel=0; int index=0; int total=0;
        for(int i=0 ;i<cost.size();i++){
             diff = gas[i]-cost[i];
            total += diff;
            fuel += diff;
            if(fuel<0){
                index =i+1;
                fuel=0;
            }
        }
        if(total<0) return -1;
        return index;
    }
};