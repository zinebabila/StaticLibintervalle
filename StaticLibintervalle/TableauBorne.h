#pragma once
#include "Tableau.h"
namespace intervalle {
    class TableauBorne :
        private Tableau
    {
    private:
        float min;
        float max;
    public:
        TableauBorne(unsigned int taille, float m, float ma);
        float operator[](unsigned int indice) const;
        void  operator()(unsigned int indice,float a);
        void print() const;
    };

}

