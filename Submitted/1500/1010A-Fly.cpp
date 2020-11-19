#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cout << #x << " = " << (x) << "\n"
#define END(e) {cout << (e) << "\n"; return EXIT_SUCCESS;}

typedef long double ld;

inline ld necessaryFuel(ld currentPayload, ld fuelCoeff) {
    return currentPayload/(fuelCoeff - (ld)1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int planetAmount, aux;
    ld payload, currentCoef, earthLandCoef, rocketWeight, *liftExpense;
    stack<ld> fuelCoefficients;
    cin >> planetAmount >> rocketWeight;
    liftExpense = new ld[planetAmount];
    for(int i=0; i<planetAmount; ++i) {
        cin >> aux;
        if(aux==1)END(-1)
        liftExpense[i] = (ld)aux;
    }

    cin >> earthLandCoef;
    fuelCoefficients.push(liftExpense[0]);
    for(int i=1; i<planetAmount; ++i) {
        cin >> aux;
        if(aux==1)END(-1)
        fuelCoefficients.push((ld)aux);
        fuelCoefficients.push(liftExpense[i]);
    }
    fuelCoefficients.push(earthLandCoef);

    payload = rocketWeight;
    while(!fuelCoefficients.empty()) {
        currentCoef = fuelCoefficients.top();
        payload += necessaryFuel(payload, currentCoef);
        fuelCoefficients.pop();
    }

    if(payload==numeric_limits<ld>::infinity())END(-1)
    cout << setprecision(15) << payload-rocketWeight << "\n";
}