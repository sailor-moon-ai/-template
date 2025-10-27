
// class ST {
//     vector<vector<int>> st_min;
//     vector<vector<int>> st_max;
//
// public:
//     ST(const vector<int>& a) {
//         size_t n = a.size();
//         int w = bit_width(n);
//         st_min.resize(w, vector<int>(n));
//         st_max.resize(w, vector<int>(n));
//
//         for (int j = 0; j < n; j++) {
//             st_min[0][j] = a[j];
//             st_max[0][j] = a[j];
//         }
//
//         for (int i = 1; i < w; i++) {
//             for (int j = 0; j + (1 << i) <= n; j++) {
//                 st_min[i][j] = min(st_min[i - 1][j], st_min[i - 1][j + (1 << (i - 1))]);
//                 st_max[i][j] = max(st_max[i - 1][j], st_max[i - 1][j + (1 << (i - 1))]);
//             }
//         }
//     }
//
//     // [l, r) 左闭右开
//     int query(int l, int r) const {
//         int k = bit_width((uint32_t) r - l) - 1;
            //这里mn和mx是指定位置l到r内的最大值和最小值
//         int mn = min(st_min[k][l], st_min[k][r - (1 << k)]);
//         int mx = max(st_max[k][l], st_max[k][r - (1 << k)]);
//         return mx - mn;
//     }
// };

//
// 使用的时候是直接给st传递一个赋值好的vector就可以
// vector<int>& nums
// ST st(nums);
