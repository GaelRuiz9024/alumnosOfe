#include <iostream>
#include <string> 
using namespace std;

class empresa{
private:
    string nombre;
    string matricula;
    double salario;

public:
    empresa(string modelo="", string matricula="", double salario=0.0);

    void bono (double bono){
        salario=salario+bono;
    }

    void deducciones (double deducciones){
        salario=salario-deducciones;
    }
    void mostrar(){
 
    }
    string getNombre(){
        return nombre;
    }
    string getMatricula(){
        return matricula;
    }
    double getSalario(){
        return salario;
    }
    void setNombre(string nom){
        nombre=nom;
    }
    void setMatricula(double mat){
        matricula=mat;
    }
    void setSalario(double sueldo){
        salario=sueldo;
    }

};
