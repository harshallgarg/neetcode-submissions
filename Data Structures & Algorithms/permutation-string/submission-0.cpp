class Solution {
public:

    bool checkIfEqual(int arr1[], int arr2[]){

        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i])
            return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {

     int n = s1.size();
     int charFreqS1[26] = {0};

     for(auto i:s1)
     charFreqS1[i-'a']++;

    int j = 0;
     int charFreqS2[26] = {0};

     for(int i=0;i<s2.size();i++){
        
        char letter = s2[i];
        charFreqS2[letter-'a']++;

        if(i-j+1>n){
            charFreqS2[s2[j]-'a']--;
            j++;
        }

        if(i-j+1==n){
            if(checkIfEqual(charFreqS1,charFreqS2))
            return true;
        }
     }

     return false;
    }
};
