#include "Projet.h"

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie le nom du clan de mon personnage
 * @return clanName : Nom du clan de mon personnage */

void Clan::SetClanName(string nomClan)
{

	clanName = nomClan;
}

string Clan::GetClanName()
{
	return clanName;
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie le nom du joueur de mon personnage
 * @return playername : nom du joueur de mon personnage */

void Clan::SetPlayername(string nomPlayer)
{
	playername = nomPlayer;
}

string Clan::GetPlayername()
{
	return playername;
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie l'historique de mon personnage
 * @return background : Contexte du clan de mon personnage */

void Clan::SetBackground(string backgroundClan)
{
	background = backgroundClan;
}

string Clan::GetBackground()
{
	return background;
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la secte du clan de mon personnage
 * @return sect : secte du clan de mon personnage */

void Clan::SetSect(string sectClan)
{
	sect = sectClan;
}

string Clan::GetSect()
{
	return sect;
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie l'abris du clan
 * @return haven : abris du clan de mon personnage */

void Clan::SetHaven(string havenClan)
{
	haven = havenClan;
}

string Clan::GetHaven()
{
	return haven;
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie l'apparence physique de mon personnage 
 * @return appearance : apparence du clan de mon personnage */

void Clan::SetAppearance(string appearanceClan)
{
	appearance = appearanceClan;
}

string Clan::GetAppearance()
{
	return appearance;
}


/****************************************************************************************************************************************************************/
/** Fonction qui renvoie le characetere de mon personnage
 * @return character : character du clan de mon personnage */

void Clan::SetCharacter(string characterClan)
{
	character = characterClan;
}

string Clan::GetCharacter()
{
	return character;
}


/****************************************************************************************************************************************************************/
/** Fonction qui renvoie un tableau des nom des dsciplines choisi 
 * @return disciplines[index] : ableau de nom des disciplines choisies pour mon personnage */

string Clan::GetDisciplinesName(int index) //l'indexe des disciplines 
{
	return disciplines[index];
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie un tableau des points investits dans la disciplines choisi mon personnage
 * @return valueDisciples[index] : Tableau des points investits dans la disciplines choisi pour mon personnage */

int Clan::GetValueDisciplines(int index)
{
	return valueDisciples[index];
}

/****************************************************************************************************************************************************************/
/** Fonction qui initialise un tableau de dsiciplines avec les points initiale a 0  investits dans la disciplines choisi pour mon personnage
 */

void Clan::SetInitDisciplines(string pouvoir1, string pouvoir2, string pouvoir3)
{
	nbPointsDisciplines = 3; // nombre de points autirisé pour disciplines
	
	disciplines.push_back(pouvoir1);
	disciplines.push_back(pouvoir2);
	disciplines.push_back(pouvoir3);
	
	valueDisciples.push_back(0);
	valueDisciples.push_back(0);
	valueDisciples.push_back(0);
}

void Clan::AddValueDisciplines(int index, int value)
{
	if(nbPointsDisciplines > 0 && nbPointsDisciplines - value >= 0)
	{
		valueDisciples[index] = valueDisciples[index] + value;
		nbPointsDisciplines = nbPointsDisciplines - value;
	}
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la faiblesse de mon personnage
 * @return weakness : faiblesse de mon personnage */

void Clan::SetWeakness(string weaknessClan)
{
	weakness = weaknessClan;
}

string Clan::GetWeakness()
{
	return weakness;
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie l'organisation du clan de mon personnage
 * @return organization : organisation du de mon personnage */

void Clan::SetOrganization(string organizationClan)
{
	organization = organizationClan;
}

string Clan::GetOrganization()
{
	return organization;
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la nature du clan de mon personnage
 * @return  nature_and_demeanor : la nature de mon personnage */

void Clan::SetNature(string nat)
{
	nature = nat;
}

string Clan::GetNature()
{
	return nature;
}


/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la demeanor du clan de mon personnage
 * @return  demeanor : la nature de mon personnage */

void Clan::SetDemeanor(string dem)
{
	demeanor = dem;
}

string Clan::GetDemeanor()
{
	return demeanor;
}




/****************************************************************************************************************************************************************/
/** Fonction qui renvoie un tableau de disciplines en fonction de leur clan **/

//file_part1.txt --> fichier qui contient que des information sur les CLAN

multimap<string, string > Clan::make_table()
{

	deque<string> liste;
	multimap<string, string > liste_disciplines;
	
 	regex re("\\,");
 	string line;
	string d = "	Clan Disciplines: ";
	string line1; 

 	fstream fichier("FilesTXT/file_part1.txt");
	if ( !fichier ) cout << "fichier inexistant";
	else {	
		while(!fichier.eof())
		{
			getline(fichier, line);
	
			if (line.find(d) == 0)
			{
			
				line1 = line.substr(d.size());
				
				if (line1.size() < 50 ){				
					strtk::parse(line1, ", ", liste);				
				}
			}

			else if (line.find("--") == 0)
			{
				line.erase(line.begin()-0);
				line.erase(line.begin()-0);				
				liste.push_back(line);
			}
		}
	    }
	    
	 for (int i = 0 ; i < liste.size() ; i ++) {
	
		liste_disciplines.insert({ liste.at(0), liste.at(1) });
		liste_disciplines.insert({ liste.at(0), liste.at(2) }); 
		liste_disciplines.insert({ liste.at(0), liste.at(3) });		
		liste.pop_front();
		liste.pop_front();
		liste.pop_front();
		liste.pop_front();
 
		
	}
	
	return liste_disciplines ;
}

/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la liste des clans **/

deque<string> Clan::clan_list(){
	
	deque<string> clan_liste;
	multimap<string, string > liste_discipl = make_table() ;
	list<string> x ; 

	for(auto it = liste_discipl.begin(); it != liste_discipl.end(); it++){
		x.push_back(it->first) ;
    		}
    	
    	x.unique();
	for (auto val : x)
    		clan_liste.push_back(val);

	return clan_liste;
}


/****************************************************************************************************************************************************************/
/** Fonction qui renvoie la liste de nature & demeanor **/

deque<string> Clan::nature_list()
{	
	deque<string> liste_nature;	
 	string line2;
 	fstream fichier("FilesTXT/file_part2.txt");
	if ( !fichier ) cout << "fichier inexistant";
	else {	
		while(!fichier.eof())
		{
			getline(fichier, line2);	
			if (line2.find("--") == 0)
			{
				line2.erase(line2.begin()-0);
				line2.erase(line2.begin()-0);				
				liste_nature.push_back(line2);
			}
		}
	    }	    
	return liste_nature;
	
}
	
	






