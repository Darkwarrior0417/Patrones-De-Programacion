#pragma once
#include "Prerequisites.h"

//Clase para el objeto a construir
class 
	bProduct {
public:
	void 
		agregarParte(const string& _parte) { //Función para poder agregar nuevas partes
		m_partes.push_back(_parte);
	}

	void 
		print() { //Función para imprimir las partes
		cout << "Partes del producto: ";
		for (int i = 0; i < m_partes.size(); i++)
		{
			cout << m_partes[i] << " ";
		}
	}

private:
	vector<string> m_partes; //Vector para las partes del producto
};

 //Interfaz para definir las partes del objeto
class Builder
{
public:
	virtual 
		void buildParteA() = 0;

	virtual 
		void buildParteB() = 0;

	virtual 
		bProduct* obtenerProducto() = 0;

};

//Clase para implementar las partes del producto
class BuilderConcreto: public Builder { 
public:
	BuilderConcreto() {
		m_product = new bProduct();
	}

	void 
		buildParteA() override {
		m_product->agregarParte("Parte A");
	}

	void 
		buildParteB() override {
		m_product->agregarParte("Parte B");
	}

	bProduct* obtenerProducto() override {
		return m_product;
	}

private:
	bProduct* m_product;
};

//Clase que se encarga de la contrucción del producto
class Director {
public:
	Director(Builder* _builder) : m_builder(_builder) {}

	void 
		build() {
		m_builder->buildParteA();
		m_builder->buildParteB();
	}

private:
	Builder* m_builder;
};