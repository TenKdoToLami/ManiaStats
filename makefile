CXX = g++
CXXFLAGS = -std=c++11 -Wall
LIBS = -lcurl

SRCDIR = src
INCDIR = include
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(addprefix $(BINDIR)/, $(notdir $(SRCS:.cpp=.o)))
TARGET = main.out

$(BINDIR)/$(TARGET): $(BINDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(INCDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

compile: $(BINDIR)/$(TARGET)

clean:
	rm -f $(OBJS) $(BINDIR)/$(TARGET)
	rmdir -p $(BINDIR)

run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)
