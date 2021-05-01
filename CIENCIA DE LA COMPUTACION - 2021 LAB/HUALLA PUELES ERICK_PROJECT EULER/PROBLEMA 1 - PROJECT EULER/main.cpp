#include <iostream>
#include <conio.h>
using namespace std;

int sum_multiples(int bellow_num, int multiple1, int multiple2)
{
    int sum=0;
    --bellow_num;
    while(bellow_num>1)
    {
        if(bellow_num%multiple1==0 || bellow_num%multiple2==0)
        {
            sum+=bellow_num;
        }
        --bellow_num;
    }
    return sum;
}
int main()
{
    int suma=sum_multiples(1000,3,5);
    cout<<"Resultado de la suma de los multiplos de 3 o 5 inferiores a 1000 es: "<<suma<<endl;
    cout<<"\nPRESIONE ENTER PARA FINALIZAR"<<endl;
    getch();
    return 0;
}
