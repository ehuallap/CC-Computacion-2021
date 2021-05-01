#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void muestra_arra(int *arra,int longi)
{
    int i;
    for (i = 0; i < longi; i++)
        cout <<arra[i]<<" ";
    cout<<endl;
}
void llenar_arra(int *arra, long longi)
{
    srand(time(NULL));
    for (long i = 0; i < longi; i++)
        arra[i] = rand() % 100;
}
void seleccionsort(int *arra, long longi)
{
    long min, i, j, aux;
    for (i = 0; i <=longi - 1; i++)
    {
        min = i;
        for (j = i + 1; j < longi; j++)
            if (arra[min] > arra[j])
                min = j;
        aux = arra[min];
        arra[min] = arra[i];
        arra[i] = aux;
    }
}
int main()
{
    long longi=100000;
    int *arra=new int[longi];
    llenar_arra(arra,longi);
    cout<<"El array se encuentra desordenado: "<<endl;
    //muestra_arra(arra,longi);
    seleccionsort(arra,longi);
    cout<<"\nEl array se encuentra ordenado: "<<endl;
    //muestra_arra(arra,longi);
    return 0;
}
