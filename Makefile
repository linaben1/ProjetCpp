#########################################
# Directory where to put the object files
OBJDIR = ./FilesCpp_h

#########################################
# Directory where to locate source files
SRCDIR = ./FilesCpp_h

#########################################
# Compiler
CC=g++

######################
# All the object files      
OBJFILES = $(OBJDIR)/MiniMain.o $(OBJDIR)/Clan.o $(OBJDIR)/OtherTraits.o $(OBJDIR)/window.o

###############
# All the flagss
DEBUGFLAGS = -O5 -g -DDEBUG -m64 -L /lib64 `pkg-config gtkmm-3.0 --cflags`	
STFLAGS    = -DLCB -DLENGTHTYPE=Uint -pthread `pkg-config gtkmm-3.0 --libs`

VampireProject: $(OBJFILES)
	$(CC) -fstack-protector-strong -g $^ $(STFLAGS) -o $(OBJDIR)/$@ 

# How to make the object files:
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -fstack-protector-strong -g $(DEBUGFLAGS) -c $? -o $@

# Cleaning target (only works with fileutils):
clean:
	/bin/rm -f $(OBJFILES) VampireProject
