typedef long long ll ;
const ll mk = 2000050;
const ll logn  = 29;
const ll mod =998244353;
const int coefA=3,coefB=(mod+1)/coefA;
 
int n,m,a[mk];

inline int binpow(int d,int z){
	int ret=1;
	for(;z;z>>=1,d=1ll*d*d%mod)
		if(z&1)ret=1ll*ret*d%mod;
	return ret;
}
 void ntt(int *a,int n,int tag){  // ntt template I used in Tet School
	int r[mk],cnt;cnt=-2;
	for(int i=n;i;i>>=1,++cnt);
	
	for(int i=0;i<n;++i){
		r[i]=(r[i>>1]>>1)|((i&1)<<cnt);
		if(r[i]>i)swap(a[r[i]],a[i]);
	}
	
	for(int i=1;i<n;i<<=1){
		int u=binpow(tag==1?coefA:coefB,(mod-1)/2/i),w=1;
		for(int j=0,I=i<<1;j<n;j+=I,w=1){
			for(int k=0;k<i;++k,w=1ll*w*u%mod){
				int t=1ll*w*a[j+k+i]%mod;
				(a[j+k+i]=a[j+k]+mod-t)%=mod;
				(a[j+k]+=t)%=mod;
			}
		}
	}
	if(tag==1)return;
	const long long iv=binpow(n,mod-2);
	for(int i=0;i<n;++i)a[i]=iv*a[i]%mod;
}
