class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> st;

        int n = temperatures.size();
        vector<int> vans(n);

        for(int i=n-1;i>=0;i--){
            pair tempPair = {temperatures[i],i};

            while(!st.empty() and tempPair.first>=st.top().first){
                st.pop();
            }

            if(st.empty())
            vans[i] = 0;
            else
            vans[i] = st.top().second - tempPair.second;

            st.push(tempPair);
        }

        return vans;
    }
};
