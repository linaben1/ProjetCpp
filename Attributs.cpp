#include "MiniProjet.h"




/********************************************************************************************************/
void Attributes::InitialiseAttribute(string clanName)
{
	strength = 1; 
	dexterity = 1; 
	stamina = 1; 
	charisma = 1;  
	manipulation = 1; 
	if( clanName == "Nosferatu" )
		appearance = 0; 
	else
		appearance = 1; 
	perception = 1;  
	intelligence = 1; 
	wits = 1; 
	
	physical = 0;		// ordre
	social = 0; 
	mental = 0;
}

void Attributes::getPhysicalPoints(int nbPoints)
{
	physical = nbPoints;
}

void Attributes::getSocialPoints(int nbPoints)
{
	social = nbPoints;
}

void Attributes::getMentalPoints(int nbPoints)
{
	mental  = nbPoints;
}

void Attributes::distribPhysical()
{
	while(physical > 0)
	{
		int choix;
		cout << "Choisissez votre attribut : strength (1), dexterity (2), stamina (3) \n";
		cin >> choix;
		switch(choix)
		{
			case 1:
				strength++;
				break;
			case 2:
				dexterity++;
				break;
			default:
				stamina++;
		}
		physical--;
	}
}

void Attributes::distribSocial(string clanName)
{
	// a vous de remplir
}

void Attributes::distribMental()
{
	// a vous de remplir
}


