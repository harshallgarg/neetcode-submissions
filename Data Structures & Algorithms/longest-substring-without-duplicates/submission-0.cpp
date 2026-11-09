class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set<char> set1;
        int maxi = 0;
        int j = 0;

        for(int i=0;i<s.size();i++){
            if(set1.find(s[i])==set1.end()){
            set1.insert(s[i]);
            maxi = max(i-j+1,maxi);
            }
            
            else{
                while(j<s.size() && s[j]!=s[i]){
                set1.erase(s[j]);
                j++;
                }

                if(s[j]==s[i]){
                    j++;
                }
            }
        }

        return maxi;        
    }
};
