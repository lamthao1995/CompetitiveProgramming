#include <bits/stdc++.h>
using namespace std;
 
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
 
struct Node {
	Node();
	Node *l, *r, *p;
	int size, key;
	int rev, lz2;
	int val;
	ll sum;
};
Node* nil = new Node();
Node::Node() {
	l = r = p = nil;
	size = 1;
	key = rev = lz2 = 0;
	val = sum = 0;
}
inline void init() {
	nil->l = nil->r = nil->p = nil;
	nil->size = 0;
}
inline int isrt(Node* x) {
	return x->p == nil || (x->p->l != x && x->p->r != x);
}
inline void setchild(Node* p, Node* c, int l) {
	c->p = p; l ? p->l = c : p->r = c;
}
inline void updatelz(Node* x, int val) {
	if (x == nil) return;
}
inline void updatelz2(Node* x, int val) {
	if (x == nil) return;
	x->lz2 += val;
	x->val += val;
	x->sum += x->size * val;
}
inline void pushdown(Node* x) {
	if (x == nil) return;
	Node *u = x->l, *v = x->r;
	if (x->rev) {
		if (u != nil) {swap(u->l, u->r); u->rev ^= 1;}
		if (v != nil) {swap(v->l, v->r); v->rev ^= 1;}
		x->rev = 0;
	}
	if (x->lz2) {
		if (u != nil) updatelz2(u, x->lz2);
		if (v != nil) updatelz2(v, x->lz2);
		x->lz2 = 0;
	}
}
inline void pushup(Node* x) {
	x->size = x->l->size + x->r->size + 1;
	x->sum = x->val + x->l->sum + x->r->sum;
}
inline void rotate(Node* x) {
	Node* y = x->p;
	int l = x->p->l == x;
	if (!isrt(y)) {
		setchild(y->p, x, y->p->l == y);
	}
	else {
		x->p = y->p;
	}
	setchild(y, l ? x->r : x->l, l);
	setchild(x, y, !l);
	pushup(y);
}
inline void splay(Node* x) {
	pushdown(x);
	while (!isrt(x)) {
		pushdown(x->p->p); pushdown(x->p); pushdown(x);
		if (!isrt(x->p)) rotate((x->p->l == x) == (x->p->p->l == x->p) ? x->p : x);
		rotate(x);
	}
	pushup(x);
}
inline Node* access(Node* x) {
	Node* z = nil;
	for (Node* y = x; y != nil; y = y->p) {
		splay(y);
		y->r = z;
		pushup(z = y);
	}
	splay(x);
	return z;
}
inline void link(Node* x, Node* y) {
	access(y); access(x);
	x->p = y;
	access(x);
}
inline void cut(Node* x) {
	access(x);
	x->l->p = nil;
	x->l = nil;
	pushup(x);
}
inline Node* findroot(Node* x) {
	access(x);
	while (x->l != nil) pushdown(x), x = x->l;
	splay(x);
	return x;
}
inline Node* lca(Node* x, Node* y) {
	if (findroot(x) != findroot(y)) return nil;
	access(x);
	return access(y);
}
inline void makeroot(Node* x) {
	access(x);
	swap(x->l, x->r);
	x->rev ^= 1;
}
inline int connected(Node* x, Node* y) {
    if (x == y) return 1;
    access(x); access(y);
    return x->p != nil;
}
 
const int maxn = 1000010;
Node node[maxn];
int n, q;
vi adj[maxn];
int p[maxn];
 
void dfs(int u, int dad = -1) {
	p[u] = dad;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != dad) {
			dfs(v, u);
		}
	}
}
 
inline void update(int u, int v, int val) {
	makeroot(node + u);
	access(node + v);
	updatelz2(node + v, val);
}
 
inline ll query(int u, int v) {
	makeroot(node + u);
	access(node + v);
	return node[v].sum;
}
 
void solve() {
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0); init();
	FOR(i, 1, n) link(node + i, node + p[i]);
	scanf("%d", &q);
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int u, v, k; scanf("%d%d%d", &u, &v, &k); u--; v--;
			update(u, v, k);
		}
		else if(op == 2){
			int u, v; scanf("%d%d", &u, &v); u--; v--;
			printf("%I64d\n", query(u, v));
		}else{
			int u, k; cin >> u >> k; u--;
			cut(node + u); makeroot(node + u);
			updatelz2(node + u, k);
			link(node + p[u], node + u);
		}
	}
}
 
int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
