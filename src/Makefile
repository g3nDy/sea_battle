# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -pedantic

# Object files
OBJECTS = main.o Ship.o ShipManager.o GameField.o

# Target
TARGET = game

# Rules
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^

main.o: main.cpp Ship.h ShipManager.h GameField.h
	$(CXX) $(CXXFLAGS) -c $<

ship.o: Ship.cpp Ship.h
	$(CXX) $(CXXFLAGS) -c $<

ship_manager.o: ShipManager.cpp ShipManager.h Ship.h
	$(CXX) $(CXXFLAGS) -c $<

game_field.o: GameField.cpp GameField.h Ship.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

