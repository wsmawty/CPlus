/*
��Ŀ������һ�������� n ������һ������ 1 �� n2 ����Ԫ�أ�
��Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix 

���������
���룺n = 3
�����[[1,2,3],[8,9,4],[7,6,5]]
https://leetcode-cn.com/problems/spiral-matrix-ii/
*/
//����һ����Ŀ���ƣ������������
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int>(n, 0));
		int a = 0;					//��
		int b = n - 1;				//��
		int c = 0;					//��
		int d = n - 1;				//��
		int index = 1;				//��ʼλ��
		int end = n * n;			//�����ж��Ƿ�����vector
		while (index <= end) {
			for (int i = c; i <= d; i++) {	//�������ң��������
				ans[a][i] = index++;
			}
			if (++a > b) {					//�ϱ߽�����
				break;
			}
			for (int i = a; i <= b; i++) {	//��������
				ans[i][d] = index++;
			}
			if (--d < c) {					//�ұ߽��Լ�
				break;
			}
			for (int i = d; i >= c; i--) {	//��������
				ans[b][i] = index++;
			}
			if (--b < a) {					//�±߽��Լ�
				break;
			}
			for (int i = b; i >= a; i--) {	//��������
				ans[i][c] = index++;
			}
			if (++c > d) {					//��߽�����
				break;						//���ұ߽�С����߽�����±߽�С���ϱ߽�ʱ���˳�ѭ��
			}
		}
		return ans;
	}
};