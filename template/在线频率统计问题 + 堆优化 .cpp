






// std::unordered_map<int,long long>cnt;//每个数对应出现的次数
// std::priority_queue<std::pair<long long,int>>pq;
// std::vector<long long>ans;//保存每一次操作后，出现的最大频率是多少，不关心是谁出现的最大，只关心最大是多少
// for(int i=0;i<nums.size();i++){
//     int x=nums[i];
//     cnt[x]+=freq[i];
//     pq.emplace(cnt[x],x);


//      //堆顶信息不一致说明已经过时，需要弹出旧的记录
//     while(pq.top().first!=cnt[pq.top().second]){
//         pq.pop();
//     }
//     ans.push_back(pq.top().first);
// }
// return ans;