#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cout << #x << " = " << (x) << "\n"
#define END(e) {cout << (e) << "\n"; return EXIT_SUCCESS;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, s3, s2;
    cin >> t;
    for (int i=0; i<t; ++i) {
        cin >> n;
        s3 = 0;
        while(n%3==0){
            ++s3;
            n /= 3;
        }
        s2 = 0;
        while(n%2==0){
            ++s2;
            n /= 2;
        }
        if(n!=1 || s3<s2)cout << -1 << "\n";
        else cout << 2*s3 - s2 << "\n";
    }
}