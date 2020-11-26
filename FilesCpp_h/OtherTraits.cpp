#include "MiniProjet.h"

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la liste des background disponible dans le fichier background.txt **/
deque<string> OtherTraits::background_list()
{

	deque<string> liste_background;	
 	string line;
 	fstream fichier("FilesTXT/background.txt");
	if ( !fichier ) cout << "fichier inexistant";
	else {	
		while(!fichier.eof())
		{
			getline(fichier, line);	
			if (line.find("--") == 0)
			{
				line.erase(line.begin()-0);
				line.erase(line.begin()-0);				
				liste_background.push_back(line);
			}
		}
	    }
	
	return liste_background ;
}


/********************************************************************************************************/
void OtherTraits::InitTraits()
{
	nbPointsBackground = 5;
	
	nbPointsVirtues = 7;
	conscience = 0;
	selfControl = 0;
	courage = 0;
	
	humanity = 0;
	willpower = 0;
	bloodPool = 10;
	
	nbPointsMeritsAndFlaws = 0;
	nbPointsMeritsAndFlawsMAX = 7;
}

void OtherTraits::SetBackground(string nomBack, int nbPoints)
{
	if(nbPointsBackground > 0 && nbPointsBackground - nbPoints >= 0)
	{
		backgroundName.push_back(nomBack);
		backgroundPoints.push_back(0);
		
		nbPointsBackground = nbPointsBackground - nbPoints;
	}
}

/*************************************************************************************************************************************************/
/** Cette fonction va d'ajouter des points dans les differentes vertues si c'est possible 
 * @param vertue : le nom de la virtue dans laquelle on veux rajouter des points
 * @param ajout : le nombre de points que l'on veut ajouter a la vertue 
 * @return RIEN */
void OtherTraits::setVirtuesPoints(string vertue, int ajout)
{
	if(nbPointsVirtues > 0 && nbPointsVirtues - ajout >= 0)
	{
		if(vertue.compare("conscience") == 0)
			conscience = conscience + ajout;
		if(vertue.compare("selfControl") == 0)
			selfControl = selfControl + ajout;
		if(vertue.compare("courage") == 0)
			courage = courage + ajout;
		
		nbPointsVirtues = nbPointsVirtues - ajout;
	}
}

int OtherTraits::getVirtuesPoints()
{
	return nbPointsVirtues;
}






