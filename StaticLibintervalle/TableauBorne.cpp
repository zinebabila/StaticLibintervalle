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
	}
	else {
		this->min = ma;
		this->max = m;
	}
	this->Tableau::operator[](0) = m;
	this->Tableau::operator[](taille - 1) = ma;
}

intervalle::TableauBorne::TableauBorne(const TableauBorne&ta)
	:Tableau(ta)
{
	this->min = ta.min;
	this->max = ta.max;
}

TableauBorne& intervalle::TableauBorne::operator=(const TableauBorne&ta)
{
	if (this != &ta) {
		this -> Tableau::operator=(ta);
		this->min = ta.min;
		this->max = ta.max;
	}
	return *this;
}

 float intervalle::TableauBorne::operator[](unsigned int indice)
{
		return (this->Tableau::operator[](indice));
}

void intervalle::TableauBorne::operator()(unsigned int indice, float a)
{
	assert(a >=this->min&&  a<=this->max );
	this->Tableau::operator[](indice) = a;
}

void intervalle::TableauBorne::print() const
{
	this->Tableau::print();
	
}


