#include "MiniProjet.h"






/****************************************************************************************************************************************************************/
/** Fonction qui permet de fixer une condition pour ensuite la vérifier afin de controller la distribution des points dans les différents catégories des attributs 
 */
int Attributes::check_attributspoint(const string &combinaisonPoints, int physical, int social , int mental  )
{		
	int condition = 0 ;
	//deque<string> results;		
    regex regex("/");
 
    deque<string> results(
    sregex_token_iterator(combinaisonPoints.begin(), combinaisonPoints.end(), regex, -1),
    sregex_token_iterator());    
	string p = to_string(physical);
	string s = to_string(social);
	string m = to_string(mental);
	
	if ( (p != results[0]) || (s != results[1]) || (m != results[2]))
	{
	
		condition++;
	}
			
	return condition; 	
}


