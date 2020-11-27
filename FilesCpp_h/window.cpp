#include "MiniProjet.h"

Clan clan;
OtherTraits otherTraits;
Attributes attributes;

/****************************************************************************************************************************************************************/
/****************************************************************************************************************************************************************/
/****************************************************************************************************************************************************************/

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
	
	//////////////////////////////////PAGE1/////////////////////////////////
	boxV.pack_start(pages);	
	pages.append_page(mainGrid, "page 1 ");
	
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
 	DistributionPointsAttribut_label.set_text(" Choose the combination for points distributed to attributes (PHYSICAL, SOCIAL, MENTAL) : ");
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
    	pages.append_page(mainGrid2, "page2");
       	
    	
  	//Choix de la combinaison de points pour les différents catégories d'abilities
	DistributionPointsAbilities_label.set_text("Choose the combination for points distributed to abilities ( TALENTS, SKILLS, KNOWLEDGES ) : ");
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
    	pages.append_page(mainGrid3, "page3");
       	  	   	
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
		background2_combo.append(backgroundName_list[i]);
		background3_combo.append(backgroundName_list[i]);
	}		
    	mainGrid3.attach(background1_combo, 2, 2, 1, 1);
    	mainGrid3.attach(background2_combo, 2, 3, 1, 1);
    	mainGrid3.attach(background3_combo, 2, 4, 1, 1);
    	
    	
	//Signal des boutons forward & back & create
	back.signal_clicked().connect(sigc::mem_fun(pages, &Gtk::Notebook::prev_page));
    	forward.signal_clicked().connect(sigc::mem_fun(pages, &Gtk::Notebook::next_page));

	//Bouton pour afficher la feuille du personnage      
   	create_button.signal_clicked().connect( sigc::mem_fun(*this,
            &Fenetre::create_button_clicked) );
  
    	create_button.add_pixlabel("info.xpm", "Open File");
    	
  	show_all_children();
}

Fenetre::~Fenetre() 
{

}
//////////////////////////////////
void Fenetre::on_combo_changed() //Signal du changement de la combobox de clan qui permet de déterminer les différents disciplines liée au clan choisi et l'apparance au niveau des abilities au cas ou le nom du clan est un Nosferatu 
{	
	//On récupere le choix du clan de l'utilisateur 
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
}
 
//////////////////////////////////////////////////////////////////////////////// 

void Fenetre::create_button_clicked() //Signal du changement de la combobox
{

	string text_pointattributs = DistributionPointsAttribut_combo.get_active_text();
	string text_clanname = Clan_combo.get_active_text();
	
	//point physic
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

	int cond = attributes.check_attributspoint(text_pointattributs , score_physical_total , score_social_total , score_mental_total  );
	
	if(cond != 10)
	{
		Gtk::MessageDialog dialog(*this, " Please choose a desired combination of points for abilities & attributes & Clan Name before proceeding next !",false,Gtk::MESSAGE_ERROR);
		dialog.run();		
	}

}	
	/*
	
	int condition = 10 ; 
	//Récuperer la combinaison d'attribution de points choisi pour les différentes catégories d'abilities & d'attributs.
	string text_pointabilities = DistributionPointsAbilities_combo.get_active_text();
	string text_pointattributs = DistributionPointsAttribut_combo.get_active_text();
	string text_clanname = Clan_combo.get_active_text();

	if(text_clanname == "" || text_pointabilities == "" || text_pointattributs == "" || )
	{
		condtion--;			
 		Gtk::MessageDialog dialog(*this, " Please choose a desired combination of points for abilities & attributes & Clan Name before proceeding next !",false,Gtk::MESSAGE_ERROR);
		dialog.run();	 
	}
	else
	{	
				/////////////////////////// Gérer les distribution de points pour les attributs////////////////////////			
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
 				condition--;
 				Gtk::MessageDialog dialog(*this, "The number of total points of PHYSICAL, SOCIAL and MENTAL attributes must equal 7, 5, 3 respectively !",false,Gtk::MESSAGE_ERROR);
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
 			Gtk::MessageDialog dialog(*this, "The number of total points of PHYSICAL, SOCIAL and MENTAL attributes must equal 7, 3, 5 respectively !",false,Gtk::MESSAGE_ERROR);
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
     	
     	

/*

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

*/

/*

void button validé {

	
        //Button pour valider les discipline 
        next1_button.signal_clicked().connect( sigc::mem_fun(*this,
            &Fenetre::next1_button_clicked) );
    	mainGrid.attach(next1_button,6 , 10, 1, 1);
   	next1_button.add_label("next");   /// Bouton pour passer a la suite du formulaire


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
    
    
    
    
    
    
    
    
























