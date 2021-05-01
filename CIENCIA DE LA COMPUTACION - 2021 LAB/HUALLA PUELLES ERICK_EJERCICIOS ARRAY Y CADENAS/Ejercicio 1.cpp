#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenar_arra(int *arra, long longi)
{
    srand(time(NULL));
    for(long i=0;i<longi;i++)
        arra[i]=rand()%100;
}
long sum_iterative(int *arra, long longi)
{
    long long final_sum_a=0;
    for(long i=0;i<longi;i++)
        final_sum_a+=arra[i];
    return final_sum_a;
}

long sum_recursive(int *arra, long longi)
{
    if(longi==0)
        return 0;
    return arra[longi-1]+sum_recursive(arra,longi-1);
}
int main()
{
    long longi=100000;
    int *arra=new int[longi];
    llenar_arra(arra,longi);
    cout<<"Suma de elementos del array: "<<sum_iterative(arra,longi)<<endl;
    cout<<"Suma de elementos del array: "<<sum_recursive(arra,longi)<<endl;
    cout<<"\nPRESIONE ENTER PARA FINALIZAR EL PROGRAMA"<<endl;
    getch();
    return 0;
}
