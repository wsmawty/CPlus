/*
题目描述：
不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
实现 MyHashSet 类：
void add(key) 向哈希集合中插入值 key 。
bool contains(key) 返回哈希集合中是否存在这个值 key 。
void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

输入输出及解释：
输入：
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
输出：
[null, null, null, true, false, null, true, null, false]
解释：
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // 返回 True
myHashSet.contains(3); // 返回 False ，（未找到）
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // 返回 True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // 返回 False ，（已移除）
提示：
0 <= key <= 106
最多调用 104 次 add、remove 和 contains 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashset

*/
class MyHashSet {
public:
	/** Initialize your data structure here. */
	vector<int> ans;						 //直接用vector容器实现，索引和值作哈希集合
	const int index = 1e6 + 10;              //0 <= key <= 106(10的六次方)定义一个最大的索引值
	MyHashSet() {
		ans.resize(index, 0);				 //初始化数据大小，默认所有索引的值为0
	}

	void add(int key) {						 //添加数据，直接在参数索引值为key的位置赋值为1
		ans[key] = 1;
	}

	void remove(int key) {				     //移除数据，重新将参数索引值为key的位置赋值为0
		ans[key] = 0;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {				 //判断该索引值key下的数值是否为1，不为1说明值不存在，返回false，反之为true
		if (ans[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
};