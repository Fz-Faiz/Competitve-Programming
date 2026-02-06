/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        int low = 1, high = n;
        while(high - low > 1){
            int mid = low + (high- low)/2;
            
            int val = guess(mid);

            if(val == 1) low = mid + 1;
            else if(val == -1 ) high = mid;
            else return mid;
            
        }

        if(guess(low) == 0) return low;
        else return high; 
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int lo = 1, hi = x;

        while(hi - lo > 1){
            int mid = lo + (hi - lo) / 2;

            if(mid <= x / mid) lo = mid;
            else hi = mid;
        }
        
        if(hi <= x / hi) return hi;
        else return lo;
    }
};

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lo = 0;
        int hi = n * m - 1;

        while( hi - lo > 1){
            int mid = lo + (hi - lo) / 2;
            int row = mid / m , col = mid % m;
            if(matrix[row][col] < target) lo = mid + 1;
            else hi = mid;
        }

        if(matrix[lo/m][lo%m] == target || matrix[hi/m][hi%m] == target) return true;
        return false;
    }
};