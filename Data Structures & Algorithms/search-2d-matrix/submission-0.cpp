class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(); // no of rows
        int col = matrix[0].size(); // no of cols

        int left = 0;
        int right = row-1;
        int selectRow = -1;

        while(left<=right){
            int mid = left+(right-left)/2;

            if(matrix[mid][0]<=target and target<=matrix[mid][col-1]){
            selectRow = mid;
            break;
            }

            if(target<matrix[mid][0])
            right = mid-1;

            else
            left = mid+1;
        }

        if(selectRow == -1)
        return false;

        int low = 0;
        int high = col-1;

        while(low<=high){

            int mid = low+(high-low)/2;

            if(target==matrix[selectRow][mid])
            return true;

            if(target<matrix[selectRow][mid])
            high = mid-1;

            else
            low = mid + 1;
        }

        return false;
    }
};
