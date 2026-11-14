class Solution {
public:

    int findPivot(vector<int> &nums){

        int n = nums.size();
        int low = 0;
        int high = n-1;

        int pivot = n;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(nums[mid]<=nums[n-1]){
                pivot = mid;
                high = mid-1; 
            }

            else
            low = mid+1;
        }

        return pivot;
    }

    int binarySearch(int low, int high, int target, vector<int> &nums){

        while(low<=high){
            int mid = low+(high-low)/2;

            if(nums[mid]==target)
            return mid;

            if(nums[mid]<target)
            low = mid+1;

            else
            high = mid-1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivot = findPivot(nums);
        int n = nums.size();

        int ind1 = binarySearch(0,pivot-1,target,nums);
        int ind2 = binarySearch(pivot,n-1,target,nums);

        if(ind1==-1 and ind2==-1)
        return -1;

        if(ind1==-1)
        return ind2;

        return ind1;
    }
};
