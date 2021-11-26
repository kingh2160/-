#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <cmath>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <list>
#include <deque>
#include <numeric>
#include <set>
#include <climits>
#include <utility>
#include <map>
#include <float.h>
typedef long long ll;
typedef unsigned long long ull;
inline int max( int x, int y ){ return x > y ? x : y ; }
inline int min( int x, int y ){ return x < y ? x : y ; }
inline ll max( ll x, ll y ){ return x > y ? x : y ; }
inline ll min( ll x, ll y ){ return x < y ? x : y ; }
inline ull max( ull x, ull y ){ return x > y ? x : y ; }
inline ull min( ull x, ull y ){ return x < y ? x : y ; }
ull GCD( ull a, ull b ) { return b ? GCD( b , a%b ) : a; }
using namespace std;
#define INF 1e9
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;
set<string> ans;
string input;
bool visited[200];
bool check[200];
vector<P> v;

void Calc( int cnt, int idx ){
    
    if( cnt >= 1 ){
        string s = "";
        for( int i=0; i<input.size(); ++i ){
            if( visited[i] ) continue;
            s += input[i];
        }
        ans.insert( s );
    }
    
    for( int i=idx; i<v.size(); ++i ){
        if( check[i] ) continue;
        check[i] = true;
        visited[v[i].first] = true;
        visited[v[i].second] = true;
        Calc( cnt+1, idx+1 );
        check[i] = false;
        visited[v[i].first] = false;
        visited[v[i].second] = false;
    }
}

int main(void) {
   
    stack<int> s;
    int pare = 0;
    
    memset( visited, 0, sizeof(visited) );
    memset( check, 0, sizeof(check) );
    cin >> input;
    for( int i=0; i<input.size(); ++i ){
        if( input[i] == '(' ){
            s.push( i );
        }else if( input[i] == ')' ){
            v.push_back({s.top(), i});
            s.pop();
            pare++;
        }
    }
    
    Calc( 0, 0 );
    for( auto i : ans ){
        cout << i << '\n';
    }
    return 0;
}
