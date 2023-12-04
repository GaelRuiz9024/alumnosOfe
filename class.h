#include <iostream>
#include <string> 
#include <vector> // Incluimos la librería para usar vector (arreglo dinámico)
#include <utility> // Incluimos la librería para usar std::pair


using namespace std;

class empresa{
private:
    string nombre;
    string matricula;
    double salario;
    vector<pair<double,string>> bonificaciones;
    vector<pair<double,string>> deducciones;


public:
    empresa(string modelo="", string matricula="", double salario=0.0);

    string getNombre(){return nombre;}

    string getMatricula(){return matricula;}

    double getSalario(){return salario;}

    void setNombre(string nom){ nombre=nom;}

    void setMatricula(double mat){ matricula=mat; }

    void setSalario(double sueldo){ salario=sueldo;}
    
    void agregarBonificacion(double bonificacion,string concepto) {
        bonificaciones.push_back(make_pair(bonificacion, concepto));
    }

    void agregarDeduccion(double deduccion,string concepto) {
        deducciones.push_back(make_pair(deduccion, concepto));
    }
    vector<pair<double, string>> obtenerBonificacion() const {
        return bonificaciones;
    }

    vector<pair<double, string>> obtenerDeduccion() const {
        return deducciones;
    }
    int calcularSalarioTotal() const {
        int totalBonificaciones = 0;
        int totalDeducciones = 0;

        for (const auto& bonificacion : bonificaciones) {
            totalBonificaciones += bonificacion.first; // Accedemos al monto
        }

        for (const auto& deduccion : deducciones) {
            totalDeducciones += deduccion.first; // Accedemos al monto
        }


        return salario + totalBonificaciones - totalDeducciones;
}

};

