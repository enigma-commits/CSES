#include<bits/stdc++.h>
using namespace std;
#define hi ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef int64_t ll;
typedef long double ld;
typedef long long unsigned llu;
#define test                int test; cin>>test; while(test--)
#define loop(i,n,k)         for(int i=n;i<k;i++)
#define rloop(i,n,k)         for(int i=n;i>=k;i--)
#define INT(a)                 int a;scanf("%d",&a);
#define intin(temp)            scanf("%d",&temp);
#define longin(temp)        scanf("%lld",&temp);
#define LLI(a)                 ll a;scanf("%lld",&a);
#define DOUBLE(a)             double a;scanf("%f",&a);
#define LD(a)                 long double a;scanf("%lf",&a);
#define pb(i)                 push_back(i)
#define sz(i)                 i.size()
#define mkp(i,j)            make_pair(i,j)
#define ip                     pair<int,int>
#define lp                    pair<ll,ll>
#define FOR(i,n)            for(i=0;i<n;i++)
#define range(v)            v.begin(),v.end()
#define bye                    return 0;
#define file                freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define endl                 '\n'
 
 
template<class c>
c gcd (c a,c b){
    if(b==0)
        return a;
    gcd(b,a%b);
}
template<class c>
c lcm(c a,c b){
    return a/gcd(a,b)*b;
}
template<class a>
bool prime(a n){
    for(a i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
bool bigger(pair<int,int>picachu,pair<int,int> qicachu){
    return (picachu.first<qicachu.first);
}void printarr(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}
int chartoint(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return 52;
}
int kadane(int arr[],int n){
    int maximum= arr[0];
    int max_so_far = 0;
    for(int i=0;i<n;i++){
        max_so_far+=arr[i];
        if(max_so_far>maximum)
            maximum = max_so_far;
        if(max_so_far<0)
            max_so_far = 0;
    }
    return maximum;
}
template<class a>
a powmod(a t1,a t2, a mod){
    a res = 1;
    t1 = t1%mod;
    if(t1==0)    return 0;
    while(t2){
        if(t2&1) res = (res*t1)%mod;
        t1 = (t1*t1)%mod;
        t2 = t2>>1;
    }
    return res;
}
const int MOD = 1e9+7;
int fact(int n){
    int ans = 1;
    loop(i,1,n+1){
        ans *= i;
    }
    return ans;
}
set<string> se;
void func(string s,int start,int end){
    if(start==end){
        se.insert(s);
    }else{
        loop(i,start,end+1){
            swap(s[start],s[i]);
            func(s,start+1,end);
            swap(s[start],s[i]);
        }
    }
}
void run(){    
    string s;
    cin >> s;
    int a[26] = {0};
    loop(i,0,sz(s)){
        a[s[i]-'a']++;
    }
    int n = sz(s);
    int ans = fact(n);
    loop(i,0,26){
        if(a[i]){
            ans/=fact(a[i]);
        }
    }
    cout << ans << endl;
    func(s,0,sz(s)-1);
    for(auto i:se){
        cout << i << endl;
    }
}
 
int main(){
    hi;
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin); 
      freopen("error.txt", "w", stderr); 
      freopen("output.txt", "w", stdout); 
       #endif 
   
  
       { 
          run(); 
       }
      cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
     bye;
}