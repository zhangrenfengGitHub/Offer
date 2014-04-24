/*
题目描述:
题目描述：
输入一个链表，从尾到头打印链表每个节点的值。
输入：
每个输入文件仅包含一组测试样例。
每一组测试案例包含多行，每行一个大于0的整数，代表一个链表的节点。第一行是链表第一个节点的值，依次类推。当输入到-1时代表链表输入完毕。-1本身不属于链表。
输出：
对应每个测试案例，以从尾到头的顺序输出链表每个节点的值，每个值占一行。
样例输入：
1
2
3
4
5
-1
样例输出：
5
4
3
2
1
*/

/*
即将链表逆序输出，很自然的想到递归算法
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct ListNode
 {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution
{
public:
        void reverseListAlgotirhm1(ListNode *head)                //递归算法
        {
            if( head == NULL)
                return;

            reverseListAlgotirhm1(head->next);
            printf("%d\n", head->val);
        }

        void reverseListAlgorithm2(ListNode *head)              //非递归算法
        {
            stack<ListNode *> listNodes;
            ListNode *current = head;
            while( current)
            {
                listNodes.push(current);
                current = current->next;
            }

            while( !listNodes.empty())                         // 栈非空
            {
                current = listNodes.top();
                printf("%d\n", current->val);
                listNodes.pop();
            }
        }
};

int main()
{
    int n;
    ListNode *head, *node, *tmp;

    head = NULL;
    while( scanf("%d", &n) != EOF && (n != -1))
    {
        node = (ListNode *)malloc(sizeof(ListNode));
        node->val = n;

        if( head == NULL)                                       //采用尾插法建立链表
        {
            head = node;
            tmp = head;
        }
        else
        {
            tmp->next = node;
            tmp = node;
        }
        tmp->next = NULL;
    }
    class Solution solution;
    //solution.reverseListAlgotirhm1(head);
    solution.reverseListAlgorithm2(head);

    return 0;
}
















