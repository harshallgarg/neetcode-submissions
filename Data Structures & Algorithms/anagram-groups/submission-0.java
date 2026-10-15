class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        Map<String, List<String>> map = new HashMap<>();

        for(int i=0;i<strs.length;i++){
            char[] word = strs[i].toCharArray();
            Arrays.sort(word);

            String sortedWord = new String(word);

            if(map.get(sortedWord)==null)
            map.put(sortedWord, new ArrayList<String>());

            map.get(sortedWord).add(strs[i]);
        }

        List<List<String>> groupAnagramsList = new ArrayList<>(map.values());

        return groupAnagramsList;
    }
}
