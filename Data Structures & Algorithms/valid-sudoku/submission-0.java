class Solution {
    public boolean isValidSudoku(char[][] board) {
        
        int rows = board.length;
        int cols = board[0].length;

        for(int i=0;i<rows;i++){
            Map<Character,Boolean> freqMap = new HashMap<>();

            for(int j=0;j<cols;j++){

                if(board[i][j]=='.')
                continue;

                if(freqMap.containsKey(board[i][j]))
                return false;

                freqMap.put(board[i][j],true);
            }
        }

        

        for(int i=0;i<cols;i++){
            Map<Character,Boolean> freqMap = new HashMap<>();

            for(int j=0;j<rows;j++){

                if(board[j][i]=='.')
                continue;

                if(freqMap.containsKey(board[j][i]))
                return false;

                freqMap.put(board[j][i],true);
            }
        }

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){

            Map<Character,Boolean> freqMap = new HashMap<>();

                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){

                         if(board[x][y]=='.')
                        continue;

                        if(freqMap.containsKey(board[x][y]))
                        return false;

                        freqMap.put(board[x][y],true);
                    }
                }
            }
        }

        return true;
    }
}
