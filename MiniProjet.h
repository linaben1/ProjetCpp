#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <iostream> 
#include <stdio.h>
#include <regex>
#include <fstream>
#include <cstddef>
#include <string>
#include <iterator>
#include <utility>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <functional>
#include "strtk.hpp"
#include <gtkmm.h>
#include <iostream>
#include <cairomm/context.h>
#include <giomm/resource.h>
#include <gdkmm/general.h>
#include <glibmm/fileutils.h>
using namespace std;

/********************************************************************************************************/
/* Cette classe memorize et manipule les donnees sur les clans de vampire */
class Clan
{
	protected:
		string clanName;						/// Nom du clan de votre vampire, sera la liste 		
		string nickname;						/// Surnom du clan (Assasins)
		string background;						/// Passe commun des membres de votre clan
		string sect;							/// Secte a laquelle les vampires de votre clan appartient habituellement	
		string haven;							///
		string appearance;						///
		string character;
		int nbPointsDisciplines;					/// Nombre de points a distribuer dans les disciples
		vector <string> disciplines;					/// Tableau de nom des disciplines choisies, unique a chaque clan 
		vector <int> valueDisciples;					/// Tableau des points investits dans la disciplines choisi
		string weakness; 
		string organization;
		
		string nature_and_demeanor; 
		
	public:
	
		string GetClanName();
		void SetClanName(string);
		
		string GetNickname();
		void SetNickname(string);
		string GetBackground();
		void SetBackground(string);
		string GetSect();
		void SetSect(string);
		string GetHaven();
		void SetHaven(string);
		string GetAppearance();
		void SetAppearance(string);
		string GetCharacter();
		void SetCharacter(string);
		string GetDisciplinesName(int);
		int GetValueDisciplines(int);
		void SetInitDisciplines(string, string, string);
		void AddValueDisciplines(int, int);
		string GetWeakness();
		void SetWeakness(string);
		string GetOrganization();
		void SetOrganization(string);
		
		string GetNature_and_Demeanor();
		void SetNature_and_Demeanor(string);
		
		multimap<string, string > make_table(void); //fonction pour récupérer un tableau des disciplines associé a chaque clan
		deque<string> clan_list(void);//fonction qui récupere la liste des clan
		deque<string> nature_list(void);	//fonction qui récupere la liste des natures
		
};


/********************************************************************************************************/
/* Cette classe memorize et manipule les donnees des attributes*/
class Attributes
{
	protected:
		int physical, social, mental;
		
		int strength, dexterity, stamina;
		int charisma, manipulation, appearance;
		int perception, intelligence, wits;
		
	public:
		void InitialiseAttribute(string);
		void getPhysicalPoints(int);
		void getSocialPoints(int);
		void getMentalPoints(int);
		
		void distribPhysical();
		void distribSocial(string);	// attention a l'apparence
		void distribMental();
};





/********************************************************************************************************/
class DistributionPoints
{
	protected:
		int nbPointsFree;
		int nbPointsExperience;
		
	public:
		void InitAdvantages();
		int GetExperience(int);
		void setExperience(int);
		void changeFreePoints(string);
		void changeExperrience();
};


/********************************************************************************************************/
class OtherTraits
{
	protected:
		
		int nbPointsBackground;
		vector <string> backgroundName;
		vector <int> backgroundPoints;
		
		int nbPointsVirtues;
		int conscience;
		int selfControl;
		int courage;
		
		int humanity; 	// (equal to Conscience + Self-Control), 
		int willpower; 	//(equal to Courage)
		int bloodPool;
		
		int nbPointsMeritsAndFlawsMAX;
		int nbPointsMeritsAndFlaws;
		vector <string> meritsAndFlaws;
		vector <int> valueMeritsAndFlaws;

	public:
		void InitTraits();
		void SetBackground(string, int);
		void setVirtuesPoints(string, int);
		int getVirtuesPoints();
		int getConsience();
		int getSelfControl();
		int getCourage();
		void setHumanity();
		void setWillPower();
};





/********************************************************************************************************/
class Abilities
{
	protected:
		int talents;
		int skills;
		int knowledges;
		int maxInitAbilities;
		
		int tabTalent[11];			/// remplace la liste des 11 talents
		int tabSkills[11];
		int tabKnowledges[11];
		
	public:
		void InitialiseAbilities();
		void getTalentPoints(int);
		void getSkillsPoints(int);
		void getKnowledgesPoints(int);
		void setTalent(int, int);
		int getValueTalent(int);
		void setSkills(int, int);
		int getValueSkills(int);
		void setKnowledges(int, int);
		int getValueKnowledges(int);
};




/********************************************************************************************************/
class Personnage : public Clan, Attributes, Abilities, OtherTraits, DistributionPoints
{
	
};


class Fenetre : public Gtk::Window {
    public :
    	Gtk::Window window;
        Fenetre();
        virtual ~Fenetre(); //Le destructeur pour pouvoir détruire le bouton.
	void on_combo_changed();
	void next_button_clicked();
    
    
    protected :
         Gtk::Grid mainGrid; //Création du pointeur sur bouton.
        
	//Clan
	 Gtk::Label clanName_label;	 
	 Gtk::ComboBoxText Clan_combo;
	 deque<string> clanName_list;
	 
	 //Nature & Demeanor
	 Gtk::Label natureName_label;
	 Gtk::ComboBoxText nature_combo;
	 deque<string> nature_demeanorName_list;
	 
	 Gtk::Label demeanorName_label;
	 Gtk::ComboBoxText demeanor_combo;
	 
	 //Nom du personnage
	 Gtk::Label name_label;
         Gtk::Entry name_entry;
         
         //Nom du joueur
         Gtk::Label player_label;
         Gtk::Entry player_entry;
         
         //Chronicle
         Gtk::Label chronicle_label;
         Gtk::Entry chronicle_entry;
         
         //Concept(la vie au passée, ex : fille de marchand)
         Gtk::Label concept_label;
         Gtk::Entry concept_entry;
     
          //Sire (le sire du personnage)
         Gtk::Label sire_label;
         Gtk::Entry sire_entry;
     	  
     
     	  //Discipline
     	 multimap<string, string > discipl_list;
     	 Gtk::Label disciplines_label;
         Gtk::SpinButton spin_discipl1;
         Gtk::SpinButton spin_discipl2;
         Gtk::SpinButton spin_discipl3;
         Gtk::Label discipl1_label;
         Gtk::Label discipl2_label;
         Gtk::Label discipl3_label;
    
    	 //Haven 
    	 Gtk::Label haven_label;
    	 Gtk::Label haven_location_label;
    	 Gtk::Entry location_entry;
    	 Gtk::Label haven_description_label;
    	 Gtk::Entry description_entry;
    	 
    	  //Weakness
    	 Gtk::Label weakness_label;
    	 Gtk::Entry weakness_entry;
    	 
    	 
    	 //Attributs
    	 Gtk::Label attributs_label;
    	 Gtk::Label physical_label;
    	 Gtk::Label social_label;
    	 Gtk::Label mental_label;
    	 Gtk::Label strength_label;
    	 Gtk::Label dexterity_label;
    	 Gtk::Label stamina_label;
    	 Gtk::Label charisma_label;
    	 Gtk::Label manipulation_label;
    	 Gtk::Label appearance_label;
    	 Gtk::Label perception_label;
    	 Gtk::Label intelligence_label;
    	 Gtk::Label wits_label;
    	 Gtk::SpinButton spin_strength;
    	 Gtk::SpinButton spin_dexterity;
    	 Gtk::SpinButton spin_stamina;
    	 Gtk::SpinButton spin_charisma;
    	 Gtk::SpinButton spin_manipulation;
    	 Gtk::SpinButton spin_appearance;
    	 Gtk::SpinButton spin_perception;
    	 Gtk::SpinButton spin_intelligence;
    	 Gtk::SpinButton spin_wits;

	//Choix combinaison des point souhaité par le joueur pour les ATTRIBUTS
	 Gtk::Label DistributionPointsAttribut_label;
	 Gtk::ComboBoxText DistributionPointsAttribut_combo;

	//Button
	Gtk::Button next_button;





};



#endif //GTKMM_EXAMPLEWINDOW_H

