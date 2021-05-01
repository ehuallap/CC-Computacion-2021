#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

long sum_digits(int num, long elevated)
{
    double product=pow(num,elevated),aux,result;
    long sum=0;
    cout<<product<<endl;
    aux=round(product/10);
    cout<<aux<<endl;
    aux*=10;
    result=product-aux;
    cout<<result<<endl;
    /*
    while(product>0)
    {
        //sum+=product%10;
        product/=10;
    }*/
    return sum;
}
int main()
{
    cout<<"La suma de los digitos de 2^1000 es: "<<sum_digits(2,100)<<endl;
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
