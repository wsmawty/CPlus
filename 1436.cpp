/*
��Ŀ������һ��������·ͼ������·ͼ�е�������·������ paths ��ʾ��
���� paths[i] = [cityAi, cityBi] ��ʾ����·����� cityAi ֱ��ǰ�� cityBi ��
�����ҳ�������е��յ�վ����û���κο���ͨ���������е���·�ĳ��С�
��Ŀ���ݱ�֤��·ͼ���γ�һ��������ѭ������·�����ֻ����һ�������յ�վ��


����������
���룺paths = [["London", "New York"], ["New York", "Lima"], ["Lima", "Sao Paulo"]]
�����"Sao Paulo"
���ͣ��� "London" ���������ִ��յ�վ "Sao Paulo" ��
�������е�·���� "London" -> "New York" -> "Lima" -> "Sao Paulo" ��

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/destination-city
*/

class Solution {
public:
	string destCity(vector<vector<string>>& paths) {		
		string result = paths[0][1];				//�õ�һ��path�ĳ�ʼ�յ�Ϊ�����յ�
		for (int i = 1; i < paths.size(); i++) {   //ֱ�ӱ������յ��Ȼ������㼯����
			if (paths[i][0] == result) {			//����ʼ�յ��������֣����ų�
				result = paths[i][1];
				i = 0;
			}

		}
		return result;
	}
};
