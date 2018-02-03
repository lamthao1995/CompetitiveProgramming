#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr freopen("in.txt","r",stdin)
#define rep(i,n) for(int i=0;i<n;i++)
#define frep(i,n) for(int i=1;i<=n;i++)
ll a[100011];
const ll mod = 1e9+7;
ll bpow(ll x,ll n) {
	ll ans = 1;
	while(n>0) {
		if(n&1) ans*=x;
		x*=x;
		ans%=mod;
		x%=mod;
		n/=2;
	}
	return ans;
}
ll lazy[400011];
ll tree[400011][11];
ll lazyPower[11];
ll C[11][11];
struct node{
    int l,r,id;
    node() {
        
    }
    node(int _l,int _r,int _id) {
        l = _l;
        r = _r;
        id = _id;
        lazy_update();
    }
    node left() {
        return node(l,(l+r)/2,2*id);
    }
    node right() {
        return node((l+r)/2+1,r,2*id+1);
    }
    void lazy_update() {
        if(lazy[id]==0) return;
        lazyPower[0] = 1;
        for(int j=1;j<11;j++) {
            lazyPower[j] = lazy[id] * lazyPower[j-1];
            lazyPower[j] %= mod;
        }
        for(int j=10;j>=1;j--) {
            for(int k=0;k<j;k++) {
                ll toAdd = tree[id][k];
                
                toAdd*=lazyPower[j-k];
                toAdd%=mod;
                
                toAdd*=C[j][k];
                toAdd%=mod;
                
                tree[id][j]+=toAdd;
                tree[id][j]%=mod;
            }
        }
        if(l!=r) {
            lazy[2*id]+=lazy[id];
            lazy[2*id+1]+=lazy[id];
            lazy[2*id]%=mod;
            lazy[2*id+1]%=mod;
        }
        lazy[id] = 0;
    }
    void update(int s,int e,int val) {
        if(r<s or e<l) return;
        if(s<=l and r<=e) {
            lazy[id]+=val;
            lazy[id]%=mod;
            lazy_update();
            return;
        }
        left().update(s,e,val);
        right().update(s,e,val);
        rep(j,11) {
            tree[id][j] = (tree[2*id][j]+tree[2*id+1][j])%mod;
        }
    }
    ll query(int s,int e,int p) {
        if(r<s or e<l) return 0;
        if(s<=l and r<=e) {
            return tree[id][p];
        }
        return (left().query(s,e,p)+right().query(s,e,p))%mod;
    }
    void build() {
        if(l==r) {
            rep(j,11) {
                tree[id][j] = bpow(a[l],j);
            }
            return;
        }
        left().build();
        right().build();
        rep(j,11) {
            tree[id][j] = (tree[2*id][j]+tree[2*id+1][j])%mod;
        }
    }
};
int main() {
    C[0][0] = 1;
    for(int i=1;i<=10;i++){
        C[i][0] = 1;
        for(int j=1;j<=i;j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
            C[i][j] %= mod;
        }
    }
    
    int T;
    cin >> T;
    while(T--) {
    	int N;
    	cin >> N;
    	frep(i,N) {
    		cin >> a[i];
    	}
    	node stree(1,N,1);
    	stree.build();
    	int Q;
    	cin >> Q;
    	ll t,l,r,k;
    	while(Q--) {
    		cin >> t;
    		if(t==1) {
    			cin >> l >> k;
    			stree.update(l,l,k);
    		}
    		else if(t==2) {
    			cin >> l >> r >> k;
                stree.update(l,r,k);
    		} else{
    			cin >> l >> r >> k;
    			cout << stree.query(l,r,k) << "\n";
    		}
    	}
    }
}
