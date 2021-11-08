#include "pch.h"
#include <assert.h>
#include <iostream>
#include "Tableau.h"
using namespace std;
using namespace intervalle;

intervalle::Tableau::Tableau(unsigned int a)
{
    assert(a > 0);
    this->taille = a;
    //alocation dynamique et initialisation
    this->t = new float[this->taille]();
   /* if (this->t) {
        for (int i = 0; i < this->taille; i++)
            this->t[i] = 0;
    }*/
    
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
    /*if (this->t) {
        delete this->t;
        this->t = 0;
    }*/
    this->t = new float[t.taille]; 
    for (int i = 0; i < this->taille; i++)
        this->t[i] = t.t[i];

}

Tableau& intervalle::Tableau::operator=(const Tableau& ta)
{
    if (this != &ta) {//autoaffectation
        this->taille = ta.taille;
        if (this->t) {
            delete [] this->t;
            this->t = 0;
        }
        this->t = new float[ta.taille];
        if (this->t) {
            for (int i = 0; i < this->taille; i++)
                this->t[i] = ta.t[i];
        }
        
    }
    return *this;
}

float& intervalle::Tableau::operator[](unsigned int indice) const
{
    assert(indice >= 0 && indice<this->taille );//debug
    try//release
    {
        if (indice < 0 ) throw"rang error";
        return this->t[indice];
        //this->t[index]=1.2; operateur[] de la classe float
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
