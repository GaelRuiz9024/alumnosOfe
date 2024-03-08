#include <iostream>
#include "proyectopoo.h"
#include <cstring> // Incluye la biblioteca para strlen
#include <utility> // Incluimos la librería para usar std::pair

using namespace std;

empresa::empresa(string nombre, string matricula, double salario) : nombre(nombre),matricula(matricula),salario(salario) {}

int main(){
    bool correcto=false;
    do{
        string contrasena="";
        cout<<"Ingrese la contrasena: ";
        cin>>contrasena;
        if(contrasena=="hola123" || contrasena=="123456" || contrasena=="adios321"){
            correcto=true;
            system("cls");
            int contador=0;
            int contempleados=0;
            cout << "Empleados que se van a registrar: "<<endl;
            cin >>contempleados;
            empresa empleados[contempleados];
            char opcion;

            do {
                system("cls");
                cout<<"*****hole*****\n";
                cout<<"a)Agregar nuevo empleado \n";
                cout<<"b)Modificar empleado\n";
                cout<<"c)Eliminar empleado\n";
                cout<<"d)Consultar plantilla \n";
                cout<<"e)Consultar empleado \n";
                cout<<"f)Sumar bonos o reducciones\n";
                cout<<"g)Salir \n";
                cin >> opcion;

                switch (opcion) {
                case 'a': {
                        system("cls");
                        cout<<"*****AGREGAR NUEVOS USUARIOS*****\n";

                        string nombre, matricula;
                        double salario;
                        cout << "Nombre del empleado: ";
                        cin >> nombre;
                        cout << "Matricula del empleado: ";
                        cin >> matricula;
                        cout << "Salario del empleado: ";
                        cin >> salario;
                        empresa empleado(nombre, matricula, salario);
                        empleados[contador] = empleado;
                        contador++;

                        cout<<"Usuario agregado correctamente\n";
                        system("PAUSE()");
                        break;  
                }

                case 'b': {
                    system("cls");
                    cout<<"*****MODIFICAR USUARIOS*****\n";
                    int indiceModificar=0;
                    char opcionModificar;
                    cout << "Ingrese el indice de la cuenta: ";
                    cin >> indiceModificar;
                    if(indiceModificar>=contador){ 
                        cout<<"indice fuera de rango, intente de nuevo\n";
                        system("PAUSE()");
                        break;
                    } 
                    do {
                        cout<<"Nombre: "<<empleados[indiceModificar].getNombre()<<"\n";
                        cout<<"Matricula: "<<empleados[indiceModificar].getMatricula()<<"\n";
                        cout<<"Salario: "<<empleados[indiceModificar].getSalario()<<"\n";
                        cout<<"ingrese que datos quieres modifica\n";
                        cout<<"a)Nombre\n";
                        cout<<" b)Matricula\n";
                        cout<<"c)Salario\n";
                        cout<<"d)Modificar todas\n";
                        cout<<")Volver al menu\n";
                        cin>>opcionModificar;
 
                        switch (opcionModificar){
                        case 'a':{
                            system("cls");

                            string newNombre;
                            cout<<"Ingrese el nuevo nombre: ";
                            cin>>newNombre;
                            empleados[indiceModificar].setNombre(newNombre);

                            cout<<"Nombre modificado correctamente";
                            system("PAUSE()");

                            break;
                        }
                        case 'b':{
                            system("cls");

                            double newMatricula;

                            cout<<"Ingrese la nueva matricula: ";
                            cin>>newMatricula;
                            empleados[indiceModificar].setMatricula(newMatricula);

                            cout<<"Matricula modificada correctamente\n";
                            system("PAUSE()");
                            break;
                        }
                        case 'c':{
                            system("cls");

                            double newSalario;

                            cout<<"Ingrese el nuevo salario base: ";
                            cin>>newSalario;
                            empleados[indiceModificar].setSalario(newSalario);

                            cout<<"Salario modificado correctamente\n";
                            system("PAUSE()");
                            break;
                        }
                        case 'd':{
                            system("cls");
                            string newNombre;
                            double newMatricula;
                            double newSalario;

                            cout<<"Ingrese el nuevo nombre: ";
                            cin>>newNombre;
                            
                            cout<<"Ingrese el nuevo matricula: ";
                            cin>>newMatricula;

                            cout<<"Ingrese el nuevo salario: ";
                            cin>>newSalario;

                            empleados[indiceModificar].setNombre(newNombre);
                            empleados[indiceModificar].setMatricula(newMatricula);
                            empleados[indiceModificar].setSalario(newSalario);

                            cout<<"Datos modificados correctamente\n";
                            system("PAUSE()");
                            break;
                        }
                        default:
                            break;
                        }
                    }while(opcionModificar != 'e');
                    break;
                }

                case 'c': {
                    system("cls");
                    int indiceEliminar=0;
                    cout<<"*****ELIMINAR USUARIOS*****\n";
                    cout << "Ingrese el indice de la cuenta: ";
                    cin >> indiceEliminar;

                    if (indiceEliminar >= 0 && indiceEliminar < contador) {
                        for (int i = indiceEliminar; i < contador - 1; ++i) {
                            empleados[i] = empleados[i + 1];
                        }
                        --contador;
                    } else {cout << "Posicion inválida\n"; }

                    cout << "El usuario ha sido eliminado correctamente\n" ;
                    system("PAUSE()");
                    break;

                }
                case 'd' :{
                    system("cls");
                    cout<<"*****MOSTRAR PLANTILLA*****\n";
                    for (int i=0; i<contador;i++){
                        cout<<"---------------------------------------------------------\n\n";
                        cout<<"Nombre: "<<empleados[i].getNombre()<<"\n";
                        cout<<"Matricula: "<<empleados[i].getMatricula()<<"\n";
                        cout<<"Salario base: "<<empleados[i].getSalario()<<"\n";
                        cout << "Bonificaciones:\n" ;
                            for (const auto& bono : empleados[i].obtenerBonificacion()) {
                                cout << "Concepto: " << bono.second << ", Monto: " << bono.first<<"\n" ;
                            }
                        cout<<"Deducciones: \n";
                            for (const auto& deduccion : empleados[i].obtenerDeduccion()) {
                                cout << "Concepto: " << deduccion.second << ", Monto: " << deduccion.first<<"\n" ;
                            }
                        cout<<"Salario neto: "<<empleados[i].calcularSalarioTotal()<<"\n";
                        cout<<"---------------------------------------------------------\n\n";


                            
                    }
                    system("PAUSE()");
                    break;
                }
                case 'e':{
                    system("cls");
                    cout<<"*****CONSULTAR EMPLEADO*****\n";
                    int indice=0;
                    cout<<"Seleciona el indice de el empleado que deseas consultar: ";
                    cin>>indice;
                    if(indice>=contador){ 
                        cout<<"indice fuera de rango, intente de nuevo\n";
                        system("PAUSE()");
                        break;
                    } 
                    cout<<"Nombre: "<<empleados[indice].getNombre()<<"\n";
                    cout<<"Matricula: "<<empleados[indice].getMatricula()<<"\n";
                    cout<<"Salario base: "<<empleados[indice].getSalario()<<"\n";
                    cout << "Bonificaciones:\n" ;
                        for (const auto& bono : empleados[indice].obtenerBonificacion()) {
                            cout << "Concepto: " << bono.second << ", Monto: " << bono.first<<"\n" ;
                        }
                    cout<<"Deducciones: \n";
                        for (const auto& deduccion : empleados[indice].obtenerDeduccion()) {
                            cout << "Concepto: " << deduccion.second << ", Monto: " << deduccion.first<<"\n" ;
                        }
                    cout<<"Salario neto: "<<empleados[indice].calcularSalarioTotal()<<"\n";
                    system("PAUSE()");

                    break;
                    
                }
                case 'f':{
                    system("cls");
                    cout<<"*****AGREGAR BONOS Y DEDUCCIONES*****\n";
                    char opcionBonos;
                    int i=0;
                    cout<<"Seleciona el indice de el empleado que deseas modificar: ";
                    cin>>i;
                    if(i>=contador){ 
                        cout<<"indice fuera de rango, intente de nuevo\n";
                        system("PAUSE()");
                        break;
                    } 
                    do{
                        cout<<"a)agregar bono\n";
                        cout<<"b)agregar deduccion\n";
                        cout<<"c)salir\n";
                        cin>>opcionBonos;
                        switch (opcionBonos){
                            case 'a':{
                                system("cls");
                                double bono=0.0;
                                string concepto="";
                                cout<<"agrega un concepto: ";
                                cin >>concepto;
                                cout<<"agrega una monto de bonificacion: ";
                                cin >>bono;
                                empleados[i].agregarBonificacion(bono, concepto);

                                cout<<"Bono agregado correctamente\n";
                                system("PAUSE()");
                                break;
                            }
                            case 'b':{
                                system("cls");
                                double deduccion=0.0;
                                string concepto="";
                                cout<<"agrega un concepto: ";
                                cin >>concepto;
                                cout<<"agrega una monto de deduccion: ";
                                cin >>deduccion;
                                empleados[i].agregarDeduccion(deduccion, concepto);

                                cout<<"Deduccion agregada correctamente\n";
                                system("PAUSE()");
                                break;
                            }
                            default:
                                break;
                            }
                    }while(opcionBonos !='c');
                    break;
                }
                

                }
            } while (opcion != 'g');
        }else{
        cout<<"Contrasena incorrecta, intente otra vez\n";
        
        }
     }while(correcto!=true);
    return 0;

}