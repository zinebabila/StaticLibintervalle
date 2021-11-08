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
        TableauBorne(const TableauBorne&);
        TableauBorne& operator=(const TableauBorne&);
        float operator[](unsigned int indice) ;
        void  operator()(unsigned int indice,float a);
        void print() const;
    };

}

