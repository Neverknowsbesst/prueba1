CXX = g++
CXXFLAGS = -I./hfiles -Wall -std=c++17

# Targets
TARGET_TAREA1 = tarea1
TARGET_CONTAR_PALABRAS = contar_palabras

# Source files
SRC_TAREA1 = tarea1.cpp
SRC_CONTAR_PALABRAS = contar_palabras.cpp

# Object files
OBJ_TAREA1 = tarea1.o
OBJ_CONTAR_PALABRAS = contar_palabras.o

# Rules
all: $(TARGET_TAREA1) $(TARGET_CONTAR_PALABRAS)

# Link the executable for tarea1
$(TARGET_TAREA1): $(OBJ_TAREA1)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Link the executable for contar_palabras
$(TARGET_CONTAR_PALABRAS): $(OBJ_CONTAR_PALABRAS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile tarea1.o
$(OBJ_TAREA1): $(SRC_TAREA1)
	$(CXX) $(CXXFLAGS) -c $<

# Compile contar_palabras.o
$(OBJ_CONTAR_PALABRAS): $(SRC_CONTAR_PALABRAS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET_TAREA1) $(TARGET_CONTAR_PALABRAS) $(OBJ_TAREA1) $(OBJ_CONTAR_PALABRAS)

.PHONY: all clean
