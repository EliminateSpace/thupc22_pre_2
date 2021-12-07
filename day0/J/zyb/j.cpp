#include<bits/stdc++.h>
//#pragma gcc optimize(3)
#define gc getchar()
//char buf[100000],*buff = buf + 100000;
//#define gc ((buff == buf + 100000 ? (fread(buf,1,100000,stdin),buff = buf) : 0),*(buff++))
#define pc putchar
//char bfu[10000000],*bfuu = bfu;
//#define pc(x) (*(bfuu++) = x)
#define li long long
#define uli unsigned li
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define md int mid = l + r >> 1
#define ls q << 1
#define rs q << 1 | 1
#define ln ls,l,mid
#define rn rs,mid + 1,r
using namespace std;
//const int mo = 998244353;
//const int mo = 1000000007;
inline li read(){
	li x = 0;
	int y = 0,c = gc;
	while(c < '0' || c > '9') y = c,c = gc;
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	return y == '-' ? -x : x;
}
inline void prt(li x){
	if(x >= 10) prt(x / 10);
	pc(x % 10 + '0');
}
inline void print(li x){
	if(x < 0) pc('-'),x = -x;
	prt(x);
}
inline void file(char *s){
	char c[50];
	sprintf(c,"%s.in",s);
	freopen(c,"r",stdin);
	sprintf(c,"%s.out",s);
	freopen(c,"w",stdout);
}
li s1 = 19260817,s2 = 23333333,s3 = 998244853,srd;
inline li rd(){
	return srd = (srd * s1 + s2 + rand()) % s3;
}
struct edge{
	int to,nxt;
	li val;
}e[1000010];
int cnt = 1,fir[15010],dq[15010],n,m;
inline void ins(int u,int v,li w){
	e[++cnt].to = v;e[cnt].nxt = fir[u];fir[u] = cnt;e[cnt].val = w;
	e[++cnt].to = u;e[cnt].nxt = fir[v];fir[v] = cnt;e[cnt].val = 0;
}
int s,g,q[15010],h,t,vis[15010];
bool bfs(){
	memset(vis,0,sizeof(vis));
	vis[s] = 1;
	h = t = 0;
	q[++t] = s; 
	while(h < t){
		int x = q[++h];
		for(int i = fir[x];i;i = e[i].nxt) if(e[i].val > 0 && !vis[e[i].to]){
			vis[e[i].to] = vis[x] + 1;
			q[++t] = e[i].to;
		}
	}
	return vis[g];
}
li dfs(int q,li fl){
	if(q == g) return fl;
	li ans = 0,tmp;
	for(int &i = dq[q];i;i = e[i].nxt) if(e[i].val > 0 && vis[e[i].to] == vis[q] + 1){
		tmp = dfs(e[i].to,min(e[i].val,fl));
		ans += tmp;fl -= tmp;
		e[i].val -= tmp;e[i ^ 1].val += tmp;
		if(!fl) return ans;
	}
	if(fl) vis[q] = -1;
	return ans;
}
li wk(){
	li ans = 0,tmp;
	while(bfs()){
		memcpy(dq,fir,sizeof(dq));
		while(tmp = dfs(s,5e18l)) ans += tmp;
	}
	return ans;
}
#define team(x) (n + n + ((x) + 1 >> 1))
#define ptn(x) (((x) + 1 ^ 1) - 1)
int main(){
	srand(time(0));rd();
	//file("");
	int i,j,a,b,c,u,v;
	n = read();m = read();
	s = n * 3 + 1;g = n * 3 + 2;
	for(i = 1;i <= n + n;++i){
		a = read();b = read();c = read();
		ins(s,team(i),a + 1e14l);
		ins(team(i),i,a + 1e14l);
		ins(i,g,b + 1e14l);
		ins(ptn(i),i,c);
	}
	for(i = 1;i <= m;++i){
		u = read();v = read();a = read();b = read();
		ins(team(u),v,a);
		ins(u,team(v),b);
	}
	print(wk() - 2e14l * n);pc('\n');
	//fwrite(bfu,1,bfuu - bfu,stdout);
	//cerr<<clock();
	return 0;
}
