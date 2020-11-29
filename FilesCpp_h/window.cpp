#include "MiniProjet.h"

Clan clan;
OtherTraits otherTraits;
Attributes attributes;
Abilities abilities;
Personnage personnage;

/****************************************************************************************************************************************************************/
/****************************************************************************************************************************************************************/
/****************************************************************************************************************************************************************/

deque <int> attribut; //deque contenant les points attributé a chaque éléments des attributs qui nous permet de remplir le formulaire 
deque <int> abilitie; //deque contenant les points attributé a chaque éléments des abilities qui nous permet de remplir le formulaire 
deque <int> discipline; //deque contenant les points attributé a chaque éléments de disciplines qui nous permet de remplir le formulaire 
deque <int> background; //deque contenant les points attributé a chaque éléments des background qui nous permet de remplir le formulaire 
deque <string> backgroundListe; //deque contenant la liste des background choisi par l'utilisateur 
deque <int> virtues; //deque contenant les points attributé a chaque éléments de virtues qui nous permet de remplir le formulaire 

Fenetre::Fenetre()
: boxV (Gtk :: ORIENTATION_HORIZONTAL, 12),back(Gtk::Stock::GO_BACK),forward(Gtk::Stock::GO_FORWARD), image("Images/image_1.jpg")
{
	
	set_title("Vampire Interface");

	set_border_width(10);
	set_position(Gtk::WIN_POS_CENTER);

	resize(300, 300); 	
		
	add(boxV);
	
	//Ajout d'une image a mon interface	
	boxV.pack_start(image);
	
	//Bouton back & forward & create
	back.set_can_focus(false);
    	FBBoutons.pack_start(back);

    	forward.set_can_focus(false);
   	FBBoutons.pack_start(forward);
   	
   	create_button.set_can_focus(false);	  	
   	VBoutons.pack_start(create_button);
   	  	
   	boxV.pack_start(FBBoutons);
   	boxV.pack_end(VBoutons);
    


	//Création des différentes pages
	
	//////////////////////////////////PAGES/////////////////////////////////
	boxV.pack_start(pages);	
	pages.append_page(mainGrid, "page 1 ");
	pages.append_page(mainGrid2, "page2");
	pages.append_page(mainGrid3, "page3");
	pages.append_page(mainGrid4, "page 4 ");
       	
	//////////////////////////////////PAGE1/////////////////////////////////
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
    	
    
   	//Concept
    	concept_label.set_text("  Concept:  ");
 	mainGrid.attach(concept_label, 2, 2, 1, 1);
   	concept_entry.set_max_length(50);
    	mainGrid.attach(concept_entry, 3, 2, 1, 1);  	
    	
    	//Le clan 	
	clanName_label.set_text("  Clan* :  ");
        mainGrid.attach(clanName_label, 4 , 0, 1, 1);
	clanName_list = clan.clan_list();
	for(int i=0; i<clanName_list.size(); ++i)	
		Clan_combo.append(clanName_list[i]);		
	Clan_combo.signal_changed().connect(sigc::mem_fun(*this,
              &Fenetre::on_combo_changed) );

	mainGrid.attach(Clan_combo, 5, 0, 1, 1);
 		 	
	//Generation 
	generation_label.set_text("  Generation :  ");
        mainGrid.attach(generation_label, 4 , 1, 1, 1);
	generation_combo.append("4th");
	generation_combo.append("5th");
	generation_combo.append("6th");
	generation_combo.append("7th");
	generation_combo.append("8th");
	generation_combo.append("9th");
	generation_combo.append("10th");
	generation_combo.append("11th");
	generation_combo.append("12th");
	generation_combo.append("13th");
	generation_combo.append("14th");
	generation_combo.append("15th");

	mainGrid.attach(generation_combo, 5, 1, 1, 1);
 	generation_combo.signal_changed().connect( sigc::mem_fun(*this,
            &Fenetre::on_combogeneration_changed) );
	
 	
    	//Sire
    	sire_label.set_text("  Sire:  ");
 	mainGrid.attach(sire_label, 4, 2, 1, 1);
   	sire_entry.set_max_length(50);
    	mainGrid.attach(sire_entry, 5, 2, 1, 1);   	
			
    	
    	//Choix de la combinaison de points pour les différents catégories d'attributs	
 	DistributionPointsAttribut_label.set_text(" Choose the combination for points distributed to attributes (PHYSICAL, SOCIAL, MENTAL) * : ");
        mainGrid.attach(DistributionPointsAttribut_label, 0 , 3, 2, 1);
	
	DistributionPointsAttribut_combo.append("7/5/3");
	DistributionPointsAttribut_combo.append("7/3/5");
	DistributionPointsAttribut_combo.append("3/7/5");
	DistributionPointsAttribut_combo.append("3/5/7");
	DistributionPointsAttribut_combo.append("5/3/7");
	DistributionPointsAttribut_combo.append("5/7/3");
	
	mainGrid.attach(DistributionPointsAttribut_combo, 2 , 3, 1, 1); 	
    
   	
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
     	     	
     	//////////////////PAGE2////////////////////////////////////
   	
  	//Choix de la combinaison de points pour les différents catégories d'abilities
	DistributionPointsAbilities_label.set_text("Choose the combination for points distributed to abilities ( TALENTS, SKILLS, KNOWLEDGES ) * : ");
        mainGrid2.attach(DistributionPointsAbilities_label, 0 , 0, 3, 1);
	
	DistributionPointsAbilities_combo.append("13/9/5");
	DistributionPointsAbilities_combo.append("13/5/9");
	DistributionPointsAbilities_combo.append("9/5/13");
	DistributionPointsAbilities_combo.append("9/13/5");
	DistributionPointsAbilities_combo.append("5/9/13");
	DistributionPointsAbilities_combo.append("5/13/9");
	
	mainGrid2.attach(DistributionPointsAbilities_combo, 4 , 0, 2, 1);
   	 					
	//Abilities
   	abilities_label.set_text("#########  ABILITIES  #########");   
     	abilities_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid2.attach(abilities_label, 3, 1, 1,1);
     	
     	talents_label.set_text("  ** TALENTS **  ");     		
     	mainGrid2.attach(talents_label, 1, 2, 1, 1);
     	
     	skills_label.set_text("  ** SKILLS **  ");     		
     	mainGrid2.attach(skills_label, 3, 2, 1, 1);
     	
     	knowledges_label.set_text("  ** KNOWLEDGES **  ");     		
     	mainGrid2.attach(knowledges_label, 5, 2, 1, 1);

	//Talents abilities
     	alertness_label.set_text(" Alertness ");     		
     	mainGrid2.attach(alertness_label, 0, 3, 1,1);    	
     	spin_alertness.set_range(0,5);
	spin_alertness.set_increments(1,1);
     	    
  	athletics_label.set_text(" Athletics ");     		
     	mainGrid2.attach(athletics_label, 0, 4, 1,1);    	
    	spin_athletics.set_range(0,5);
	spin_athletics.set_increments(1,1);
     	     	  	
    	awareness_label.set_text(" Awareness ");     		
     	mainGrid2.attach(awareness_label, 0, 5, 1,1);     	
     	spin_awareness.set_range(0,5);
	spin_awareness.set_increments(1,1);
	
	brawl_label.set_text(" Brawl ");     		
     	mainGrid2.attach(brawl_label, 0, 6, 1,1);    	
     	spin_brawl.set_range(0,5);
	spin_brawl.set_increments(1,1);
     	   
  	empathy_label.set_text(" Empathy ");     		
     	mainGrid2.attach(empathy_label, 0, 7, 1,1);    	
    	spin_empathy.set_range(0,5);
	spin_empathy.set_increments(1,1);
     	     	  	
    	expression_label.set_text(" Expression ");     		
     	mainGrid2.attach(expression_label, 0, 8, 1,1);     	
     	spin_expression.set_range(0,5);
	spin_expression.set_increments(1,1);
	
	intimidation_label.set_text(" Intimidation ");     		
     	mainGrid2.attach(intimidation_label, 0, 9, 1,1);    	
     	spin_intimidation.set_range(0,5);
	spin_intimidation.set_increments(1,1);
     	  
  	leadership_label.set_text(" Leadership ");     		
     	mainGrid2.attach(leadership_label, 0, 10, 1,1);    	
    	spin_leadership.set_range(0,5);
	spin_leadership.set_increments(1,1);
     	     	   	
    	streetwise_label.set_text(" Streetwise ");     		
     	mainGrid2.attach(streetwise_label, 0, 11, 1,1);     	
     	spin_streetwise.set_range(0,5);
	spin_streetwise.set_increments(1,1);
	
	subterfuge_label.set_text(" Subterfuge ");     		
     	mainGrid2.attach(subterfuge_label, 0, 12, 1,1);     	
     	spin_subterfuge.set_range(0,5);
	spin_subterfuge.set_increments(1,1);
	  
     	//Skills abilities
     	animalKen_label.set_text(" Animal Ken ");     		
     	mainGrid2.attach(animalKen_label, 2, 3, 1,1);    	
     	spin_animalKen.set_range(0,5);
	spin_animalKen.set_increments(1,1);
	 
     	crafts_label.set_text(" Crafts ");     		
     	mainGrid2.attach(crafts_label, 2, 4, 1,1);     	
     	spin_crafts.set_range(0,5);
	spin_crafts.set_increments(1,1);
	
	drive_label.set_text(" Drive ");     		
     	mainGrid2.attach(drive_label, 2, 5, 1,1);     	
     	spin_drive.set_range(0,5);
	spin_drive.set_increments(1,1);
	  
	etiquette_label.set_text(" Etiquette ");     		
     	mainGrid2.attach(etiquette_label, 2, 6, 1,1);     	
     	spin_etiquette.set_range(0,5);
	spin_etiquette.set_increments(1,1);

 	firearms_label.set_text(" Firearms ");     		
     	mainGrid2.attach(firearms_label, 2, 7, 1,1);     	
     	spin_firearms.set_range(0,5);
	spin_firearms.set_increments(1,1);
     	
     	larceny_label.set_text(" Larceny ");     		
     	mainGrid2.attach(larceny_label, 2, 8, 1,1);     	
     	spin_larceny.set_range(0,5);
	spin_larceny.set_increments(1,1);
	
	melee_label.set_text(" Melee ");     		
     	mainGrid2.attach(melee_label, 2, 9, 1,1);     	
     	spin_melee.set_range(0,5);
	spin_melee.set_increments(1,1);
	
	performance_label.set_text(" Performance ");     		
     	mainGrid2.attach(performance_label, 2, 10, 1,1);     	
     	spin_performance.set_range(0,5);
	spin_performance.set_increments(1,1);
	
	stealth_label.set_text(" Stealth ");     		
     	mainGrid2.attach(stealth_label, 2, 11, 1,1);     	
     	spin_stealth.set_range(0,5);
	spin_stealth.set_increments(1,1);
	
	survival_label.set_text(" Survival ");     		
     	mainGrid2.attach(survival_label, 2, 12, 1,1);     	
     	spin_survival.set_range(0,5);
	spin_survival.set_increments(1,1);
	
     	//Knowledges abilities
     	academics_label.set_text(" Academics ");     		
     	mainGrid2.attach(academics_label, 4, 3, 1,1);     	
     	spin_academics.set_range(0,5);
	spin_academics.set_increments(1,1);
	 
     	computer_label.set_text(" Computer ");     		
     	mainGrid2.attach(computer_label, 4, 4, 1,1);
     	spin_computer.set_range(0,5);
	spin_computer.set_increments(1,1);
     	 
     	finance_label.set_text(" Finance ");     		
     	mainGrid2.attach(finance_label, 4, 5, 1,1);     	
     	spin_finance.set_range(0,5);
	spin_finance.set_increments(1,1);
	
	investigation_label.set_text(" Investigation ");     		
     	mainGrid2.attach(investigation_label, 4, 6, 1,1);     	
     	spin_investigation.set_range(0,5);
	spin_investigation.set_increments(1,1);
	 
     	law_label.set_text(" Law ");     		
     	mainGrid2.attach(law_label, 4, 7, 1,1);
     	spin_law.set_range(0,5);
	spin_law.set_increments(1,1);
     	 
     	medicine_label.set_text(" Medicine ");     		
     	mainGrid2.attach(medicine_label, 4, 8, 1,1);     	
     	spin_medicine.set_range(0,5);
	spin_medicine.set_increments(1,1);
	 
	occult_label.set_text(" Occult ");     		
     	mainGrid2.attach(occult_label, 4, 9, 1,1);     	
     	spin_occult.set_range(0,5);
	spin_occult.set_increments(1,1);
	 
     	politics_label.set_text(" Politics ");     		
     	mainGrid2.attach(politics_label, 4, 10, 1,1);
     	spin_politics.set_range(0,5);
	spin_politics.set_increments(1,1);
     	 
     	science_label.set_text(" Science ");     		
     	mainGrid2.attach(science_label, 4, 11, 1,1);     	
     	spin_science.set_range(0,5);
	spin_science.set_increments(1,1);
	
	technology_label.set_text(" Technology ");     		
     	mainGrid2.attach(technology_label, 4, 12, 1,1);     	
     	spin_technology.set_range(0,5);
	spin_technology.set_increments(1,1);
   	
   	//Talents spinButton
     	mainGrid2.attach(spin_alertness, 1, 3, 1, 1);  
     	mainGrid2.attach(spin_athletics, 1, 4, 1, 1); 
     	mainGrid2.attach(spin_awareness, 1, 5, 1, 1); 
     	mainGrid2.attach(spin_brawl, 1, 6, 1, 1);  
     	mainGrid2.attach(spin_empathy, 1, 7, 1, 1);
     	mainGrid2.attach(spin_expression, 1, 8, 1, 1); 
     	mainGrid2.attach(spin_intimidation, 1, 9, 1, 1);
     	mainGrid2.attach(spin_leadership, 1, 10, 1, 1); 
     	mainGrid2.attach(spin_streetwise, 1, 11, 1, 1);  
     	mainGrid2.attach(spin_subterfuge, 1, 12, 1, 1); 
     	//Skills spinButton
     	mainGrid2.attach(spin_animalKen, 3, 3, 1, 1); 
     	mainGrid2.attach(spin_crafts, 3, 4, 1, 1);  
     	mainGrid2.attach(spin_drive, 3, 5, 1, 1);
     	mainGrid2.attach(spin_etiquette, 3, 6, 1, 1); 
     	mainGrid2.attach(spin_firearms, 3, 7, 1, 1);
     	mainGrid2.attach(spin_larceny, 3, 8, 1, 1);
     	mainGrid2.attach(spin_melee, 3, 9, 1, 1);  
     	mainGrid2.attach(spin_performance, 3, 10, 1, 1); 
     	mainGrid2.attach(spin_stealth, 3, 11, 1, 1); 
     	mainGrid2.attach(spin_survival, 3, 12, 1, 1);  
     	//knowlodges spin Button
     	mainGrid2.attach(spin_academics, 5, 3, 1, 1);
     	mainGrid2.attach(spin_computer, 5, 4, 1, 1); 
     	mainGrid2.attach(spin_finance, 5, 5, 1, 1);
     	mainGrid2.attach(spin_investigation, 5, 6, 1, 1);  
     	mainGrid2.attach(spin_law, 5, 7, 1, 1);  
     	mainGrid2.attach(spin_medicine, 5, 8, 1, 1); 
     	mainGrid2.attach(spin_occult, 5, 9, 1, 1); 
     	mainGrid2.attach(spin_politics, 5, 10, 1, 1);  
     	mainGrid2.attach(spin_science, 5, 11, 1, 1);
     	mainGrid2.attach(spin_technology, 5, 12, 1, 1);  
     	
   
    	  //////////////////PAGE3////////////////////////////////////
       	  	   	
     	//Advantages 
     	
     	advantages_label.set_text("#########  ADVANTAGES  #########");   
     	advantages_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid3.attach(advantages_label, 3, 0, 1,1);
   
  	//Disciplines      	
     	disciplines_label.set_text("  ** DISCIPLINES **  ");   
     	disciplines_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid3.attach(disciplines_label, 1, 1, 1,1); 
	 		
	//La 1 ere discipline
	spin_discipl1.set_range(0,3);
	spin_discipl1.set_increments(1,1);
	 
	//La 2 eme discipline            	
	spin_discipl2.set_range(0,3);
	spin_discipl2.set_increments(1,1);
	
	//La 3 eme discipline 
	spin_discipl3.set_range(0,3);
	spin_discipl3.set_increments(1,1);
  	    	
     	mainGrid3.attach(spin_discipl1, 1, 2, 1, 1);     	
     	mainGrid3.attach(spin_discipl2, 1, 3, 1, 1);     	
     	mainGrid3.attach(spin_discipl3, 1, 4, 1, 1);
     	
     	//Les noms des disciplines              
     	mainGrid3.attach(discipl1_label, 0, 2, 1, 1);
     	mainGrid3.attach(discipl2_label, 0, 3, 1, 1);
     	mainGrid3.attach(discipl3_label, 0, 4, 1, 1);
     	    	
     	//Background 
     	background_label.set_text("  ** BACKGROUND **  ");   
     	background_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid3.attach(background_label, 3, 1, 1,1);

        backgroundName_list = otherTraits.background_list();        
        for(auto i=0; i<backgroundName_list.size(); ++i)
        {	
		background1_combo.append(backgroundName_list[i]);
	}		
    	mainGrid3.attach(background1_combo, 2, 2, 1, 1);
    	mainGrid3.attach(background2_combo, 2, 3, 1, 1);
    	mainGrid3.attach(background3_combo, 2, 4, 1, 1); 
    	mainGrid3.attach(background4_combo, 2, 5, 1, 1); 
    	mainGrid3.attach(background5_combo, 2, 6, 1, 1);   
    	
    	spin_background1.set_range(0,5);
	spin_background1.set_increments(1,1); 
	
	mainGrid3.attach(spin_background1, 3, 2, 1, 1);
    	mainGrid3.attach(spin_background2, 3, 3, 1, 1);
    	mainGrid3.attach(spin_background3, 3, 4, 1, 1); 
    	mainGrid3.attach(spin_background4, 3, 5, 1, 1); 
    	mainGrid3.attach(spin_background5, 3, 6, 1, 1);  
		
	
	//BAckground signaux 
	background1_combo.signal_changed().connect(sigc::mem_fun(*this,
              &Fenetre::on_combobackground_changed) );
       background2_combo.signal_changed().connect(sigc::mem_fun(*this,
              &Fenetre::on_combobackground1_changed) );
       background3_combo.signal_changed().connect(sigc::mem_fun(*this,
              &Fenetre::on_combobackground2_changed) );
       background4_combo.signal_changed().connect(sigc::mem_fun(*this,
              &Fenetre::on_combobackground3_changed) );
              
       //Virtues         	 
        virtues_label.set_text("  ** Virtues **  ");   
     	virtues_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid3.attach(virtues_label, 5, 1, 1,1);  
     		 
     	conscience_label.set_text(" Conscience/Conviction ");     		
     	mainGrid3.attach(conscience_label, 4, 2, 1,1);     	
     	spin_conscience.set_range(1,5);
	spin_conscience.set_increments(1,1);
	 
	selfControl_label.set_text(" Self-Control/Instinct ");     		
     	mainGrid3.attach(selfControl_label, 4, 3, 1,1);     	
     	spin_selfControl.set_range(1,5);
	spin_selfControl.set_increments(1,1);
	 
     	courage_label.set_text(" Courage ");     		
     	mainGrid3.attach(courage_label, 4, 4, 1,1);
     	spin_courage.set_range(1,5);
	spin_courage.set_increments(1,1);
	
	mainGrid3.attach(spin_conscience, 5, 2, 1, 1);
    	mainGrid3.attach(spin_selfControl, 5, 3, 1, 1);
    	mainGrid3.attach(spin_courage, 5, 4, 1, 1); 
 
    	//Signal du changement des virtues 
    	spin_conscience.signal_value_changed().connect( sigc::mem_fun(*this,
            &Fenetre::spin_virtues_clicked) );
  	spin_selfControl.signal_value_changed().connect( sigc::mem_fun(*this,
            &Fenetre::spin_virtues_clicked) );
        spin_courage.signal_value_changed().connect( sigc::mem_fun(*this,
            &Fenetre::spin_virtues_clicked) );
  	    	
    	//Humanity     	
    	humanity_label.set_text(" Humanity/Path "); 
    	humanity_score.set_text("2");
    	willpower_score.set_text("1");

    	mainGrid3.attach(humanity_label, 7, 0, 1, 1); 
    	mainGrid3.attach(humanity_score, 7, 1, 1, 1); 
    	
    	//Willpower   	
    	willpower_label.set_text(" Willpower "); 

    	mainGrid3.attach(willpower_label, 7, 3, 1, 1); 
    	mainGrid3.attach(willpower_score, 7, 4, 1, 1); 
    	
    	//Blood pool    	
    	blood_label.set_text(" Blood Pool "); 
    	blood_turn_label.set_text(" Blood Per Turn "); 
    	
    	mainGrid3.attach(blood_label, 7, 5, 1, 1); 
    	mainGrid3.attach(blood_score, 7, 6, 1, 1); 
    	mainGrid3.attach(blood_turn_label, 7, 7, 1, 1); 
    	mainGrid3.attach(blood_score_turn, 7, 8, 1, 1); 
		
	//////////////////////////////////PAGE4/////////////////////////////////	

	
	
	
	
	
	//Freebie
	
		



	
	
	//Signal des boutons forward & back & create
	back.signal_clicked().connect(sigc::mem_fun(pages, &Gtk::Notebook::prev_page));
    	forward.signal_clicked().connect(sigc::mem_fun(pages, &Gtk::Notebook::next_page));

	//Bouton pour afficher la feuille du personnage      
   	create_button.signal_clicked().connect( sigc::mem_fun(*this,
            &Fenetre::create_button_clicked) );
  
    	create_button.add_pixlabel("info.xpm", "Open File");
    	
  	show_all_children();
  	background2_combo.hide();
  	background3_combo.hide();
  	background4_combo.hide();
  	background5_combo.hide();
}

Fenetre::~Fenetre() 
{

}
////////////////////////////////////////////////////////////////////////
deque<string> liste_discip; //Liste avec les différents disciplines
void Fenetre::on_combo_changed() //Signal du changement de la combobox de clan qui permet de déterminer les différents disciplines liée au clan choisi et l'apparance au niveau des abilities au cas ou le nom du clan est un Nosferatu 
{	
	//On récupere le choix du clan de l'utilisateur 
	string text_clanname = Clan_combo.get_active_text();
	discipl_list = clan.make_table();	
		
	//On détermine ici les disciplines associer au clan que l'utilisateur aura choisi 
	for (auto it = discipl_list.begin(); it!= discipl_list.end(); ++it)
	{
		string text2 = it->first ; 
		if (text_clanname == text2)
		{
			liste_discip.push_back(it->second);			
		}
 	} 	
 	discipl1_label.set_text("  " + liste_discip[0] + "  ");
 	discipl2_label.set_text("  " + liste_discip[1] + "  ");
 	discipl3_label.set_text("  " + liste_discip[2] + "  ");
 	
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
 	
 	liste_discip.clear();  		
}
////////////////////////////////////////////////////////////////////////

void Fenetre::on_combogeneration_changed() //Signal du changement de la combobox de génération
{
	string text_generation = generation_combo.get_active_text();
	
	if(text_generation != "")
	{
		if(text_generation == "4th"){ blood_score.set_text("50"); blood_score_turn.set_text("10"); }
		else if (text_generation == "5th"){blood_score.set_text("40"); blood_score_turn.set_text("8"); }
		else if(text_generation == "6th"){blood_score.set_text("30"); blood_score_turn.set_text("6"); }
		else if(text_generation == "7th"){ blood_score.set_text("20"); blood_score_turn.set_text("5"); }	
		else if(text_generation == "8th"){ blood_score.set_text("15"); blood_score_turn.set_text("3"); }
		else if(text_generation == "9th"){blood_score.set_text("14"); blood_score_turn.set_text("2"); }
		else if(text_generation == "10th"){blood_score.set_text("13"); blood_score_turn.set_text("1"); }
		else if(text_generation == "11th"){blood_score.set_text("12"); blood_score_turn.set_text("1"); }
		else if(text_generation == "12th"){blood_score.set_text("11"); blood_score_turn.set_text("1"); }
		else if(text_generation == "13th"){blood_score.set_text("10"); blood_score_turn.set_text("1"); }
		else if(text_generation == "14th"){blood_score.set_text("10"); blood_score_turn.set_text("1"); }
		else{blood_score.set_text("9"); blood_score_turn.set_text("1"); }
	}
	else
	{
		blood_score.set_text("0"); 
    		blood_score_turn.set_text("0"); 			
	}
}

////////////////////////////////////////////////////////////////////////
void Fenetre::on_combobackground_changed() //Signal du changement de la combobox 1 de background 
{
	spin_background2.set_range(0,5);
	spin_background2.set_increments(1,1); 	
	//On récupere le choix du background de l'utilisateur 
	string text_backgroundname =background1_combo.get_active_text();
	background2_combo.remove_all();
	backgroundName_list = otherTraits.background_list();        
        for(auto i=0; i<backgroundName_list.size(); ++i)
        {	
        	if(text_backgroundname != backgroundName_list[i] )
        	{      	
        		background2_combo.append(backgroundName_list[i]); 
        		  		       		     	
        	}       	       	
	}
	background2_combo.show();
}
////////////////////////////////////////////////////////////////////////
void Fenetre::on_combobackground1_changed() //Signal du changement de la combobox 2 de background 
{	
	//On récupere le choix background précédent
	spin_background3.set_range(0,5);
	spin_background3.set_increments(1,1); 
	
	string text_backgroundname =background1_combo.get_active_text();
	string text_backgroundname2 =background2_combo.get_active_text();	
	background3_combo.remove_all();
	for(auto i=0; i<backgroundName_list.size(); ++i)
        {	
        	if( text_backgroundname != backgroundName_list[i] && text_backgroundname2 != backgroundName_list[i])
        	{      	      		
        			background3_combo.append(backgroundName_list[i]);        	        		
        	}
	}
	background3_combo.show();
}

////////////////////////////////////////////////////////////////////////
void Fenetre::on_combobackground2_changed() //Signal du changement de la combobox 3 de background 
{	
	spin_background4.set_range(0,5);
	spin_background4.set_increments(1,1); 

	//On récupere le choix du clan de l'utilisateur 
	string text_backgroundname =background1_combo.get_active_text();	
	string text_backgroundname2 =background2_combo.get_active_text();	
	string text_backgroundname3 =background3_combo.get_active_text();
	
	background4_combo.remove_all();
	for(auto i=0; i<backgroundName_list.size(); ++i)
        {	
        	if( text_backgroundname != backgroundName_list[i] && text_backgroundname2 != backgroundName_list[i] && text_backgroundname3 != backgroundName_list[i] )
        	{      	      		
        			background4_combo.append(backgroundName_list[i]);        	        		
        	}
	}
	background4_combo.show();
}



////////////////////////////////////////////////////////////////////////
void Fenetre::on_combobackground3_changed() //Signal du changement de la combobox 4 de background 
{
	spin_background5.set_range(0,5);
	spin_background5.set_increments(1,1); 
	
	//On récupere le choix background précédent
	string text_backgroundname =background1_combo.get_active_text();	
	string text_backgroundname2 =background2_combo.get_active_text();	
	string text_backgroundname3 =background3_combo.get_active_text();	
	string text_backgroundname4 =background4_combo.get_active_text();		
	background5_combo.remove_all();
	for(auto i=0; i<backgroundName_list.size(); ++i)
        {	
        	if( text_backgroundname != backgroundName_list[i] && text_backgroundname2 != backgroundName_list[i] && text_backgroundname3 != backgroundName_list[i] && text_backgroundname4 != backgroundName_list[i] )
        	{      	      		
        			background5_combo.append(backgroundName_list[i]);        	        		
        	}
	}
	background5_combo.show();
}


////////////////////////////////////////////////////////////////////////////////////////////////////// 

void Fenetre::spin_virtues_clicked() //Signal du changement de la combobox 1 de background 
{
	int human = spin_conscience.get_value_as_int()+spin_selfControl.get_value_as_int();
	humanity_score.set_text(to_string(human)); 
	int willp = spin_courage.get_value_as_int();
	willpower_score.set_text(to_string(willp)); 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void Fenetre::create_button_clicked() //Signal du changement de la combobox
{
/*	//Récupération des signaux 
	string text_pointattributs = DistributionPointsAttribut_combo.get_active_text();
	string text_pointabilities = DistributionPointsAbilities_combo.get_active_text();*/
	string text_clanname = Clan_combo.get_active_text();
		
	int condition_total = 10 ;
/*	//Verification si le joueur a bien sélectionné un nom de clan et les combinaison nécéssaire pour les attribution des points 
	if(text_clanname == "" || text_pointabilities == "" || text_pointattributs == "" )
	{
		condition_total-- ;
	}
*/	/////////////////////////////Verifier l'attribution des points pour les attributs 
	//point physic
	int score_strength = spin_strength.get_value_as_int() , score_dexterity = spin_dexterity.get_value_as_int() , score_stamina = spin_stamina.get_value_as_int();
	
	attribut.push_back(score_strength); attribut.push_back(score_dexterity); attribut.push_back(score_stamina); 
	
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
  	
  	attribut.push_back(score_charisma) ; attribut.push_back(score_manipulation); attribut.push_back(score_appearance);
  	//Récupération des points attribué au caractere mental
	int score_perception = spin_perception.get_value_as_int() , score_intelligence = spin_intelligence.get_value_as_int() , score_wits = spin_wits.get_value_as_int();
	int score_mental_total = score_perception + score_intelligence + score_wits  ; 
	
	attribut.push_back(score_perception) ; attribut.push_back(score_intelligence) ; attribut.push_back(score_wits);
	//Vérification de la condition d'attribution des points aux attributs par le joueur				
//	int condition_attributs = attributes.check_attributspoint(text_pointattributs , score_physical_total , score_social_total , score_mental_total  );
/*	if(condition_attributs == 1 )
	{
		condition_total--;
	}		
*/	/////////////////////////////Verifier l'attribution des points pour les abilities

	//Récuppération des points attribué au talents
	int score_alertness = spin_alertness.get_value_as_int() , score_athletics = spin_athletics.get_value_as_int() , score_awareness = spin_awareness.get_value_as_int(), score_brawl = spin_brawl.get_value_as_int() , score_empathy = spin_empathy.get_value_as_int() , score_expression = spin_expression.get_value_as_int() , score_intimidation = spin_intimidation.get_value_as_int() , score_leadership = spin_leadership.get_value_as_int() , score_streetwise = spin_streetwise.get_value_as_int(), score_subterfuge = spin_subterfuge.get_value_as_int();
		
		abilitie.push_back(score_alertness) ; abilitie.push_back(score_athletics) ; abilitie.push_back(score_awareness) ; abilitie.push_back(score_brawl) ; abilitie.push_back(score_empathy) ; abilitie.push_back(score_expression) ; abilitie.push_back(score_intimidation) ; abilitie.push_back(score_leadership) ; abilitie.push_back(score_streetwise) ; abilitie.push_back(score_subterfuge) ;
	
	int score_talents_total = score_alertness + score_athletics + score_awareness + score_brawl + score_empathy + score_expression + score_intimidation + score_leadership + score_streetwise + score_subterfuge;
	
	//Récuppération des points attribué au skills
	int score_animalKen = spin_animalKen.get_value_as_int() , score_crafts = spin_crafts.get_value_as_int() , score_drive = spin_drive.get_value_as_int(), score_etiquette = spin_etiquette.get_value_as_int() , score_firearms = spin_firearms.get_value_as_int() , score_larceny = spin_larceny.get_value_as_int() , score_melee = spin_melee.get_value_as_int() , score_performance = spin_performance.get_value_as_int() , score_stealth = spin_stealth.get_value_as_int(), score_survival = spin_survival.get_value_as_int();
	
	abilitie.push_back(score_animalKen) ;abilitie.push_back(score_crafts) ; abilitie.push_back(score_drive) ; abilitie.push_back(score_etiquette) ; abilitie.push_back(score_firearms) ; abilitie.push_back(score_larceny) ; abilitie.push_back(score_melee) ; abilitie.push_back(score_performance) ; abilitie.push_back(score_stealth) ;  abilitie.push_back(score_survival) ;
	
	int score_skills_total = score_animalKen + score_crafts + score_drive + score_etiquette + score_firearms + score_larceny + score_melee + score_performance + score_stealth + score_survival;
		
	//Récupération des points attribué au knowledges	
	int score_academics = spin_academics.get_value_as_int() , score_computer = spin_computer.get_value_as_int() , score_finance = spin_finance.get_value_as_int(), score_investigation = spin_investigation.get_value_as_int() , score_law = spin_law.get_value_as_int() , score_medicine = spin_medicine.get_value_as_int() , score_occult = spin_occult.get_value_as_int() , score_politics = spin_politics.get_value_as_int() , score_science = spin_science.get_value_as_int(), score_technology = spin_technology.get_value_as_int();
	
	 abilitie.push_back(score_academics) ;abilitie.push_back(score_computer) ; abilitie.push_back(score_finance) ; abilitie.push_back(score_investigation) ; abilitie.push_back(score_law) ; abilitie.push_back(score_medicine) ; abilitie.push_back(score_occult) ; abilitie.push_back(score_politics) ; abilitie.push_back(score_science) ; abilitie.push_back(score_technology) ;
	
	int score_knowledges_total = score_academics + score_computer + score_finance + score_investigation + score_law + score_medicine + score_occult + score_politics + score_science + score_technology ;

/*	//Vérification de la condition d'attribution des points aux attributs par le joueur
	int condition_abilities = abilities.check_attributspointabilities(text_pointabilities , score_talents_total , score_skills_total , score_knowledges_total  );
	if(condition_abilities == 1 )
	{
		condition_total--;
	}	
*/		
	///////////////////////Récuperer les points attribué pour chaque discipline et s'assurer qu'il soit égale a 3 
  	int score1 = spin_discipl1.get_value_as_int();
  	int score2 = spin_discipl2.get_value_as_int();
 	int score3 = spin_discipl3.get_value_as_int();
 	discipline.push_back(score1) ; discipline.push_back(score2); discipline.push_back(score3);
 	int score_dicipl = score1 + score2 + score3  ; 
 	
 	/*	
 	if (score_dicipl != 3 )
 	{		
 		Gtk::MessageDialog dialog(*this, " The total points awarded to disciplines  must be equal to 3 !",false,Gtk::MESSAGE_ERROR);
		dialog.run();	
 		condition_total--;	
 	}
	*/
	//////////////////////Récuperer les points attribué pour chaque discipline et s'assurer qu'il soit égale a 3 
  	int score1_background = spin_background1.get_value_as_int();
  	int score2_background = spin_background2.get_value_as_int();
 	int score3_background = spin_background3.get_value_as_int();
 	int score4_background = spin_background4.get_value_as_int();
 	int score5_background = spin_background5.get_value_as_int();
 	background.push_back(score1_background); background.push_back(score2_background); background.push_back(score3_background); background.push_back(score4_background);background.push_back(score5_background);
 	int score_background = score1_background + score2_background + score3_background + score4_background +score5_background  ; 
 	/*	
 	if (score_background != 5 )
 	{		
 		Gtk::MessageDialog dialog(*this, " The total points awarded to disciplines  must be equal to 5 !",false,Gtk::MESSAGE_ERROR);
		dialog.run();	
 		condition_total--;	
 	}
*/
	//////////////////////Vérifier si c'est on a choisi la bonne génération car si on choisi pas génération dans le background le personnage sera assigné automatiquement a la 13 eme génération 	
		//Récupération du champ du dernier background si présent 
		 
	backgroundListe.push_back(background1_combo.get_active_text()); backgroundListe.push_back(background2_combo.get_active_text()); backgroundListe.push_back(background3_combo.get_active_text()); backgroundListe.push_back(background4_combo.get_active_text()); backgroundListe.push_back(background5_combo.get_active_text());
	string text_generation = generation_combo.get_active_text();		
	
	for (int i = 0 ; i < backgroundListe.size() ; i++)
	{
		if( text_generation != "")
		{
			if(backgroundListe[i] == "Generation")
			{
				if(text_generation != "13th")
				{			
					condition_total--;
					/*Gtk::MessageDialog dialog(*this, " If you have chosen generation in the backgrounds you must choose the 13th generation for your game character!",false,Gtk::MESSAGE_ERROR);
					dialog.run();		*/		
				}		
			}	
		}
	}
	
/*	if(condition_total != 10)
	{
		Gtk::MessageDialog dialog(*this, " Please choose a desired combination of points for abilities & attributes & Clan Name before proceeding next !",false,Gtk::MESSAGE_ERROR);
		dialog.run();	
	}
*/	


	//Récuperer les points attribué pour chaque virtues et s'assurer qu'il soit égale a 7
  	int score1_virtue = spin_conscience.get_value_as_int();
  	int score2_virtue = spin_selfControl.get_value_as_int();
 	int score3_virtue = spin_courage.get_value_as_int();
 	virtues.push_back(score1_virtue) ; virtues.push_back(score2_virtue); virtues.push_back(score3_virtue);
 	int score_virtue = score1_virtue + score2_virtue + score3_virtue  ; 	
 	/*	
 	if (score_virtue != 7 )
 	{		
 		Gtk::MessageDialog dialog(*this, " The total points awarded to disciplines  must be equal to 7 !",false,Gtk::MESSAGE_ERROR);
		dialog.run();	
 		condition_total--;	
 	}
	*/
	

	if(condition_total == 10)
	{
		//Récupération des info rentrer par le joueur 
		string nomP = name_entry.get_text();
		string nomJ = player_entry.get_text();
		string chronic  = chronicle_entry.get_text();
		string nature = nature_combo.get_active_text();
		string demeanor = demeanor_combo.get_active_text();
		string concepte = concept_entry.get_text();
		string nomC = Clan_combo.get_active_text();
		string sir = sire_entry.get_text();
		string hum = humanity_score.get_text();
		string wil = willpower_score.get_text();
		string blood = blood_score.get_text(); 
    		string bloodt = blood_score_turn.get_text(); 
			
		//Envoie les information aux différentes classe afin de pouvroi les récuperer aprés pour le dessin de la feuille de personnage 
		personnage.setNomPersonnage(nomP);	// nom du personnage 
		clan.SetPlayername(nomJ); // nom du joueur 
		personnage.setChronicle(chronic); // la chronicle 
		clan.SetNature(nature); //la nature du personnage
		clan.SetDemeanor(demeanor); //demeanor du personnage
		personnage.setConcept(concepte); //le concept du personnage 
		clan.SetClanName(nomC); //nom du clan 
		personnage.setSire(sir); //le sire 
		personnage.setHumanity(hum); //le score de l'humanity
		personnage.setWillpower(wil); //le score de willpower
		otherTraits.setBloodpool(blood); //le niveau de sang du personnage 
		otherTraits.setBloodpoolturn(bloodt); //le niveau de blood per turn
		
		Feuille_Vampire.show(); 		
	}
}

///////////////////////////////////////////////

//Ajout de la Fenetre_Vampire
Fenetre_Vampire::Fenetre_Vampire(): monImage("Images/Vampire.jpg") 
{
	set_title(" Vampire ");
	set_border_width(10);
  
	m_ScrolledWindow.add(monImage);
	m_ScrolledWindow.set_policy( Gtk::POLICY_NEVER, Gtk::POLICY_ALWAYS);
	m_ScrolledWindow.set_size_request(900, 900);
	add(m_ScrolledWindow);  
    
	show_all_children();
}

Fenetre_Vampire::~Fenetre_Vampire()
{
}

DrawImage::DrawImage(const string& file)
{
	try
	{
		monImage = Gdk::Pixbuf::create_from_file(file);
	}catch(...)
	{
		cerr<<"An error occured while loading the image file."<< endl;
	}

	if(monImage)
	{
		set_size_request(monImage->get_width(), monImage->get_height());
		set_halign(Gtk::ALIGN_CENTER);
		set_valign(Gtk::ALIGN_CENTER);
	}
}

DrawImage::~DrawImage()
{
}
//Dessiner sur la fiche du personnage 
bool DrawImage::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	//Récupération de tous les choix du joueur 	
	string name = personnage.getNomPersonnage();	// nom du personnage 
	string player = clan.GetPlayername(); // nom du joueur 
	string chron = personnage.getChronicle(); // la chronicle 
	string nat = clan.GetNature(); //la nature du personnage
	string dem = clan.GetDemeanor(); //demeanor du personnage
	string conc = personnage.getConcept(); //le concept du personnage 
	string cla =  clan.GetClanName(); //nom du clan 
	string sir =  personnage.getSire(); //nom du sire
	string hu =  personnage.getHumanity(); //point attribué a humanity
	string wi =  personnage.getWillpower(); //nom du sire
	string bloo = otherTraits.getBloodpool(); //blood pool
	string bloot = otherTraits.getBloodpoolturn(); //blood pool per turn
	
	//Les points pour chaque élément d'attributs 
	int strenght = attribut[0], dexterity = attribut[1] , stamina = attribut[2] ,charisma = attribut[3] ,manipulation = attribut[4] ,appearance = attribut[5] ,perception = attribut[6] ,intelligence = attribut[7] ,wits = attribut[8] ;
		
	//Les points pour chaque élément d'abilities
	int alertness = abilitie[0] , athletics = abilitie[1] , awareness = abilitie[2], brawl = abilitie[3] , empathy = abilitie[4] , expression = abilitie[5] , intimidation = abilitie[6] , leadership = abilitie[7], streetwise = abilitie[8] , subterfuge = abilitie[9], animalKen =abilitie[10] , crafts = abilitie[11], drive = abilitie[12], etiquette = abilitie[13], firearms = abilitie[14] , larceny = abilitie[15] , melee = abilitie[16], performance = abilitie[17], stealth =abilitie[18] , survival = abilitie[19], academics = abilitie[20], computer = abilitie[21], finance = abilitie[22] , investigation = abilitie[23] , law = abilitie[24] , medicine = abilitie[25], occult = abilitie[26] , politics = abilitie[27] , science = abilitie[28] , technology = abilitie[29] ;
		
	//Disciplines	
	string discipl1 = liste_discip[0] , discipl2 = liste_discip[1] , discipl3 = liste_discip[2] ;
	int discip1 = discipline[0] , discip2 = discipline[1] , discip3 = discipline[2] ;
	
	//Background 		
	string background1 = backgroundListe[0] , background2= backgroundListe[1] , background3= backgroundListe[2] , background4= backgroundListe[3] , background5= backgroundListe[4] ;		
	int backgroundP1 = background[0] , backgroundP2 = background[1] , backgroundP3 = background[2] , backgroundP4 = background[3] , backgroundP5 = background[4] ;
		
	//Virtues	
	int virtue1 = virtues[0] , virtue2 = virtues[1] , virtue3 = virtues[2] ;
	
	attribut.clear();
	abilitie.clear();
	liste_discip.clear();
	discipline.clear();
	backgroundListe.clear();
	background.clear();
	virtues.clear();
			     
	if(!monImage)
	{
        	return false;
	}
	Gtk::Allocation allocation = get_allocation();
	const int height = allocation.get_height();
	const int width = allocation.get_width();
	Gdk::Cairo::set_source_pixbuf(cr, monImage, width-monImage->get_width(), height-monImage->get_height());
	cr->paint();

	Gdk::Cairo::set_source_pixbuf(cr, monImage, width-monImage->get_width(), height-monImage->get_height());
	cr->set_source_rgb(1, 0.0, 0.0); 
	draw_text(cr, 368 , 275 , name);
	draw_text(cr, 368 , 313 , player);
	draw_text(cr, 368 , 351 , chron);
	draw_text(cr, 768 , 275 , nat);
	draw_text(cr, 768 , 313 , dem);
	draw_text(cr, 768 , 351 , conc);
	draw_text(cr, 1168 , 275 , cla);
	draw_text(cr, 1168 , 351 , sir);	
	//Attributs
	draw_text(cr, 368 , 490 , to_string(strenght));
	draw_text(cr, 368 , 525, to_string(dexterity));	
	draw_text(cr, 368 , 561 , to_string(stamina));
	draw_text(cr, 768 , 490 , to_string(charisma));
	draw_text(cr, 768 , 525 , to_string(manipulation));
	draw_text(cr, 768 , 561 , to_string(appearance));
	draw_text(cr, 1168 , 490 , to_string(perception));
	draw_text(cr, 1168 , 525 , to_string(intelligence));
	draw_text(cr, 1168 , 561 , to_string(wits));
	
	
	//Abilities
	draw_text(cr, 368 , 681 , to_string(alertness));
	draw_text(cr, 368 , 718, to_string(athletics));	
	draw_text(cr, 368 , 749 , to_string(awareness));
	draw_text(cr, 368 , 779 , to_string(brawl));
	draw_text(cr, 368 , 809, to_string(empathy));	
	draw_text(cr, 368 , 840 , to_string(expression));
	draw_text(cr, 368 , 872 , to_string(intimidation));
	draw_text(cr, 368 , 902, to_string(leadership));	
	draw_text(cr, 368 , 934 , to_string(streetwise));
	draw_text(cr, 368 , 964 , to_string(subterfuge));
		
	draw_text(cr, 768 , 681 , to_string(animalKen));
	draw_text(cr, 768 , 718 , to_string(crafts));
	draw_text(cr, 768 , 749 , to_string(drive));
	draw_text(cr, 768 , 779 , to_string(etiquette));
	draw_text(cr, 768 , 809 , to_string(firearms));
	draw_text(cr, 768 , 840 , to_string(larceny));
	draw_text(cr, 768 , 872 , to_string(melee));
	draw_text(cr, 768 , 902 , to_string(performance));
	draw_text(cr, 768 , 934 , to_string(stealth));
	draw_text(cr, 768 , 964 , to_string(survival));
		
	draw_text(cr, 1168 , 681 , to_string(academics));
	draw_text(cr, 1168 , 718 , to_string(computer));
	draw_text(cr, 1168 , 749 , to_string(finance));
	draw_text(cr, 1168 , 779 , to_string(investigation));
	draw_text(cr, 1168 , 809 , to_string(law));	
	draw_text(cr, 1168 , 840 , to_string(medicine));
	draw_text(cr, 1168 , 872 , to_string(occult));
	draw_text(cr, 1168 , 902 , to_string(politics));	
	draw_text(cr, 1168 , 934 , to_string(science));
	draw_text(cr, 1168 , 964 , to_string(technology));
		
	//Discipline
	draw_text(cr, 240 , 1118 , discipl1);
	draw_text(cr, 240 , 1155 , discipl2);	
	draw_text(cr, 240 , 1190 , discipl3);
	
	draw_text(cr, 368 , 1118 , to_string(discip1));
	draw_text(cr, 368 , 1155 , to_string(discip2));
	draw_text(cr, 368 , 1190 , to_string(discip3));
	
	//Background 
	draw_text(cr, 578 , 1118 , background1);
	draw_text(cr, 578 , 1155 , background2);	
	draw_text(cr, 578 , 1190 , background3);
	draw_text(cr, 578 , 1225 , background4);	
	draw_text(cr, 578 , 1260 , background5);
	
	draw_text(cr, 768 , 1118 , to_string(backgroundP1));
	draw_text(cr, 768 , 1155 , to_string(backgroundP2));
	draw_text(cr, 768 , 1190 , to_string(backgroundP3));
	draw_text(cr, 768 , 1225 , to_string(backgroundP4));
	draw_text(cr, 768 , 1260 , to_string(backgroundP5));
	
	//Virtues	
	draw_text(cr, 1168 , 1118 , to_string(virtue1));
	draw_text(cr, 1168 , 1190 , to_string(virtue2));
	draw_text(cr, 1168 , 1255 , to_string(virtue3));
	
	//Humanity & Willpower
	draw_text(cr, 668 , 1400 , hu);
	draw_text(cr, 668 , 1560 , wi);
	
	//Blood pool
	draw_text(cr, 668 , 1680 , bloo);
	draw_text(cr, 780 , 1800 , bloot);
		
	return true;
		
}
    
void DrawImage::draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int rectangle_width, int rectangle_height, Glib::ustring text)
{
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_ULTRABOLD);

  auto layout = create_pango_layout(text);

  layout->set_font_description(font);

  int text_width;
  int text_height;

  //get the text dimensions (it updates the variables -- by reference)
  layout->get_pixel_size(text_width, text_height);

  // Position the text in the middle
  cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);
  layout->show_in_cairo_context(cr);
} 	
     	/*    	
     	//Haven      	
     	haven_label.set_text("###########  HAVEN  ###########");   
     	haven_label.set_justify(Gtk::JUSTIFY_LEFT); 	
     	mainGrid.attach(haven_label, 3, 25, 1,1);
  
 	//Localisation de Haven
     	haven_location_label.set_text("  Location:  ");     		
     	mainGrid.attach(haven_location_label, 0, 26, 1,1);
     	location_entry.set_max_length(50);
   	mainGrid.attach(location_entry, 1, 27, 1, 1);
    	
    	//Description de Haven
     	haven_description_label.set_text("  Description:  ");     		
     	mainGrid.attach(haven_description_label, 2, 28, 1,1);
     	description_entry.set_max_length(50);
   	mainGrid.attach(description_entry, 3, 29, 1, 1);
    	
    	//Weakness (faiblesse du personnage)
     	weakness_label.set_text("  Weakness:  ");     		
     	mainGrid.attach(weakness_label, 0, 30, 1,1);
     	weakness_entry.set_max_length(50);
   	mainGrid.attach(weakness_entry, 1, 31, 1, 1);
   
     	*/
     	
  


