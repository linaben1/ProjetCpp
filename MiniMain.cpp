#include "MiniProjet.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  
  auto app = Gtk::Application::create(argc, argv);
  
  Fenetre f;
 
 
  app->run(f.window);
  //On l'affiche, l'exécute
  return 0;
}
