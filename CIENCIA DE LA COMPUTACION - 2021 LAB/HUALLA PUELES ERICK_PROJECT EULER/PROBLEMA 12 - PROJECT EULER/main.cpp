#include <iostream>
#include <conio.h>
using namespace std;

long n_triangle_number(long position)
{
    long sum=0;
    for(long i=1;i<=position;i++)
        sum+=i;
    return sum;
}
int divisors(long num)
{
    int result=0;
    for(long i=1;i<=num;i++)
    {
        if(num%i==0)
        {
            result++;
        }
    }
    return result;
}
long divisors_Dtriangle(int fivehundred)
{
    long long control=12370;
    long triangle;
    while(true)
    {
        triangle=n_triangle_number(control);
        //cout<<triangle<<" "<<divisors(triangle)<<endl;
        if(divisors(triangle)>=fivehundred){
            break;
        }
        control++;
    }
    return triangle;
}
int main()
{
    cout<<"El primer numero con 500 divisores es: "<<divisors_Dtriangle(500)<<endl;
    //EL PROBLEMA SI DA LA SOLUCION PERO DEMORA EN SU TIEMPO DE EJERCUCION
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
