/*
题目：给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，
其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。
请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。
题目数据保证线路图会形成一条不存在循环的线路，因此只会有一个旅行终点站。


输入和输出：
输入：paths = [["London", "New York"], ["New York", "Lima"], ["Lima", "Sao Paulo"]]
输出："Sao Paulo"
解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。
本次旅行的路线是 "London" -> "New York" -> "Lima" -> "Sao Paulo" 。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/destination-city
*/

class Solution {
public:
	string destCity(vector<vector<string>>& paths) {		
		string result = paths[0][1];				//让第一个path的初始终点为最终终点
		for (int i = 1; i < paths.size(); i++) {   //直接遍历，终点必然不在起点集合中
			if (paths[i][0] == result) {			//当初始终点在起点出现，则排除
				result = paths[i][1];
				i = 0;
			}

		}
		return result;
	}
};
