/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

// 需要创建结构体存储
// struct filePointer
// {
//     string fileName;
//     vector<filePointer*> childs;
//     filePointer()
//     {
//         fileName="";
//     }
//     filePointer(string name)
//     {
//         fileName=name;
//     }
// };


class Solution {
public:
    int lengthLongestPath(string input) {
        // 如何处理输入字符呢
        stringstream ss;
        ss<<input;
        string file;

        // 首先获取根目录的名称,创建指针
        getline(ss,file,'\n');
        int maxLen=0;
        if(file.find('.'!=string::npos)) maxLen=file.size();
        vector<int> levelNameLength;
        levelNameLength.push_back(file.size());
        while(getline(ss,file,'\n'))
        {
            // 如果是文件
            // 获取当前文件所在层次
            int level=0;
            int index=0;
            while(file[index++]=='\t') level++;
            // 此时的level代表所在层次
            if(file.find('.')!=string::npos)
            {
                int len=file.length()-level;
                for(int i=0;i<level;i++)
                    len+=levelNameLength[i]+1;
                maxLen=max(maxLen,len);
            }
            else
            { // 说明只是个文件夹
                // 此时的level也代表了问价夹所在的层次
                if(levelNameLength.size()<level) cout<<"Error On Level"<<endl;
                else if(levelNameLength.size()==level) levelNameLength.push_back(0);
                levelNameLength[level]=file.length()-level;
            }
        }
        return maxLen;
    }
};
// @lc code=end

