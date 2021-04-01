/*
��Ŀ������
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣ���ϣ�HashSet����
ʵ�� MyHashSet �ࣺ
void add(key) ���ϣ�����в���ֵ key ��
bool contains(key) ���ع�ϣ�������Ƿ�������ֵ key ��
void remove(key) ������ֵ key �ӹ�ϣ������ɾ���������ϣ������û�����ֵ��ʲôҲ������

������������ͣ�
���룺
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
�����
[null, null, null, true, false, null, true, null, false]
���ͣ�
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // ���� True
myHashSet.contains(3); // ���� False ����δ�ҵ���
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // ���� True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // ���� False �������Ƴ���
��ʾ��
0 <= key <= 106
������ 104 �� add��remove �� contains ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-hashset

*/
class MyHashSet {
public:
	/** Initialize your data structure here. */
	vector<int> ans;						 //ֱ����vector����ʵ�֣�������ֵ����ϣ����
	const int index = 1e6 + 10;              //0 <= key <= 106(10�����η�)����һ����������ֵ
	MyHashSet() {
		ans.resize(index, 0);				 //��ʼ�����ݴ�С��Ĭ������������ֵΪ0
	}

	void add(int key) {						 //������ݣ�ֱ���ڲ�������ֵΪkey��λ�ø�ֵΪ1
		ans[key] = 1;
	}

	void remove(int key) {				     //�Ƴ����ݣ����½���������ֵΪkey��λ�ø�ֵΪ0
		ans[key] = 0;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {				 //�жϸ�����ֵkey�µ���ֵ�Ƿ�Ϊ1����Ϊ1˵��ֵ�����ڣ�����false����֮Ϊtrue
		if (ans[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
};