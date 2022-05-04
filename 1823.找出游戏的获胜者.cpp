/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
	 /*从结果最后剩下的那个元素位置为0开始推；
	    跟踪这个元素的位置下标
	    考虑k > n的情况因此每次对元素队列取余操作；
	    直到队列个数恢复至开始状态；
	    得到这个最后剩下的元素下标。(本题记得答案位置+1)
	*/
        int i  = 2, f = 0;
        while(i <= n){
            f = (f + k) % (i ++);
        }
        return f + 1;
    }
};
// @lc code=end

