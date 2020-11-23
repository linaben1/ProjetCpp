#include "MiniProjet.h"

Clan clan;

/****************************************************************************************************************************************************************/
/****************************************************************************************************************************************************************/
/****************************************************************************************************************************************************************/

Fenetre::Fenetre()
{

	window.set_title("Vampire Interface");
	window.set_border_width(10);
	window.set_position(Gtk::WIN_POS_CENTER);
	window.resize(1000, 1000); 
	
	//Label du nom du personnage
	name_label.set_text("  Name:  ");
 	mainGrid.attach(name_label, 0, 0, 1, 1);	
   	name_entry.set_max_length(50);
    	mainGrid.attach(name_entry, 1, 0, 1, 1);
    	
	//Label pour le nom du joueur 				
   	player_label.set_text("  Player:  ");
 	mainGrid.attach(player_label, 0, 1, 1, 1);
   	player_entry.set_max_length(50);
    	mainGrid.attach(player_entry, 1, 1, 1, 1);
    	
    	//Chronicle 
    	chronicle_label.set_text("  Chronicle:  ");
 	mainGrid.attach(chronicle_label, 0, 2, 1, 1);
   	chronicle_entry.set_max_length(50);
    	mainGrid.attach(chronicle_entry, 1, 2, 1, 1);   	
    	
    	//Concept
    	concept_label.set_text("  Concept:  ");
 	mainGrid.attach(concept_label, 2, 2, 1, 1);
   	concept_entry.set_max_length(50);
    	mainGrid.attach(concept_entry, 3, 2, 1, 1);  	
    	
    	//Sire
    	sire_label.set_text("  Sire:  ");
 	mainGrid.attach(sire_label, 4, 2, 1, 1);
   	sire_entry.set_max_length(50);
    	mainGrid.attach(sire_entry, 5, 2, 1, 1);   	
	
	//Le clan 	
	clanName_label.set_text("  Clan:  ");
        mainGrid.attach(clanName_label, 4 , 0, 1, 1);
	clanName_list = clan.clan_list();
	for(int i=0; i<clanName_list.size(); ++i)	
		Clan_combo.append(clanName_list[i]);		
	Clan_combo.signal_changed().connect(sigc::mem_fun(*this,
              &Fenetre::on_combo_changed) );

	mainGrid.attach(Clan_combo, 5, 0, 1, 1);
	 
	 //Nature & Denameor
	natureName_label.set_text("  Nature:  ");
        mainGrid.attach(natureName_label, 2, 0, 1, 1);
        demeanorName_label.set_text("  Demeanor:  ");
        mainGrid.attach(demeanorName_label, 2, 1, 1, 1);
        
        nature_demeanorName_list = clan.nature_list();        
        for(auto i=0; i<nature_demeanorName_list.size(); ++i)
        {	
		nature_combo.append(nature_demeanorName_list[i]);
		demeanor_combo.append(nature_demeanorName_list[i]);
	}		
    	mainGrid.attach(nature_combo, 3, 0, 1, 1);
    	mainGrid.attach(demeanor_combo, 3, 1, 1, 1);
    	
    	//Choix de la combinaison de points pour les différents catégories d'attributs	
 	DistributionPointsAttribut_label.set_text(" Choisissez la combinaison pour les points d'attributs ( PHYSICAL, SOCIAL, MENTAL ) : ");
        mainGrid.attach(DistributionPointsAttribut_label, 0 , 3, 2, 1);
	
	DistributionPointsAttribut_combo.append("7/5/3");
	DistributionPointsAttribut_combo.append("7/3/5");
	DistributionPointsAttribut_combo.append("3/7/5");
	DistributionPointsAttribut_combo.append("3/5/7");
	DistributionPointsAttribut_combo.append("5/3/7");
	DistributionPointsAttribut_combo.append("5/7/3");
	
	mainGrid.attach(DistributionPointsAttribut_combo, 2 , 3, 1, 1);
	
	 //Button pour valider le choix souhaité de la combinaison des points des attributs et d'abilities et pour passer a la suite du formulaire
        next_button.signal_clicked().connect( sigc::mem_fun(*this,
            &Fenetre::next_button_clicked) );
    	mainGrid.attach(next_button,6 , 22, 1, 1);
   	next_button.add_label("next"); 
   	 	 	
   	
  	//Attributs
   	attributs_label.set_text("#########  ATTRIBUTS  #########");   
     	attributs_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid.attach(attributs_label, 3, 4, 1,1);
     	
     	physical_label.set_text("  ** PHYSICAL **  ");     		
     	mainGrid.attach(physical_label, 1, 5, 1, 1);
     	
     	social_label.set_text("  ** SOCIAL **  ");     		
     	mainGrid.attach(social_label, 3, 5, 1, 1);
     	
     	mental_label.set_text("  ** MENTAL **  ");     		
     	mainGrid.attach(mental_label, 5, 5, 1, 1);

	//Attributs physique
     	strength_label.set_text(" Strength ");     		
     	mainGrid.attach(strength_label, 0, 6, 1,1);    	
     	spin_strength.set_range(1,5);
	spin_strength.set_increments(1,1);
     	   
  	dexterity_label.set_text(" Dexterity ");     		
     	mainGrid.attach(dexterity_label, 0, 7, 1,1);    	
    	spin_dexterity.set_range(1,5);
	spin_dexterity.set_increments(1,1);     	     	
   	
    	stamina_label.set_text(" Stamina ");     		
     	mainGrid.attach(stamina_label, 0, 8, 1,1);     	
     	spin_stamina.set_range(1,5);
	spin_stamina.set_increments(1,1);	  

     	//Attributs social
     	charisma_label.set_text(" Charisma ");     		
     	mainGrid.attach(charisma_label, 2, 6, 1,1);    	
     	spin_charisma.set_range(1,5);
	spin_charisma.set_increments(1,1);	 

     	manipulation_label.set_text(" Manipulation ");     		
     	mainGrid.attach(manipulation_label, 2, 7, 1,1);     	
     	spin_manipulation.set_range(1,5);
	spin_manipulation.set_increments(1,1);
	  
	mainGrid.attach(appearance_label, 2, 8, 1,1);     	 	   
 	mainGrid.attach(spin_appearance, 3, 8, 1, 1);     	

     	//Attributs Mental
     	perception_label.set_text(" Perception ");     		
     	mainGrid.attach(perception_label, 4, 6, 1,1);     	
     	spin_perception.set_range(1,5);
	spin_perception.set_increments(1,1);
	 
     	intelligence_label.set_text(" Intelligence ");     		
     	mainGrid.attach(intelligence_label, 4, 7, 1,1);
     	spin_intelligence.set_range(1,5);
	spin_intelligence.set_increments(1,1);
     	 
     	wits_label.set_text(" Wits ");     		
     	mainGrid.attach(wits_label, 4, 8, 1,1);     	
     	spin_wits.set_range(1,5);
	spin_wits.set_increments(1,1);
	   	
     	mainGrid.attach(spin_strength, 1, 6, 1, 1);  
     	mainGrid.attach(spin_charisma, 3, 6, 1, 1); 
     	mainGrid.attach(spin_perception, 5, 6, 1, 1); 
     	mainGrid.attach(spin_dexterity, 1, 7, 1, 1);  
     	mainGrid.attach(spin_manipulation, 3, 7, 1, 1);
     	mainGrid.attach(spin_intelligence, 5, 7, 1, 1); 
     	mainGrid.attach(spin_stamina, 1, 8, 1, 1);
     	mainGrid.attach(spin_wits, 5, 8, 1, 1); 
     	
  	//Choix de la combinaison de points pour les différents catégories d'abilities
	DistributionPointsAbilities_label.set_text(" Choisissez la combinaison pour les points d'abilities ( TALENTS, SKILLS, KNOWLEDGES ) : ");
        mainGrid.attach(DistributionPointsAbilities_label, 0 , 9, 2, 1);
	
	DistributionPointsAbilities_combo.append("13/9/5");
	DistributionPointsAbilities_combo.append("13/5/9");
	DistributionPointsAbilities_combo.append("9/5/13");
	DistributionPointsAbilities_combo.append("9/13/5");
	DistributionPointsAbilities_combo.append("5/9/13");
	DistributionPointsAbilities_combo.append("5/13/9");
	
	mainGrid.attach(DistributionPointsAbilities_combo, 2 , 9, 1, 1);
					
	//Abilities
   	abilities_label.set_text("#########  ABILITIES  #########");   
     	abilities_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid.attach(abilities_label, 3, 10, 1,1);
     	
     	talents_label.set_text("  ** TALENTS **  ");     		
     	mainGrid.attach(talents_label, 1, 11, 1, 1);
     	
     	skills_label.set_text("  ** SKILLS **  ");     		
     	mainGrid.attach(skills_label, 3, 11, 1, 1);
     	
     	knowledges_label.set_text("  ** KNOWLEDGES **  ");     		
     	mainGrid.attach(knowledges_label, 5, 11, 1, 1);

	//Talents abilities
     	alertness_label.set_text(" Alertness ");     		
     	mainGrid.attach(alertness_label, 0, 12, 1,1);    	
     	spin_alertness.set_range(1,5);
	spin_alertness.set_increments(1,1);
     	    
  	athletics_label.set_text(" Athletics ");     		
     	mainGrid.attach(athletics_label, 0, 13, 1,1);    	
    	spin_athletics.set_range(1,5);
	spin_athletics.set_increments(1,1);
     	     	  	
    	awareness_label.set_text(" Awareness ");     		
     	mainGrid.attach(awareness_label, 0, 14, 1,1);     	
     	spin_awareness.set_range(1,5);
	spin_awareness.set_increments(1,1);
	
	brawl_label.set_text(" Brawl ");     		
     	mainGrid.attach(brawl_label, 0, 15, 1,1);    	
     	spin_brawl.set_range(1,5);
	spin_brawl.set_increments(1,1);
     	   
  	empathy_label.set_text(" Empathy ");     		
     	mainGrid.attach(empathy_label, 0, 16, 1,1);    	
    	spin_empathy.set_range(1,5);
	spin_empathy.set_increments(1,1);
     	     	  	
    	expression_label.set_text(" Expression ");     		
     	mainGrid.attach(expression_label, 0, 17, 1,1);     	
     	spin_expression.set_range(1,5);
	spin_expression.set_increments(1,1);
	
	intimidation_label.set_text(" Intimidation ");     		
     	mainGrid.attach(intimidation_label, 0, 18, 1,1);    	
     	spin_intimidation.set_range(1,5);
	spin_intimidation.set_increments(1,1);
     	  
  	leadership_label.set_text(" Leadership ");     		
     	mainGrid.attach(leadership_label, 0, 19, 1,1);    	
    	spin_leadership.set_range(1,5);
	spin_leadership.set_increments(1,1);
     	     	   	
    	streetwise_label.set_text(" Streetwise ");     		
     	mainGrid.attach(streetwise_label, 0, 20, 1,1);     	
     	spin_streetwise.set_range(1,5);
	spin_streetwise.set_increments(1,1);
	
	subterfuge_label.set_text(" Subterfuge ");     		
     	mainGrid.attach(subterfuge_label, 0, 21, 1,1);     	
     	spin_subterfuge.set_range(1,5);
	spin_subterfuge.set_increments(1,1);
	  
     	//Skills abilities
     	animalKen_label.set_text(" Animal Ken ");     		
     	mainGrid.attach(animalKen_label, 2, 12, 1,1);    	
     	spin_animalKen.set_range(1,5);
	spin_animalKen.set_increments(1,1);
	 
     	crafts_label.set_text(" Crafts ");     		
     	mainGrid.attach(crafts_label, 2, 13, 1,1);     	
     	spin_crafts.set_range(1,5);
	spin_crafts.set_increments(1,1);
	
	drive_label.set_text(" Drive ");     		
     	mainGrid.attach(drive_label, 2, 14, 1,1);     	
     	spin_drive.set_range(1,5);
	spin_drive.set_increments(1,1);
	  
	etiquette_label.set_text(" Etiquette ");     		
     	mainGrid.attach(etiquette_label, 2, 15, 1,1);     	
     	spin_etiquette.set_range(1,5);
	spin_etiquette.set_increments(1,1);

 	firearms_label.set_text(" Firearms ");     		
     	mainGrid.attach(firearms_label, 2, 16, 1,1);     	
     	spin_firearms.set_range(1,5);
	spin_firearms.set_increments(1,1);
     	
     	larceny_label.set_text(" Larceny ");     		
     	mainGrid.attach(larceny_label, 2, 17, 1,1);     	
     	spin_larceny.set_range(1,5);
	spin_larceny.set_increments(1,1);
	
	melee_label.set_text(" Melee ");     		
     	mainGrid.attach(melee_label, 2, 18, 1,1);     	
     	spin_melee.set_range(1,5);
	spin_melee.set_increments(1,1);
	
	performance_label.set_text(" Performance ");     		
     	mainGrid.attach(performance_label, 2, 19, 1,1);     	
     	spin_performance.set_range(1,5);
	spin_performance.set_increments(1,1);
	
	stealth_label.set_text(" Stealth ");     		
     	mainGrid.attach(stealth_label, 2, 20, 1,1);     	
     	spin_stealth.set_range(1,5);
	spin_stealth.set_increments(1,1);
	
	survival_label.set_text(" Survival ");     		
     	mainGrid.attach(survival_label, 2, 21, 1,1);     	
     	spin_survival.set_range(1,5);
	spin_survival.set_increments(1,1);
	
     	//Knowledges abilities
     	academics_label.set_text(" Academics ");     		
     	mainGrid.attach(academics_label, 4, 12, 1,1);     	
     	spin_academics.set_range(1,5);
	spin_academics.set_increments(1,1);
	 
     	computer_label.set_text(" Computer ");     		
     	mainGrid.attach(computer_label, 4, 13, 1,1);
     	spin_computer.set_range(1,5);
	spin_computer.set_increments(1,1);
     	 
     	finance_label.set_text(" Finance ");     		
     	mainGrid.attach(finance_label, 4, 14, 1,1);     	
     	spin_finance.set_range(1,5);
	spin_finance.set_increments(1,1);
	
	investigation_label.set_text(" Investigation ");     		
     	mainGrid.attach(investigation_label, 4, 15, 1,1);     	
     	spin_investigation.set_range(1,5);
	spin_investigation.set_increments(1,1);
	 
     	law_label.set_text(" Law ");     		
     	mainGrid.attach(law_label, 4, 16, 1,1);
     	spin_law.set_range(1,5);
	spin_law.set_increments(1,1);
     	 
     	medicine_label.set_text(" Medicine ");     		
     	mainGrid.attach(medicine_label, 4, 17, 1,1);     	
     	spin_medicine.set_range(1,5);
	spin_medicine.set_increments(1,1);
	 
	occult_label.set_text(" Occult ");     		
     	mainGrid.attach(occult_label, 4, 18, 1,1);     	
     	spin_occult.set_range(1,5);
	spin_occult.set_increments(1,1);
	 
     	politics_label.set_text(" Politics ");     		
     	mainGrid.attach(politics_label, 4, 19, 1,1);
     	spin_politics.set_range(1,5);
	spin_politics.set_increments(1,1);
     	 
     	science_label.set_text(" Science ");     		
     	mainGrid.attach(science_label, 4, 20, 1,1);     	
     	spin_science.set_range(1,5);
	spin_science.set_increments(1,1);
	
	technology_label.set_text(" Technology ");     		
     	mainGrid.attach(technology_label, 4, 21, 1,1);     	
     	spin_technology.set_range(1,5);
	spin_technology.set_increments(1,1);
   	
   	//Talents spinButton
     	mainGrid.attach(spin_alertness, 1, 12, 1, 1);  
     	mainGrid.attach(spin_athletics, 1, 13, 1, 1); 
     	mainGrid.attach(spin_awareness, 1, 14, 1, 1); 
     	mainGrid.attach(spin_brawl, 1, 15, 1, 1);  
     	mainGrid.attach(spin_empathy, 1, 16, 1, 1);
     	mainGrid.attach(spin_expression, 1, 17, 1, 1); 
     	mainGrid.attach(spin_intimidation, 1, 18, 1, 1);
     	mainGrid.attach(spin_leadership, 1, 19, 1, 1); 
     	mainGrid.attach(spin_streetwise, 1, 20, 1, 1);  
     	mainGrid.attach(spin_subterfuge, 1, 21, 1, 1); 
     	//Skills spinButton
     	mainGrid.attach(spin_animalKen, 3, 12, 1, 1); 
     	mainGrid.attach(spin_crafts, 3, 13, 1, 1);  
     	mainGrid.attach(spin_drive, 3, 14, 1, 1);
     	mainGrid.attach(spin_etiquette, 3, 15, 1, 1); 
     	mainGrid.attach(spin_firearms, 3, 16, 1, 1);
     	mainGrid.attach(spin_larceny, 3, 17, 1, 1);
     	mainGrid.attach(spin_melee, 3, 18, 1, 1);  
     	mainGrid.attach(spin_performance, 3, 19, 1, 1); 
     	mainGrid.attach(spin_stealth, 3, 20, 1, 1); 
     	mainGrid.attach(spin_survival, 3, 21, 1, 1);  
     	//knowlodges spin Button
     	mainGrid.attach(spin_academics, 5, 12, 1, 1);
     	mainGrid.attach(spin_computer, 5, 13, 1, 1); 
     	mainGrid.attach(spin_finance, 5, 14, 1, 1);
     	mainGrid.attach(spin_investigation, 5, 15, 1, 1);  
     	mainGrid.attach(spin_law, 5, 16, 1, 1);  
     	mainGrid.attach(spin_medicine, 5, 17, 1, 1); 
     	mainGrid.attach(spin_occult, 5, 18, 1, 1); 
     	mainGrid.attach(spin_politics, 5, 19, 1, 1);  
     	mainGrid.attach(spin_science, 5, 20, 1, 1);
     	mainGrid.attach(spin_technology, 5, 21, 1, 1);  
	
	mainGrid.show_all();
	window.add(mainGrid);
	window.show_all_children();
}

Fenetre::~Fenetre() 
{

}

void Fenetre::on_combo_changed()
{

	string text_clanname = Clan_combo.get_active_text();
	discipl_list = clan.make_table();	
	deque<string> liste_discip;
	
	//On détermine ici les disciplines associer au clan que l'utilisateur aura choisi 
	for (auto it = discipl_list.begin(); it!= discipl_list.end(); ++it)
	{
		string text2 = it->first ; 
		if (text_clanname == text2)
		{
			liste_discip.push_back(it->second);
						
		}
 	} 	
 	discipl1_label.set_text("  " + liste_discip[0] + ":  ");
 	discipl2_label.set_text("  " + liste_discip[1] + ":  ");
 	discipl3_label.set_text("  " + liste_discip[2] + ":  ");
 	
 	 if ( text_clanname != "Nosferatu")
 	{	
 		appearance_label.set_text(" Appearance ");     		 	 	
   	  	spin_appearance.set_range(1,5);
		spin_appearance.set_increments(1,1);
 			
 	}
 	else 	
 	{  	
 		appearance_label.set_text(" Appearance ");     		 	 	
   	  	spin_appearance.set_range(0,0);
		spin_appearance.set_increments(1,1);
  		
 	}
    		
}
 

void Fenetre::next_button_clicked()
{	

	//Récuperer la combinaison d'attribution de points choisi pour les différentes catégories d'abilities & d'attributs.
	string text_pointabilities = DistributionPointsAbilities_combo.get_active_text();
	string text_pointattributs = DistributionPointsAttribut_combo.get_active_text();


	if(text_pointabilities == "" || text_pointattributs == "" )
	{			
 		Gtk::MessageDialog dialog(*this, "Veuillez choisir une combinaison de points souhaité pour les abilities & les attributs avant de passer à la suite !",false,Gtk::MESSAGE_ERROR);
		dialog.run();	 
	}
		
	else
	{		
   	window.show_all_children();   		
	next_button.hide();  
	
	}
}



/*

void button validé {

	// Gérer les distribution de points pour les attributs
	
	string text_pointattributs = DistributionPointsAttribut_combo.get_active_text();
	string text_clanname = Clan_combo.get_active_text();
	
	//Le cas ou la distribution choisi par l'utilisateur est 7/5/3
	if (text_pointattributs == "7/5/3")
	{	
		int score_physical = 7 , score_social = 5 , score_mental = 3 ;
		
		//Récupération des points attribué au caractere physique
		int score_strength = spin_strength.get_value_as_int() , score_dexterity = spin_dexterity.get_value_as_int() , score_stamina = spin_stamina.get_value_as_int();
		int score_physical_total = score_strength + score_dexterity + score_stamina  ; 
				
		//Récupération des points attribué au caractere social
		int score_charisma = spin_charisma.get_value_as_int() , score_manipulation = spin_manipulation.get_value_as_int() , score_appearance = spin_appearance.get_value_as_int();
		int score_social_total = score_charisma + score_manipulation + score_appearance  ; 
    	  
     		if ( text_clanname != "Nosferatu")
 		{	
 			int score_social_total = score_charisma + score_manipulation + score_appearance  ; 	
 		}
 		else 	
 		{  	
			int score_social_total = score_charisma + score_manipulation  ;			  		
 		}
   
  		//Récupération des points attribué au caractere mental
		int score_perception = spin_perception.get_value_as_int() , score_intelligence = spin_intelligence.get_value_as_int() , score_wits = spin_wits.get_value_as_int();
		int score_mental_total = score_perception + score_intelligence + score_wits  ; 				
 		if ( (score_physical_total != 7) || (score_social_total != 5) || (score_mental_total != 3))
 		{		
 			Gtk::MessageDialog dialog(*this, "Le nombre des points totaux de PHYSICAL, SOCIAL et MENTAL doivent être égaux à 7, 5, 3 respectivement !",false,Gtk::MESSAGE_ERROR);
			dialog.run();	
 		} 
 	
	}
	
	//Le cas ou la distribution choisi par l'utilisateur est 7/5/3
	else if (text_pointattributs == "7/3/5")
	{	
		int score_physical = 7 , score_social = 3 , score_mental = 5 ;
		
		//Récupération des points attribué au caractere physique
		int score_strength = spin_strength.get_value_as_int() , score_dexterity = spin_dexterity.get_value_as_int() , score_stamina = spin_stamina.get_value_as_int();
		int score_physical_total = score_strength + score_dexterity + score_stamina  ; 
				
		//Récupération des points attribué au caractere social
		int score_charisma = spin_charisma.get_value_as_int() , score_manipulation = spin_manipulation.get_value_as_int() , score_appearance = spin_appearance.get_value_as_int();
		int score_social_total = score_charisma + score_manipulation + score_appearance  ; 
    	  
     		if ( text_clanname != "Nosferatu")
 		{	
 			int score_social_total = score_charisma + score_manipulation + score_appearance  ; 	
 		}
 		else 	
 		{  	
			int score_social_total = score_charisma + score_manipulation  ;			  		
 		}
   
  		//Récupération des points attribué au caractere mental
		int score_perception = spin_perception.get_value_as_int() , score_intelligence = spin_intelligence.get_value_as_int() , score_wits = spin_wits.get_value_as_int();
		int score_mental_total = score_perception + score_intelligence + score_wits  ; 				
 		if ( (score_physical_total != 7) || (score_social_total != 3) || (score_mental_total != 5))
 		{		
 			Gtk::MessageDialog dialog(*this, "Le nombre des points totaux de PHYSICAL, SOCIAL et MENTAL doivent être égaux à 7, 3, 5 respectivement !",false,Gtk::MESSAGE_ERROR);
			dialog.run();	
 		} 
 	
	}
	
	
	//Le cas ou la distribution choisi par l'utilisateur est 3/7/5
	else if (text_pointattributs == "3/7/5")
	{	
		int score_physical = 3 , score_social = 7 , score_mental = 5 ;
		
		//Récupération des points attribué au caractere physique
		int score_strength = spin_strength.get_value_as_int() , score_dexterity = spin_dexterity.get_value_as_int() , score_stamina = spin_stamina.get_value_as_int();
		int score_physical_total = score_strength + score_dexterity + score_stamina  ; 
				
		//Récupération des points attribué au caractere social
		int score_charisma = spin_charisma.get_value_as_int() , score_manipulation = spin_manipulation.get_value_as_int() , score_appearance = spin_appearance.get_value_as_int();
		int score_social_total = score_charisma + score_manipulation + score_appearance  ; 
    	  
     		if ( text_clanname != "Nosferatu")
 		{	
 			int score_social_total = score_charisma + score_manipulation + score_appearance  ; 	
 		}
 		else 	
 		{  	
			int score_social_total = score_charisma + score_manipulation  ;			  		
 		}
   
  		//Récupération des points attribué au caractere mental
		int score_perception = spin_perception.get_value_as_int() , score_intelligence = spin_intelligence.get_value_as_int() , score_wits = spin_wits.get_value_as_int();
		int score_mental_total = score_perception + score_intelligence + score_wits  ; 				
 		if ( (score_physical_total != 3) || (score_social_total != 7) || (score_mental_total != 5))
 		{		
 			Gtk::MessageDialog dialog(*this, "Le nombre des points totaux de PHYSICAL, SOCIAL et MENTAL doivent être égaux à 3, 7, 5 respectivement !",false,Gtk::MESSAGE_ERROR);
			dialog.run();	
 		} 
 	
	}
	
	//Le cas ou la distribution choisi par l'utilisateur est 3/5/7
	else if (text_pointattributs == "3/5/7")
	{	
		int score_physical = 3 , score_social = 5 , score_mental = 7 ;
		
		//Récupération des points attribué au caractere physique
		int score_strength = spin_strength.get_value_as_int() , score_dexterity = spin_dexterity.get_value_as_int() , score_stamina = spin_stamina.get_value_as_int();
		int score_physical_total = score_strength + score_dexterity + score_stamina  ; 
				
		//Récupération des points attribué au caractere social
		int score_charisma = spin_charisma.get_value_as_int() , score_manipulation = spin_manipulation.get_value_as_int() , score_appearance = spin_appearance.get_value_as_int();
		int score_social_total = score_charisma + score_manipulation + score_appearance  ; 
    	  
     		if ( text_clanname != "Nosferatu")
 		{	
 			int score_social_total = score_charisma + score_manipulation + score_appearance  ; 	
 		}
 		else 	
 		{  	
			int score_social_total = score_charisma + score_manipulation  ;			  		
 		}
   
  		//Récupération des points attribué au caractere mental
		int score_perception = spin_perception.get_value_as_int() , score_intelligence = spin_intelligence.get_value_as_int() , score_wits = spin_wits.get_value_as_int();
		int score_mental_total = score_perception + score_intelligence + score_wits  ; 				
 		if ( (score_physical_total != 3) || (score_social_total != 5) || (score_mental_total != 7))
 		{		
 			Gtk::MessageDialog dialog(*this, "Le nombre des points totaux de PHYSICAL, SOCIAL et MENTAL doivent être égaux à 3, 5, 7 respectivement !",false,Gtk::MESSAGE_ERROR);
			dialog.run();	
 		} 
	}


	//Le cas ou la distribution choisi par l'utilisateur est 5/3/7
	else if (text_pointattributs == "5/3/7")
	{	
		int score_physical = 5 , score_social = 3 , score_mental = 7 ;
		
		//Récupération des points attribué au caractere physique
		int score_strength = spin_strength.get_value_as_int() , score_dexterity = spin_dexterity.get_value_as_int() , score_stamina = spin_stamina.get_value_as_int();
		int score_physical_total = score_strength + score_dexterity + score_stamina  ; 
				
		//Récupération des points attribué au caractere social
		int score_charisma = spin_charisma.get_value_as_int() , score_manipulation = spin_manipulation.get_value_as_int() , score_appearance = spin_appearance.get_value_as_int();
		int score_social_total = score_charisma + score_manipulation + score_appearance  ; 
    	  
     		if ( text_clanname != "Nosferatu")
 		{	
 			int score_social_total = score_charisma + score_manipulation + score_appearance  ; 	
 		}
 		else 	
 		{  	
			int score_social_total = score_charisma + score_manipulation  ;			  		
 		}
   
  		//Récupération des points attribué au caractere mental
		int score_perception = spin_perception.get_value_as_int() , score_intelligence = spin_intelligence.get_value_as_int() , score_wits = spin_wits.get_value_as_int();
		int score_mental_total = score_perception + score_intelligence + score_wits  ; 				
 		if ( (score_physical_total != 5) || (score_social_total != 3) || (score_mental_total != 7))
 		{		
 			Gtk::MessageDialog dialog(*this, "Le nombre des points totaux de PHYSICAL, SOCIAL et MENTAL doivent être égaux à 5, 3, 7 respectivement !",false,Gtk::MESSAGE_ERROR);
			dialog.run();	
 		} 
 	
	}
	
	
	//Le cas ou la distribution choisi par l'utilisateur est 5/7/3
	else 
	{	
		int score_physical = 5 , score_social = 7 , score_mental = 3 ;
		
		//Récupération des points attribué au caractere physique
		int score_strength = spin_strength.get_value_as_int() , score_dexterity = spin_dexterity.get_value_as_int() , score_stamina = spin_stamina.get_value_as_int();
		int score_physical_total = score_strength + score_dexterity + score_stamina  ; 
				
		//Récupération des points attribué au caractere social
		int score_charisma = spin_charisma.get_value_as_int() , score_manipulation = spin_manipulation.get_value_as_int() , score_appearance = spin_appearance.get_value_as_int();
		int score_social_total = score_charisma + score_manipulation + score_appearance  ; 
    	  
     		if ( text_clanname != "Nosferatu")
 		{	
 			int score_social_total = score_charisma + score_manipulation + score_appearance  ; 	
 		}
 		else 	
 		{  	
			int score_social_total = score_charisma + score_manipulation  ;			  		
 		}
   
  		//Récupération des points attribué au caractere mental
		int score_perception = spin_perception.get_value_as_int() , score_intelligence = spin_intelligence.get_value_as_int() , score_wits = spin_wits.get_value_as_int();
		int score_mental_total = score_perception + score_intelligence + score_wits  ; 				
 		if ( (score_physical_total != 5) || (score_social_total != 7) || (score_mental_total != 3))
 		{		
 			Gtk::MessageDialog dialog(*this, "Le nombre des points totaux de PHYSICAL, SOCIAL et MENTAL doivent être égaux à 5, 7, 3 respectivement !",false,Gtk::MESSAGE_ERROR);
			dialog.run();	
 		} 
 	
	}
	

  */ 		

	
/*
		//Disciplines      	
     	disciplines_label.set_text("#########  DISCIPLINES  #########");   
     	disciplines_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid.attach(disciplines_label, 3, 9, 1,1);
  
	 		
	//La 1 ere discipline
	spin_discipl1.set_range(0,3);
	spin_discipl1.set_increments(1,1);
	 
	//La 2 eme discipline            	
	spin_discipl2.set_range(0,3);
	spin_discipl2.set_increments(1,1);
	
	//La 3 eme discipline 
	spin_discipl3.set_range(0,3);
	spin_discipl3.set_increments(1,1);

	
        //Button pour valider les discipline 
        next1_button.signal_clicked().connect( sigc::mem_fun(*this,
            &Fenetre::next1_button_clicked) );
    	mainGrid.attach(next1_button,6 , 10, 1, 1);
   	next1_button.add_label("next");   /// Bouton pour passer a la suite du formulaire

  	    	
     	mainGrid.attach(spin_discipl1, 1, 10, 1, 1);     	
     	mainGrid.attach(spin_discipl2, 3, 10, 1, 1);     	
     	mainGrid.attach(spin_discipl3, 5, 10, 1, 1);
     	
     	//Les noms des disciplines              
     	mainGrid.attach(discipl1_label, 0, 10, 1, 1);
     	mainGrid.attach(discipl2_label, 2, 10, 1, 1);
     	mainGrid.attach(discipl3_label, 4, 10, 1, 1);
     	
     	    	
     	//Haven      	
     	haven_label.set_text("###########  HAVEN  ###########");   
     	haven_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid.attach(haven_label, 3, 11, 1,1);
  
 	//Localisation de Haven
     	haven_location_label.set_text("  Location:  ");     		
     	mainGrid.attach(haven_location_label, 0, 12, 1,1);
     	location_entry.set_max_length(50);
   	mainGrid.attach(location_entry, 1, 12, 1, 1);
    	
    	//Description de Haven
     	haven_description_label.set_text("  Description:  ");     		
     	mainGrid.attach(haven_description_label, 2, 12, 1,1);
     	description_entry.set_max_length(50);
   	mainGrid.attach(description_entry, 3, 12, 1, 1);
    	
    	//Weakness (faiblesse du personnage)
     	weakness_label.set_text("  Weakness:  ");     		
     	mainGrid.attach(weakness_label, 0, 13, 1,1);
     	weakness_entry.set_max_length(50);
   	mainGrid.attach(weakness_entry, 1, 13, 1, 1);
   	   	
   	*/


	
	
/*	

  	//Récuperer les points attribué pour chaque discipline et s'assurer qu'il soit égale a 3 
  	int score1 = spin_discipl1.get_value_as_int();
  	int score2 = spin_discipl2.get_value_as_int();
 	int score3 = spin_discipl3.get_value_as_int();
 	int score_dicipl = score1 + score2 + score3  ; 
 		
 	if (score_dicipl != 3 )
 	{		
 		Gtk::MessageDialog dialog(*this, "Le nombre de points totale de disciplines doit être égal à 3 !",false,Gtk::MESSAGE_ERROR);
		dialog.run();	
 	} 
 */	
 
	



/*
void next_button_clicked {





	string choosen = sex_combo.get_active_text() 
	Clan.name(sex)
	
	Player.RandomName(choosen_race, choosen_sex);
    Glib::ustring random_name = Player.getNomPerso();
    
      Player.setSexe(choosen_sex);


}

bool DrawImage::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{

    string name = Player.getNomPerso();
    string classe = Player.getChoixClasse();
    string race = Player.getChoixRace();
    string sexe = Player.getSexe();
}

*/    
    
    
    
    
    
    
    
    
























