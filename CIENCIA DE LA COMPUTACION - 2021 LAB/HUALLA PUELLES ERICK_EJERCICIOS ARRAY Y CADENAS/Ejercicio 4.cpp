#include <iostream>
#include <fstream>
using namespace std;

long longi_string_iterative(string expression)
{
    long longi=0;
    while(!expression.empty())
    {
        expression.erase(0,1);
        ++longi;
    }
    return longi;
}
long longi_b=0;
long longi_string_recursive(string expression)
{
    if(expression.empty())
        return longi_b;
    else{
        longi_b+=1;
        expression.erase(0,1);
        return longi_string_recursive(expression);
    }
}
int main()
{
    string final_string,part_string;
    ifstream expression("E:\FICHEROS/ejercicio4_expression.txt");
    while (expression >> part_string) {
        final_string += part_string;
    }
    expression.close();

    cout<<"Longitud de la cadena es: "<<longi_string_iterative(final_string)<<endl;
    cout<<"Longitud de la cadena es: "<<longi_string_recursive(final_string)<<endl;
    return 0;
}
