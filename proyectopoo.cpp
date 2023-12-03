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
                cout<<"a)Nombre b)Matricula c)Salario d)Modificar todas e)Volver al menu"<<endl;
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
                    double newMatricula;

                    cout<<"Ingrese el nuevo nombre";
                    cin>>newMatricula;
                    empleados[indiceModificar].setMatricula(newMatricula);

                    break;
                }
                case 'c':{
                    double newSalario;

                    cout<<"Ingrese el nuevo nombre";
                    cin>>newSalario;
                    empleados[indiceModificar].setSalario(newSalario);

                    break;
                }
                case 'd':{
                    string newNombre;
                    double newMatricula;
                    double newSalario;

                    cout<<"Ingrese el nuevo nombre";
                    cin>>newNombre;
                    
                    cout<<"Ingrese el nuevo matricula";
                    cin>>newMatricula;

                    cout<<"Ingrese el nuevo salario";
                    cin>>newSalario;

                    empleados[indiceModificar].setNombre(newNombre);
                    empleados[indiceModificar].setMatricula(newMatricula);
                    empleados[indiceModificar].setSalario(newSalario);


                }
                default:
                    break;
                }
            }while(opcion != 'e');
            break;
        }

        case 'c': {
            int indiceEliminar;
                 
            cout << "Ingrese el indice de la cuenta: ";
            cin >> indiceEliminar;

            if (indiceEliminar >= 0 && indiceEliminar < contador) {
                for (int i = indiceEliminar; i < contador - 1; ++i) {
                    empleados[i] = empleados[i + 1];
                }
                --contador;
            } else {
                std::cout << "Posición inválida\n";
            }

            std::cout << "El usuario ha sido eliminado correctamente\n" ;
            break;

        }
        case 'd' :{
            for (int i=0; i<contador;i++){
                cout<<"Nombre: "<<empleados[i].getNombre()<<"\n";
                cout<<"Matricula: "<<empleados[i].getMatricula()<<"\n";
                cout<<"Salario: "<<empleados[i].getSalario()<<"\n";
            }
            break;
        }
        case 'e':{
            int indice;
            cout<<"Seleciona el indice de el empleado que deseas consultar";
            cin>>indice;
            cout<<"Nombre: "<<empleados[indice].getNombre()<<"\n";
            cout<<"Matricula: "<<empleados[indice].getMatricula()<<"\n";
            cout<<"Salario: "<<empleados[indice].getSalario()<<"\n";
        }

        
        

        }
    } while (opcion != 'f');

    
    return 0;

}