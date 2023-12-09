#pragma once
#include "Prerequisites.h"

//Clase con la lógica para prototype
class Prototype
{
public:
  virtual Prototype* clonar() = 0; //Instancia de la clase que se va a clonar
  virtual void configurar(string _value ) = 0; //Función para configurar el prototipo
  virtual void print() = 0; //Función para imprimir los valores de configurar
};

//Clase concreta de prototipo
class PrototipocConcreto : public Prototype {
public:
  Prototype* clonar() override {
    PrototipocConcreto* copy = new PrototipocConcreto();
    copy->configurar(m_value);
    return copy;
  }

  void configurar(string _value) override {
    m_value = _value;
  }

  void print() override {
    cout << "Valor: " << m_value << endl;
  }

private:
  string m_value;
};

// Clase abstracta DocumentoPrototype que define la interfaz del prototipo de documento
class
  DocumentoPrototype {
public:
  virtual DocumentoPrototype* clone() = 0; // Método para clonar el prototipo de documento
  virtual void configurar(string _value) = 0; // Método para configurar el prototipo de documento
  virtual void mostrar() = 0; // Método para mostrar detalles del prototipo de documento
};

// Clase concreta DocumentoTexto que implementa la interfaz del prototipo de documento
class
  DocumentoTexto :
  public DocumentoPrototype {
public:
  // Método para clonar el prototipo de documento de texto
  DocumentoPrototype* clone() override {
    DocumentoTexto* copy = new DocumentoTexto();
    copy->configurar(m_value);
    return copy;
  }

  // Método para configurar el prototipo de documento de texto
  void configurar(string _value) override {
    m_value = _value;
  }

  // Método para mostrar detalles del prototipo de documento de texto
  void mostrar() override {
    cout << "Texto: " << m_value << endl;
  }

private:
  string m_value; // Variable para almacenar el valor del prototipo de documento de texto
};

// Clase concreta DocumentoImagen que implementa la interfaz del prototipo de documento
class
  DocumentoImagen :
  public DocumentoPrototype {
public:
  // Método para clonar el prototipo de documento de imagen
  DocumentoPrototype* clone() override {
    DocumentoImagen* copy = new DocumentoImagen();
    copy->configurar(m_value);
    return copy;
  }

  // Método para configurar el prototipo de documento de imagen
  void configurar(string _value) override {
    m_value = _value;
  }

  // Método para mostrar detalles del prototipo de documento de imagen
  void mostrar() override {
    cout << "Imagen: " << m_value << endl;
  }

private:
  string m_value; // Variable para almacenar el valor del prototipo de documento de imagen
};