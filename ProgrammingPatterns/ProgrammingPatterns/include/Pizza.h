#pragma once
#include "Prerequisites.h"

//----------------Ejemplo para el Pattern Builder----------------

//Clase para las pizzas por cocinar
class Pizza
{
public:
  void addParts(const string _part) { //Función para agregar partes a la pizza
    m_parts.push_back(_part);
  }

	void
		print() { //Función para imprimir las partes de la pizza
		cout << "Partes de la pizza: ";
		for (int i = 0; i < m_parts.size(); i++)
		{
			cout << m_parts[i] << ", ";
		}
		cout << "" << endl;
	}

private:
  vector<string> m_parts;
};

//Interfaz para definir las partes del objeto para cocinar la pizza
class Oven
{
public:
	virtual
		void buildMass() = 0;

	virtual
		void buildCheese() = 0;

	virtual
		void buildSauce() = 0;

	virtual
		void buildIngredients() = 0;

	virtual
		Pizza* getProduct() = 0;
};

//Implementación de los métodos de Oven para hacer una pizza hawaiana
class HawaianPizza : public Oven {
public:
	HawaianPizza() {
		m_product = new Pizza();
	}

	void
		buildMass() override {
		m_product->addParts("Masa de orilla de queso");
	}

	void
		buildCheese() override {
		m_product->addParts("Queso derretido");
	}

	void
		buildSauce() override {
		m_product->addParts("Salsa de tomate");
	}

	void
		buildIngredients() override {
		m_product->addParts("Piña");
	}

	Pizza* getProduct() override {
		return m_product;
	}

private:
	Pizza* m_product;
};

//Implementación de los métodos de Oven para hacer una pizza veggie
class VeggiePizza : public Oven {
public:
	VeggiePizza() {
		m_product = new Pizza();
	}

	void
		buildMass() override {
		m_product->addParts("Masa de orilla de queso");
	}

	void
		buildCheese() override {
		m_product->addParts("Queso derretido");
	}

	void
		buildSauce() override {
		m_product->addParts("Salsa de tomate");
	}

	void
		buildIngredients() override {
		m_product->addParts("Verduras");
	}

	Pizza* getProduct() override {
		return m_product;
	}

private:
	Pizza* m_product;
};

// Método que funciona como director para construir una pizza con un Oven específico
class Chef {
public:
	Chef(Oven* _oven) : m_builder(_oven) {}

	void
		build() {
		m_builder->buildMass();
		m_builder->buildCheese();
		m_builder->buildSauce();
		m_builder->buildIngredients();
	}

private:
	Oven* m_builder;
};