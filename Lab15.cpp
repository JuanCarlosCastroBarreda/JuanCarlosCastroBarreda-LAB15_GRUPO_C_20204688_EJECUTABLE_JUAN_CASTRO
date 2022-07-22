/*El alumno deberá de implementar un conjunto de clases que permita seleccionar
las piezas de un automóvil, es decir, se podrán tener componentes a disposición
del cliente (puertas, llantas, timón, asientos, motor, espejos, vidrios, etc.). Del cual
el cliente puede indicar que características de color puede tener cada pieza. Al
final mostrar opciones al Cliente o permitirle que él pueda escoger las piezas e
indicar el color. Utilizar el patrón Builder.*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Auto{
    string color{" POR DEFECTO "};
    string puertas{" POR DEFECTO "};
    string llantas{" POR DEFECTO "};
    string timon{" POR DEFECTO "};
    string asientos{" POR DEFECTO "};
    string motor{" POR DEFECTO "};
    string espejos{" POR DEFECTO "};
    string vidrios{" POR DEFECTO "};
};

class Producto1 {
public:
    Auto componentes;
    void ListaComp()const {
        cout << "\nComponentes : ";
        cout << "\nColor : "<<componentes.color;
        cout << "\nPuertas : "<<componentes.puertas;
        cout << "\nLlantas : "<<componentes.llantas;
        cout << "\nTimon : "<<componentes.timon;
        cout << "\nAsientos : "<<componentes.asientos;
        cout << "\nMotor : "<<componentes.motor;
        cout << "\nEspejos : "<<componentes.espejos;
        cout << "\nVidrios : "<<componentes.vidrios;
        }
};

class IBuilder {
public:
    virtual ~IBuilder() {}
    virtual void ProducirColor() const = 0;
    virtual void ProducirPuertas() const = 0;
    virtual void ProducirLLantas() const = 0;
    virtual void ProducirTimon() const = 0;
    virtual void ProducirAsientos() const = 0;
    virtual void ProducirMotor() const = 0;
    virtual void ProducirEspejos() const = 0;
    virtual void ProducirVidrios() const = 0;
};


string colores(){
    string _color;
    cout<<"\nIngrese Color\n";
    cin>>_color;
    return _color;
}

class BuilderEspecifico : public IBuilder {
private:
    Producto1* product;
public:
    BuilderEspecifico() {
        this->Reset();
    }
    ~BuilderEspecifico() {
        delete product;
    }
    void Reset() {
        this->product = new Producto1();
    }


    void ProducirColor()const override {
        string dato{"Auto "};
        dato+=colores();
        this->product->componentes.color=dato;
        
    }

    void ProducirPuertas()const override {
        string dato{"Puertas "};
        cout<<"Seleccione como quiere las puertas\n";
        int opcion{0};
        while(opcion<1 || opcion>3){
            cout << "1.- Puertas de ala mariposa:\n";
            cout << "2.- Puertas de tijera:\n";
            cout << "3.- Puertas corredizas:\n";
            cin >> opcion;
        }
        if (opcion==1){
            dato = "Puertas de ala mariposa";
        }
        else if (opcion==2){
            dato = "Puertas de tijera";
        }
        else{
            dato = "Puertas corredizas";
        }
        this->product->componentes.puertas=dato;
       
    }
    void ProducirLLantas()const override {
        string dato{"Llantas "};
        int opcion{0};
        cout<<"Seleccione como quiere las llantas\n";
        while(opcion<1 || opcion>2){
            cout << "1.- Aro 15:\n";
            cout << "2.- Aro 14:\n";
            cin >> opcion;
        }
        if (opcion==1){
            dato = "Aro 15";
        }
        else{
            dato = "Aro 14";
        }
        this->product->componentes.llantas=dato;
        
    }
    void ProducirTimon()const override {
        string dato{"Timon "};
        cout<<"Seleccione como quiere el Timon\n";
        int opcion{0};
        while(opcion<1 || opcion>2){
            cout << "1.- Cuero:\n";
            cout << "2.- Plastico:\n";
            cin >> opcion;
        }
        if (opcion==1){
            dato = "Cuero ";
        }
        else{
            dato = "Plastico ";
        }
        dato+=colores();
        this->product->componentes.timon=dato;
       
    }
    void ProducirAsientos()const override {
        string dato{"Asientos "};
        cout<<"Seleccione como quiere los Asientos\n";
        int opcion{0};
        while(opcion<1 || opcion>2){
            cout << "1.- Cuero:\n";
            cout << "2.- Tela:\n";
            cin >> opcion;
        }
        if (opcion==1){
            dato = "Cuero ";
        }
        else{
            dato = "Tela ";
        }
        dato+=colores();
        this->product->componentes.asientos=dato;
        
    }
    void ProducirMotor()const override {
        string dato{"Motor "};
        int opcion{0};
        cout<<"Seleccione como quiere el Motor\n";
        while(opcion<1 || opcion>2){
            cout << "1.- Monocilindrico:\n";
            cout << "2.- Doble cilindro:\n";
            cin >> opcion;
        }
        if (opcion==1){
            dato = "Monocilindrico";
        }
        else{
            dato = "Doble cilindro";
        }
        this->product->componentes.motor=dato;
      
    }
    void ProducirEspejos()const override {
        string dato{"Espejos "};
        cout<<"Seleccione como quiere los Espejos\n";
        int opcion{0};
        while(opcion<1 || opcion>2){
            cout << "1.- Lateral y Central\n";
            cout << "2.- Solo Lateral:\n";
            cin >> opcion;
        }
        if (opcion==1){
            dato = "Lateral y Central";
        }
        else{
            dato = "Solo Lateral";
        }
        this->product->componentes.espejos=dato;
        
    }
    void ProducirVidrios()const override {
        string dato{"Vidrios "};
        cout<<"Seleccione como quiere los Vidrios\n";
        int opcion{0};
        while(opcion<1 || opcion>2){
            cout << "1.- Laminado\n";
            cout << "2.- Templado:\n";
            cin >> opcion;
        }
        if (opcion==1){
            dato = "Laminado";
        }
        else{
            dato = "Templado";
        }
        this->product->componentes.vidrios=dato;
        
    }

    Producto1* GetProducto() {
        Producto1* resultado = this->product;
        this->Reset();
        return resultado;
    }
};

class Director {
private:
    IBuilder* builder;
public:
    void set_builder(IBuilder* builder) {
        this->builder = builder;
    }
    void BuildProductoMin() {
        this->builder->ProducirColor();
        this->builder->ProducirAsientos();
        this->builder->ProducirMotor();
        this->builder->ProducirVidrios();
    }
    void BuildProductoCompleto() {
        this->builder->ProducirColor();
        this->builder->ProducirPuertas();
        this->builder->ProducirLLantas();
        this->builder->ProducirTimon();
        this->builder->ProducirAsientos();
        this->builder->ProducirMotor();
        this->builder->ProducirEspejos();
        this->builder->ProducirVidrios();
    }
};

void ClienteCode(Director& director)
{
    BuilderEspecifico* builder = new BuilderEspecifico();
    director.set_builder(builder);

    int opcion{0};

    while(opcion <1 || opcion >2){
        
        cout << "1.- Producto Basico:\n";
        cout << "2.- Producto Completo:\n";
        cin >> opcion;
    }
    if (opcion==1){
        director.BuildProductoMin();
        Producto1* p = builder->GetProducto();
        p->ListaComp();
        delete p;
    }

    else{
        director.BuildProductoCompleto();
        Producto1* p = builder->GetProducto();
        p->ListaComp();
        delete p;
    }
    delete builder;
}

int main() {
        Director* director = new Director();
        ClienteCode(*director);
        delete director;
    return 0;
}