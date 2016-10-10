#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int find_number(string &s1, string &s2);

int main()
{
    string s1 = "GCCCTAABCDEFGGCCAGDE";
    string s2 = "GCGCCAABCDEFGGTGDE";
    
    cout << find_number(s1, s2) << endl;
    
    return 0;
}

/**
 * 思路为指定 S1 某个字符下标N，然后在 S2 中进行匹配。
 * 如果匹配不成功再设置为原来的N值，继续匹配，直到遍历整个S2
 */
int find_number(string &s1, string &s2)
{
    int result = 0;
    for (int i = 0; i < s1.length(); ++i) {
        int k = i;
        int j = 0;
        int max = 0;
        
        //这里的j++很精髓
        while (j++ < s2.length()) {
            /**  这里没有很好的解决j的递增问题
            k = i;
            max = 0;
            while (s1[k] == s2[j]) {
                ++k;
                ++j;
                ++max;
            }
            if (max > result)
                result = max;
            */
            if (s1[k] == s2[j]) {
                ++k;
                ++max;
            } else {
                if (max > result) {
                    result = max;
                }
                k = i;
                max = 0;
            }
        }
    }

    return result;
}