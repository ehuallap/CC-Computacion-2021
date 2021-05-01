#include <iostream>
#include <conio.h>
using namespace std;
void collatz_sequence(long long limit)
{
    long long maxi=0,maxlen=1,len,n;
    for (long long i = 1; i < limit; i++){
        len = 1;
        for (long long n = i; n > 1; len++)
            n = n % 2 ? n * 3 + 1 : n / 2;
        if (len > maxlen) {
            maxlen = len;
            maxi = i;
        }
    }
    cout<<"El numero que crea la longitud mas larga es: "<<maxi<< " con longitud de "<<maxlen<<endl;
}
int main()
{
    collatz_sequence(1000000);
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
