//#include <vector>
//const int N=5e5+10;
//int n,m,s,a,b;
//std::vector<int>e[N];
//int dep[N],fa[N][20];
//
//void dfs(int u,int father) {
//    dep[u]=dep[father]+1;
//    fa[u][0]=father;
//    for(int i=1;i<=19;i++) {
//        fa[u][i]=fa[fa[u][i-1]][i-1];
//    }
//    for(int v:e[u]) {
//        if(v!=father) {
//            dfs(v,u);
//        }
//    }
//}
//
//int lca(int u,int v) {
//    if(dep[u]<dep[v]) {
//        std::swap(u,v);
//    }
//    //先跳到同一层
//    for(int i=19;i>=0;i--) {
//        if(dep[fa[u][i]]>=dep[v]) {
//            u=fa[u][i];
//        }
//    }
//    if(u==v)return v;
//    //再跳到lca的下一层
//    for(int i=19;i>=0;i--) {
//        if(fa[u][i]!=fa[v][i]) {
//            u=fa[u][i];
//            v=fa[v][i];
//        }
//    }
//    return fa[u][0];
//}
//
//
//// 2.6s
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int N=500005;
//int n,m,s;
//vector<int> e[N];
//int dep[N],fa[N][22];
//
//void dfs(int x,int f){ //树增dep,fa
//    dep[x]=dep[f]+1; fa[x][0]=f;
//    //x上面2,4,8...的祖先fa
//    for(int i=1; i<=20; i++)
//        fa[x][i]=fa[fa[x][i-1]][i-1];
//    for(int y : e[x])
//        if(y!=f) dfs(y,x);
//}
//int lca(int x,int y){ //树增lca
//    if(dep[x]<dep[y]) swap(x,y);
//    //x先大步后小步向上跳，直到与y同层
//    for(int i=20; ~i; i--)
//        if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
//    if(x==y) return y;
//    //x,y一起向上跳，直到lca的下面
//    for(int i=20; ~i; i--)
//        if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
//    return fa[x][0];
//}
//int main(){
//    scanf("%d%d%d",&n,&m,&s); int a,b;
//    for(int i=1; i<n; i++){
//        scanf("%d%d",&a,&b);
//        e[a].push_back(b); e[b].push_back(a);
//    }
//    dfs(s,0);
//    while(m--)
//        scanf("%d%d",&a,&b),printf("%d\n",lca(a,b));
//}