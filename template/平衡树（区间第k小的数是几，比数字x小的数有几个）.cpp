/*
 *
 * 关于这个tree的详细使用，看https://oi-wiki.org/lang/pb-ds/tree/
 */





// #include <iostream>
// using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using ld = long double;
// using pii = pair<int, int>;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

    //平衡树
// __gnu_pbds::tree<pair<int, int>, __gnu_pbds::null_type, less<pair<int, int>>,
//                  __gnu_pbds::rb_tree_tag,
//                  __gnu_pbds::tree_order_statistics_node_update>
//     trr;
//
// int main() {
//     int cnt = 0;
//     trr.insert(make_pair(1, cnt++));
//     trr.insert(make_pair(5, cnt++));
//     trr.insert(make_pair(4, cnt++));
//     trr.insert(make_pair(3, cnt++));
//     trr.insert(make_pair(2, cnt++));
//     // 树上元素 {(1,0), (2,4), (3,3), (4,2), (5,1)}
//
//     auto it = trr.lower_bound(make_pair(2, 0));
//     trr.erase(it);
//     // 树上元素 {(1,0), (3,3), (4,2), (5,1)}
//
//     // 输出排名 0 1 2 3 中的排名 1 的元素的 first
//     auto it2 = trr.find_by_order(1);
//     cout << (*it2).first << endl;  // 输出：3
//
//     // 输出其排名
//     int pos = trr.order_of_key(*it2);
//     cout << pos << endl;  // 输出：1
//
//     // 按照 it2 分裂 trr
//     decltype(trr) newtr;
//     trr.split(*it2, newtr);
//     for (auto i = newtr.begin(); i != newtr.end(); ++i) {
//         cout << (*i).first << ' ';  // 输出：4 5
//     }
//     cout << endl;
//
//     // 将 newtr 树并入 trr 树，newtr 树被清空。
//     trr.join(newtr);
//     for (auto i = trr.begin(); i != trr.end(); ++i) {
//         cout << (*i).first << ' ';  // 输出：1 3 4 5
//     }
//     cout << endl;
//     cout << newtr.size() << endl;  // 输出：0
//
//     return 0;
// }