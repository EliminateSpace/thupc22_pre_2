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
int n,m;
int main(){
	n = read(1,5000);m = read(0,10000); 
	for(int i = 1;i <= n + n;++i){
		read(1,1e9);read(1,1e9);read(1,1e9);
	}
	for(int i = 1;i <= m;++i){
		int l = read(1,n + n),r = read(1,n + n);
		assert(l != r && ((l + 1) ^ (r + 1)) != 1);
		read(1,1e9);read(1,1e9);
	}
	return end_chk();
}
