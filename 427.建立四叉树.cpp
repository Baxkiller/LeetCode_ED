/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

/*
vector<vector<int>> grid;
void recursion(Node* &root,int x,int y,int len)
{// 传入时的root 不一定是真的root,只是提供了一个root的指针
    // 从(x,y)开始,长度为n
    int beginNum=grid[x][y];
    
    if(len==1)
    {
        root->val=beginNum;
        root->isLeaf=true;
        return;
    }

    for(int i=x,u=0;u<len;i++,u++)
    {
        for(int j=y,v=0;v<len;j++,v++)
        {
            if(grid[i][j]!=beginNum)
            {// 当前节点一定不是叶子节点了
                // 需要为其创建四个子结点
                root->isLeaf=false;
                root->val=0;
                NotLeafNode(root,x,y,len);
                return;
            }
        }
    }
    // 是叶子节点就不需要再创建子节点了
    root->isLeaf=true;
    root->val=beginNum;
    return;
}
void NotLeafNode(Node*& root,int x,int y,int len)
{
    root->topLeft=new Node(0,false);
    recursion(root->topLeft,x,y,len/2);
    root->topRight=new Node(0,false);
    recursion(root->topRight,x,y+len/2,len/2);
    root->bottomLeft=new Node(0,false);
    recursion(root->bottomLeft,x+len/2,y,len/2);
    root->bottomRight=new Node(0,false);
    recursion(root->bottomRight,x+len/2,y+len/2,len/2);
}
Node* construct(vector<vector<int>>& grid) {
    int n=grid.size();
    if(n==1)
    {
        Node* root=new Node(grid[0][0],true);
        return root;
    }
    this->grid=grid;

    // 如果不是只有一个的情况,那么根一定不是叶子?
    // 不一定
    // 可以递归求解?
    Node* root=new Node(0,false);
    recursion(root,0,0,n);
    return root;
}
*/


// @lc code=start
// 开始的想法是直接通过遍历进行求解
// 时间复杂度大概在O(n^2logn) 其中n代表行数
// 时间空间: 53.06--95
// 如果采用前缀和的方式进行求解
// 判断一个区域是否为叶子节点
// 只需要确保这个区域的和为0(即整个区域的节点值都为0)
// 或者和为这个区域的大小(每个区域的节点值都为1)
// 时间空间 82--94
// 98--95

// 感觉也可以通过队列的方式进行求解
class Solution {
public:
    vector<vector<int>> grid;
    void recursion(Node* root,int x,int y,int len)
    {
        // 先获取这个区域的前缀和
        int preSum;
        if(x==0 && y==0)
            preSum=grid[x+len-1][y+len-1];
        else if(x==0 && y!=0)
            preSum=grid[x+len-1][y+len-1]-grid[x+len-1][y-1];
        else if(x!=0 && y==0)
            preSum=grid[x+len-1][y+len-1]-grid[x-1][y+len-1];
        else
            preSum=grid[x+len-1][y+len-1]-grid[x-1][y+len-1]-grid[x+len-1][y-1]+grid[x-1][y-1];
        int S=len*len;
        if(preSum==S)
            root->isLeaf=true,root->val=1;
        else if(preSum==0)
            root->isLeaf=true,root->val=0;
        else
        {// not leaf,change its four childs
            root->bottomLeft=new Node(0,false);
            root->bottomRight=new Node(0,false);
            root->topLeft=new Node(0,false);
            root->topRight=new Node(0,false);
            recursion(root->bottomLeft,x+len/2,y,len/2);
            recursion(root->bottomRight,x+len/2,y+len/2,len/2);
            recursion(root->topLeft,x,y,len/2);
            recursion(root->topRight,x,y+len/2,len/2);
        }
    }
    Node* construct(vector<vector<int>>& grid)
    {
        // 矩阵前缀和的求解需要先将最上面一行和最左侧一列的前缀和求出来
        int n=grid.size();
        for(int i=1;i<n;i++)
        {// 最上面一行的前缀和求解
            grid[0][i]+=grid[0][i-1];
            grid[i][0]+=grid[i-1][0];
        }
        // 进行其他区域前缀和的求解
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            }
        }

        Node* root;
        this->grid=grid;
        root=new Node(grid[0][0],false);
        // 进行递归判断求解?
        recursion(root,0,0,n);
        return root;
    }
};
// @lc code=end

