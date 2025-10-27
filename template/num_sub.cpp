/*
 *
 * 统计一个字符串中某个子序列出现的个数
 *
 *
 */


//s是匹配串(较长的),t是模式串(较短的)
// long long numDistinct(const string& s, const string& t) {
//     int n = s.size(), m = t.size();
//     if (n < m) {
//         return 0;
//     }
//
//     vector<long long> f(m + 1);
//     f[0] = 1;
//     for (int i = 0; i < n; i++) {
//         for (int j = min(i, m - 1); j >= max(m - n + i, 0); j--) {
//             if (s[i] == t[j]) {
//                 f[j + 1] += f[j];
//             }
//         }
//     }
//     //返回的f[m]存储的就是 s 中包含 t 作为子序列的总方式数。
//     return f[m];
// }
//
