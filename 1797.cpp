/*
题目描述：
你需要设计一个包含验证码的验证系统。每一次验证中，用户会收到一个新的验证码，这个验证码在 currentTime 时刻之后 timeToLive 秒过期。如果验证码被更新了，那么它会在 currentTime （可能与之前的 currentTime 不同）时刻延长 timeToLive 秒。
请你实现 AuthenticationManager 类：
AuthenticationManager(int timeToLive) 构造 AuthenticationManager 并设置 timeToLive 参数。
generate(string tokenId, int currentTime) 给定 tokenId ，在当前时间 currentTime 生成一个新的验证码。
renew(string tokenId, int currentTime) 将给定 tokenId 且 未过期 的验证码在 currentTime 时刻更新。如果给定 tokenId 对应的验证码不存在或已过期，请你忽略该操作，不会有任何更新操作发生。
countUnexpiredTokens(int currentTime) 请返回在给定 currentTime 时刻，未过期 的验证码数目。
如果一个验证码在时刻 t 过期，且另一个操作恰好在时刻 t 发生（renew 或者 countUnexpiredTokens 操作），过期事件 优先于 其他操作。

输入输出及解释：
输入：
["AuthenticationManager", "renew", "generate", "countUnexpiredTokens", "generate", "renew", "renew", "countUnexpiredTokens"]
[[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10], [15]]
输出：
[null, null, null, 1, null, null, null, 0]

解释：
AuthenticationManager authenticationManager = new AuthenticationManager(5); // 构造 AuthenticationManager ，设置 timeToLive = 5 秒。
authenticationManager.renew("aaa", 1); // 时刻 1 时，没有验证码的 tokenId 为 "aaa" ，没有验证码被更新。
authenticationManager.generate("aaa", 2); // 时刻 2 时，生成一个 tokenId 为 "aaa" 的新验证码。
authenticationManager.countUnexpiredTokens(6); // 时刻 6 时，只有 tokenId 为 "aaa" 的验证码未过期，所以返回 1 。
authenticationManager.generate("bbb", 7); // 时刻 7 时，生成一个 tokenId 为 "bbb" 的新验证码。
authenticationManager.renew("aaa", 8); // tokenId 为 "aaa" 的验证码在时刻 7 过期，且 8 >= 7 ，所以时刻 8 的renew 操作被忽略，没有验证码被更新。
authenticationManager.renew("bbb", 10); // tokenId 为 "bbb" 的验证码在时刻 10 没有过期，所以 renew 操作会执行，该 token 将在时刻 15 过期。
authenticationManager.countUnexpiredTokens(15); // tokenId 为 "bbb" 的验证码在时刻 15 过期，tokenId 为 "aaa" 的验证码在时刻 7 过期，所有验证码均已过期，所以返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-authentication-manager
*/

class AuthenticationManager {
private:
	int time;									//定义验证码存活时间
	unordered_map<string, int> a;				//关联容器a,存放id和对应时间
public:
	AuthenticationManager(int timeToLive) {		
		time = timeToLive;						//初始化验证码存活时间time
	}

	void generate(string tokenId, int currentTime) {    //生成一个新的验证码
		a[tokenId] = currentTime;					    //键为tokenId下赋值currentTime
	}

	void renew(string tokenId, int currentTime) {		//更新操作
		if (a.find(tokenId) == a.end()) {				//判断tokenId验证码的time是否刚好过期，过期事件优先，不执行任何操作

		}
		else {
			if ((a[tokenId] + time) > currentTime) {	//tokenId验证码不过期
				a[tokenId] = currentTime;				//更新tokenId验证码的currentTime
			}
		}
	}

	int countUnexpiredTokens(int currentTime) {			
		int count = 0;
		for (auto map : a) {							//for循环寻找未过期数量count
			if ((map.second + time) > currentTime) {
				count++;
			}
		}
		return count;
	}
};