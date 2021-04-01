/*
题目描述：
请你实现一个类 UndergroundSystem ，它支持以下 3 种方法：
1. checkIn(int id, string stationName, int t)
编号为 id 的乘客在 t 时刻进入地铁站 stationName 。
一个乘客在同一时间只能在一个地铁站进入或者离开。
2. checkOut(int id, string stationName, int t)
编号为 id 的乘客在 t 时刻离开地铁站 stationName 。
3. getAverageTime(string startStation, string endStation) 
返回从地铁站 startStation 到地铁站 endStation 的平均花费时间。
平均时间计算的行程包括当前为止所有从 startStation 直接到达 endStation 的行程。
调用 getAverageTime 时，询问的路线至少包含一趟行程。
你可以假设所有对 checkIn 和 checkOut 的调用都是符合逻辑的。也就是说，如果一个顾客在 t1 时刻到达某个地铁站，那么他离开的时间 t2 一定满足 t2 > t1 。所有的事件都按时间顺序给出。

输入输出及解释：
输入：
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

输出：
[null,null,null,null,null,null,null,14.0,11.0,null,11.0,null,12.0]

解释：
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(45, "Leyton", 3);
undergroundSystem.checkIn(32, "Paradise", 8);
undergroundSystem.checkIn(27, "Leyton", 10);
undergroundSystem.checkOut(45, "Waterloo", 15);
undergroundSystem.checkOut(27, "Waterloo", 20);
undergroundSystem.checkOut(32, "Cambridge", 22);
undergroundSystem.getAverageTime("Paradise", "Cambridge");       // 返回 14.0。从 "Paradise"（时刻 8）到 "Cambridge"(时刻 22)的行程只有一趟
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo" 的行程，编号为 id=45 的乘客出发于 time=3 到达于 time=15，编号为 id=27 的乘客于 time=10 出发于 time=20 到达。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
undergroundSystem.checkIn(10, "Leyton", 24);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0
undergroundSystem.checkOut(10, "Waterloo", 38);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 12.0


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-underground-system

*/
class UndergroundSystem {
public:
	unordered_map<int, pair<string, int>> a;		//定义关联容器a，存储乘客的id(键)，地铁站名称和进入时间(值)
	unordered_map<string, pair<double, int>> b;		//定义关联容器b，存储出地铁站进出字符串(键)，所用时间和相同站进出次数(值)

	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {		//进站
		a[id] = { stationName,t };							//进站时，存储乘客id对应进站名及进站时间
	}

	void checkOut(int id, string stationName, int t) {		//出站
		string name = getName(a[id].first, stationName);	//获取进出站的字符串，作为容器b的键
		t = t - a[id].second;								//进出站间隔时间
		b[name].first = b[name].first + (double)t;			//存储进出站的字符串，两站所用时间
		b[name].second += 1;								//相同站进出的自增，算平均
	}

	double getAverageTime(string startStation, string endStation) { //算平均时间
		string name = getName(startStation, endStation);			//先获取进出站的字符串name
		return b[name].first / b[name].second;						//返回键为name的时间除以所有乘客进出站次数
	}
private:
	string getName(string startStation, string endStation) {	//一个内部函数，返回进出站结合的字符串
		return startStation + "," + endStation;
	}

};