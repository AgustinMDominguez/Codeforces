#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cout << #x << " = " << (x) << "\n"
#define END(e) {cout << (e) << "\n"; return EXIT_SUCCESS;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int planedT, TamountPerPack, singleTcost, packCost, packsBought, singleBought;
    cin >> planedT >> TamountPerPack >> singleTcost >> packCost;
    if(singleTcost*TamountPerPack > packCost) {
        packsBought = planedT/TamountPerPack;
        singleBought = planedT%TamountPerPack;
        if(singleBought*singleTcost > packCost)END((packsBought+1)*packCost)
        END(packsBought*packCost + singleBought*singleTcost)
    }
    END(planedT*singleTcost)
}

/*
A. Cheap Travel

Ann has recently started commuting by subway. 
We know that a one ride subway ticket costs a rubles. 
Besides, Ann found out that she can buy a special ticket for m rides (she can buy it several times)
It costs b rubles. 
Ann will need to use subway n times. 
Help Ann, tell her what is the minimum sum of money she will have to spend to make n rides?

Input
The single line contains four space-separated integers n, m, a, b (1 <= n, m, a, b <= 1000) 
the number of rides Ann has planned, the number of rides covered by the m ride ticket, 
the price of a one ride ticket and the price of an m ride ticket.

Output
Print a single integer — the minimum sum in rubles that Ann will need to spend.
*/