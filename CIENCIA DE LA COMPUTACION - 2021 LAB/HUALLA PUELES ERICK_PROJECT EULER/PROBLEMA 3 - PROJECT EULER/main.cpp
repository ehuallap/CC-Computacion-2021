#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
void prime_factors(long long number)
{
    for(long long i=2;i<=number;i++)
    {
        if(number>1)
        {
            if(number%i==0)
            {
                cout<<i<<" ";
                while(number%i==0)
                    number/=i;
            }
        }else
            break;
    }
}
int main()
{
    cout<<"Los factores primos de 600851475143 son: ";
    prime_factors(600851475143);
    cout<<endl;
    cout<<"\nPRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
