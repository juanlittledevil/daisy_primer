# Project Name
TARGET = MyProj

# Sources
# CPP_SOURCES = src/main.cpp
CPP_SOURCES = $(wildcard src/*.cpp)

# Include Directories
INCLUDES = -Iinclude

# Library Locations
LIBDAISY_DIR = ../../libDaisy/
DAISYSP_DIR = ../../DaisySP/

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

# Add INCLUDES to the compilation flags
CFLAGS += $(INCLUDES)
CXXFLAGS += $(INCLUDES)