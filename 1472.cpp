/*
题目：
你有一个只支持单个标签页的 浏览器 ，最开始你浏览的网页是 homepage ，
你可以访问其他的网站 url ，也可以在浏览历史中后退 steps 步或前进 steps 步。

请你实现 BrowserHistory 类：
BrowserHistory(string homepage) ，用 homepage 初始化浏览器类。
void visit(string url) 从当前页跳转访问 url 对应的页面  。执行此操作会把浏览历史前进的记录全部删除。
string back(int steps) 在浏览历史中后退 steps 步。如果你只能在浏览历史中后退至多 x 步且 steps > x ，
那么你只后退 x 步。请返回后退 至多 steps 步以后的 url 。
string forward(int steps) 在浏览历史中前进 steps 步。如果你只能在浏览历史中前进至多 x 步且 steps > x ，
那么你只前进 x 步。请返回前进 至多 steps步以后的 url 。
 
 输入输出：
 输入：
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
输出：
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

解释：
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // 你原本在浏览 "leetcode.com" 。访问 "google.com"
browserHistory.visit("facebook.com");     // 你原本在浏览 "google.com" 。访问 "facebook.com"
browserHistory.visit("youtube.com");      // 你原本在浏览 "facebook.com" 。访问 "youtube.com"
browserHistory.back(1);                   // 你原本在浏览 "youtube.com" ，后退到 "facebook.com" 并返回 "facebook.com"
browserHistory.back(1);                   // 你原本在浏览 "facebook.com" ，后退到 "google.com" 并返回 "google.com"
browserHistory.forward(1);                // 你原本在浏览 "google.com" ，前进到 "facebook.com" 并返回 "facebook.com"
browserHistory.visit("linkedin.com");     // 你原本在浏览 "facebook.com" 。 访问 "linkedin.com"
browserHistory.forward(2);                // 你原本在浏览 "linkedin.com" ，你无法前进任何步数。
browserHistory.back(2);                   // 你原本在浏览 "linkedin.com" ，后退两步依次先到 "facebook.com" ，然后到 "google.com" ，并返回 "google.com"
browserHistory.back(7);                   // 你原本在浏览 "google.com"， 你只能后退一步到 "leetcode.com" ，并返回 "leetcode.com"


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-browser-history

*/
class BrowserHistory {
private:
	vector<string> result;					//结果
	int index = 0;							//下标
public:
	BrowserHistory(string homepage) {
		result.emplace_back(homepage);	//插入初始网页
	}

	void visit(string url) {			//浏览网页时，会重新
		result.resize(index + 1);		//把vector大小改为当前位置加一，并存储浏览的网页，前面的浏览记录全删掉了
		result.emplace_back(url);
		++index;
	}

	string back(int steps) {			//如果当前位置减去回退步数大于零，则返回回退后的网站
		int temp = index - steps;		//否则说明回到了初始网站homepage
		if (temp > 0) {
			index = temp;
			return result[index];
		}
		else {
			index = 0;
			return result[index];
		}

	}
	string forward(int steps) {				
		int temp = index + steps;			//如果前进步数加上当前位置大于最大存储的网站数，返回最后的网站
		if (temp > (result.size() - 1)) {	//否则返回当前位置加前进步数的网站
			index = (result.size() - 1);
			return result[index];
		}
		else {
			index = temp;
			return result[index];
		}

	}
};