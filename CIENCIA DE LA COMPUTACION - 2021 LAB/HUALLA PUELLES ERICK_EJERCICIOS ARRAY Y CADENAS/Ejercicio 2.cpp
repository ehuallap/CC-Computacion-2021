#include <iostream>
#include <stdio.h>
using namespace std;
void mostrar(long *arra, long tam)
{
    for(long i=0;i<tam;i++)
        cout<<arra[i]<<" ";
    cout<<endl;
}
void create_array(long *arra, long tam)
{
    for(long i=0;i<tam;i++)
        arra[i]=i+1;
}
void invert_sort_iterative(long *arra, long tam)
{
    int aux;
    for(long i=0;i<(tam/2);i++){
        aux=arra[i];
        arra[i]=arra[tam-i-1];
        arra[tam-i-1]=aux;
    }
}
void invert_sort_recursive(long *arra, long tam, long pos_i, long aux)
{
    if(!(pos_i>=tam/2)){
        aux=arra[pos_i];
        arra[pos_i]=arra[tam-1-pos_i];
        arra[tam-1-pos_i]=aux;
        invert_sort_recursive(arra,tam,pos_i+1,aux);
    }
}
int main()
{
    long tam=10000,pos_inici=0,auxiliar;
    long *group_numbers=new long[tam];
    create_array(group_numbers,tam);
    cout<<"Array sin invertir tiene 1000000 elementos"<<endl;
    cout<<"\nInvirtiendo...iterativamente\n"<<endl;
    invert_sort_iterative(group_numbers,tam);
    cout<<"Array invertido correctamente"<<endl;
    cout<<"\nInvirtiendo...recursivamente\n"<<endl;
    invert_sort_recursive(group_numbers,tam,pos_inici,auxiliar);
    cout<<"Array invertido correctamente"<<endl;
    return 0;
}
