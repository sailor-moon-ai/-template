//找到满足条件的第k小的数





//容斥+二分
//check函数是经典的容斥定理函数



// 使用容斥原理进行扩展，核心是：
//
// 1.枚举子集
//
//2. 计算 lcm
//
// 3.加减贡献（奇加偶减）




// class Solution {
// public:
//     long long findKthSmallest(vector<int>& coins, int k) {
//         auto check = [&](long long m) -> bool {
//             long long cnt = 0;
//             for (int i = 1; i < (1 << coins.size()); i++) { // 枚举所有非空子集
//                 long long lcm_res = 1; // 计算子集 LCM
//                 for (int j = 0; j < coins.size(); j++) {
//                     if (i >> j & 1) {
//                         lcm_res = lcm(lcm_res, coins[j]);
//                         if (lcm_res > m) { // 太大了
//                             break;
//                         }
//                     }
//                 }

                    //__builtin_popcount
                    //__builtin_popcount 是 GCC / Clang 提供的一个内置函数（built-in function），
                    //用于快速计算一个整数的 二进制表示中有多少个 1。
                    //这里算出有多少个1就说明了子集中数的个数

//                 cnt += __builtin_popcount(i) % 2 ? m / lcm_res : -m / lcm_res;
//             }
//             return cnt >= k;
//         };
//
//         long long left = k - 1, right = (long long) ranges::min(coins) * k;
//         while (left + 1 < right) {
//             long long mid = (left + right) / 2;
//             (check(mid) ? right : left) = mid;
//         }
//         return right;
//     }
// };
