/*
题目：给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，
且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 

输入输出：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
https://leetcode-cn.com/problems/spiral-matrix-ii/
*/
//和上一道题目类似，反过来球矩阵
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int>(n, 0));
		int a = 0;					//上
		int b = n - 1;				//下
		int c = 0;					//左
		int d = n - 1;				//右
		int index = 1;				//初始位置
		int end = n * n;			//用于判断是否填完vector
		while (index <= end) {
			for (int i = c; i <= d; i++) {	//从左往右，填充数据
				ans[a][i] = index++;
			}
			if (++a > b) {					//上边界自增
				break;
			}
			for (int i = a; i <= b; i++) {	//从上往下
				ans[i][d] = index++;
			}
			if (--d < c) {					//右边界自减
				break;
			}
			for (int i = d; i >= c; i--) {	//从右往左
				ans[b][i] = index++;
			}
			if (--b < a) {					//下边界自减
				break;
			}
			for (int i = b; i >= a; i--) {	//从下往上
				ans[i][c] = index++;
			}
			if (++c > d) {					//左边界自增
				break;						//当右边界小于左边界或者下边界小于上边界时，退出循环
			}
		}
		return ans;
	}
};