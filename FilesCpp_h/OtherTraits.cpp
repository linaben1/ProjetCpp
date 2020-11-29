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





