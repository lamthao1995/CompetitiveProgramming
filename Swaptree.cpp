#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct T {
  ll val , sum , lz ;
  int y, sz ;
  T *l , *r , *p ;
  T ( int v ) { val = sum = v; y = rand(); sz = 1; lz = 0 ; l = r = p = NULL ; }
}; 
typedef T* ptr;
inline int sz ( ptr t ) { return t ? t->sz : 0 ; }
inline ll sum ( ptr t ) { return t ? t->sum : 0LL ; } 
inline void upd ( ptr t ) { if ( t ) t->sz = sz(t->l) + sz(t->r) + 1 ; }
inline void pushLazy ( ptr t ) {
  upd ( t ) ;
  if ( !t || !t->lz ) return ;
  t->sum += sz(t) * t->lz ;
  t->val += t->lz ;
  if ( t->l ) t->l->lz += t->lz ;
  if ( t->r ) t->r->lz += t->lz ;
  t->lz = 0 ;
}
inline void push ( ptr t ) {
  if ( !t ) return ;
  upd ( t ) ; pushLazy ( t->l ) ; pushLazy ( t->r ) ;
  t->sum = t->val + sum ( t->l ) + sum ( t->r ) ;
}
void split ( ptr t , ptr &l , ptr &r , int s ) {
  pushLazy ( t ) ;
  if ( !t ) l = r = 0 ;
  else if ( sz ( t->l ) <= s ) {
    split ( t->r , t->r , r , s - sz ( t->l ) - 1 ) ;
    l = t ;
    if ( l->r ) l->r->p = l ;
  }else{
    split ( t->l , l , t->l , s ) ;
    r = t ;
    if ( r->l ) r->l->p = r ;
  }
  push ( r ) ; push ( l ) ;
  if ( l ) l->p = 0 ;
  if ( r ) r->p = 0 ;
}
void merge ( ptr &t , ptr l , ptr r ) {
  pushLazy ( l ) ; pushLazy ( r ) ;
  if ( !l || !r ) t = r ? r : l ;
  else if ( l->y > r->y ) { merge ( l->r , l->r , r ) ; t = l ; if ( l->r ) l->r->p = t ; }
  else { merge ( r->l , l , r->l ) ; t = r ; if ( r->l ) r->l->p = t ; }
  push ( t ) ;
  if ( t ) t->p = 0 ;
}
int pos ( ptr t , bool L = 1 ) {
  if ( !t ) return 0 ;
  return (int)(L) * sz ( t->l ) + ( t->p ? pos ( t->p , t->p->r == t ) + ( t->p->r == t ) : 0 ) ;
}
 
ptr L [ 100002 ] , R [ 100002 ] , t = 0;
int n, q, a [ 100002 ] ;
vector<int> adj [ 100002 ] ;
 
void dfs ( int x = 0 , int pp = -1 ) {
  L[x] = new T ( a[x] ) ; merge ( t , t , L[x] ) ;
  for ( auto u : adj[x] ) if ( u != pp ) dfs ( u , x ) ;
  R[x] = new T ( a[x] ) ; merge ( t , t , R[x] ) ;
}
 
int main() {
  srand(time(0));
  ios::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ;
  scanf("%d%d", &n, &q );
  for ( int i = 0 ; i < n ; i ++ ) scanf("%d", &a[i] );
  for ( int i = 1 , x , y ; i < n ; i ++ ) {
    scanf("%d%d",&x,&y);
    x -- ; y -- ; 
    adj[x].push_back(y) ;
    adj[y].push_back(x) ;
  }
  dfs();
  while ( q -- ) {
    int o , x , y ;
    scanf("%d%d", &o, &x );
    x -- ;
    if ( o == 1 ) {
      int l = pos ( L[x] ) , r = pos ( R[x] ) ;
      ptr t1 , t2 , t3 ;
      split ( t , t1 , t2 , l - 1 ) ;
      split ( t2 , t , t3 , r - l ) ;
      cout << t->sum / 2LL << endl ;
      merge ( t2 , t , t3 ) ;
      merge ( t , t1 , t2 ) ;
    }else{
      scanf("%d", &y ) ;
      if ( o == 2 ) {
        int l = pos ( L[x] ) , r = pos ( R[x] ) ;
        ptr t1 = 0 , t2 = 0 , t3 = 0 ;
        split ( t , t1 , t2 , l - 1 ) ;
        split ( t2 , t , t3 , r - l ) ;
        t->lz += y ;
        merge ( t2 , t , t3 ) ;
        merge ( t , t1 , t2 ) ;
      }else{
        y -- ;
        if ( x == y ) cout << -1 << endl ;
        else{
          int lx = pos ( L[x] ) , rx = pos ( R[x] ) , ly = pos ( L[y] ) , ry = pos ( R[y] ) ;
          if ( lx > ly ) swap ( lx , ly ) , swap ( rx , ry ) ;
          if ( rx > ry ) cout << -1 << endl ;
          else{
            ptr a , tx , b , ty ;
            split ( t , a , t , lx - 1 ) ;
            split ( t , tx , t , rx - lx ) ;
            split ( t , b , t , ly - rx - 2 ) ;
            split ( t , ty , t , ry - ly ) ;
            swap ( tx , ty ) ;
            merge ( t , ty , t ) ;
            merge ( t , b , t ) ;
            merge ( t , tx , t ) ;
            merge ( t , a , t ) ;
          }
        }
      }
    }
  }
} 
