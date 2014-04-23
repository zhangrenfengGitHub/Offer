/*
题目描述：
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
输入：
每个输入文件仅包含一组测试样例。
对于每组测试案例，输入一行代表要处理的字符串。
输出：
对应每个测试案例，出经过处理后的字符串。
样例输入：
We Are Happy
样例输出：
We%20Are%20Happy
*/

/*
算法步骤：1> 扫描原始字符串(假设字符串长度为len),统计空格数num
             则替换后的字符串长度为：length =len + 2 * num
          2> 设置两个指针，同时从原始字符串，替换后的字符串从后向前扫描
             因为length > len, 且从后向前扫描，所以可以利用原始字符串来存储替换后的字符串
时间复杂度O(n), 空间复杂度O(n)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAXN = 1000005;

int main()
{
    char str[MAXN];
    int i, num, len, length;

    while( gets(str) )
    {
        len = strlen(str);
        for( i = 0, num = 0; i < len; i++)           //统计空格数
        {
            if( str[i] == ' ')
               num++;
        }
        length = len + 2 * num;                     //替换后的字符串长度

        str[length--] ='\0';                        //字符串结束符
        for( i = len - 1; i >= 0; i--)              //从后向前遍历
        {
            if( str[i] == ' ')
            {
                str[length--] = '0';
                str[length--] = '2';
                str[length--] = '%';
            }
            else
                str[length--] = str[i];
        }
        printf("%s\n", str);
    }
    return 0;
}
