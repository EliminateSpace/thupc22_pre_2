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
int r,c,n,m;
char s[1010][1010]; 
int ans;
int main(){
	srand(time(0));rd();
	//file("");
	int i,j,k;
	r = read();c = read();
	for(i = 1;i <= r;++i){
		for(j = 1;j <= c;++j){
			do{
				s[i][j] = gc;
			}while(s[i][j] == '\n' || s[i][j] == '\r');
		} 
	}
	for(i = 1;i <= c;++i) if(s[r][i] == '.') break;
	m = i / 4;
	for(i = 1;i <= m;++i){
		int ty = 4 * i - 1;
		for(j = r - 2,k = 0;j > 0;++k,j -= 3){
			//cerr<<i<<" "<<j<<" "<<ty<<"*"<<k<<" "<<s[j][ty]<<endl;
			while(j > 0 && s[j][ty] == '+'){
				ans += k;
				ty += 2;
				j -= 2;
				//if(j > 0) cerr<<i<<" "<<j<<" "<<ty<<"*"<<k<<" "<<s[j][ty]<<endl;
			}
			if(j <= 0 || s[j][ty] != ' ') break; 
		}
	}
	print(ans);
	//fwrite(bfu,1,bfuu - bfu,stdout);
	//cerr<<clock();
	return 0;
}


