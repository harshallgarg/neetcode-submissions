class Solution {

    // We cant sort a string directly as 'String' is immutable
    // char[] a = s.toCharArray();
    // Here a is an Array, which is reference type. It contains primitive types in it.

    public boolean isAnagram(String s, String t) {

        if(s.length()!=t.length())
        return false;

        char[] a = s.toCharArray();
        char[] b = t.toCharArray();

        Arrays.sort(a);
        Arrays.sort(b);

        // for(int i=0;i<s.length();i++){
        //     if(a[i] == b[i])
        //     continue;

        //     else
        //     return false;
        // }        

        return Arrays.equals(a,b);
    }
}
