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
int n,m;
li a[10010],b[10010],c[10010];
li ans = 1e18l;
int s[10010],t[10010];
li x[10010],y[10010]; 
int p[10010],q[10010];
void chk(){
	li as = 0;
	for(int i = 1;i <= n + n;++i){
		if(p[i]) as += a[i];
		else as += b[i];
	}
	for(int i = 1;i <= n;++i){
		if(p[i + i - 1] && !p[i + i]) as += c[i + i - 1];
		if(p[i + i] && !p[i + i - 1]) as += c[i + i];
	}
	for(int i = 1;i <= m;++i){
		if(!q[s[i]] && p[t[i]]) as += x[i];
		if(!p[s[i]] && q[t[i]]) as += y[i];
	}
	ans = min(ans,as);
}
void dfs(int x){
	if(x == n + 1){
		chk();
		return;
	}
	p[x + x - 1] = q[x + x - 1] = 0;
	p[x + x] = q[x + x] = 0;
	dfs(x + 1);
	p[x + x - 1] = 1;
	dfs(x + 1);
	p[x + x - 1] = 0;p[x + x] = 1;
	dfs(x + 1);
	p[x + x - 1] = 1;
	dfs(x + 1);
	q[x + x - 1] = q[x + x] = 1;
	dfs(x + 1); 
}
int main(){
	srand(time(0));rd();
	//file("");
	int i,j;
	n = read();m = read();
	for(i = 1;i <= n + n;++i) a[i] = read(),b[i] = read(),c[i] = read();
	for(i = 1;i <= m;++i) s[i] = read(),t[i] = read(),x[i] = read(),y[i] = read();
	dfs(1);
	print(ans);pc('\n');
	//fwrite(bfu,1,bfuu - bfu,stdout);
	//cerr<<clock();
	return 0;
}


