#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct unit
{
    char name[10];
    int lasttime;
    int firsttime,nexttime;
}a[10],b[10],c[10],s[10];
int idx=0;
bool cmp(unit a,unit b)//����
{
    if(a.nexttime<b.nexttime)
        return true;
    else
        return false;
}
bool cmp1(unit a,unit b)//����
{
    if(a.firsttime>b.firsttime)
        return true;
    else
        return false;
}

void Apply(struct unit a[],int n)
{


    cout << "ԤԼ��λ ԤԼʱ�� ��ʼʱ�� ����ʱ��" << endl;
    int i;
    for(i=0;i<n;i++)
        scanf("%s %d %d %d",a[i].name,&a[i].lasttime,&a[i].firsttime,&a[i].nexttime);
    getchar();
    system("CLS");
}
int j=0,k=0;
void Search(struct unit a[],int n,struct unit b[],struct unit c[])//����ɸѡ����
{
    sort(a,a+n,cmp);
    int i,first=0,next=24;
    for(i=0;i<n;i++)
    {
        if(a[i].firsttime>=first&&a[i].nexttime<=next)
            {
                strcpy(b[j].name,a[i].name);
                b[j].lasttime=a[i].lasttime;
                b[j].firsttime=a[i].firsttime;
                b[j].nexttime=a[i].nexttime;
                j++;
                first=a[i].nexttime;
            }

    }
    sort(a,a+n,cmp1);
    first=0,next=24;
    for(i=0;i<n;i++)
    {
        if(a[i].firsttime>=first&&a[i].nexttime<=next)
            {
                strcpy(c[k].name,a[i].name);
                c[k].lasttime=a[i].lasttime;
                c[k].firsttime=a[i].firsttime;
                c[k].nexttime=a[i].nexttime;
                k++;
                next=a[i].firsttime;
            }

    }
}
/*�ݹ����n�������е��Ӽ�,����b��ʾ�ýڵ��Ƿ�ѡ�У�curΪ��ǰ�±�,��ʼֵ0*/
int visit[100];
void print_subset(int n,int *visit,int cur){
    int sss[10]={0};
    int m=0;
    int flag5,flag;
     for(int i=0;i<cur;i++)
     {
         sss[m]=visit[i];
         m++;
     }
    if(m!=0)
    {
     if(j<k)
     {
         for(int i=k-1;i>=0;i--)
         {
             flag5=1;
             for(int y=0;y<m;y++)
             {
                if(s[sss[y]].firsttime==c[i].firsttime&&s[sss[y]].nexttime==c[i].nexttime)
                {
                    printf("%s %d %d %d\n",s[sss[y]].name,s[sss[y]].lasttime,s[sss[y]].firsttime,s[sss[y]].nexttime);
                    flag5=0;
                    break;
                }
             }
             if(flag5)
                printf("%s %d %d %d\n",c[i].name,c[i].lasttime,c[i].firsttime,c[i].nexttime);
         }
     }
     else if(j>k)
     {
        for(int i=0;i<j;i++)
        {
            flag5=1;
            for(int y=0;y<m;y++)
            {
                if(s[sss[y]].firsttime==b[i].firsttime&&s[sss[y]].nexttime==b[i].nexttime)
                {
                    printf("%s %d %d %d\n",s[sss[y]].name,s[sss[y]].lasttime,s[sss[y]].firsttime,s[sss[y]].nexttime);
                    flag5=0;
                    break;
                }
            }
            if(flag5)
                printf("%s %d %d %d\n",b[i].name,b[i].lasttime,b[i].firsttime,b[i].nexttime);
        }
     }
     else{
        for(int i=0;i<j;i++)
        {
            int flag5=1;
            for(int y=0;y<m;y++)
            {
                if(s[sss[y]].firsttime==b[i].firsttime&&s[sss[y]].nexttime==b[i].nexttime)
                    {
                        printf("%s %d %d %d\n",s[sss[y]].name,s[sss[y]].lasttime,s[sss[y]].firsttime,s[sss[y]].nexttime);
                        flag5=0;
                        break;
                    }
            }
            if(flag5)
                printf("%s %d %d %d\n",b[i].name,b[i].lasttime,b[i].firsttime,b[i].nexttime);
        }
        printf("\n");
        for(int i=0,xx=k-1;i<j;i++)
        {
            if(strcmp(b[i].name,c[xx].name)==0)
                flag=0;
            else
            {
                flag=1;break;
            }
            xx--;
        }
        if(flag)
        {
            for(int i=k-1;i>=0;i--)
            {
                flag5=1;
                for(int y=0;y<m;y++)
                {
                    if(s[sss[y]].firsttime==c[i].firsttime&&s[sss[y]].nexttime==c[i].nexttime)
                    {
                        printf("%s %d %d %d\n",s[sss[y]].name,s[sss[y]].lasttime,s[sss[y]].firsttime,s[sss[y]].nexttime);
                        flag5=0;
                        break;
                    }
                }
                if(flag5)
                printf("%s %d %d %d\n",c[i].name,c[i].lasttime,c[i].firsttime,c[i].nexttime);
            }
        }
     }
     }
     printf("\n");
     int s=cur?visit[cur-1]+1:0;//�����ɣ������Ӽ��ظ�
     for(int i=s;i<n;i++){
         visit[cur]=i;//���µ�Ԫ�ؼ����Ӽ��ĵ�cur��λ��
         print_subset(n,visit,cur+1);
     }
}
int flag2=0;
void SearchSame(struct unit a[],int n,struct unit s[])
{
    sort(a,a+n,cmp);
    for(int i=0;i<n-1;i++)
    {
        if(a[i].firsttime==a[i+1].firsttime&&a[i].nexttime==a[i+1].nexttime)
        {
            strcpy(s[idx].name,a[i+1].name);
            s[idx].lasttime=a[i+1].lasttime;
            s[idx].firsttime=a[i+1].firsttime;
            s[idx].nexttime=a[i+1].nexttime;
            idx++;
        }
    }
    if(idx!=1&&s[0].firsttime==s[idx-1].firsttime&&s[0].nexttime==s[idx-1].nexttime)
    {
        flag2=1;
    }
}
int flag1;
void print(struct unit b[],struct unit c[],struct unit s[])//����ɸѡ�������
{
    if(j==k)
        {
            for(int i=0;i<j;i++)
            {
                printf("%s %d %d %d\n",b[i].name,b[i].lasttime,b[i].firsttime,b[i].nexttime);
            }printf("\n");
            for(int i=0,xx=k-1;i<j;i++)
            {
                if(strcmp(b[i].name,c[xx].name)==0)
                    flag1=0;
                else
                {
                    flag1=1;break;
                }
                xx--;
            }
            if(flag1)
            {
                for(int i=k-1;i>=0;i--)
                {
                    printf("%s %d %d %d\n",c[i].name,c[i].lasttime,c[i].firsttime,c[i].nexttime);
                }
                printf("\n");
            }
        }
        else if(j<k)
        {
            for(int i=k-1;i>=0;i--)
            {
                printf("%s %d %d %d\n",c[i].name,c[i].lasttime,c[i].firsttime,c[i].nexttime);
            }printf("\n");
        }
        else
        {
            for(int i=0;i<j;i++)
            {
                printf("%s %d %d %d\n",b[i].name,b[i].lasttime,b[i].firsttime,b[i].nexttime);
            }printf("\n");
        }
}
void flagprint(struct unit b[],struct unit c[],struct unit s[])//�ظ��Ӽ��������
{
    if(idx==0)
    {
        return ;//û���ظ�ֱ��������
    }
    if(flag2)//����ȫ���ظ�Ԫ�������ж�
    {
        int m=0;
        while(m<idx)
        {
            printf("%s %d %d %d\n",s[m].name,s[m].lasttime,s[m].firsttime,s[m].nexttime);
            for(int i=0;i<j;i++)
            {
                if((b[i].firsttime==s[m].firsttime)&&(b[i].nexttime==s[m].nexttime))
                    continue;
                else
                    printf("%s %d %d %d\n",b[i].name,b[i].lasttime,b[i].firsttime,b[i].nexttime);
            }
            m++;
            printf("\n");
        }
    }
    int f=1;
    for(int i=0;i<j;i++)
        {
            for(int x=0;x<idx;x++)
            {
                if(b[i].name==s[x].name)
                    {
                        f=0;
                        break;
                    }
            }
        }
    if(f)//�����Ӽ���ӡ����ֱ�������
    {
            print_subset(idx,visit,0);
    }
}
int main()
{
    cout << "\t\t****************************************" << endl;
	cout << "\t\t****************************************" << endl;
	cout << "\t\t******                            ******" << endl;
	cout << "\t\t******   ��ӭ���뱨��������ϵͳ   ******" << endl;
	cout << "\t\t******                            ******" << endl;
	cout << "\t\t****************************************" << endl;
	cout << "\t\t****************************************" << endl;
	cout << "\t\t������ԤԼ���" << endl;
	cout << "ԤԼ��λ����" << endl;
	int n;
	scanf("%d",&n);
    Apply(a,n);
    SearchSame(a,n,s);
    Search(a,n,b,c);
    print(b,c,s);
    flagprint(b,c,s);
    return 0;
}
