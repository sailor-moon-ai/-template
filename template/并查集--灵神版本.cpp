// // 完整的并查集模板，见我的数据结构题单
// class UnionFind {
//     vector<int> fa; // 代表元
//
// public:
//     int cc; // 连通块个数
//
//     UnionFind(int n) : fa(n), cc(n) {
//         // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
//         // 集合 i 的代表元是自己，大小为 1
//         ranges::iota(fa, 0); // iota(fa.begin(), fa.end(), 0);
//     }
//
//     // 返回 x 所在集合的代表元
//     // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
//     int find(int x) {
//         // 如果 fa[x] == x，则表示 x 是代表元
//         if (fa[x] != x) {
//             fa[x] = find(fa[x]); // fa 改成代表元
//         }
//         return fa[x];
//     }
//
//     // 把 from 所在集合合并到 to 所在集合中
//     void merge(int from, int to) {
//         int x = find(from), y = find(to);
//         if (x == y) { // from 和 to 在同一个集合，不做合并
//             return;
//         }
//         fa[x] = y; // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
//         cc--; // 成功合并，连通块个数减一
//     }
// };
