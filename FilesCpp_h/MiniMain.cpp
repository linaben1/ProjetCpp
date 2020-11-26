#include "MiniProjet.h"
#include <gtkmm/application.h>


int main(int argc, char *argv[])
{
  
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
  
  
  Fenetre f;
 
 
  return app->run(f);
  //On l'affiche, l'exécute
  
}


