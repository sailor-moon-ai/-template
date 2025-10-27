 // 找出从 a 到 b 的路径
//a和b是树上的两个点



// vector<int> path, p;
// auto dfs = [&](auto &&dfs, int u, int fa) -> void {
//     path.push_back(u);
//     if (u == b){
//         p = path; // 找到 b 时保存当前路径
//     }
//     for(auto j : g[u]){//g是用来存储树的邻接表
//         if (j == fa) continue; // 避免回到父节点
//         dfs(dfs, j, u);
//     }
//     path.pop_back(); // 回溯
// };
//
// dfs(dfs, a, -1);

// 从节点 a 出发 DFS，path 保存当前遍历路径。
//
// 当到达 b 时，把当前路径 path 保存到 p。
//
// 这样 p 就是 a 到 b 的唯一简单路径。
