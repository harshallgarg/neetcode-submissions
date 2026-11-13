class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> vans;
       deque<int> dq;

       int j=0; // left

        // iterating the right pointer
       for(int i=0;i<nums.size();i++){

        while(!dq.empty() and dq.back()<nums[i])
        dq.pop_back();

        dq.push_back(nums[i]);

        if(i-j+1==k){
            vans.push_back(dq.front());

            if(nums[j]==dq.front()){
                dq.pop_front();
            }

            j++;
        }
       }

       return vans;
    }
};
