/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects=rects;
        int n=rects.size();
        squares[0]=(rects[0][2]-rects[0][0])*(rects[0][3]-rects[0][1]);
        for(int i=1;i<n;i++)
        {
            squares[i]=static_cast<long long>
            (rects[0][2]-rects[0][0])*(rects[0][3]-rects[0][1])
            +squares[i-1];
        }
        max_Size=squares[n-1];
    }
    
    vector<int> pick() {
        int index_rect=rand()%max_Size;
        index_rect=upper_bound(squares.begin(),squares.end(),index_rect);
        index_rect--;
        vector<int> rect=rects[index_rect];
        int w=(rect[2]-rect[0]);
        int h=(rect[3]-rect[1]);

        int ix=rand() % w;
        int iy=rand() % h;

        return {rect[0]+ix,rect[1]+iy};
    }

private :
    vector<vector<int>> rects;
    vector<long long> squares;
    int max_Size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

