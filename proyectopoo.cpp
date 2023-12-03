#include <iostream>
#include "proyectopoo.h"
#include <cstring> // Incluye la biblioteca para strlen
using namespace std;

empresa::empresa(string nombre, string matricula, double salario) : nombre(nombre),matricula(matricula),salario(salario) {}

int main(){
    int contador=0;
    int contempleados=0;
    cout << "Empleados que se van a registrar: "<<endl;
    cin >>contempleados;
    empresa empleados[contempleados];
    char opcion;

    do {
        cout << "a)Agregar nuevo empleado b)Modificar empleado c)Eliminar empleado d)Consultar plantilla e)Consultar empleado f)Salir ";
        cin >> opcion;

        switch (opcion) {
        case 'a': {

                string nombre, matricula;
                double salario;
                cout << "Nombre del empleado ";
                cin >> nombre;
                cout << "Matrícula del empleado: ";
                cin >> matricula;
                cout << "Salario del empleado: ";
                cin >> salario;
                empresa empleado(nombre, matricula, salario);
                empleados[contador] = empleado;
                contador++;
                break;  
        }

        case 'b': {
           int indiceModificar;
           char opcionModificar;
            cout << "Ingrese el indice de la cuenta: ";
            cin >> indiceModificar;
            do {
                cout<<"Nombre: "<<empleados[indiceModificar].getNombre();
                cout<<"Matricula: "<<empleados[indiceModificar].getMatricula();
                cout<<"Salario: "<<empleados[indiceModificar].getSalario();
                cout<<"ingrese que datos quieres modificar"<<endl;
                cout<<"a)Nombre b)Matricula c)Salario d)Volver al menu"<<endl;
                cin>>opcionModificar;
                switch (opcionModificar)
                {
                case 'a':{
                    string newNombre;
                    cout<<"Ingrese el nuevo nombre";
                    cin>>newNombre;
                    empleados[indiceModificar].setNombre(newNombre);

                    break;
                }
                case 'b':{
                    string newNombre;
                    cout<<"Ingrese el nuevo nombre";
                    cin>>newNombre;
                    empleados[indiceModificar].setNombre(newNombre);

                    break;
                }
                case 'c':{
                    string newNombre;
                    cout<<"Ingrese el nuevo nombre";
                    cin>>newNombre;
                    empleados[indiceModificar].setNombre(newNombre);

                    break;
                }
                default:
                    break;
                }
            }while(opcion != 'd');
            break;
        }

        case 'c': {

            int indice; 

            string nombre, matricula;
            double salario;
            cout << "Ingrese el indice del empleado";
            cin >> indice;
            empresa empleado (nombre, matricula, salario);
            empleados[contador]=empleado;
            contador 
        }

        
        

        }
    } while (opcion != 'c');

    
    return 0;

}