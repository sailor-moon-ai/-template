
//快速幂，求x的n次
// long long q_pow(long long x, int n) {
//     long long res = 1;
//     for (; n > 0; n /= 2) {
//         if (n % 2) {
//             res = res * x % MOD;
//         }
//         x = x * x % MOD;
//     }
//     return res;
// }


// // 组合数模板
// long long fac[MX], inv_fac[MX];

//fac[i]是i的阶乘
//inv_fac是i的阶乘的倒数

// auto init = [] {
//     fac[0] = 1;
//     for (int i = 1; i < MX; i++) {
//         fac[i] = fac[i - 1] * i % MOD;
//     }
//     inv_fac[MX - 1] = q_pow(fac[MX - 1], MOD - 2);
//     for (int i = MX - 1; i > 0; i--) {
//         inv_fac[i - 1] = inv_fac[i] * i % MOD;
//     }
//     return 0;
// }();
//

//n个数中选择k个数的方案数
// long long comb(int n, int k) {
//     return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
// }
