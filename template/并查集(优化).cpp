/*
合并（路径压缩）
int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);  //父节点设为根节点
        return fa[x];         //返回父节点
    }
}


初始化（按秩合并）

inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] ]= i;
        rank[i = 1;
    }
}

合并（按秩合并）

inline void merge(int i, int j)
{
    int x = find(i), y = find(j);    //先找到两个根节点
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
}


模版整理
const int maxn = 5005;
int Fa[maxn],Rank[maxn];
void init(int n)  ///初始化
{
    for (int i = 1; i <= n; i++)
    {
        Fa[i] = i;
        Rank[i] = 1;
    }
}
int find(int x) //查找
{
    return x == Fa[x]? x:(Fa[x] = find(Fa[x]));//路径压缩
}
 void merge(int i, int j) //合并
{
     int x = find(i), y = find(j);
     if (Rank[x] <= Rank[y])
     {
         Fa[x] = y;
     }
     else
     {
         Fa[y] = x;
     }
     if (Rank[x] == Rank[y] && x!=y)
     {
         Rank[y]++;
     }
}

 */