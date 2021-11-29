#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define dmin(a,b) ((a)<(b)?(a):(b))
namespace io
{
	int F()
	{
		int n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
	long long G()
	{
		long long n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
}
int R(int l,int r)
{
	return rand()%(r-l+1)+l;
}
struct edge
{
	int to;
	int cap;
	int next;
}e[4444444];
int pe=444444;
void insert(int a,int to,int cap)
{
	e[pe]=(edge){to,cap,e[a].next};
	e[a].next=pe++;
}
void addedge(int a,int to,int cap)
{
	insert(a,to,cap);
	insert(to,a,0);
}
int pno;
int indiv[111111],team[111111],ptn[111111];
int S,T;

int d[111111],q[111111],hq,tq,vis[111111],pv;
int cur[111111];
bool bfs()
{
	for(q[hq=1]=T,tq=2,vis[T]=++pv;hq!=tq;++hq)
		for(int p=e[q[hq]].next;p;p=e[p].next)
			if(vis[e[p].to]!=pv&&e[p^1].cap)
				vis[e[p].to]=pv,d[e[p].to]=d[q[hq]]+1,q[tq++]=e[p].to;
	return vis[S]==pv;
}
long long dfs(int o,long long min)
{
	if(o==T||min==0)return min;
	long long f=0,tmp;
	for(int &p=cur[o];p;p=e[p].next)
		if(e[p].cap&&d[e[p].to]==d[o]-1&&(tmp=dfs(e[p].to,dmin(min,e[p].cap))))
		{
			e[p].cap-=tmp;
			e[p^1].cap+=tmp;
			f+=tmp;
			min-=tmp;
			if(min==0)return f;
		}
	return f;
}
long long dinic()
{
	long long flow=0;
	while(bfs())
	{
		for(int i=1;i<=T;++i)
			cur[i]=e[i].next;
		flow+=dfs(S,0x3f3f3f3f3f3f3f3fll);
	}
	return flow;
}
int main()
{
	int n=io::F(),m=io::F();
	for(int i=1;i<=2*n;++i)
		indiv[i]=++pno;
	for(int i=1;i<=2*n;++i)
		ptn[i]=(i-1^1)+1;
	for(int i=1;i<=n;++i)
		team[i]=++pno;
	S=++pno;
	T=++pno;
	for(int i=1;i<=2*n;++i)
	{
		int c=io::F(),d=io::F(),e=io::F();
		addedge(S,indiv[i],d);
		addedge(indiv[i],team[i+1>>1],c);
		addedge(team[i+1>>1],T,c);
		addedge(indiv[i],indiv[ptn[i]],e);
	}
	for(int i=1;i<=m;++i)
	{
		int A=io::F(),B=io::F(),a=io::F(),b=io::F();
		addedge(indiv[B],team[A+1>>1],a);
		addedge(team[B+1>>1],indiv[A],b);
	}
	printf("%lld\n",dinic());
	return 0;
}