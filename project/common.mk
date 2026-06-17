# Common definitions used by Makefile
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
INCDIR   := include
SRCDIR   := src
BINDIR   := bin

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)
