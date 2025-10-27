//
// template<typename T, typename F>
// class LazySegmentTree {
//     // 注：也可以去掉 template<typename T, typename F>，改在这里定义 T 和 F
//     // using T = pair<int, int>;
//     // using F = pair<int, int>;
//
//     // 懒标记初始值
//     const F TODO_INIT = 0; // **根据题目修改**
//
//     struct Node {
//         T val;
//         F todo;
//     };
//
//     int n;
//     vector<Node> tree;
//
//     // 合并两个 val
       /*
merge_val(T a, T b) 负责合并两个子区间的计算结果（a 和 b
定义如何合并两个区间的值，是线段树（尤其是支持区间查询的线段树）的核心操作之一。
它的具体行为取决于你的需求
//这里修改了的话，对应的apply记得修改
Sum Query:
return a + b
Max Query:
return max(a, b)
Min Query:
return min(a, b)
        */
//     T merge_val(T a, T b) const {
//         return a + b; // **根据题目修改**
//     }
//
//     // 合并两个懒标记
//     F merge_todo(F a, F b) const {
//         return a + b; // **根据题目修改**
//     }
//
//     // 把懒标记作用到 node 子树（本例为区间加）
//     void apply(int node, int l, int r, F todo) {
//         Node& cur = tree[node];
//         // 计算 tree[node] 区间的整体变化
//         cur.val += todo * (r - l + 1); // **根据题目修改**
//         cur.todo = merge_todo(todo, cur.todo);
//     }
//
//     // 把当前节点的懒标记下传给左右儿子
//     void spread(int node, int l, int r) {
//         Node& cur = tree[node];
//         F todo = cur.todo;
//         if (todo == TODO_INIT) { // 没有需要下传的信息
//             return;
//         }
//         int m = (l + r) / 2;
//         apply(node * 2, l, m, todo);
//         apply(node * 2 + 1, m + 1, r, todo);
//         cur.todo = TODO_INIT; // 下传完毕
//     }
//
//     // 合并左右儿子的 val 到当前节点的 val
//     void maintain(int node) {
//         tree[node].val = merge_val(tree[node * 2].val, tree[node * 2 + 1].val);
//     }
//
//     // 用 a 初始化线段树
//     // 时间复杂度 O(n)
//     void build(const vector<T>& a, int node, int l, int r) {
//         Node& cur = tree[node];
//         cur.todo = TODO_INIT;
//         if (l == r) { // 叶子
//             cur.val = a[l]; // 初始化叶节点的值
//             return;
//         }
//         int m = (l + r) / 2;
//         build(a, node * 2, l, m); // 初始化左子树
//         build(a, node * 2 + 1, m + 1, r); // 初始化右子树
//         maintain(node);
//     }
//
//     void update(int node, int l, int r, int ql, int qr, F f) {
//         if (ql <= l && r <= qr) { // 当前子树完全在 [ql, qr] 内
//             apply(node, l, r, f);
//             return;
//         }
//         spread(node, l, r);
//         int m = (l + r) / 2;
//         if (ql <= m) { // 更新左子树
//             update(node * 2, l, m, ql, qr, f);
//         }
//         if (qr > m) { // 更新右子树
//             update(node * 2 + 1, m + 1, r, ql, qr, f);
//         }
//         maintain(node);
//     }
//
//     T query(int node, int l, int r, int ql, int qr) {
//         if (ql <= l && r <= qr) { // 当前子树完全在 [ql, qr] 内
//             return tree[node].val;
//         }
//         spread(node, l, r);
//         int m = (l + r) / 2;
//         if (qr <= m) { // [ql, qr] 在左子树
//             return query(node * 2, l, m, ql, qr);
//         }
//         if (ql > m) { // [ql, qr] 在右子树
//             return query(node * 2 + 1, m + 1, r, ql, qr);
//         }
//         T l_res = query(node * 2, l, m, ql, qr);
//         T r_res = query(node * 2 + 1, m + 1, r, ql, qr);
//         return merge_val(l_res, r_res);
//     }
//
// public:
//     // 线段树维护一个长为 n 的数组（下标从 0 到 n-1），元素初始值为 init_val
       //例：// 创建一个长度为 3 的线段树，初始值全部为 10
       // LazySegmentTree<int, int> seg2(3, 10);
//     LazySegmentTree(int n, T init_val = 0) : LazySegmentTree(vector<T>(n, init_val)) {}
//
//     // 线段树维护数组 a
       //例：
       //vector<int> nums = {1, 3, 2, 5, 4};
       //LazySegmentTree<int, int> seg(nums); // 用 nums 初始化线段树
//     LazySegmentTree(const vector<T>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) {
//         build(a, 1, 0, n - 1);
//     }
//
//     // 用 f 更新 [ql, qr] 中的每个 a[i]
//     // 0 <= ql <= qr <= n-1
//     // 时间复杂度 O(log n)
        /*
         update(ql, qr, f) 的作用是对区间 [ql, qr] 内的每个元素执行一个修改操作，
         具体是“加 f”还是其他操作（如赋值、乘 f 等），取决于你在 apply 函数中的实现逻辑
         */
//     void update(int ql, int qr, F f) {
//         update(1, 0, n - 1, ql, qr, f);
//     }
//
//     // 返回用 merge_val 合并所有 a[i] 的计算结果，其中 i 在闭区间 [ql, qr] 中
//     // 0 <= ql <= qr <= n-1
//     // 时间复杂度 O(log n)
        /*
        query的作用是返回区间(ql,qr)的区间和
         */
//     T query(int ql, int qr) {
//         return query(1, 0, n - 1, ql, qr);
//     }
// };
//
