#include "MiniProjet.h"


/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie le nom du personnage  **/

void Personnage::setNomPersonnage(string perso)
{
	nomPersonnage = perso;
}

string Personnage::getNomPersonnage()
{
	return nomPersonnage;
}



/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie le sexe du personnage  **/


void Personnage::setSexe(string sexe)
{
	sexePerso = sexe;
}

string Personnage::getSexe()
{
	return sexePerso;
}



/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie la chronicle du personnage  **/



void Personnage::setChronicle(string chronicle)
{
	chroniclePerso = chronicle;
}

string Personnage::getChronicle()
{
	return chroniclePerso;
}


/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie le concept du personnage  **/



void Personnage::setConcept(string concp)
{
	Concept = concp;
}

string Personnage::getConcept()
{
	return Concept;
}



