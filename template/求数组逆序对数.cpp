#include<bits/stdc++.h>
using namespace std;
const int Maxn = 5e5+10;
int t[Maxn]={0};//树状数组
typedef struct node{
    int val,ind;
}Node;
Node stu[Maxn];
int Rank[Maxn];
typedef long long ll;
int n;
int lowbit(int x){return x&(-x);}
/*单点修改*/
void add(int pos){
    for(int i=pos;i<=n;i+=lowbit(i)) t[i]+=1;
}
/*区间求和*/
int ask(int pos){
    int ans = 0;
    for(int i=pos;i;i-=lowbit(i)) ans+=t[i];
    return ans;
}
/*不能单纯的a.val<b.val,如果相等的话也要保证位置不变,不然贡献会增多*/
int cmp(Node a,Node b){
    if(a.val==b.val)
        return a.ind<b.ind;

    return a.val<b.val;
}
int main()
{
    ll ans = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stu[i].val;
        stu[i].ind=i;
    }
    sort(stu+1,stu+n+1,cmp);
    /*离散化操作*/
    for(int i=1;i<=n;i++){
        Rank[stu[i].ind] = i;
    }
    for(int i=1;i<=n;i++){
        int pos = Rank[i];

        ans+=ask(n)-ask(pos);//digit+1~n中有多少数字已经出现就贡献多少逆序对数，累加到答案
        add(pos);//单点修改
    }
    cout<<ans;
    return 0;
}

/*
 *ans输出的就是数组的逆序对数量
 *
 */


// #include<bits/stdc++.h>
// using namespace std;
// const int Maxn = 5e5+10;
// int t[Maxn];//树状数组
// typedef struct node{
//     int val,ind;
// }Node;
// Node stu1[Maxn],stu2[Maxn];
// int Rank1[Maxn],Rank2[Maxn];
// typedef long long ll;
// int n;
// int lowbit(int x){return x&(-x);}
// /*单点修改*/
// void add(int pos){
//     for(int i=pos;i<=n;i+=lowbit(i)) t[i]+=1;
// }
// /*区间求和*/
// int ask(int pos){
//     int ans = 0;
//     for(int i=pos;i;i-=lowbit(i)) ans+=t[i];
//     return ans;
// }
// /*不能单纯的a.val<b.val,如果相等的话也要保证位置不变,不然贡献会增多*/
// int cmp(Node a,Node b){
//     if(a.val==b.val)
//         return a.ind<b.ind;
//
//     return a.val<b.val;
// }
// void clearBIT() {
//     for(int i=0;i<=Maxn;i++) t[i]=0;
// }
// int main() {
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
//     std::cout.tie(0);
//         ll ans = 0;
//         cin>>n;
//         for(int i=0;i<=n;i++) {
//             t[i]=0;
//         }
//         for(int i=1;i<=n;i++){
//             cin>>stu1[i].val;
//             stu1[i].ind=i;
//         }
//         sort(stu1+1,stu1+n+1,cmp);
//         /*离散化操作*/
//         for(int i=1;i<=n;i++){
//             Rank1[stu1[i].ind] = i;
//         }
//         for(int i=1;i<=n;i++){
//             int pos = Rank1[i];
//
//             ans+=ask(n)-ask(pos);//digit+1~n中有多少数字已经出现就贡献多少逆序对数，累加到答案
//             add(pos);//单点修改
//         }
//         for(int i=0;i<=n;i++) {
//             t[i]=0;
//         }
//         for(int i=1;i<=n;i++){
//             cin>>stu2[i].val;
//             stu2[i].ind=i;
//         }
//         sort(stu2+1,stu2+n+1,cmp);
//         /*离散化操作*/
//         for(int i=1;i<=n;i++){
//             Rank2[stu2[i].ind] = i;
//         }
//         for(int i=1;i<=n;i++){
//             int pos = Rank2[i];
//
//             ans+=ask(n)-ask(pos);//digit+1~n中有多少数字已经出现就贡献多少逆序对数，累加到答案
//             add(pos);//单点修改
//         }
//     }

// 这里的ans就是数组A和数组B逆序对数总和