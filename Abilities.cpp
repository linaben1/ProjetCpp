#include "MiniProjet.h"


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




