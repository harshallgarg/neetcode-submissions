class Solution {
public:

    bool isOpenBracket(char s){
        if(s=='{' or s=='(' or s=='[')
        return true;

        return false;
    }

    bool isValidBrackets(char a, char b){
        if(a=='[' and b==']')
        return true;

        if(a=='{' and b=='}')
        return true;

        if(a=='(' and b==')')
        return true;

        return false;
    }

    bool isValid(string s) {
        
        stack<char> openBracketStack;

        for(int i=0;i<s.size();i++){

            if(isOpenBracket(s[i])==true)
                openBracketStack.push(s[i]);
            else
            {
                if(!openBracketStack.empty() and isValidBrackets(openBracketStack.top(),s[i]))
                openBracketStack.pop();
                else
                return false;
            }
        }

        if(openBracketStack.empty())
        return true;


        return false;
    }
};
