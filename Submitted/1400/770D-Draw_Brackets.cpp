#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cout << #x << " = " << (x) << "\n"


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, bracketInd, columnInd, offset, *lbrackets, rowAmount, columnAmount, center;
    int aux, maxlevel=0, level=0;
    char *cbrackets, **mtx;
    bool anteriorCerro = true;
    cin >> n;
    columnAmount = n;
    lbrackets = new int[n];
    cbrackets = new char[n];
    for(int i=0; i<n; ++i) {
        cin >> cbrackets[i];
        if(cbrackets[i]=='[') {
            if(anteriorCerro)anteriorCerro = false;
            else {++level; maxlevel = max(maxlevel,level);}
        } else {
            if(!anteriorCerro) { anteriorCerro = true; columnAmount+=3; }
            else --level;
        }
        lbrackets[i]=level;
    }
    rowAmount = 3 + 2*maxlevel;
    mtx = new char*[rowAmount];
    for (int i=0; i<rowAmount;++i){
        mtx[i] = new char[columnAmount];
        for (int j=0; j<columnAmount;++j)mtx[i][j]=' ';
    }

    for(int i=1; i<rowAmount-1; ++i) { mtx[i][0] = '|'; mtx[i][columnAmount-1] = '|'; }
    mtx[0][0] = '+';
    mtx[0][1] = '-';
    mtx[0][columnAmount-1] = '+';
    mtx[0][columnAmount-2] = '-';
    mtx[rowAmount-1][0] = '+';
    mtx[rowAmount-1][1] = '-';
    mtx[rowAmount-1][columnAmount-1] = '+';
    mtx[rowAmount-1][columnAmount-2] = '-';

    columnInd = (cbrackets[1]==']') ? 4 : 1;
    bracketInd = 1;
    center = rowAmount/2;
    while(columnInd < columnAmount-1) {
        offset = (cbrackets[bracketInd]=='[') ? 1 : -1;
        aux = 1 + maxlevel - lbrackets[bracketInd];
        for(int i=0; i<aux; ++i) {
            mtx[center+i][columnInd] = '|';
            mtx[center-i][columnInd] = '|';
        }

        mtx[center+aux][columnInd] = '+';
        mtx[center-aux][columnInd] = '+';
        mtx[center+aux][columnInd+offset] = '-';
        mtx[center-aux][columnInd+offset] = '-';

        if(cbrackets[bracketInd]=='[' && cbrackets[bracketInd+1]==']') {
            columnInd += 4;
        } else {
            ++columnInd;
        }
        ++bracketInd;
    }
    for(int i=0; i<rowAmount; ++i) {
        for(int j=0; j<columnAmount; ++j)cout << mtx[i][j];
        cout << "\n";
    }
}