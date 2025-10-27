// // Ī���㷨�ĺ���˼���ǣ���ѯ�ʰ�����˵����ڿ���飬��˵���ͬһ�����ѯ�ʷֵ�ͬһ�顣
//
// class Solution {
// public:
//     vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size(), m = queries.size();
//
//         unordered_map<int, int> cnt;
//         int max_cnt = 0, min_val = 0;
//
//         // ���Ԫ�� x
//         auto add = [&](int x) {
//             int c = ++cnt[x];
//             if (c > max_cnt) {
//                 max_cnt = c;
//                 min_val = x;
//             } else if (c == max_cnt) {
//                 min_val = min(min_val, x);
//             }
//         };
//
//         vector<int> ans(m, -1);
//         int block_size = ceil(n / sqrt(m));
//
//         struct Query {
//             int bid, l, r, threshold, qid; // [l,r) ����ҿ�
//         };
//
//         vector<Query> qs;
//         for (int i = 0; i < m; i++) {
//             auto& q = queries[i];
//             int l = q[0], r = q[1] + 1, threshold = q[2]; // ����ҿ�
//
//             // ���������ߣ���֤ l �� r ����ͬһ�����У�
//             if (r - l > block_size) {
//                 qs.emplace_back(l / block_size, l, r, threshold, i);
//                 continue;
//             }
//
//             // С���䱩��
//             for (int j = l; j < r; j++) {
//                 add(nums[j]);
//             }
//             if (max_cnt >= threshold) {
//                 ans[i] = min_val;
//             }
//
//             // ��������
//             cnt.clear();
//             max_cnt = 0;
//         }
//
//         ranges::sort(qs, {}, [](auto& q) { return pair(q.bid, q.r); });
//
//         int r;
//         for (int i = 0; i < qs.size(); i++) {
//             auto& q = qs[i];
//             int l0 = (q.bid + 1) * block_size;
//             if (i == 0 || q.bid > qs[i - 1].bid) { // ������һ���µĿ�
//                 r = l0; // �Ҷ˵��ƶ������
//                 // ��������
//                 cnt.clear();
//                 max_cnt = 0;
//             }
//
//             // �Ҷ˵�� r �ƶ��� q.r��q.r �����룩
//             for (; r < q.r; r++) {
//                 add(nums[r]);
//             }
//
//             int tmp_max_cnt = max_cnt, tmp_min_val = min_val;
//
//             // ��˵�� l0 �ƶ��� q.l��l0 �����룩
//             for (int j = q.l; j < l0; j++) {
//                 add(nums[j]);
//             }
//             if (max_cnt >= q.threshold) {
//                 ans[q.qid] = min_val;
//             }
//
//             // �ع�
//             max_cnt = tmp_max_cnt;
//             min_val = tmp_min_val;
//             for (int j = q.l; j < l0; j++) {
//                 cnt[nums[j]]--;
//             }
//         }
//         return ans;
//     }
// };
