/*
题目描述:
题目描述：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并输出它的后序遍历序列。

输入：
输入可能包含多个测试样例，对于每个测试案例，
输入的第一行为一个整数n(1<=n<=1000)：代表二叉树的节点个数。
输入的第二行包括n个整数(其中每个元素a的范围为(1<=a<=1000))：代表二叉树的前序遍历序列。
输入的第三行包括n个整数(其中每个元素a的范围为(1<=a<=1000))：代表二叉树的中序遍历序列。
输出：
对应每个测试案例，输出一行：
如果题目中所给的前序和中序遍历序列能构成一棵二叉树，则输出n个整数，代表二叉树的后序遍历序列，每个元素后面都有空格。
如果题目中所给的前序和中序遍历序列不能构成一棵二叉树，则输出”No”。
样例输入：
8
1 2 4 7 3 5 6 8
4 7 2 1 5 3 8 6
8
1 2 4 7 3 5 6 8
4 1 2 7 5 3 8 6
样例输出：
7 4 2 5 8 6 3 1
No
*/

/*
已知二叉树的前序序列和中序序列求该二叉树的后序序列
前序序列的第一个数字为根节点，在中序序列中找到该数字，则该数字前面为左子树，后面为右子树，然后递归构建二叉树
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1005;

//pre为前序序列，in为后序序列，n为节点数,post存储后序序列
int usedPreAndInToAchievePost(int *pre, int *in, int n, int *post)
{
    if( n <= 0)
        return 1;

    int i, left, right;
    for( i = 0; i < n; i++)                                     //在中序序列中查找根节点
    {
        if( in[i] == *pre)
            break;
    }
    if( i >= n )                                                 //无根节点
        return 0;

    left = usedPreAndInToAchievePost(pre + 1, in, i, post);     //递归构建左子树
    right = usedPreAndInToAchievePost(pre + i + 1, in + i + 1, n - i - 1, post + i);
    post[n-1] = *pre;                                            //后序遍历的根节点

    return left && right;
}

//in为后序序列，post为后序序列，n为节点数,pre存储后序序列
int usedInAndPostToAchievePre(int *in, int *post, int n, int *pre)
{
    if( n <= 0)
        return 1;

    int i, left, right;
    for( i = 0; i < n; i++)
    {
        if( in[i] == post[n-1])                                     //post[n-1]为根节点
            break;
    }
    if( i >= n)                                                     //中序序列中不存在根节点
        return 0;

    pre[0] = post[n - 1];                                           //线序遍历的根节点
    left = usedInAndPostToAchievePre(in, post, i, pre + 1);
    right = usedInAndPostToAchievePre(in + i + 1, post + i, n - 1 - i, pre + i + 1);

    return left && right;
}

int main()
{
    int i, n;
    int pre[MAXN], in[MAXN], post[MAXN];

    while( scanf("%d", &n) != EOF)
    {
        for( i = 0; i < n; i++)
            scanf("%d", &pre[i]);
        for( i = 0; i < n; i++)
            scanf("%d", &in[i]);

        int flag = usedPreAndInToAchievePost(pre, in, n, post);

        if( flag )
        {
            for( i = 0; i < n; i++)
                printf("%d ", post[i]);
            printf("\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
























