/*
 *当想要求一个区间的异或，或，与等值时
 *可以用前缀和来计算前i位中，第j位为1的个数
 *然后用前缀和来计算区间异或和
 *
 *
 * exp：
 * std::vector<int>a(n+1);
*  for(int i=1;i<=n;i++) {
        std::cin>>a[i];
    }
    std::vector<std::vector<int>>pre(n+1,std::vector<int>(100));
    //pre[i][j]表示前i位中，第j位上1的个数
    for(int i=1;i<=n;i++) {
        for(int j=0;j<32;j++) {
            if((a[i]>>j)&1) {
                pre[i][j]++;
            }
            pre[i][j]+=pre[i-1][j];
        }
    }

            int now=0;
            for(int j=0;j<32;j++) {
                int num=pre[id][j]-pre[mid-1][j];
                if(num==id-mid+1) {
                    now|=(1<<j);
                }
            }
 */