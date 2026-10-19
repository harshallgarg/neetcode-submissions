class Solution {
    public boolean isPalindrome(String s) {

        int i=0;
        int j = s.length()-1;

        while(i<j){
            while(i<j && !isAlphanumeric(s.charAt(i)))
            i++;

            while(i<j && !isAlphanumeric(s.charAt(j)))
            j--;

            if(i<j && Character.toUpperCase(s.charAt(i)) != Character.toUpperCase(s.charAt(j)))
            return false;
            
            i++;
            j--;
        }

        return true;
    }

    public boolean isAlphanumeric(char c){
        
        boolean flag = false;

        if(c>='a' && c<='z')
        flag = true;

        if(c>='A' && c<='Z')
        flag = true;

        if(c>='0' && c<='9')
        flag = true;

        return flag;
    }
}
