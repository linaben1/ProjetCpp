#include "Projet.h"




/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie le niveau du sang  **/



void  OtherTraits::setBloodpool(string blo)
{
	bloodPool = blo;
}

string  OtherTraits::getBloodpool()
{
	return bloodPool;
}


/****************************************************************************************************************************************************************/
/** Fonction qui recupere et renvoie le turn blood  **/



void  OtherTraits::setBloodpoolturn(string bloo)
{
	bloodPoolturn = bloo;
}

string  OtherTraits::getBloodpoolturn()
{
	return bloodPoolturn;
}



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



/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la liste des Merits **/

deque<string> OtherTraits::merits_list()
{
	deque<string> liste;	
 	string line;
 	regex pattern { "--.+(Merit\\))" };
 	fstream fichier("FilesTXT/file_part11.txt");
	if ( !fichier ) cout << "fichier inexistant";
	else 
	{	
		while(!fichier.eof())
		{
			getline(fichier, line);	
			if (line.find("--") == 0)
			{
				bool result = regex_match(line , pattern); 	
				if (result == 1) 
				{
					line.erase(line.begin()-0);
					line.erase(line.begin()-0);	
					line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();
								
					liste.push_back(line);			
				}
			}
		
		}
		
		liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();
	}	
	
	string line2 ; 
	for(int i = 0 ; i < 13 ; i++ )
	{
		line2 = liste[i];
		line2.pop_back(); 
		line2.pop_back();
		line2.pop_back();
		liste.pop_front();
		liste.push_back(line2);			
	}		
			

	return liste ;
}






/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la liste des flaws **/
deque<string> OtherTraits::flaws_list()
{
	deque<string> liste;	
 	string line;
 	regex pattern { "--.+(Merit\\))" };
 	fstream fichier("FilesTXT/file_part11.txt");
	if ( !fichier ) cout << "fichier inexistant";
	else 
	{	
		while(!fichier.eof())
		{
			getline(fichier, line);	
			if (line.find("--") == 0)
			{
				bool result = regex_match(line , pattern); 	
				if (result == 1) 
				{
					line.erase(line.begin()-0);
					line.erase(line.begin()-0);	
					line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();
								
					liste.push_back(line);			
				}
			}		
		}
		liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();liste.pop_front();
	}	
	
	string line2 ; 
	for(int i = 0 ; i < 31 ; i++ )
	{
		line2 = liste[i];
		line2.pop_back(); 
		line2.pop_back();
		liste.pop_front();
		liste.push_back(line2);
			
	}		
	return liste ;
}

