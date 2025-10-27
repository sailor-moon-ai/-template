/*
 *
 *
 *
 * 单点修改，区间查询
 * */
// #include<iostream>
// #define lowbit(x) (x&(-x))
// typedef long long ll;
// using namespace std;
// int c[2000006];
// int n,m;
// ll ans;
// int add_dandian(int x,int k)
// {
//     for(int i=x;i<=n;i+=lowbit(i))
//         c[i]+=k;
// }
// int search(int begin,int end)
// {
//     for(int i=end;i;i-=lowbit(i))
//         ans+=c[i];
//     for(int i=begin-1;i;i-=lowbit(i))
//         ans-=c[i];
//     return 0;
// }
// int main()
// {
//     scanf("%d %d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         int number;
//         scanf("%d",&number);
//         add_dandian(i,number);
//     }

//     for(int i=1;i<=m;i++)
//     {
//         int choice,x,y;
//         scanf("%d %d %d",&choice,&x,&y);
/*
 *
 操作 1：1 x k 含义：将第 x 个数加上 k；
 操作 2：2 x y 含义：输出区间 [x,y] 内每个数的和。
 *
 *
 */
//         if(choice==1) add_dandian(x,y);
//         else
//         {
//             ans=0;
//             search(x,y);
//             printf("%lld\n",ans);
//         }
//     }
//     return 0;
// }





//区间修改，单点查询
//
// #include<iostream>
// #include<cstring>
// #define lowbit(x) (x&(-x))
// using namespace std;
// typedef long long ll;
// const int Maxn=1e6+5;
// int a[500005];
// int d[Maxn]={0};//d[i]的值，d[i]表示第i和i-1个数的差值
// ll c[Maxn];
// int n,m;
// int update(int pos,int k)//pos表示修改点的位置,K表示修改的值也即+K操作
// {
//  for(int i=pos;i<=n;i+=lowbit(i))
//   c[i]+=k;
//  return 0;
// }
// ll ask_qujian(int pos)//返回区间pos到1的总和
// {
//  ll ans=0;
//  for(int i=pos;i;i-=lowbit(i)) ans+=c[i];
//  return ans;
// }
// int main()
// {
//  memset(c,0,sizeof(c));
//  scanf("%d %d",&n,&m);
//  a[0]=0;
//  for(int i=1;i<=n;i++)
//  {
//   scanf("%d",&a[i]);
//   d[i]=a[i]-a[i-1];
//   update(i,d[i]);
//  }

/*
操作 1： 格式：1 x y k 含义：将区间 [x,y] 内每个数加上 k；

操作 2： 格式：2 x 含义：输出第 x 个数的值。
 *
 */
//  for(int i=1;i<=m;i++)
//  {
//   int choice,x,y,k;
//   scanf("%d",&choice);
//   if(choice==1)
//   {
//    scanf("%d %d %d",&x,&y,&k);
//    update(x,k);
//    update(y+1,-k);
//   }
//   else
//   {
//    scanf("%d",&x);
//    printf("%lld\n",ask_qujian(x));
//   }
//  }
//  return 0;
// }
