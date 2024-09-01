.DEFAULT_GOAL := client02
OBJDIR := object_files
CXX := g++
CXXFLAGS := -g
CONST_PATH := ressources/constants
OBJS := $(addprefix $(OBJDIR)/, main.o constants.o)
VPATH := ressources/constants object_files

client02: $(OBJS)
	@echo "Linking the client..."
	$(CXX) -o client02 $^
	
$(OBJDIR)/main.o: main.cpp constants.h
	@echo "Compiling main.cpp..."
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/constants.o: constants.cpp constants.h
	@echo "Compiling constants.cpp..."
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

launch: client02
	./client02 -i

.PHONY: clean
clean:
	@echo "Removing everything but the source files..."
	rm -rf $(OBJDIR)

