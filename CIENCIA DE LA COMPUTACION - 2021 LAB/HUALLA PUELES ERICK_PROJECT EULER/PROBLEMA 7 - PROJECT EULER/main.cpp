#include <iostream>
#include <conio.h>
using namespace std;
bool isPrime(long num)
{
    int cont=0;
    for(int i=2;i<=num;i++)
    {
        if(num%i==0)
        {
            cont++;
        }
        if(cont>1)
            return false;
    }
    if(cont==1)
        return true;
}
long prime_number(int position)
{
    if(position!=0){
        long n=2,cont=0;
        while(true)
        {
            if(isPrime(n))
                cont++;
            if(cont==position)
                return n;
            n++;
        }
        return n;
    }else
        return 0;
}
int main()
{
    cout<<"10 001avo numero primo es "<<prime_number(10001)<<endl;
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
