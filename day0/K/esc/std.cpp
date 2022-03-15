#include<bits/stdc++.h>
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
}
char map[555][444];
int main()
{
	int r=io::F(),c=io::F();
	for(int i=1;i<=r;++i,getchar())
		for(int j=1;j<=c;++j)
			map[i][j]=getchar();
	int p=strstr(map[r]+1,".")-map[r];
	int m=p-2>>2,n=c-p+1>>1;
	int ans=m*n*(r-n);
	for(int i=2;i<=r;++i)
	{
		int now=1;
		char* tmp;
		while(tmp=strstr(map[i]+now,"/   /"))
			ans-=i,now=tmp-map[i]+4;
	}
	printf("%d\n",ans/3);
	return 0;
}