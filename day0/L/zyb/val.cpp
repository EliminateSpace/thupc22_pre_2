#include<bits/stdc++.h>
#define gc getchar()
#define pc putchar
#define li long long
using namespace std;
inline li read(li l = 0,li r = 1e9){
	li x = 0;
	int c = gc;
	while(c < '0' || c > '9') assert(c == ' ' || c == '\n' || c == '\r'),c = gc;
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	assert(c == -1 || c == ' ' || c == '\n' || c == '\r');
	assert(x >= l && x <= r);
	return x;
}
int end_chk(){
	char c;
	do{
		c = gc;
		assert(c == -1 || c == ' ' || c == '\n' || c == '\r');			
	}while(c != -1);
	return 0;
}
int n,m,a[110][110],rr,cc;
char s[1010][1010]; 
char c[1010][1010],d[10][10] = {
"..+---+",
"./   /|",
"+---+ |",
"|   | +",
"|   |/.",
"+---+.."
};
int ax,bx,ay;
void work(int q,int w,int e){
	int i,j,px = bx - 5 - (n - q) * 2 - (e - 1) * 3,py = (w - 1) * 4 + (n - q) * 2 + 1;
	for(i = 0;i < 6;++i){
		for(j = 0;j < 7;++j) if(d[i][j] != '.') c[i + px][j + py] = d[i][j];
	}
	ax = min(ax,px);
	ay = max(ay,py + 6);
}
void fil(){
	int i,j,k;
	ax = bx = 1000;
	memset(c,'.',sizeof(c));
	for(i = 1;i <= n;++i){
		for(j = 1;j <= m;++j){
			for(k = 1;k <= a[i][j];++k) if(k == a[i][j] || a[i + 1][j] < k || a[i][j + 1] < k) work(i,j,k);
		}
	}
}
int main(){
	int i,j,k;
	rr = read(1,500);cc = read(1,500);
	for(i = 1;i <= rr;++i){
		for(j = 1;j <= cc;++j){
			do{
				s[i][j] = gc;
			}while(s[i][j] == '\n' || s[i][j] == '\r');
			assert(s[i][j] == ' ' || s[i][j] == '.' || s[i][j] == '+' || s[i][j] == '-' || s[i][j] == '/' || s[i][j] == '|');
		} 
	}
	
	for(i = 1;i <= cc;++i) if(s[rr][i] == '.') break;
	m = i / 4;
	int ty = 3;
	for(j = rr - 2,k = 0;j > 0;++k,j -= 3){
		while(j > 0 && s[j][ty] == '+'){
			++n;
			ty += 2;
			j -= 2;
		}
		if(j <= 0 || s[j][ty] != ' ') break; 
	}
	assert(n <= 50 && m <= 50);
	cerr<<n<<" "<<m<<endl;
	for(i = 1;i <= m;++i){
		int ty = 4 * i - 1;
		int p = n;
		for(j = rr - 2,k = 0;j > 0;++k,j -= 3){
			while(j > 0 && s[j][ty] == '+'){
				a[p--][i] = k;
				assert(a[p + 1][i] <= 100);
				ty += 2;
				j -= 2;
			}
			if(j <= 0 || s[j][ty] != ' ') break; 
		}
	}
	for(i = 1;i <= n;++i){
		for(j = 1;j <= m;++j){
			cerr<<a[i][j]<<" ";
			assert(a[i][j] >= a[i + 1][j] && a[i][j] >= a[i][j + 1]);
		}
		cerr<<endl;
	}
	
	fil();
	cerr<<ax<<" "<<bx<<" "<<ay<<endl;
	for(i = ax;i <= bx;++i){
		for(j = 1;j <= ay;++j) putchar(c[i][j]);putchar('\n');
	}
	assert(bx - ax + 1 == rr && ay == cc);
	for(i = ax;i <= bx;++i){
		for(j = 1;j <= ay;++j) assert(c[i][j] == s[i - ax + 1][j]);
	}
	end_chk();
	return 0;
}
