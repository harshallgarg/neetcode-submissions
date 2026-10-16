// O(nlogk)
// one more solution is there - use bucket sort

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        
        // max heap
        // PriorityQueue<int[]> maxHeap = new PriorityQueue<>(Comparator.comparingInt((int[] a) -> a[0]).reversed());

        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(arr -> arr[0]));


        Map<Integer,Integer> freqMap = new HashMap<>(); // {number, freq}

        for(int i=0;i<nums.length;i++){

            if(freqMap.containsKey(nums[i])){
            Integer freq = freqMap.get(nums[i]) + 1;
            freqMap.put(nums[i],freq);
            }
            else
            freqMap.put(nums[i],1);
        }

        for(var entry: freqMap.entrySet()){    

            minHeap.add(new int[]{entry.getValue(), entry.getKey()});

            if(minHeap.size()>k)
            minHeap.poll();
        }

        int[] answerArray = new int[k];
        int i=0;

        for(var pair: minHeap){
            answerArray[i++] = pair[1];
        }

        return answerArray;
    }
}
