class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,double>> v;

        for(int i=0;i<position.size();i++){
            double time = (double)(target-position[i])/(double)speed[i];
            v.push_back({position[i],time});
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        int fleet = 1;
        double aheadCarTime = v[0].second;

        for(int i=1;i<v.size();i++){
            if(v[i].second>aheadCarTime){
                fleet++;
                aheadCarTime = v[i].second;
            }
        }

        return fleet;
    }
};
