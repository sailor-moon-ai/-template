
//未改进的求next数组
/*
*typedef struct
{
    char data[MaxSize];
    int length;			//串长
} SqString;
//SqString 是串的数据结构
//typedef重命名结构体变量，可以用SqString t定义一个结构体。
void GetNext(SqString t,int next[])		//由模式串t求出next值
{
    int j,k;
    j=0;k=-1;
    next[0]=-1;//第一个字符前无字符串，给值-1
    while (j<t.length-1)
    //因为next数组中j最大为t.length-1,而每一步next数组赋值都是在j++之后
    //所以最后一次经过while循环时j为t.length-2
    {
        if (k==-1 || t.data[j]==t.data[k]) 	//k为-1或比较的字符相等时
        {
            j++;k++;
            next[j]=k;
            //对应字符匹配情况下，s与t指向同步后移
            //通过字符串"aaaaab"求next数组过程想一下这一步的意义
            //printf("(1) j=%d,k=%d,next[%d]=%d\n",j,k,j,k);
           }
           else
        {
            k=next[k];
           /我们现在知道next[k]的值代表的是下标为k的字符前面的字符串最长相等前后缀的长度
            //也表示该处字符不匹配时应该回溯到的字符的下标
            //这个值给k后又进行while循环判断，此时t.data[k]即指最长相等前缀后一个字符**
            //为什么要回退此处进行比较，我们往下接着看。其实原理和上面介绍的KMP原理差不多
            //printf("(2) k=%d\n",k);
        }
	}
}
 */

//配合未改就的next数组的kmp
/*
*int KMPIndex(SqString s,SqString t)  //KMP算法
{

    int next[MaxSize],i=0,j=0;
    GetNext(t,next);
    while (i<s.length && j<t.length)
    {
        if (j==-1 || s.data[i]==t.data[j])
        {
            i++;j++;  			//i,j各增1
        }
        else j=next[j]; 		//i不变,j后退，现在知道为什么这样让子串回退了吧
    }
    if (j>=t.length)
        return(i-t.length);  	//返回匹配模式串的首字符下标
    else
        return(-1);        		//返回不匹配标志
}
 */

//改进的next数组
/*void GetNextval(SqString t,int nextval[])
//由模式串t求出nextval值
{
    int j=0,k=-1;
    nextval[0]=-1;
       while (j<t.length)
    {
           if (k==-1 || t.data[j]==t.data[k])
        {
            j++;k++;
            if (t.data[j]!=t.data[k])
//这里的t.data[k]是t.data[j]处字符不匹配而会回溯到的字符
//为什么？因为没有这处if判断的话，此处代码是next[j]=k;
//next[j]不就是t.data[j]不匹配时应该回溯到的字符位置嘛
                nextval[j]=k;
               else
                nextval[j]=nextval[k];
//这一个代码含义是不是呼之欲出了？
//此时nextval[j]的值就是就是t.data[j]不匹配时应该回溯到的字符的nextval值
//用较为粗鄙语言表诉：即字符不匹配时回溯两层后对应的字符下标
           }
           else  k=nextval[k];
    }

}
 */


//配合改进的next数组的kmp
/*
*int KMPIndex1(SqString s,SqString t)
//修正的KMP算法
//只是next换成了nextval
{
    int nextval[MaxSize],i=0,j=0;
    GetNextval(t,nextval);
    while (i<s.length && j<t.length)
    {
        if (j==-1 || s.data[i]==t.data[j])
        {
            i++;j++;
        }
        else j=nextval[j];
    }
    if (j>=t.length)
        return(i-t.length);
    else
        return(-1);
}
 *
 */


