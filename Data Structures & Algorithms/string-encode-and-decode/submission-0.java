class Solution {

    // more efficient approach as when we use StringBuilder we can modify the same string

    public String encode(List<String> strs) {

        StringBuilder encode = new StringBuilder("");
        char separator = '#';

        for(int i=0;i<strs.size();i++){
            
            int length = strs.get(i).length();

            encode.append(length)
            .append(separator)
            .append(strs.get(i));
        }

        System.out.println(encode);
        return encode.toString();
    }


// inefficient approach
// TC - O(n^2)
// as string is immutable, it creates a new string every time we write s+=word;

    // public String encode(List<String> strs) {
    //     String encode = "";
    //     char separator = '#';

    //     for (int i = 0; i < strs.size(); i++) {
    //         int length = strs.get(i).length();

    //         encode += length + "" + separator + strs.get(i);
    //     }
        
    //     return encode;
    // }

    public List<String> decode(String str) {

        List<String> decodedString = new ArrayList<>();

        StringBuilder word = new StringBuilder();

        int i=0;

        while(i<str.length()){

            int dig = 0;

            while(str.charAt(i)>='0' && str.charAt(i)<='9'){
                dig = dig*10 + str.charAt(i)-'0';
                i++;
            }

            i++;

            while(dig-- > 0){
                word.append(str.charAt(i));
                i++;
            }

            decodedString.add(word.toString());
            word.setLength(0);
        }

        return decodedString;
    }
}
