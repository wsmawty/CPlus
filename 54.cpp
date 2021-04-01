/*
��Ŀ������һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
���������
���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
�����[1,2,3,6,9,8,7,4,5]

https://leetcode-cn.com/problems/spiral-matrix/
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector <int> ans;
		if (matrix.empty()) {
			return ans;
		}
		int a = 0;						//�ϱ߽�
		int b = matrix.size() - 1;		//�±߽�
		int c = 0;						//��߽�
		int d = matrix[0].size() - 1;	//�ұ߽�
		while (true) {
			for (int i = c; i <= d; i++) {
				ans.push_back(matrix[a][i]);	//��������ʱ����һ��ȡ����
			}
			if (++a > b) {						//�ҵ��߽���ϱ߽���������ʼ������
				break;
			}
			for (int i = a; i <= b; i++) {		//��������ʱ����һ��ȡ���ݣ�
				ans.push_back(matrix[i][d]);
			}
			if (--d < c) {						///���±߽���ұ߽��Լ�����ʼ������
				break;
			}
			for (int i = d; i >= c; i--) {		//��������ʱ����һ��ȡ����
				ans.push_back(matrix[b][i]);	
			}
			if (--b < a) {						//����߽���±߽��Լ�����ʼ������
				break;
			}
			for (int i = b; i >= a; i--) {		//�������ϣ���һ��ȡ����
				ans.push_back(matrix[i][c]);
			}
			if (++c > d) {						//�����ϱ߽����߽�����������������
				break;							//���ұ߽�С����߽�����±߽�С���ϱ߽�ʱ���˳�ѭ��
			}
		}
		return ans;
	}
};