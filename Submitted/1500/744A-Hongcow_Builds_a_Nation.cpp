#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cout << "dbg:: "<< #x << " = " << (x) << "\n"

set<int> *graf = nullptr; // Arreglo de sets donde el indice representa el nodo y el set representa las conexiones
bool *visitadosarr = nullptr;
int cantidadvisitados = 0;

int dfs(int node) {
    int cantidad = 0;
    stack<int> s;
    s.push(node);
    visitadosarr[node] = true;
    while(s.size()) {
        int x = s.top();
        s.pop();
        ++cantidadvisitados;
        ++cantidad;
        for(int y : graf[x]) {
            if(!visitadosarr[y]) {
                s.push(y);
                visitadosarr[y] = true;
            }
        }
    }
    return cantidad;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cantVertices, cantAristas, cantGobiernos, nd1, nd2, gobmax, aux, ans=0;
    cin >> cantVertices >> cantAristas >> cantGobiernos;
    graf = new set<int>[cantVertices];
    visitadosarr = new bool[cantVertices]();
    int *nodosPorGob = new int[cantVertices]();
    set<int> gobiernos;

    for(int i=0;i<cantGobiernos;++i) {
        cin >> aux;
        gobiernos.insert(aux-1);
    }

    for(int i=0;i<cantAristas;++i) {
        cin >> nd1 >> nd2;
        graf[nd1-1].insert(nd2-1);
        graf[nd2-1].insert(nd1-1);
    }

    gobmax = *(gobiernos.begin());
    for (set<int>::iterator it = gobiernos.begin(); it!=gobiernos.end(); ++it) {
        nodosPorGob[*it] = dfs(*it);
        gobmax = (nodosPorGob[*it] > nodosPorGob[gobmax]) ? *it : gobmax;
        ans += (nodosPorGob[*it])*(nodosPorGob[*it] - 1)/2;
    }
    aux = cantVertices-cantidadvisitados;
    ans += (2*nodosPorGob[gobmax] + aux - 1)*aux/2;
    cout << ans-cantAristas << "\n";
}