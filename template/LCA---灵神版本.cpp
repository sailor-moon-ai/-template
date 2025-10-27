// class LcaBinaryLifting {
//     //depth：每个节点的深度（根节点深度为 0）
//     //dis：每个节点到根节点的距离（用于计算任意两点距离）。
//     vector<int> depth, dis;
//     //pa：pa[x][i] 表示节点 x 的第 2的i次幂个祖先
//     //pa[x][0]是x节点的直接父节点
//     vector<vector<int>> pa;
//
//     负责预处理树的 LCA 信息，并提供三个关键方法：
//
//      get_kth_ancestor(node, k)：找 node 的第 k 个祖先。
//
//      get_lca(x, y)：计算 x 和 y 的最近公共祖先。
//
//      get_dis(x, y)：计算 x 和 y 之间的路径距离。
// public:
//     LcaBinaryLifting(vector<vector<int>>& edges) {
            //edges这个二维数组存储的就是边信息
            //edges[i][0]=u,edges[i][1]=v,edges[i][2]=w
            //u<-->v,边权为w
//         int n = edges.size() + 1;

//         int m = bit_width((unsigned) n); // n 的二进制长度
//         vector<vector<pair<int, int>>> g(n);
//         for (auto& e : edges) {
//             int x = e[0], y = e[1], w = e[2];
//             g[x].emplace_back(y, w);
//             g[y].emplace_back(x, w);
//         }
//
//         depth.resize(n);
//         dis.resize(n);
//         pa.resize(n, vector<int>(m, -1));
//         auto dfs = [&](this auto&& dfs, int x, int fa) -> void {
//             pa[x][0] = fa;
//             for (auto& [y, w] : g[x]) {
//                 if (y != fa) {
//                     depth[y] = depth[x] + 1;
//                     dis[y] = dis[x] + w;
//                     dfs(y, x);
//                 }
//             }
//         };
//         dfs(0, -1);
//
//         for (int i = 0; i < m - 1; i++) {
//             for (int x = 0; x < n; x++) {
//                 if (int p = pa[x][i]; p != -1) {
//                     pa[x][i + 1] = pa[p][i];
//                 }
//             }
//         }
//     }
//     //找 node 的第 k 个祖先。
//     int get_kth_ancestor(int node, int k) {
//         for (; k; k &= k - 1) {
//             node = pa[node][countr_zero((unsigned) k)];
//         }
//         return node;
//     }
//
//     // 返回 x 和 y 的最近公共祖先（节点编号从 0 开始）
//     int get_lca(int x, int y) {
//         if (depth[x] > depth[y]) {
//             swap(x, y);
//         }
//         y = get_kth_ancestor(y, depth[y] - depth[x]); // 使 y 和 x 在同一深度
//         if (y == x) {
//             return x;
//         }
//         for (int i = pa[x].size() - 1; i >= 0; i--) {
//             int px = pa[x][i], py = pa[y][i];
//             if (px != py) {
//                 x = px;
//                 y = py; // 同时往上跳 2^i 步
//             }
//         }
//         return pa[x][0];//这里返回的是x和y的最近公共祖先
//     }
//
//     // 返回 x 到 y 的距离（最短路长度）
//     int get_dis(int x, int y) {
//         //dis[x] + dis[y] - 2 * dis[lca]（因为 dis[lca] 是公共路径部分）
//         return dis[x] + dis[y] - dis[get_lca(x, y)] * 2;
//     }
// };
