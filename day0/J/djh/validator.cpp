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
inline li readI(li l = 0,li r = 1e9){
	li x = 0;
	int c = gc;
    int flag = 0;
	while(c < '0' || c > '9') {
        assert(c == ' ' || c == '\n' || c == '\r' || c == '-');
        flag = (c == '-');
        c = gc;
        if(flag) assert(c >= '0' && c <= '9');
    }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	assert(c == -1 || c == ' ' || c == '\n' || c == '\r');
    if(flag) x = -x;
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
	n = read(1,100000);
	for(int i = 1;i <= n;++i) {
        read(0,1);
        int l = readI(-1000000000, 1000000000);
        int r = readI(-1000000000, 1000000000);
        int w = readI(-1000000000, 1000000000);
        assert(l < r);
    }
	return end_chk();
}
