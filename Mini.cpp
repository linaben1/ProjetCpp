#include "MiniProjet.h"

/********************************************************************************************************/
void DistributionPoints::InitAdvantages()
{
	nbPointsFree = 15; 
	nbPointsExperience = 0;
}

int DistributionPoints::GetExperience(int retirePoints)
{
	nbPointsExperience = nbPointsExperience - retirePoints;
	return nbPointsExperience;
}

void DistributionPoints::setExperience(int initExp)
{
	nbPointsExperience = initExp;
}

void DistributionPoints::changeFreePoints(string type)
{
	if(type.compare("Attribute") == 0)
	{
		if(nbPointsFree > 0 && nbPointsFree - 5 >= 0)
			nbPointsFree = nbPointsFree - 5;
	}
	
	//Attribute		5 per dot
	//Ability		2 per dot
	//Discipline		7 per dot
	//Background		1 per dot
	//Virtue		2 per dot
	//Humanity 		2 per dot
	//Willpower		1 per dot
}

void DistributionPoints::changeExperrience()
{
	//New Ability:3
	//New Discipline:10
	//New Path:7
	//Attribute:CRx4
	//Ability:CRx2
	//Clan Discipline:CRx5
	//Other Discipline:CRx7
	//Secondary Path:CRx4
	//Virtue:CRx2
	//Humanity or Path of Enlightenment:CR2
	//Willpower:CR

	//	!!*CR is the current rating of the trait
}



