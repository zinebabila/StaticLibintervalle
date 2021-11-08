#pragma once
//n'importe quelle classe creee a une classe mere object
namespace intervalle {
	class Tableau
	{	
	private :
		int taille;
	     float* t;
	public:
		Tableau(unsigned int a);
		~Tableau();
		Tableau(const Tableau&t);
		Tableau& operator=(const Tableau&);
		float& operator[](unsigned int indice) const;
		void print() const;
	};
}


