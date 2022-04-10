/*
 * @lc app=leetcode.cn id=780 lang=cpp
 *
 * [780] 到达终点
 */
// 10\n1\n11\n6
// 4\n2\n2\n4
// 进行逆推 注意逆推时超结果前进的每一步的特点

// @lc code=start
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx > 0 && ty > 0)
        {
            if(tx==sx)
            {
                return (ty>=sy) && (ty-sy)%tx==0;
            }
            if(ty==sy)
            {
                return (tx>=sx) && (tx-sx)%ty==0;
            }
            
            if(tx > ty)
            {
                if(tx-sx < ty) return false;
                tx-=max((tx-sx)/ty,1)*ty;
            }
            else
            {
                if(ty-sy < tx) return false; 
                ty-=max((ty-sy)/tx,1)*tx;
            }
        }
        return false;
    }
};
// @lc code=end

