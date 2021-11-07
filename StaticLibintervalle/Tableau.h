#pragma once
namespace intervalle {
	class Tableau
	{
	protected:
		int taille;
	private :
		
	     float* t;
	public:
		Tableau(unsigned int a);
		~Tableau();
		Tableau(const Tableau&t);
		Tableau& operator=(const Tableau&);
		float& operator[](unsigned int indice);
		void print() const;
	};
}


