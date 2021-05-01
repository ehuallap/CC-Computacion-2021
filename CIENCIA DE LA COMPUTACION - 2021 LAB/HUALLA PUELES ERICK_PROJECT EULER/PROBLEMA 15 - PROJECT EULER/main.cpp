#include <iostream>
#include <conio.h>
#define SIZE 21
using namespace std;

long long int count_routes(long long int cache[SIZE][SIZE], unsigned short x, unsigned short y) {

    if (cache[x][y] != 0) {
        return cache[x][y];
    }

    long long int n = 0;

    if (x == 0 && y == 0) {
        n = 1;
    }
    else {
        n = 0;
        if (x > 0) {
            n += count_routes(cache, x-1, y);
        }
        if (y > 0) {
            n += count_routes(cache, x, y-1);
        }
    }
    cache[x][y] = n;

    return n;
}

int main() {

    long long int cache[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cache[i][j] = 0;
        }
    }
    cout<<"En un cuadro de 20 x 20 hay: "<<count_routes(cache, SIZE-1, SIZE-1)<<" rutas"<<endl;
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}

