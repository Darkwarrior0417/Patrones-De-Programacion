#pragma once
#include "Prerequisites.h"

//----------------Ejemplo para el Pattern Adapter----------------

//En este caso la depreciada es un círculo
class Circulo {
public:
  virtual
    void
    dibujarCirculo() {
    cout << "Se ha dibujado un circulo." << endl;
  }
};

//En este caso la depreciada es un cuadrado
class Cuadrado {
public:
  virtual
    void
    dibujarCuadrado() {
    cout << "Se ha dibujado un cuadrado." << endl;
  }
};

//Clase que funciona como una nueva interfaz para cuadrado y círculo
class Dibujable {
public:
  virtual
    void
    dibujar() {
    cout << "Metodo nuevo llamado." << endl;
  }
};

//Implementa la clase dibujable heredando el círculo para poder dibujarlo
class CirculoAdapter : public Dibujable {
public:
  CirculoAdapter(Circulo* circulo) : m_Circulo(circulo) {}

  void dibujar() override {
    cout << "Adaptador llamado para dibujar un circulo." << endl;
    m_Circulo->dibujarCirculo();
  }

public:
  Circulo* m_Circulo;
};

//Implementa la clase dibujable heredando el cuadrado para poder dibujarlo
class CuadradoAdapter : public Dibujable {
public:
  CuadradoAdapter(Cuadrado* cuadrado) : m_cuadrado(cuadrado) {}

  void dibujar() override {
    cout << "Adaptador llamado para dibujar un cuadrado." << endl;
    m_cuadrado->dibujarCuadrado();
  }

public:
  Cuadrado* m_cuadrado;
};