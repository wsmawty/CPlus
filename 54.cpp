/*
题目：给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
输入输出：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

https://leetcode-cn.com/problems/spiral-matrix/
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector <int> ans;
		if (matrix.empty()) {
			return ans;
		}
		int a = 0;						//上边界
		int b = matrix.size() - 1;		//下边界
		int c = 0;						//左边界
		int d = matrix[0].size() - 1;	//右边界
		while (true) {
			for (int i = c; i <= d; i++) {
				ans.push_back(matrix[a][i]);	//从左往右时，逐一获取数据
			}
			if (++a > b) {						//右到边界后，上边界自增，开始往下走
				break;
			}
			for (int i = a; i <= b; i++) {		//从上往下时，逐一获取数据，
				ans.push_back(matrix[i][d]);
			}
			if (--d < c) {						///到下边界后，右边界自减，开始往左走
				break;
			}
			for (int i = d; i >= c; i--) {		//从左往右时，逐一获取数据
				ans.push_back(matrix[b][i]);	
			}
			if (--b < a) {						//到左边界后，下边界自减，开始往上走
				break;
			}
			for (int i = b; i >= a; i--) {		//从下往上，逐一获取数据
				ans.push_back(matrix[i][c]);
			}
			if (++c > d) {						//到达上边界后，左边界自增，继续往右走
				break;							//当右边界小于左边界或者下边界小于上边界时，退出循环
			}
		}
		return ans;
	}
};