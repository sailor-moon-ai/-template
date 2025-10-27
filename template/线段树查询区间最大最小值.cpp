// int n, m, TA[N << 2], TB[N << 2], a[N], b[N];
//
// void pushup(int x) {
//     TA[x] = max(TA[x << 1], TA[x << 1 | 1]);
//     TB[x] = min(TB[x << 1], TB[x << 1 | 1]);
// }
//
// void build(int l, int r, int x) {
//     if (l == r) {
//         TA[x] = a[l];
//         TB[x] = b[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build (l, mid, x << 1);
//     build (mid + 1, r , x << 1 | 1);
//     pushup(x);
// }
//
// int queryMax(int l, int r, int x, int ql, int qr) {
//     if (l >= ql && r <= qr) {
//         return TA[x];
//     }
//     int mid = l + r >> 1;
//     int ans = 0;
//     if (ql <= mid) ans = max(ans, queryMax(l, mid, x << 1, ql, qr));
//     if (qr > mid) ans = max(ans, queryMax(mid + 1, r , x << 1 | 1, ql, qr));
//     return ans;
// }
//
// int queryMin(int l, int r, int x, int ql, int qr) {
//     if (l >= ql && r <= qr) {
//         return TB[x];
//     }
//     int mid = l + r >> 1;
//     int ans = 1e9;
//     if (ql <= mid) ans = min(ans, queryMin(l, mid, x << 1, ql, qr));
//     if (qr > mid) ans = min(ans, queryMin(mid + 1, r , x << 1 | 1, ql, qr));
//     return ans;
// }


// 建树：
// build(1,n,1);