#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

long longi_string(string expression)
{
    long longi=0;
    while(!expression.empty())
    {
        expression.erase(0,1);
        ++longi;
    }
    return longi;
}
string concate(string a, string b)
{
    char temp;
    for(int i=0;i<longi_string(a);i++)
    {
        temp=a[i];
        b+=temp;
    }
    return b;
}
int main()
{
    string final_string_a,final_string_b,part_string;
    setlocale(LC_ALL, "spanish");

    ifstream expression_a("E:\FICHEROS/ejercicio5_expression_a.txt");
    while (expression_a >> part_string) {
        final_string_a+= part_string;
        final_string_a+=' ';
    }
    expression_a.close();
    ifstream expression_b("E:\FICHEROS/ejercicio5_expression_b.txt");
    while (expression_b >> part_string) {
        final_string_b+= part_string;
        final_string_b+=' ';
    }
    expression_b.close();
    cout<<"La concatenación de ambas cadenas ha sido completada: \n\n"<<concate(final_string_a,final_string_b)<<endl;
    return 0;
}
