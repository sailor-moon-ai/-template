

// mP数组：mP[i]表示数字i的最小质因子。
// ll mP[N+5];
// vector<int> sieve(int n)
// {
//     vector<bool> vis(n+1);
//     vector<int> prime;
//     vis[1] = 1;
//     mP[1] = 1;
//     for (int i = 2; i <= n; ++i) {
//         if (!vis[i]) {
//             prime.push_back(i);
//             mP[i] = i;
//         }
//         for (auto p: prime) {
//             if (i*p > n) { break; }
//             vis[i*p] = 1;
//             mP[i*p] = p;
//             if (i%p == 0) { break; }  // 线性筛关键优化
//         }
//     }
        //返回的prime数组里包含了2到n中所有的质数
//     return prime;

// }