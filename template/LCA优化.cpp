// void add(int a, int b){
//     to[++tot]=b,ne[tot]=h[a],h[a]=tot;
// }
// void dfs(int x, int f){
//     dep[x]=dep[f]+1; fa[x][0]=f;
//     for(int i=0; i<=20; i++)
//         fa[x][i+1]=fa[fa[x][i]][i];
//     for(int i=h[x]; i; i=ne[i])
//         if(to[i]!=f) dfs(to[i], x);
// }
// int lca(int x, int y){
//     if(dep[x]<dep[y]) swap(x, y);
//     for(int i=20; ~i; i--)
//         if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
//     if(x==y) return y;
//
//     for(int i=20; ~i; i--)
//         if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
//     return fa[x][0];
// }
//
//
//
// // 2.0s
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;
//
// const int N=5e5+10,M=2*N;
// int n,m,s,a,b;
// int dep[N],fa[N][22];
// int h[N],to[M],ne[M],tot;
// void add(int a, int b){
//     to[++tot]=b,ne[tot]=h[a],h[a]=tot;
// }
// void dfs(int x, int f){
//     dep[x]=dep[f]+1; fa[x][0]=f;
//     for(int i=0; i<=20; i++)
//         fa[x][i+1]=fa[fa[x][i]][i];
//     for(int i=h[x]; i; i=ne[i])
//         if(to[i]!=f) dfs(to[i], x);
// }
// int lca(int x, int y){
//     if(dep[x]<dep[y]) swap(x, y);
//     for(int i=20; ~i; i--)
//         if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
//     if(x==y) return y;
//
//     for(int i=20; ~i; i--)
//         if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
//     return fa[x][0];
// }
// int main(){
//     scanf("%d%d%d", &n,&m,&s);
//     for(int i=1; i<n; i++){
//         scanf("%d%d",&a,&b);
//         add(a,b); add(b,a);
//     }
//     dfs(s, 0);
//     while(m--){
//         scanf("%d%d", &a, &b);
//         printf("%d\n",lca(a, b));
//     }
//     return 0;
// }