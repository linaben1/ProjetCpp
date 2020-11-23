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





/********************************************************************************************************/
void Abilities::InitialiseAbilities()
{
	maxInitAbilities = 3;
	talents = 0;
	skills = 0;
	knowledges = 0;

	for(int i=0; i<11; i++)
		tabTalent[i] = 0;			
	for(int i=0; i<11; i++)
		tabSkills[11] = 0;
	for(int i=0; i<11; i++)
		tabKnowledges[11] = 0;
}

void Abilities::getTalentPoints(int nbPoints)
{
	talents = nbPoints;
}

void Abilities::getSkillsPoints(int nbPoints)
{
	skills = nbPoints;
}

void Abilities::getKnowledgesPoints(int nbPoints)
{
	knowledges  = nbPoints;
}

void Abilities::setTalent(int index, int value)
{
	if(talents > 0 && talents - value >= 0)
	{
		tabTalent[index] = tabTalent[index] + value;
		talents = talents - value;
	}
}

int Abilities::getValueTalent(int index)
{
	return tabTalent[index];
}

void Abilities::setSkills(int index, int value)
{
}

int Abilities::getValueSkills(int index)
{
	return tabSkills[index];
}

void Abilities::setKnowledges(int index, int value)
{
}

int Abilities::getValueKnowledges(int index)
{
	return tabKnowledges[index];
}




