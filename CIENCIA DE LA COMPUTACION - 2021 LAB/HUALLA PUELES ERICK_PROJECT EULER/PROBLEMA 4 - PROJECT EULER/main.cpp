#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

bool isPal(long num)
{
    bool ifIs_Pal= true;
    long digit, rev= 0, original_num;
    original_num= num;

    while(num>0)
    {
        digit=num%10;
        num/=10;
        rev=rev*10 + digit;
    }
    if (rev==original_num)
        ifIs_Pal=true;
    else
        ifIs_Pal=false;
    return ifIs_Pal;
}
void findPal(int digits)
{
    long pal,largest=0;
    int comb1,comb2;
    for (int a=9*pow(10,digits-1); a<pow(10,digits); a++)
    {
        for (int b=9*(10,digits-1); b<pow(10,digits); b++)
        {
            pal=a*b;
            if (isPal(pal))
            {
                if(pal>largest){
                    largest=pal;
                    comb1=a;
                    comb2=b;
                }
            }
        }
    }
    cout<<"El palendromo mas grande es: "<<largest<<" por el producto de "<<comb1<<" x "<<comb2<<endl;
}
int main()
{
    findPal(3); //tiene como dato de entrada los digitos de los numeros multiplicados, funciona para datos de entrada 3 y 4
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
