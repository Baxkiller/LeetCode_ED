#include <bits/stdc++.h>
using namespace std;


// 初始题解: 采用暴力法进行求解
// 后来更改方法,使用前缀和进行求解,时间效率 30%->80%
// 实现效率显著提高
// vector<vector<int>> ret(img.size(),vector<int>(img[0].size()));
//         // 遍历每一行
//         for(int i=0;i<img.size();i++)
//         {// 遍历每一列
//             for(int j=0;j<img[0].size();j++)
//             {
//                 int left=max(0,j-1);
//                 int top=max(0,i-1);
//                 int right=min<int>(j+1,img[0].size()-1);
//                 int bottom=min<int>(i+1,img.size()-1);
//                 float sums=0;
//                 int count=0;
//                 for(int m=top;m<=bottom;m++)
//                 {
//                     for(int n=left;n<=right;n++)
//                     {
//                         sums+=img[m][n];
//                         count++;
//                     }
//                 }
//                 ret[i][j]=floor(sums/count);
//             }
//         }
//         return ret;

/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // 首先尝试计算前缀和,然后每次计算都通过前缀和进行计算
        for(int j=1;j<img[0].size();j++)
        {
            img[0][j]+=img[0][j-1];
        }
        for(int i=1;i<img.size();i++) // 每行元素的遍历
        {
            img[i][0]+=img[i-1][0];
            for(int j=1;j<img[0].size();j++) // 每列元素的遍历
            {
                img[i][j]+=(img[i-1][j]+img[i][j-1]-img[i-1][j-1]);
            }
        }

        vector<vector<int>> ret(img.size(),vector<int>(img[0].size()));
        // 遍历每一行
        for(int i=0;i<img.size();i++)
        {// 遍历每一列
            for(int j=0;j<img[0].size();j++)
            {
                int left=max(0,j-1);
                int top=max(0,i-1);
                int right=min<int>(j+1,img[0].size()-1);
                int bottom=min<int>(i+1,img.size()-1);
                float sums=0;
                if(left==0&&top==0)
                {
                    sums=img[bottom][right];
                }
                else if(left==0 && top!=0)
                {
                    sums=img[bottom][right]-img[top-1][right];
                }
                else if(left && top==0)
                {
                    sums=img[bottom][right]-img[bottom][left-1];
                }
                else
                {
                    sums=img[bottom][right]+img[top-1][left-1]-img[bottom][left-1]-img[top-1][right];
                }
                int count=(right-left+1)*(bottom-top+1);
                ret[i][j]=floor(sums/count);
            }
        }
        return ret;
    }
};
// @lc code=end

