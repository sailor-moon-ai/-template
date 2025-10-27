
//从n个位置中填m个位置的=个数
/*auto comb=[&](int n,int m)->int{
     m=std::min(m,n-m);
     long long res=1;
     for(int i=1;i<=m;i++){
         res=res*(n-i+1)/i;
     }
     return res;
 };
 */



//长度为sz的排列个数
/*
        auto perm=[&](int sz)->int{
            long long res=1;
            for(auto c:cnt){
                if(c==0){
                    continue;
                }
                res*=comb(sz,c);//从长sz中选c个位置填
                sz-=c;
            }
            return res;
        };
 *
 */



