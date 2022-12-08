/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius=radius;
        this->x=x_center;
        this->y=y_center;
    }
    
    vector<double> randPoint() {
        bool check=false;
        double nx,ny;
        do{
            nx=(static_cast<float>(rand()))/RAND_MAX*2*radius-radius;
            ny=(static_cast<float>(rand()))/RAND_MAX*2*radius-radius;

            if(pow(nx,2)+pow(ny,2)>radius*radius)
                check=true;
            else
                check=false;
        }while(check);

        return {x+nx,y+ny}; 
    }
private:
    double radius;
    double x,y;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

