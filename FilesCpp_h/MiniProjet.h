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
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

/********************************************************************************************************/
/* Cette classe memorize et manipule les donnees sur les clans de vampire */
class Clan
{
	protected:
		string clanName;						/// Nom du clan de votre vampire, sera la liste 		
		string playername;						/// Surnom du clan (Assasins)
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
		
		string GetPlayername();
		void SetPlayername(string);
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
		int check_attributspoint(const string &combinaisonPoints, int physical, int social , int mental ); //pour tester l'attribution des points aux attributs 
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

		deque<string> background_list();
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
class Personnage : public Clan, Attributes, Abilities, OtherTraits, DistributionPoints
{
	
	
	//Nom personnage
	//Nom joueur
	//Chronicle
	//Concept
	//Generation
	//Sire 
	
};


class Fenetre : public Gtk::Window
{
    public :
 
        Fenetre();
        virtual ~Fenetre(); //Le destructeur pour pouvoir détruire le bouton.
	void on_combo_changed();
	void next_button_clicked();
	void next1_button_clicked();
	void create_button_clicked();
	void num_pages(Gtk::Widget* page, int numPage);
	void next_page() ; 
	
	
    
    protected :
    
	//Image en background    	  
  	Gtk::Image image;

    	//Les différents GRIDs 
        Gtk::Grid mainGrid, mainGrid2, mainGrid3; //Création du pointeur sur bouton.
        
        //BOX
        Gtk::VBox boxV;
        
        //Notebook Button
	 Gtk::Notebook pages;
	 
	 
	 //Notebook Button 
	Gtk::Button back, forward;
	Gtk::HButtonBox FBBoutons;

	//Button pour afficher le résultat
	Gtk::Button create_button;
	Gtk::HButtonBox VBoutons;

	
	
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
     	      
    	 //Haven 
    	 Gtk::Label haven_label, haven_location_label, haven_description_label;
    	 Gtk::Entry location_entry;
    	 Gtk::Entry description_entry;
    	 
    	  //Weakness
    	 Gtk::Label weakness_label;
    	 Gtk::Entry weakness_entry;
    	     	 
    	 //Attributs
    	 Gtk::Label attributs_label, physical_label, social_label, mental_label, strength_label, dexterity_label, stamina_label, charisma_label, manipulation_label, appearance_label, perception_label, intelligence_label, wits_label;    	 
    	 Gtk::SpinButton spin_strength, spin_dexterity, spin_stamina, spin_charisma, spin_manipulation, spin_appearance, spin_perception, spin_intelligence, spin_wits;

	//Choix combinaison des point souhaité par le joueur pour les ATTRIBUTS
	 Gtk::Label DistributionPointsAttribut_label;
	 Gtk::ComboBoxText DistributionPointsAttribut_combo;
	 
 	//Choix combinaison des point souhaité par le joueur pour les ABILITIES
	 Gtk::Label DistributionPointsAbilities_label;
	 Gtk::ComboBoxText DistributionPointsAbilities_combo;
	 
	//Abilities	
	Gtk::Label abilities_label, talents_label, alertness_label, athletics_label, awareness_label, brawl_label, empathy_label, expression_label, intimidation_label, leadership_label, streetwise_label, subterfuge_label,  skills_label, animalKen_label, crafts_label, drive_label, etiquette_label, firearms_label, larceny_label, melee_label, performance_label, stealth_label, survival_label,  knowledges_label, academics_label, computer_label, finance_label, investigation_label, law_label, medicine_label, occult_label, politics_label, science_label, technology_label;
	
	
	Gtk::SpinButton spin_abilities, spin_talents, spin_alertness, spin_athletics, spin_awareness, spin_brawl, spin_empathy, spin_expression, spin_intimidation, spin_leadership, spin_streetwise, spin_subterfuge,  spin_skills, spin_animalKen, spin_crafts, spin_drive, spin_etiquette, spin_firearms, spin_larceny, spin_melee, spin_performance, spin_stealth, spin_survival, spin_knowledges, spin_academics, spin_computer, spin_finance, spin_investigation, spin_law, spin_medicine, spin_occult, spin_politics, spin_science, spin_technology;
    	 
    	 //Advantages
    	 Gtk::Label advantages_label, background_label;
    	 
    	 
    	 //**Discipline
     	 multimap<string, string > discipl_list;
     	 Gtk::Label disciplines_label;

         Gtk::SpinButton spin_discipl1, spin_discipl2, spin_discipl3;         
         Gtk::Label discipl1_label, discipl2_label, discipl3_label;

    	 //**Background 
	 Gtk::ComboBoxText background1_combo, background2_combo, background3_combo;
	 deque<string> backgroundName_list;

    	 
    	 
    	 //**Virtues
    	
	
};



#endif //GTKMM_EXAMPLEWINDOW_H

