/*
��Ŀ����ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣӳ�䣨HashMap����ʵ�� MyHashMap �ࣺ
MyHashMap() �ÿ�ӳ���ʼ������
void put(int key, int value) �� HashMap ����һ����ֵ�� (key, value) ����� key �Ѿ�������ӳ���У���������Ӧ��ֵ value ��
int get(int key) �����ض��� key ��ӳ��� value �����ӳ���в����� key ��ӳ�䣬���� -1 ��
void remove(key) ���ӳ���д��� key ��ӳ�䣬���Ƴ� key ��������Ӧ�� value ��

������������ͣ�
���룺
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
�����
[null, null, null, 1, -1, null, 1, null, -1]

���ͣ�
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // myHashMap ����Ϊ [[1,1]]
myHashMap.put(2, 2); // myHashMap ����Ϊ [[1,1], [2,2]]
myHashMap.get(1);    // ���� 1 ��myHashMap ����Ϊ [[1,1], [2,2]]
myHashMap.get(3);    // ���� -1��δ�ҵ�����myHashMap ����Ϊ [[1,1], [2,2]]
myHashMap.put(2, 1); // myHashMap ����Ϊ [[1,1], [2,1]]���������е�ֵ��
myHashMap.get(2);    // ���� 1 ��myHashMap ����Ϊ [[1,1], [2,1]]
myHashMap.remove(2); // ɾ����Ϊ 2 �����ݣ�myHashMap ����Ϊ [[1,1]]
myHashMap.get(2);    // ���� -1��δ�ҵ�����myHashMap ����Ϊ [[1,1]]


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-hashmap
*/
class MyHashMap {
public:
	/** Initialize your data structure here. */
	vector<int> ans;						//ֱ��ʹ��vector����ʵ��
	const int index = 1e6 + 10;				//��Ŀ��value<10000000����ʼ��vectorʱ����index���ռ�
	MyHashMap() {
		ans = vector<int>(index, -1);		//���е�ֵ��ʼ��Ϊ-1����ʾ������
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		ans[key] = value;					//������
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		return ans[key];					//��ȡkey���ݣ�ֱ��return
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		ans[key] = -1;						//�Ƴ����ݣ����±�Ϊkey��ֵ�ĳ�-1��
	}
};