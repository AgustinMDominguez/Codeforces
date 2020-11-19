#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cout << #x << " = " << (x) << "\n"
#define END(e) {cout << e << "\n";return(EXIT_SUCCESS);}
#define MAX_ARRAY 200000

typedef long long ll;

bool g_betterBerserk;
ll g_fireCost, g_fireRange, g_berserkCost;

ll cleanSubarray(int deleteAmount, bool lockedStrong) {
    if(deleteAmount<1) return 0ll;
    if(g_betterBerserk) {
        if(lockedStrong) return g_berserkCost*deleteAmount;
        else if ((ll)deleteAmount < g_fireRange) return -1ll;
        else return g_fireCost + g_berserkCost*((ll)(deleteAmount)-g_fireRange);
    } else if (deleteAmount < g_fireRange) {
            if(lockedStrong) return g_berserkCost*deleteAmount;
            else return -1ll;
    } else {
        return g_fireCost*((ll)(deleteAmount)/g_fireRange) + g_berserkCost*((ll)(deleteAmount)%g_fireRange);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool lockedAreStronger, state=false, *mset;
    int n, m, *arrN, *arrM, lowInd=0, highInd=0, lockedL=0, lockedR, maxLocked, aux;
    ll laux, solution=0;

    cin >> n >> m;
    if(m>n)END(-1)

    cin >> g_fireCost >> g_fireRange >> g_berserkCost;
    g_betterBerserk = (ll)g_fireCost > (ll)(g_fireRange)*(ll)(g_berserkCost);

    arrN = new int[n];
    for(int i=0; i<n; ++i)cin >> arrN[i];

    arrM = new int[m];
    mset = new bool[MAX_ARRAY+1]();
    for(int i=0; i<m; ++i) {
        cin >> aux;
        mset[aux] = true;
        arrM[i] = aux;
    }
    for(int mInd=0; mInd<m; ++mInd) {
        lockedR = arrM[mInd];
        maxLocked = max(lockedL, lockedR);
        lockedAreStronger = true;
        while (highInd<n) {
            state = mset[arrN[highInd]];
            if (state) {
                if(arrN[highInd]!=lockedR)END(-1)
                break; 
            } else if (lockedAreStronger) {
                if(arrN[highInd]>maxLocked) {
                    lockedAreStronger = false;
                }
            }
            ++highInd;
        }
        if(!state) END(-1)
        laux = cleanSubarray(highInd-lowInd, lockedAreStronger);
        if(laux<0) END(-1);
        solution += laux;
        lockedL = lockedR;
        ++highInd;
        lowInd = highInd;
    }
    lockedR = 0;
    maxLocked = lockedL;
    lockedAreStronger = true;
    while (highInd<n) {
        if (lockedAreStronger && arrN[highInd]>maxLocked) {
            lockedAreStronger = false;
            highInd = n;
            break;
        }
        ++highInd;
    }
    laux = cleanSubarray(highInd-lowInd, lockedAreStronger);
    if(laux<0)END(-1);
    solution += laux;
    cout << solution << "\n";
}

/* 
    > NOTES:
 -Things that would give -1:
    >: m>n;
    >: arrm es subset de arrn pero en mal orden

 - If an element is in arrM, then it's 'locked' in arrN, meaning that it can't be eliminated

 - Every subarray between two "locked" elements becomes its independent problem, as in
   if the global solution is possible then the local solution must be possible too and also
   since the destroying acts can only be made sequencially and the extremes are locked, 
   the actions can only be made inside that subarray
*/

/*
D. Berserk And Fireball
2 seconds 256 megabytes

There are n warriors in a row. The power of the i-th warrior is a_i. 
All powers are pairwise distinct.

You have two types of spells which you may cast:

Fireball: you spend x mana and destroy exactly k consecutive warriors;
Berserk: you spend y mana, choose two consecutive warriors and the warrior
         with greater power destroys another chosen warrior.

For example, let the powers of warriors be [2,3,7,8,11,5,4], and k=3. 
If you cast Berserk on warriors with powers 8 and 11, 
the resulting sequence of powers becomes [2,3,7,11,5,4]
Then, for example, if you cast Fireball on consecutive warriors with powers [7,11,5],
 the resulting sequence of powers becomes [2,3,4].

You want to turn the current sequence of warriors powers 
 [a1,a2,…,an ] into [b1,b2,…,bm]

Calculate the minimum amount of mana you need to spend on it.

Input
    n and m (1<=n,m<=2*10**5) length of sequence a and the length of sequence b respectively
    x,k,y (1<=x,y,<=10**9;1≤k≤n) the cost of fireball, 
        the range of fireball and the cost of berserk

    n integers a1,a2,…,an (1<=ai<=n). It is guaranteed that all integers ai are pairwise distinct.
    m integers b1,b2,…,bm (1≤bi≤n). It is guaranteed that all integers bi are pairwise distinct.

    Output:
    Print the minimum amount of mana for turning the sequnce a1,a2,…,an into b1,b2,…,bm, 
    or −1 if it is impossible
*/