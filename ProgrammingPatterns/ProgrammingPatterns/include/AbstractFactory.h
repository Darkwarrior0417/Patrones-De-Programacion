#pragma once
#include "Prerequisites.h"

//Clase base para productos A
class ProductA {
public:
  virtual
    void
    operationA() = 0;
};

//Clase base para productos B
class ProductB {
public:
  virtual
    void
    operationB() = 0;
};

//Clase abstract factory
class AbstractFactory {
  public:
    virtual ProductA* crearProductoA() = 0;
    virtual ProductB* crearProductoB() = 0;
}; 

//Clase concreta para productos A
class productA1 : public ProductA {
public:
  void
    operationA() override {
    cout << "Operaci�n A en ProductoA1" << endl;
  }
};

//Clase concreta para productos B
class productB1 : public ProductB {
public:
  void
    operationB() override {
    cout << "Operaci�n B en ProductoA1" << endl;
  }
};

//Clase concreta para la implementaci�n de abstract factory
class ConcreteAbsFactory : public AbstractFactory {
public:
  ProductA* crearProductoA() override {
    return new productA1();
  }
  ProductB* crearProductoB() override {
    return new productB1();
  }
};

// Interfaz base para los muebles
class
  Mueble {
public:
  virtual void descripcion() = 0; // M�todo para describir el mueble
  virtual void color() = 0;       // M�todo para obtener el color del mueble
};

// Clase concreta que representa una silla
class
  Silla :
  public Mueble {
public:
  void descripcion() override {
    cout << "Un mueble espl�ndido de la factor�a" << endl;
  }

  void color() override {
    cout << "De color mueble de la factor�a" << endl;
  }
};

// Clase concreta que representa una mesa
class
  Mesa :
  public Mueble {
public:
  void descripcion() override {
    cout << "Una mesa espl�ndida de la factor�a" << endl;
  }

  void color() override {
    cout << "De color mesa de la factor�a" << endl;
  }
};

// Interfaz para las factor�as de muebles
class
  FactoriaMuebles {
public:
  virtual Silla* crearSilla() = 0; // M�todo para crear una silla
  virtual Mesa* crearMesa() = 0;   // M�todo para crear una mesa
};

// Implementaci�n de la factor�a de muebles r�sticos
class
  FactoriaMueblesRusticos :
  public FactoriaMuebles {
public:
  Silla* crearSilla() override {
    return new Silla(); // Crea una silla r�stica
  }

  Mesa* crearMesa() override {
    return new Mesa(); // Crea una mesa r�stica
  }
};

// Implementaci�n de la factor�a de muebles modernos
class
  FactoriaMueblesModernos :
  public FactoriaMuebles {
public:
  Silla* crearSilla() override {
    return new Silla(); // Crea una silla moderna
  }

  Mesa* crearMesa() override {
    return new Mesa(); // Crea una mesa moderna
  }
};
