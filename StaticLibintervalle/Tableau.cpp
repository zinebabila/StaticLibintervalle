#include "pch.h"
#include "Tableau.h"
#include <assert.h>
#include <iostream>
using namespace std;
using namespace intervalle;

intervalle::Tableau::Tableau(unsigned int a)
{
    assert(a >= 0);
    this->taille = a;
    this->t = new float[this->taille];
    for (int i = 0; i < this->taille; i++)
        this->t[i] = 0;
}

intervalle::Tableau::~Tableau()
{
    if (this->t != nullptr) {
        delete this->t;
        this->t = nullptr;
    }
}

intervalle::Tableau::Tableau(const Tableau& t)
{
    this->taille = t.taille;
    if (this->t) {
        delete this->t;
        this->t = 0;
    }
    this->t = new float(*(t.t));   
}

Tableau& intervalle::Tableau::operator=(const Tableau& ta)
{
    if (this != &ta) {
        this->taille = ta.taille;
        if (this->t) {
            delete this->t;
            this->t = 0;
        }
        this->t = new float(*(ta.t));
    }
    return *this;
}

float& intervalle::Tableau::operator[](unsigned int indice)
{
    assert(indice >= 0 );//debug
    try//release
    {
        if (indice < 0 ) throw"rang error";
        return this->t[indice];
    }
    catch (char* e) {
        cout << e << endl;
    }
}

void intervalle::Tableau::print() const
{
    
        cout << "[";
        for (int i = 0; i < this->taille; i++)
            cout << this->t[i] << ",";
        cout << "]" << endl;
    

}
