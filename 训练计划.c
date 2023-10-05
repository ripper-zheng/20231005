#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))



int n,m;
int p[10010];
int t[10010];
int temp[10010];




int main()
{
    scanf("%d %d",&n,&m);
    int i;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&p[i]);
        
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&t[i]);
    }

    int slove=0;
    
    for(i=1;i<=m;i++)
    {
        if(p[i]==0)temp[i]=1;
        else
        {
            
            temp[i]=temp[p[i]]+t[p[i]];
            
            
            slove=max(slove,temp[i]+t[i]-1);  //temp[i]+t[i]-1 最晚结束的时间
            
        }
        
    }
    for (i = 1;i <= m;i ++) printf("%d ",temp[i]);


    if(slove>n)
    {
        return 0;
    }
    printf("\n");
    
    memset(temp, sizeof(int), sizeof(temp));//设置为一个很大数，为了判断有没有被执行过
    for ( i = m; i > 0; i -- ) //m为训练项目的数目
    {
        if (temp[i] > n) temp[i] = n + 1 - t[i]; //倒着算(因为后者都是关联前者) 被计算过的训练开始天数不会大于n （只会搞自己，不会搞母亲）
        if (p[i] != 0) temp[p[i]] = min(temp[p[i]], temp[i] - t[p[i]]);//（搞母亲）
    }

    for ( i = 1; i <= m; i ++ ) printf("%d ", temp[i]);

    return 0;




}
