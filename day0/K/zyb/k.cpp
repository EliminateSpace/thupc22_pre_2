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
struct xd{
	bool op;
	int l,r,p;
}a[100010],b[100010],c[100010],d[100010];
int n,cnt1,cnt2,cnt3,cnt4; 
inline bool operator < (xd q,xd w){
	if(q.op != w.op) return q.op < w.op;
	return q.p == w.p ? q.l < w.l : q.p < w.p;
}
bool pd[20];
vector<xd> zm[20];
int f[20];
inline int getf(int x){
	return f[x] == x ? x : f[x] = getf(f[x]);
}
inline void mg(int x,int y){
	f[getf(x)] = getf(y);
}
inline bool jiao(xd x,xd y){
	return x.l <= y.p && y.p <= x.r && y.l <= x.p && x.p <= y.r;
}
inline void wk(vector<xd> x){
	sort(x.begin(),x.end());
	if(x.size() == 2){//T
		if(!x[0].op && x[1].op){
			if(x[0].l < x[1].p && x[1].p < x[0].r){
				if(x[0].p == x[1].r)
					pd[0] = 1;
			}
		}
	}
	if(x.size() == 3){//H
		if(!x[0].op && x[1].op){
			if(x[0].l == x[1].p && x[0].r == x[2].p){
				if(x[1].l == x[2].l && x[1].l < x[0].p && x[0].p < x[1].r && x[1].r == x[2].r)
					pd[1] = 1;
			}
		}
	}
	if(x.size() == 3){//U
		if(!x[0].op && x[1].op){
			if(x[0].l == x[1].p && x[0].r == x[2].p){
				if(x[1].l == x[2].l && x[1].l == x[0].p && x[1].r == x[2].r)
					pd[2] = 1;
			}
		}
	}
	if(x.size() == 4){//P
		if(!x[1].op && x[2].op){
			if(x[0].l == x[1].l && x[1].l == x[2].p && x[0].r == x[1].r && x[1].r == x[3].p){
				if(x[2].l < x[0].p && x[3].l == x[0].p && x[2].r == x[1].p && x[3].r == x[1].p)
					pd[3] = 1;
			}
		}
	}
	if(x.size() == 3){//C
		if(!x[1].op && x[2].op){
			if(x[2].p == x[0].l && x[0].l == x[1].l && x[0].r == x[1].r){
				if(x[0].p == x[2].l && x[1].p == x[2].r)
					pd[4] = 1;
			}
		}
	}
}
int main(){
	srand(time(0));rd();
	//file("");
	n = read();
	int op,i,j,k,l;
	for(i = 1;i <= n;++i){
		op = read();
		if(op == 0){
			a[++cnt1].op = 0;
			a[cnt1].l = read();
			a[cnt1].r = read();
			a[cnt1].p = read();
		}
		else{
			b[++cnt2].op = 1;
			b[cnt2].l = read();
			b[cnt2].r = read();
			b[cnt2].p = read();
		}
	}
	sort(a + 1,a + cnt1 + 1);
	sort(b + 1,b + cnt2 + 1);
	for(i = 1;i <= cnt1;++i){
		if(i == 1 || c[cnt3].p != a[i].p || c[cnt3].r < a[i].l) c[++cnt3] = a[i];
		else c[cnt3].r = max(c[cnt3].r,a[i].r);
	}
	for(i = 1;i <= cnt2;++i){
		if(i == 1 || d[cnt4].p != b[i].p || d[cnt4].r < b[i].l) d[++cnt4] = b[i];
		else d[cnt4].r = max(d[cnt4].r,b[i].r);
	}	
	if(cnt3 != 7 || cnt4 != 8){
		puts("No");
		return 0;
	}
	for(i = 1;i <= 15;++i) f[i] = i;
	for(i = 1;i <= 7;++i) for(j = 1;j <= 8;++j) if(jiao(c[i],d[j])) mg(i,j + 7);
	for(i = 1;i <= 7;++i) zm[getf(i)].pb(c[i]);
	for(i = 1;i <= 8;++i) zm[getf(i + 7)].pb(d[i]);
	for(i = 1;i <= 15;++i) if(getf(i) == i) wk(zm[i]);
	//cerr<<pd[0]<<" "<<pd[1]<<" "<<pd[2]<<" "<<pd[3]<<" "<<pd[4]<<endl;
	if(pd[0] && pd[1] && pd[2] && pd[3] && pd[4]) puts("Yes");
	else puts("No");
	//fwrite(bfu,1,bfuu - bfu,stdout);
	//cerr<<clock();
	return 0;
}


