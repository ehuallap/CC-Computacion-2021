#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
bool isPrime(long num)
{
    int cont=0;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            cont++;
        }
        if(cont>0)
            return false;
    }
    if(cont==0)
        return true;
}
long long prime_sum(long maximus)
{
    if(maximus>1){
        long long n=2;
        long long suma=0;
        while(n<=maximus)
        {
            if(n==2 || n==3 || n==5 || n==7){
                suma+=n;
                cout<<n<<endl;
            }else if(n>=11 && n<210)
            {
                if(isPrime(n)){
                    suma+=n;
                    cout<<n<<endl;
                }
            }else{
                if(n>210 && n%210!=0)
                {
                    if(isPrime(n)){
                        suma+=n;
                        cout<<n<<endl;
                    }
                }
            }
            n++;
        }
        return suma;
    }
}
int main()
{
    cout<<"La suma de los primos menores a 2 millones es: "<<prime_sum(2000000)<<endl;
    //LA COMPILACION TOMA BASTANTES DECENAS DE MINUTOS PARA SER CONCLUIDA PERO ES FUNCIONAL
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
