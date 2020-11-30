#include "Projet.h"


/****************************************************************************************************************************************************************/
/** Fonction qui permet de fixer une condition pour ensuite la vérifier afin de controller la distribution des points dans les différents catégories des abilities
 */
int Abilities::check_abilitiespointabilities(string combinaisonPoints, int talents, int skills , int knowledges  )
{		

	int condition = 0 ;
	//deque<string> results;		
	regex regex("/");
    	deque<string> results(
   sregex_token_iterator(combinaisonPoints.begin(), combinaisonPoints.end(), regex, -1),
    sregex_token_iterator());    
	string t = to_string(talents);
	string s = to_string(skills);
	string k = to_string(knowledges);
	
	if ( (t != results[0]) || (s != results[1]) || (k != results[2]))
	{	
		condition++;
	}
			
	return condition; 	
}


