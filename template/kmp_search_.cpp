
//kmp原理讲解网址
// https://www.zhihu.com/question/21923021/answer/37475572


//pi：存储前缀函数的数组，pi[i] 表示子串 p[0..i] 的最长公共前后缀长度。
//match：当前匹配的长度（初始为 0）。
//  // 计算字符串 p 的 pi 数组
// vector<int> calcPi(const string& p) {
//     vector<int> pi(p.size());
//     int match = 0;
//     for (int i = 1; i < p.size(); i++) {
//         char v = p[i];
//         while (match > 0 && p[match] != v) {
//             match = pi[match - 1];
//         }
//         if (p[match] == v) {
//             match++;
//         }
//         pi[i] = match;
//     }
//     return pi;
// }

// Pi 表（也称为 前缀函数 或 失败函数）存储了模式串每个前缀的最长 相同真前缀和真后缀 的长度
// 使得 KMP 在匹配失败时可以高效地跳过不必要的比较。

// 示例 1：p = "ABABCABAB"
// i	p[i]	match 变化	pi[i]	解释
// 0	'A'	-	0	单个字符
// 1	'B'	match=0 → pi[1]=0	0	"AB" 无公共前后缀
// 2	'A'	match=0 → p[0]=='A' → match=1 → pi[2]=1	1	"ABA" → 公共前后缀 "A"
// 3	'B'	match=1 → p[1]=='B' → match=2 → pi[3]=2	2	"ABAB" → "AB"
// 4	'C'	match=2 → p[2]!='C' → match=pi[1]=0 → pi[4]=0	0	"ABABC" 无公共前后缀
// 5	'A'	match=0 → p[0]=='A' → match=1 → pi[5]=1	1	"ABABCA" → "A"
// 6	'B'	match=1 → p[1]=='B' → match=2 → pi[6]=2	2	"ABABCAB" → "AB"
// 7	'A'	match=2 → p[2]=='A' → match=3 → pi[7]=3	3	"ABABCABA" → "ABA"
// 8	'B'	match=3 → p[3]=='B' → match=4 → pi[8]=4	4	"ABABCABAB" → "ABAB"
// 最终 Pi 表：[0, 0, 1, 2, 0, 1, 2, 3, 4]




//  // 在文本串 s 中查找模式串 p，返回所有成功匹配的位置（p[0] 在 s 中的下标）

//最终返回一个vector,里面包含了所有p在s中成功匹配的在s中的开始下标

// vector<int> kmp_search(const string& s, const string& p) {
//
//          //如果p是空串，那么s的所有位置都能匹配成功
//     if (p.empty()) {
//         // s 的所有位置都能匹配空串，包括 s.size()
//         vector<int> pos(s.size() + 1);
//         ranges::iota(pos, 0);
//         return pos;
//     }
//
//     vector<int> pi = calcPi(p);
//     vector<int> pos;
//     int match = 0;
//     for (int i = 0; i < s.size(); i++) {
//         char v = s[i];
//         while (match > 0 && p[match] != v) {
//             match = pi[match - 1];
//         }
//         if (p[match] == v) {
//             match++;
//         }
//         if (match == p.size()) {
//             pos.push_back(i - p.size() + 1);
//             match = pi[match - 1];
//         }
//     }
//     return pos;
// }
//




