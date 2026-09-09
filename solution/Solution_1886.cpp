/**
 * 題目：1886. Determine Whether Matrix Can Be Obtained By Rotation
 * 難度：簡單 (Easy)
 * 描述：判斷矩陣 mat 是否可以透過旋轉 0、90、180 或 270 度得到矩陣 target。
 * 時間複雜度：O(N^2)
 * 空間複雜度：O(1)

 */
class Solution {
public:
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0 ; i< 4 ; i++ ) {
            if(mat == target) {
                return true;
            }
            rotate(mat);
        }
        return false;
    }
private:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n ; i++) {
            for(int j = i+1; j < n ; j++) {
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i = 0; i < n ; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        
    }
};