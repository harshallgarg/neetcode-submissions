class Solution {
public:

   // TC - O(26n+26n) = O(n)

    int characterReplacement(string s, int k) {
        int ans = 0;
        int freq[26] = {0};
        int j = 0;

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'A']++;

            int size = i - j + 1;
            int maxFreq = 0;

            for(int l = 0; l < 26; l++)
                maxFreq = max(maxFreq, freq[l]);

            while(size - maxFreq > k) {
                freq[s[j] - 'A']--;
                j++;

                size = i - j + 1;
                maxFreq = 0;

                for(int l = 0; l < 26; l++)
                    maxFreq = max(maxFreq, freq[l]);
            }

            ans = max(ans, size);
        }

        return ans;
    }
};