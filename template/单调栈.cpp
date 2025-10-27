/*
    利用单调栈寻找字符串中字典序最小的长度为k的子序列

    for (int i = 0; i < m; i++) {
    while ((b.size() + m - i != k) && b.size() && b.back() > a[i])
        b.pop_back();  // 移除比 a[i] 大的字符，保证字典序最小
    b.push_back(a[i]); // 入栈
    }
     while (b.size() > k)
     b.pop_back();  // 如果超长，移除多余字符
=====================================================
关键点
b.back() > a[i]：如果 b 末尾字符比当前字符 a[i] 大，就移除它，以保持字典序最小；
b.size() + m - i != k：确保剩余字符足够填充 k 长度。
输入

例子：
m = 7, k = 3
a = "cbacdcb"
过程
i	a[i]	b (栈操作)
0	'c'    	c
1	'b' 	b (移除 c)
2	'a'	    a (移除 b)
3	'c'	    ac
4	'd'  	acd
5	'c'  	acd
6	'b'  	acd
 */


//利用单调栈寻找子数组长度大于等于3，并且左右两端点值大于中间所有点
//class Solution {
//public:
//    long long bowlSubarrays(vector<int>& nums) {
//        int ans = 0;
//        stack<int> st;
//        for (int i = 0; i < nums.size(); i++) {
//            int x = nums[i];
//            while (!st.empty() && nums[st.top()] < x) {
//                // j=st.top() 右侧严格大于 nums[j] 的数的下标是 i
//                if (i - st.top() > 1) { // 子数组的长度至少为 3
//                    ans++;
//                }
//                st.pop();
//            }
//            // i 左侧大于等于 nums[i] 的数的下标是 st.top()
//            if (!st.empty() && i - st.top() > 1) { // 子数组的长度至少为 3
//                ans++;
//            }
//            st.push(i);
//        }
//        return ans;
//    }
//};

