



//例子dfs(dfs,x,-1)就是找出以x为根时的最大深度，根的父节点设置为-1

// auto dfs = [&](auto &&dfs, int u, int fa) -> int {
//     int mx = 0;
//     for(auto j : g[u]){
//         if (j == fa) continue;
//         mx = max(mx, dfs(dfs, j, u) + 1);
//     }
//     return mx;
// };
// 功能：返回 以 u 为根的子树最大深度（边数）。
//
// 类似求树高的 DFS。