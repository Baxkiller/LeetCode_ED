#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
// int pindex=0,sindex=0;
// bool allmatch=false;
// while (sindex < s.length())
// {
//     if(s[sindex]==p[pindex])
//     {pindex++,sindex++;}
//     else if(p[pindex]=='*')
//     {
//         // 出现了.*
//         if(p[pindex-1]=='.') {allmatch=true;break;}
//         if(p[pindex-1]==s[sindex]) sindex++;
//         else pindex++;
//     }
//     else if(p[pindex]=='.'){pindex++,sindex++;}
//     else{
//         if(pindex+1<p.length() && p[pindex+1]=='*')
//         {
//             pindex++;
//         }
//         else
//         {
//             cout<<p[pindex] <<"!="<<s[sindex]<<endl;
//             return false;
//         }
//     }

//     if(pindex==p.length() && sindex <s.length()){
//         cout<<"Length Error"<<endl;
//         return false;
//     }else if(pindex<p.length() && sindex==s.length())
//     {
//         // if(pindex+1==p.length() && p[pindex]!='*') return false;
//         // else if(pindex+2==p.length() && p[pindex+1]!='*') return false;
//         // else return false;
//         if(p[pindex]=='*')
//         {
//             if(pindex+1!=p.length()) return false;
//         }
//         else if(pindex+1==p.length()-1 && p[pindex]=='*')
//         {
//             return true;
//         }
//     }
// }
// if(allmatch)
// {
//     for(int i=s.length()-1,j=p.length()-1;i>0&& p[j]!='*';)
//     {
//         if(s[i]==p[j])
//         {
//             i--,j--;
//         }
//         else if(p[j]=='.')
//         {
//             i--,j--;
//         }
//         else
//             return false;
//     }
// }
// return true;

// }

// 样例
// "aab" "c*a*b"

// "mississippi" "mis*is*p*."

// "aaa" "a.a"

// "aaa" "ab*a*c*a"


///---------------------
/// 内容匹配有三种情况
/// 1. 内容正好相等
/// 2. pattern中对应字符为.
/// 3. pattern中匹配指针指向*,
///    且s的i位置与*之前的内容相等
///---------------------
// @lc code=start
class Solution {
public:
struct charNum
{
    char c;
    int pre;
    int back;
    bool flex;
    // charNum(){c='',pre=0,back=0,flex;}
    charNum(char cc){c=cc,pre=1,back=0,flex=false;}
};

    bool isMatch(string s, string p) {
        // 可以去进行字符合并,然后进行比较
        vector<charNum> ss;
        vector<charNum> pp;
        // i指向ss中的刚刚被操作过的一个
        int i=0,j=0;
        bool allMatch=false;
        ss.push_back(charNum(s[0]));
        pp.push_back(charNum(p[0]));
        for(int tmp=1;tmp<s.length();tmp++)
        {
            if(s[tmp]==ss[i].c) ss[i].pre++;
            else
            {
                ss.push_back(charNum(s[tmp]));
                i++;
            }
        }
        for(int tmp=1;tmp<p.length();tmp++)
        {
            if(p[tmp]==pp[j].c)
            {
                if(pp[j].flex) pp[j].back++;
                else pp[j].pre++;
            }
            else if(p[tmp]=='*')
            {
                pp[j].flex=true;
                pp[j].pre--;
            }
            // else if(p[tmp]=='.')
            // {
            //     pp.push_back(charNum(p[tmp]));
            //     j++;
            // }
            else
            {
                pp.push_back(charNum(p[tmp]));
                j++;
            }
        }
        int ssSize=ss.size();
        int ppSize=pp.size();
        cout<<"pp.size = "<<ppSize<<endl;
        cout<<"ss.size = "<<ssSize<<endl;
        for(i=0,j=0;i<ssSize&&j<ppSize;)
        {
            cout<<"i="<<i<<" "<<"j="<<j<<endl;
            if(ss[i].c !=pp[j].c && pp[j].c !='.')
            {
                cout<<"Not Equal And Not ."<<endl;
                if(pp[j].flex && pp[j].pre+pp[j].back ==0){
                    cout<<"Next pp"<<endl;
                    j++;
                }
                else return false;
            }
            else if(ss[i].c==pp[j].c)
            {
                cout<<"Equal"<<endl;
                if(pp[j].flex)
                {
                    if(ss[i].pre<pp[j].pre+pp[j].back) return false;
                    else i++,j++;
                }
                else
                {
                    if(ss[i].pre > pp[j].pre)
                    {
                        ss[i].pre-=pp[j].pre;
                        j++;
                    }
                    else if(ss[i].pre==pp[j].pre){
                        i++,j++;
                    }
                    else 
                    {
                        return false;
                    }
                }
            }
            else if(pp[j].c=='.')
            {
                cout<<"Entrance ."<<endl;
                if(!pp[j].flex)
                {
                    if(pp[j].pre >ss[i].pre)
                    {
                        pp[j].pre-=ss[i].pre;
                        i++;
                    }
                    else if(pp[j].pre<ss[i].pre)
                    {
                        ss[i].pre-=pp[j].pre;
                        j++;
                    }
                    else
                    {
                        i++,j++;
                    }
                }
                else
                {
                    allMatch=true;
                    break;
                }
            }
            else
            {
                cout<<"Error"<<endl;
                return false;
            }
        }

        if(allMatch)
        {
            cout<<"Check Tail Match"<<endl;
            for(int i=s.length(),j=p.length();
            p[j]!='*'&& i>=0 && j>=0;i--,j--)
            {
                if(s[i]==p[j] || p[j]=='.') continue;
                else return false;
            }
        }
        else
        {
            cout<<"Length Not Match"<<endl;
            if(i!=ssSize) return false;
            if(j!=ppSize)
            {
                for(;j<ppSize;j++)
                {
                    if(!pp[j].flex || pp[j].pre+pp[j].back >0)
                    {
                        if(pp[j].pre >0 && pp[j].c !=ss.back().c) return false;
                        else if(!pp[j].flex)
                            return f
                    }
                }
            }
        }


        return true;
    }
};
// @lc code=end

