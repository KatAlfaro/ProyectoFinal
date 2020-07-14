#include <iostream>
#include <string>


using namespace std;
/*Elaborar un programa que procese información sobre productos comprados por un cliente en una tienda, a modo de procesamiento 
de una factura de compra. La información se manejará en un arreglo, en el cual cada casilla contendrá los datos de:
nombre del artículo, cantidad de unidades compradas, precio unitario y costo total por artículo.*/


void nombreArti(int cantidad, string articulos[][4])
{

    string  nombre, cantidad2, precio;          //declaracion de variables
    
    for(int i =0;i<cantidad;i++)
    {
        cout<<endl;
        cout << "Articulo "<<i+1 <<endl;
        for(int k =0;k<3;k++)
        {
            if(k==0)
            {
                cout<<endl;
                cout<< "Por favor represente los espacios con _ "<< endl;
                cout << "Nombre: "<< endl; //Los espacios serán representados mediante "_"
                cin>> nombre;
                articulos[i][k] = nombre;
            }
            if(k==1)
            {
                cout << "Cantidad: "<< endl;
                cin >> cantidad2;
                articulos[i][k] = cantidad2;
            }
            if(k==2)
            {
                cout << "Precio: "<< endl;
                cin >> precio;
                articulos[i][k] = precio;
            }
        }
    }
    
}

void Calculo_Total(int cantidad,string articulos[][4])
{
    
    for(int i =0;i<cantidad;i++)
    {
        articulos[i][3] = to_string(stof(articulos[i][2])*stof(articulos[i][1]));
    }
}

void Valor_Compra1(int cantidad,string articulos[][4])
{
    for(int i =0;i<cantidad;i++)
    {
        cout<< endl; 
        cout << "Articulo "<<i+1 <<endl;
        cout << "Nombre: " << articulos[i][0] <<endl;
        cout << "Cantidad: " << articulos[i][1] <<endl;
        cout << "Precio Unitario: " << articulos[i][2] <<endl;
        cout << "Total: " <<articulos[i][3]<<endl;
        
    }
}

void Valor_Compra2(int cantidad,string articulos[][4])   //funcion que despliega el contenido del arreglo
{
    cout<< endl;
    cout<<"Nombre | Cantidad | Precio Unitario | Total\n"<<endl;
    for(int i =0;i<cantidad;i++){
        for(int k =0;k<4;k++){
            cout << articulos[i][k]<<"    |    ";
        }cout << endl;
        
    }
}

float Total_Compra(int cantidad,string articulos[][4] )
{
    float total = 0;
    for(int i =0;i<cantidad;i++){
        total+=stof(articulos[i][3]);
    }
    
    return total;
}

int main(){               //funcion principal, controla la llamda de las demás funciones
    int cantidad;
    float Total_Final;
    cout<< endl;
    cout<< "BIENVENIDO"<< endl;
    cout << "Por favor ingrese la cantidad de articulos: ";
    cin >> cantidad;
    
    string articulos [cantidad][4];           //cantidad de articulos en el arreglo 
    
    nombreArti(cantidad, articulos);
    Calculo_Total(cantidad,articulos);
    Valor_Compra2(cantidad,articulos);
    
    Total_Final = Total_Compra(cantidad,articulos);
     cout<< endl; 
     cout << "El valor total de la compra es de: "<<Total_Final; // costo final
}