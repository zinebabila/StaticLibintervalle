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
		this->t[0] = m;
		this->t[this->taille-1] = ma;
	}
	else {
		this->min = ma;
		this->max = m;
		this->t[0] = ma;
		this->t[this->taille-1] = m;
	}
	

}

float intervalle::TableauBorne::operator[](unsigned int indice) const
{
	assert(indice >= 0);//debug
	try//release
	{
		if (indice < 0) throw"rang error";
		return this->t[indice];
	}
	catch (char* e) {
		cout << e << endl;
	}
}

void intervalle::TableauBorne::operator()(unsigned int indice, float a)
{
	assert(indice > this->taille);
	this->t[indice] = a;
}

void intervalle::TableauBorne::print() const
{
	cout << "[";
	for (int i = 0; i < this->taille; i++)
		cout  << this->t[i] << ",";
		cout << "]" << endl;
}

