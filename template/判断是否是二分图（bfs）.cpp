// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         std::vector<int>ans(n,-1);
//         auto bfs=[&](int S){
//             std::queue<int> q;
//             q.push(S),ans[S]=0;
//             while(!q.empty()){
//                 int sn=q.front();
//                 q.pop();
//                 for(int fn:graph[sn]){
//                     if(ans[fn]>=0){
//                         if(ans[fn]==ans[sn]){
//                             return false;
//                         }
//                     }else{
//                         q.push(fn);
//                         ans[fn]=ans[sn]^1;
//                     }
//                 }
//             }
//             return true;
//         };
//         bool end=true;
//         for(int i=0;i<n;i++){
//             if(ans[i]==-1){
//                 end=bfs(i);
//             }
//             if(end==false){
//                 break;
//             }
//         }
//         return end;
//     }
// };