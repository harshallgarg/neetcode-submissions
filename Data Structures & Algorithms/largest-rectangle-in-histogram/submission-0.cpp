class Solution {
public:

    // 4 5 4

    // st  

    vector<int> smallestElementOnRight(vector<int> v){
        stack<pair<int,int>> st; //value, index
        int n = v.size();
        vector<int> nser(n);

        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() and v[i]<=st.top().first)
            st.pop();

            if(st.empty())
            nser[i] = n;
            else
            nser[i] = st.top().second;

            st.push({v[i],i});
        }

        return nser;
    }

    vector<int> smallestElementOnLeft(vector<int> v){
        stack<pair<int,int>> st; //value, index
        int n = v.size();
        vector<int> nsel(n);

        for(int i=0;i<n;i++){
            
            while(!st.empty() and v[i]<=st.top().first)
            st.pop();

            if(st.empty())
            nsel[i] = -1;
            else
            nsel[i] = st.top().second;

            st.push({v[i],i});
        }

        return nsel;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nser = smallestElementOnRight(heights);
        vector<int> nsel = smallestElementOnLeft(heights);

        int maxArea = 0;

        for(int i=0;i<heights.size();i++){
            maxArea = max(maxArea, heights[i]*(nser[i]-nsel[i]-1));
        }

        return maxArea;
    }
};
