#include<bits/stdc++.h>
#define Fe(i,L,R) for(int i=L;i<=R;++i)
#define F(i,L,R) for(int i=L;i<R;++i)

#if 1
#define pr(...) fprintf(stderr,__VA_ARGS__)
#else
#define pr(...) void(0)
#endif

int read(int L,int R){
	int x;
	assert(scanf("%d",&x)==1);
	assert(L<=x&&x<=R);
	return x;
}

const int N=1e6+8,sN=1e4+8;

struct Vertex{
	int sz,id,btm,tsz,dfn1,dfn2,id2,dep;
	std::vector<int> e;
	int bid();
}ws[N];
int Vertex::bid(){
	return ws[btm].id2;
}

int B,bp,bp2,tk;

void dfs2(int w){
	if(ws[w].id)return;
	ws[w].id=bp;
	for(int u:ws[w].e)dfs2(u);
}

void dfs1(int w){
	ws[w].dfn1=++tk;
	ws[w].tsz=1;
	int btm=0,sz=0,sz1=0;
	std::vector<int> tmp;
	for(int u:ws[w].e){
		dfs1(u);
		ws[w].tsz+=ws[u].tsz;
		if(ws[u].btm){
			if(!btm)btm=ws[u].btm,sz1=ws[u].sz;
			else btm=-1;
		}else{
			sz+=ws[u].sz;
			tmp.push_back(u);
			if(sz>=B){
				++bp;
				for(int x:tmp)dfs2(x);
				tmp.clear();
				sz=0;
				btm=-1;
			}
		}
	}
	if(btm!=-1){
		sz+=sz1;
		if(sz>=B){
			++bp;
			for(int x:tmp)dfs2(x);
			tmp.clear();
			sz=0;
			btm=-1;
		}
	}
	
	if(btm==-1)
	for(int u:ws[w].e){
		if(ws[u].btm){
			++bp;
			dfs2(u);
		}
	}
	ws[w].sz=1+sz;
	ws[w].id=0;
	ws[w].btm=(btm==-1?w:btm);
	ws[w].dfn2=tk;
	//pr("%d: sz=%d btm=%d\n",w,ws[w].sz,ws[w].btm);
}

struct TDN{
	int x,d,i,md;
	bool operator<(const TDN &w)const{return md<w.md;}
};

int bsz[sN],btms[sN];
std::vector<TDN> ms[sN];
void op1(int x,int d){
	printf("1 %d %d\n",x,d);
}
void op2(){
	printf("2\n");
}
void op3(int i){
	printf("3 %d\n",i);
}

int main(){
	int n=read(1,1e6);
	int m=read(1,1e6);
	
	B=n/sqrt(m)+1;
	pr("B: %d\n",B);
	
	Fe(i,2,n){
		int f=read(1,i-1);
		ws[i].dep=ws[f].dep+1;
		ws[f].e.push_back(i);
	}
	
	bp=0;
	dfs1(1);
	++bp;
	dfs2(1);
	
	assert(ws[1].tsz==n);
	int mbsz=0;
	Fe(i,1,n)++bsz[ws[i].id],assert(1<=ws[i].id&&ws[i].id<=bp);
	Fe(i,1,bp)assert(bsz[i]<=B*2),mbsz=std::max(mbsz,bsz[i]);
	assert(bp<=(n/B+1)*3);
	
	bp2=0;
	Fe(w,1,n){
		if(ws[w].btm==w)btms[ws[w].id2=++bp2]=w;
	}
	
	pr("mbsz: %d / %d\n",mbsz,B*2);
	pr("bp: %d / %d\n",bp,(n/B+1)*3);
	pr("bp2: %d / %d\n",bp2,(n/B+1)*2);
	
	/*Fe(i,1,n){
		pr("%d: dep=%d btm=%d id2=%d\n",i,ws[i].dep,ws[i].btm,ws[i].id2);
	}*/
	
	Fe(i,1,m){
		int x=read(1,n);
		int d=read(0,n);
		ms[ws[ws[x].btm].id2].push_back(TDN{x,d,i,ws[x].dep+d});
	}
	printf("%d\n",5*m-2*(int)ms[0].size());
	for(TDN z:ms[0]){
		op1(z.x,z.d);
		op3(z.i);
		op2();
	}
	Fe(i,1,bp2){
		int x0=btms[i];
		int d0=ws[x0].dep;
		std::sort(ms[i].begin(),ms[i].end());
		int sz=(int)ms[i].size();
		F(j,0,sz){
			TDN z=ms[i][j];
			op1(x0,std::min(n,std::max(0,z.md-d0)));
			op1(z.x,z.d);
			op3(z.i);
			op2();
		}
		F(j,0,sz)op2();
	}
	return 0;
}


