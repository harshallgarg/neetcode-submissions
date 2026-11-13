class Solution {
public:

    bool checkIfTPresentInS(int freqS[], int freqT[]){
        
        for(int i=0;i<128;i++){
            if(freqT[i]!=0 and freqS[i]<freqT[i])
            return false;
        }

        return true;
    }

    string minWindow(string s, string t) {

        int freqT[128] = {0};

        // O(t)
        for(auto i:t)
        freqT[i]++;

        int freqS[128] = {0};

        int minLength = INT_MAX;
        int index = 0;
        int j=0;

        // O(128*S + 128*S) 
        for(int i=0;i<s.size();i++){
            freqS[s[i]]++;


            if(checkIfTPresentInS(freqS,freqT)){
                if(i-j+1<minLength){
                minLength = i-j+1;
                index = j;
                }

               // O(128*n)
                while(checkIfTPresentInS(freqS, freqT)==true){
                    if(i-j+1<minLength){
                    minLength = i-j+1;
                    index = j;
                    }

                    freqS[s[j]]--;
                    j++;
                }
            }
        }

        if(minLength==INT_MAX)
        return "";

        // O(s)
        return s.substr(index,minLength);
    }
};
 