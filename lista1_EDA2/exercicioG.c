#include <stdio.h>
#define ll long long

void ultrapassa(ll *v, int p, ll s, const ll m, const ll n){
    if(p == n) return;

    if(s + v[p] > m){
        ultrapassa(v, p+1, 0, m, n);
        printf("%lli\n", v[p]);
    }
    else
        ultrapassa(v, p+1, s+ v[p], m, n);
}

int main(){
    ll x;
    ll arr[(int)1e5+66];
    int p = 0;
    while(scanf("%lli", &x) != EOF){
        if(x == 0) break;
        arr[p++] = x;
    }
    ll s;
    scanf("%lli", &s);

    ultrapassa(arr, 0, 0, s, p);
    return 0;
}