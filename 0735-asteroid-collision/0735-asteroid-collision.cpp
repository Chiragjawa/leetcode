class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            while(!st.empty()){
                if(st.top()>0 && asteroids[i]<0){
                    if(st.top()>-asteroids[i]){
                        asteroids[i] =0;
                        break;
                    }else if(st.top() == -asteroids[i]){
                        st.pop();
                        asteroids[i] =0;
                        break;
                    }else{
                        st.pop();
                    }

                }
                else{
                    break;
                }
            }
            if(asteroids[i] !=0){
                st.push(asteroids[i]);
            }
        }
        vector<int> out;
        out.resize(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {            
            out[i] = st.top();
            st.pop();
        }
        return out;
    }
};