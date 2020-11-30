#include "Projet.h"


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


/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie le nom du sire  **/



void Personnage::setSire(string sir)
{
	sire = sir;
}

string Personnage::getSire()
{
	return sire;
}


/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie humanity du personnage  **/

void Personnage::setHumanity(string human)
{
	Humanity = human;
}

string Personnage::getHumanity()
{
	return Humanity;
}



/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie le sexe du personnage  **/


void Personnage::setWillpower(string willp)
{
	Willpower = willp;
}

string Personnage::getWillpower()
{
	return Willpower;
}


