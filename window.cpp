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
     	
 	DistributionPointsAttribut_label.set_text("  Choissisez la combinaison des point soihaité pour  ");
        mainGrid.attach(DistributionPointsAttribut_label, 1 , 3, 1, 1);
	
	DistributionPointsAttribut_combo.append("7/5/3");
	DistributionPointsAttribut_combo.append("7/3/5");
	DistributionPointsAttribut_combo.append("3/7/5");
	DistributionPointsAttribut_combo.append("3/5/7");
	DistributionPointsAttribut_combo.append("5/3/7");
	DistributionPointsAttribut_combo.append("5/7/3");
	
	mainGrid.attach(DistributionPointsAttribut_combo, 3 , 3, 3, 1);
     	
     	
     	

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
	  


     	appearance_label.set_text(" Appearance ");     		
     	mainGrid.attach(appearance_label, 2, 8, 1,1);     	 	
     	spin_appearance.set_range(1,5);
	spin_appearance.set_increments(1,1);
     	  
     	
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
     	mainGrid.attach(spin_appearance, 3, 8, 1, 1);
     	mainGrid.attach(spin_wits, 5, 8, 1, 1); 
     	
     		 

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
        next_button.signal_clicked().connect( sigc::mem_fun(*this,
            &Fenetre::next_button_clicked) );
    	mainGrid.attach(next_button,6 , 10, 1, 1);
   	next_button.add_label("next");   /// Bouton pour passer a la suite du formulaire

  	    	
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
   		

   
	mainGrid.show_all();
	window.add(mainGrid);
	window.show_all_children();
}

Fenetre::~Fenetre() 
{

}

void Fenetre::on_combo_changed()
{

	string text = Clan_combo.get_active_text();
	discipl_list = clan.make_table();
	
	deque<string> liste_discip;
	
	//On détermine ici les disciplines associer au clan que l'utilisateur aura choisi 
	for (auto it = discipl_list.begin(); it!= discipl_list.end(); ++it)
	{
		string text2 = it->first ; 
		if (text == text2)
		{
			liste_discip.push_back(it->second);
						
		}
 	} 	
 	discipl1_label.set_text("  " + liste_discip[0] + ":  ");
 	discipl2_label.set_text("  " + liste_discip[1] + ":  ");
 	discipl3_label.set_text("  " + liste_discip[2] + ":  ");
 	
 	
 	if ( text != "Nosferatu")
 	{
	
 		spin_appearance.show();	
 	}
 	else 	
 	{
  	
		spin_appearance.hide();
  		
 	}
 	
 	

 }
 
void Fenetre::next_button_clicked()
{	
  	//Récuperer les points attribué pour chaque discipline et s'assurer qu'il soit égale a 3 
  	int score1 = spin_discipl1.get_value_as_int();
  	int score2 = spin_discipl2.get_value_as_int();
 	int score3 = spin_discipl3.get_value_as_int();
 	int score_dicipl = score1 + score2 + score3  ; 
 		
 	if (score_dicipl > 3 )
 	{		
 		Gtk::MessageDialog dialog(*this, "Le nombre de points totale de disciplines doit être infèrieur ou égal à 3 !",false,Gtk::MESSAGE_ERROR);
		dialog.run();	
 	} 
 	
 
	
}


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
    
    
    
    
    
    
    
    
























