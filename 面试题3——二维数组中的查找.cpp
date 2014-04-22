/*
题目地址：http://ac.jobdu.com/problem.php?pid=1384

题目描述：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
输入：
输入可能包含多个测试样例，对于每个测试案例，
输入的第一行为两个整数m和n(1<=m,n<=1000)：代表将要输入的矩阵的行数和列数。
输入的第二行包括一个整数t(1<=t<=1000000)：代表要查找的数字。
接下来的m行，每行有n个数，代表题目所给出的m行n列的矩阵(矩阵如题目描述所示，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
输出：
对应每个测试案例，
输出”Yes”代表在二维数组中找到了数字t。
输出”No”代表在二维数组中没有找到数字t。
样例输入：
3 3
5
1 2 3
4 5 6
7 8 9
3 3
1
2 3 4
5 6 7
8 9 10
3 3
12
2 3 4
5 6 7
8 9 10
样例输出：
Yes
No
No
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1005;

int main()
{
	int i, j, m, n, key;
	int row, col, tmp, num[MAXN][MAXN];
	bool flag;

	while(scanf("%d%d", &m,&n) != EOF)
	{
		scanf("%d", &key);
		for( i = 1; i <= m; i++)
		{
			for( j = 1; j <= n; j++)
				scanf("%d", &num[i][j]);
		}

		row = 1;											//第一次取右上角元素
		col = n;
		flag = false;
		while( (row <= m) && (col >= 1))
		{
			tmp = num[row][col];

			if( tmp == key)
			{
				flag = true;
				break;
			}
			else if( tmp < key)								//比右上角元素大，即在右上角元素下方，则删除右上角所在行
				row++;
			else if( tmp > key)								//比右上角元素小，即在右上角元素左方，则删除右上角所在列
				col--;
		}

		if( flag)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
