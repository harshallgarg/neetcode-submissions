class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        List<List<Integer>> answerList = new ArrayList<>();

        Set<List<Integer>> uniqueTriplets = new HashSet<>();

        Arrays.sort(nums);

        for(int i=0;i<nums.length-2;i++){
            int a = nums[i];

            // a + b + c = 0
            int target = -a;

            int j = i+1;
            int k = nums.length-1;

            while(j<k){
                int sum = nums[j]+nums[k];

                if(sum==target)
                {
                    // answerList.add(new ArrayList<>(List.of(a,nums[j],nums[k])));
                    uniqueTriplets.add(new ArrayList<>(List.of(a,nums[j],nums[k])));
                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1])
                    j++;

                    while(j<k && nums[k]==nums[k+1])
                    k--;
                }

                else if(sum<target)
                j++;

                else
                k--;
            }
        }

        for(var triplets:uniqueTriplets){
            answerList.add(triplets);
        }

        return answerList;
    }
}
