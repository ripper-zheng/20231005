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
            
            
            slove=max(slove,temp[i]+t[i]-1);  //temp[i]+t[i]-1 ���������ʱ��
            
        }
        
    }
    for (i = 1;i <= m;i ++) printf("%d ",temp[i]);


    if(slove>n)
    {
        return 0;
    }
    printf("\n");
    
    memset(temp, sizeof(int), sizeof(temp));//����Ϊһ���ܴ�����Ϊ���ж���û�б�ִ�й�
    for ( i = m; i > 0; i -- ) //mΪѵ����Ŀ����Ŀ
    {
        if (temp[i] > n) temp[i] = n + 1 - t[i]; //������(��Ϊ���߶��ǹ���ǰ��) ���������ѵ����ʼ�����������n ��ֻ����Լ��������ĸ�ף�
        if (p[i] != 0) temp[p[i]] = min(temp[p[i]], temp[i] - t[p[i]]);//����ĸ�ף�
    }

    for ( i = 1; i <= m; i ++ ) printf("%d ", temp[i]);

    return 0;




}
