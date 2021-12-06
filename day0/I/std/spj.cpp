#include<bits/stdc++.h>
#define Fe(i,L,R) for(int i=L;i<=R;++i)
#define F(i,L,R) for(int i=L;i<R;++i)

#if 1
#define pr(...) fprintf(stderr,__VA_ARGS__)
#else
#define pr(...) void(0)
#endif

const int MEM=1<<26;
char pool[MEM],*pool_p=pool;

template<class T>
void alloc(T *&p,int sz){
	p=reinterpret_cast<T*>(pool_p);
	pool_p+=sz*sizeof(T);
	assert(pool_p<pool+MEM);
	F(i,0,sz)new(p+i)T();
}

template<class T>
struct BIT{
	T *a;
	int n;
	void alloc(int n0){
		n=n0;
		::alloc(a,n+1);
	}
	void add(int x,T y){
		assert(1<=x&&x<=n);
		int _n=n;
		for(;x<=_n;x+=x&-x)a[x]+=y;
	}
	T sum(int x){
		assert(0<=x&&x<=n);
		T s=0;
		for(;x;x-=x&-x)s+=a[x];
		return s;
	}
	void dna(){
		Fe(i,1,n)a[i]+=a[i-(i&-i)];
	}
	T at(int x){
		assert(0<=x&&x<=n);
		return a[x];
	}
};

int read(int L,int R){
	int x;
	assert(scanf("%d",&x)==1);
	assert(L<=x&&x<=R);
	return x;
}
FILE *f;
int readf(int L,int R){
	int x;
	assert(fscanf(f,"%d",&x)==1);
	assert(L<=x&&x<=R);
	return x;
}

const int N=1e6+8;
const long long COST_LIMIT=4e9;

struct Vertex{
	int sz,dep,dfn1,dfn2,h;
	std::vector<int> e;
}ws[N];
int tk=0;
void dfs(int w,int dep=0){
	ws[w].dep=dep;
	ws[w].dfn1=++tk;
	ws[w].h=1;
	for(int u:ws[w].e){
		dfs(u,dep+1);
		ws[w].h=std::max(ws[w].h,ws[u].h+1);
	}
	ws[w].dfn2=tk;
}
struct Q{
	int x,y,sgn,tp;
	bool operator<(const Q &q)const{return y*2+tp<q.y*2+q.tp;}
};
std::vector<Q> qs;
int n,m;
struct TN{
	int x,d;
	void rd(){
		x=read(1,n);
		d=read(0,n);
		d=std::min(d,ws[x].h);
	}
	void subseteq(TN w){
		if(d==0)return;
		assert(ws[w.x].dfn1<=ws[x].dfn1&&ws[x].dfn2<=ws[w.x].dfn2);
		assert(ws[w.x].dep+ws[w.x].h>=ws[x].dep+ws[x].h);
	}
	void que(int sgn){
		if(!d)return;
		int x1=ws[x].dfn1-1;
		int x2=ws[x].dfn2;
		int y1=ws[x].dep-1;
		int y2=y1+d;
		qs.push_back(Q{x2,y2,sgn,1});
		qs.push_back(Q{x1,y2,-sgn,1});
		qs.push_back(Q{x2,y1,-sgn,1});
		qs.push_back(Q{x1,y1,sgn,1});
	}
	bool has(int i){
		return(ws[x].dfn1<=ws[i].dfn1&&ws[i].dfn1<=ws[x].dfn2&&ws[i].dep-ws[x].dep<d);
	}
}ms[N];

bool ed[N];

int main(){
	f=fopen("o1.txt","r");
	n=read(1,1e6);
	m=read(1,1e6);
	Fe(i,2,n){
		int f=read(1,i-1);
		ws[f].e.push_back(i);
	}
	Fe(i,1,m)ms[i].rd();
	dfs(1);
	Fe(i,1,n){
		qs.push_back(Q{ws[i].dfn1,ws[i].dep,1,0});
	}
	long long tot=0;
	int m0=readf(1,m*5);
	TN cur{1,0};
	std::vector<TN> undo{cur};
	F(_,0,m0){
		int o=readf(1,3);
		if(o==3){
			int i=readf(1,m);
			//pr("3 %d\n",i);
			assert(!ed[i]);
			ed[i]=1;
			cur.subseteq(ms[i]);
			ms[i].subseteq(cur);
		}else if(o==1){
			int x=readf(1,n),d=readf(0,n);
			/*pr("%d %d %d\n",o,x,d);
			Fe(i,1,n){
				if(ws[x].dfn1<=ws[i].dfn1&&ws[i].dfn1<=ws[x].dfn2&&ws[i].dep-ws[x].dep<d)pr("[%d]",i);
			}pr("\n");*/
			TN nxt{x,d};
				/*Fe(i,1,n){
					int t1=nxt.has(i);
					int t2=cur.has(i);
					assert(t1>=t2);
					tot+=t1-t2;
				}*/
				cur.subseteq(nxt);
				cur.que(-1);
				nxt.que(1);
			cur=nxt;
			undo.push_back(nxt);
		}else{
			assert(undo.size()>=2);
			undo.pop_back();
			cur=undo.back();
		}
	}
	Fe(i,1,m)assert(ed[i]);
	std::sort(qs.begin(),qs.end());
	long long ans=0;
	BIT<long long> bit;
	bit.alloc(n);
	for(Q &q:qs){
		if(q.tp)ans+=q.sgn*bit.sum(q.x);
		else bit.add(q.x,q.sgn);
	}
	//fprintf(stderr,"cost: %lld\n",tot);
	fprintf(stderr,"cost: %lld\n",ans);
	//assert(tot==ans);
	assert(ans<=COST_LIMIT);
	return 0;
}


