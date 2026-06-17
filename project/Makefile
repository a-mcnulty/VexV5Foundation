# ============================================================
#  PROS Project — Local Simulator Makefile
#  Compiles with g++ so you can run on your computer.
#  On a real V5, use: pros make  (uses the PROS toolchain)
# ============================================================

include common.mk

TARGET := $(BINDIR)/robot

all: $(TARGET)
	@echo "Build complete: $(TARGET)"

$(BINDIR):
	mkdir -p $(BINDIR)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: all
	./$(TARGET)

clean:
	rm -rf $(BINDIR)

.PHONY: all run clean
