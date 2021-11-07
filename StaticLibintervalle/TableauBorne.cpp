#include "pch.h"
#include "TableauBorne.h"
#include <assert.h>
#include <iostream>
using namespace std;
using namespace intervalle;

intervalle::TableauBorne::TableauBorne(unsigned int taille, float m, float ma)
	:Tableau(taille)
{
	if (m < ma) {
		this->min = m;
		this->max = ma;
		this->Tableau::operator[](0)= m;
		this->Tableau::operator[](taille-1) = ma;
	}
	else {
		this->min = ma;
		this->max = m;
		this->Tableau::operator[](0) = ma;
		this->Tableau::operator[](taille - 1) = m;
	}
	

}

float intervalle::TableauBorne::operator[](unsigned int indice) 
{
	assert(indice >= 0);//debug
	try//release
	{
		if (indice < 0) throw"rang error";
		return (this->Tableau::operator[](indice));
	}
	catch (char* e) {
		cout << e << endl;
	}
}

void intervalle::TableauBorne::operator()(unsigned int indice, float a)
{
	assert(indice > this->taille);
	this->Tableau::operator[](indice) = a;
}

void intervalle::TableauBorne::print() const
{
	this->Tableau::print();
}


