# The names of the executables, and the names of the C++ files we use to build them
TARGETS  = text_server text_client binary_server binary_client select_server select_client
CXXFILES = text_server text_client binary_server binary_client select_server select_client

# Basic tool configuration for a 64-bit build
BITS     ?= 64
CXX       = g++
LD        = g++
CXXFLAGS += -MMD -O3 -m$(BITS) -ggdb -std=c++17 -Wall -Werror -Wextra -march=native
LDFLAGS  += -m$(BITS)

# Compute the names of everything that gets built; make the output folder
ODIR       := ./obj$(BITS)
out_folder := $(shell mkdir -p $(ODIR))
EXEFILES    = $(patsubst %, $(ODIR)/%.exe, $(TARGETS))
OFILES      = $(patsubst %, $(ODIR)/%.o, $(CXXFILES))
DFILES      = $(patsubst %, $(ODIR)/%.d, $(CXXFILES))

# Build 'all' by default, and don't clobber .o files after each build
.DEFAULT_GOAL = all
.PRECIOUS: $(OFILES)
.PHONY: all clean

# Goal is to build all executables
all: $(EXEFILES)

# Build a .o from a .cc
$(ODIR)/%.o: %.cc
	@echo "[CXX] $< --> $@"
	@$(CXX) $< -o $@ -c $(CXXFLAGS)

# Build each .exe from its corresponding .o file
$(ODIR)/text_server.exe: $(ODIR)/text_server.o
	@echo "[LD] $^ --> $@"
	@$(LD) $^ -o $@ $(LDFLAGS)

$(ODIR)/text_client.exe: $(ODIR)/text_client.o
	@echo "[LD] $^ --> $@"
	@$(LD) $^ -o $@ $(LDFLAGS)

$(ODIR)/binary_server.exe: $(ODIR)/binary_server.o
	@echo "[LD] $^ --> $@"
	@$(LD) $^ -o $@ $(LDFLAGS)

$(ODIR)/binary_client.exe: $(ODIR)/binary_client.o
	@echo "[LD] $^ --> $@"
	@$(LD) $^ -o $@ $(LDFLAGS)

$(ODIR)/select_server.exe: $(ODIR)/select_server.o
	@echo "[LD] $^ --> $@"
	@$(LD) $^ -o $@ $(LDFLAGS)

$(ODIR)/select_client.exe: $(ODIR)/select_client.o
	@echo "[LD] $^ --> $@"
	@$(LD) $^ -o $@ $(LDFLAGS)

# Clean by clobbering the build folder
clean:
	@echo Cleaning up...
	@rm -rf $(ODIR)

# Include the auto-generated dependency files, so that re-making is quick
-include $(DFILES)
