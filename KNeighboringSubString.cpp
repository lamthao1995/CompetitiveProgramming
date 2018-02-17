#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#include <cstring>  
#include <map>  
#include <iostream>  
#include <set>  
using namespace std;  
  
const double PI = acos(-1.0);  
//?????  
struct complex  
{  
    double r,i;  
    complex(double _r = 0.0,double _i = 0.0)  
    {  
        r = _r; i = _i;  
    }  
    complex operator +(const complex &b)  
    {  
        return complex(r+b.r,i+b.i);  
    }  
    complex operator -(const complex &b)  
    {  
        return complex(r-b.r,i-b.i);  
    }  
    complex operator *(const complex &b)  
    {  
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);  
    }  
};  
/* 
 * ??FFT?IFFT??????? 
 * ??i? (i????????)?? 
 * len???2?? 
 */  
void change(complex y[],int len)  
{  
    int i,j,k;  
    for(i = 1, j = len/2;i < len-1; i++)  
    {  
        if(i < j) swap(y[i],y[j]);  
        //???????????,i<j??????  
        //i????+1,j??????+1,????i?j????  
        k = len/2;  
        while( j >= k)  
        {  
            j -= k;  
            k /= 2;  
        }  
        if(j < k) j += k;  
    }  
}  
/* 
 * ?FFT 
 * len???2^k??, 
 * on==1??DFT,on==-1??IDFT 
 */  
void fft(complex y[],int len,int on)  
{  
    change(y,len);  
    for(int h = 2; h <= len; h <<= 1)  
    {  
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));  
        for(int j = 0;j < len;j+=h)  
        {  
            complex w(1,0);  
            for(int k = j;k < j+h/2;k++)  
            {  
                complex u = y[k];  
                complex t = w*y[k+h/2];  
                y[k] = u+t;  
                y[k+h/2] = u-t;  
                w = w*wn;  
            }  
        }  
    }  
    if(on == -1)  
        for(int i = 0;i < len;i++)  
            y[i].r /= len;  
}  
/////////////////////  
typedef unsigned long long LL;  
const int maxn = 100007;  
const int MAGIC = 3;  
const int M = 1e9+7;  
complex x1[maxn*4],x2[maxn*4];  
string s1,s2;  
int sum1[maxn*4],sum2[maxn*4];  
int k;  
int len,len1,len2;  
LL Hash[maxn],Pow[maxn];  
set<LL> s;  
  
void solve(int res[],char c){  
    len1 = s1.length(),len2 = s2.length();  
    len = 1;  
    while(len < 2*len1 || len<2*len2) len <<= 1;  
    for(int i=0;i<len1;i++){  
        if(s1[i] == c) x1[i] = complex(1,0);  
        else x1[i] = complex(0,0);  
    }  
    for(int i=len1;i<len;i++){  
        x1[i] = complex(0,0);  
    }  
    for(int i=0;i<len2;i++){  
        if(s2[len2 - i -1] == c) x2[i] = complex(1,0);  
        else x2[i] = complex(0,0);  
    }  
    for(int i=len2;i<len;i++){  
        x2[i] = complex(0,0);  
    }  
    //  
    fft(x1,len,1);  
    fft(x2,len,1);  
    for(int i=0;i<len;i++) x1[i] = x1[i]*x2[i];  
    fft(x1,len,-1);  
  
    //cout << "len:" << len << endl;  
    for(int i=0;i<len;i++){  
        res[i] = (int) (x1[i].r + 0.5);  
        //cout<< res[i] << " ";  
    }  
    //cout << endl;  
}  
  
int main(){  
    int nCase = 1;  
    Pow[0] = 1;  
    for(int i=1;i<maxn;i++) Pow[i] = Pow[i-1]*MAGIC;  
    while(cin >> k){  
        if(k == -1) break;  
        cin >> s1 >> s2;  
  
        solve(sum1,'a');  
        solve(sum2,'b');  
  
        Hash[0] = 0;  
        s.clear();  
        for(int i=0;i<=len1;i++) Hash[i+1] = Hash[i]*MAGIC + s1[i];  
  
        for(int i=len2-1;i<len1;i++){  
            //cout << i <<" " << len2 + i<< endl;  
            LL now = Hash[i+1] - Hash[i - len2 + 1]*Pow[len2];  
            if(len2 - sum1[i] - sum2[i] <= k){  
                s.insert(now);  
            }  
        }  
        printf("Case %d: %d\n",nCase++,s.size());  
    }  
    return 0;  
}  
