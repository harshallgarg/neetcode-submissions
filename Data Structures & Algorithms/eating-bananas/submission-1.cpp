#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isRateValid(int k, int h, vector<int> &piles){
        
        int hoursTaken = 0;

        for(int i=0;i<piles.size();i++){

            if(hoursTaken>h)
            return false;

            if(k>=piles[i])
            hoursTaken++;

            else
            hoursTaken += ceil((double)piles[i]/k);
        }

        if(hoursTaken<=h)
        return true;

        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        // range of k from low to high
        int low = 1;
        int high = INT_MAX;

        int minK = INT_MAX;

        while(low<=high){
            int k = low+(high-low)/2;

            if(isRateValid(k,h,piles)){
                minK = k;
                high = k-1;
            }

            else
            low = k+1;
        }

        return minK;
    }
};
