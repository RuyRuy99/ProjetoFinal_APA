# Nome do executável
TARGET = programa

# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Iinclude

# Arquivos fonte
SOURCES = $(wildcard src/*.cpp)

# Arquivos objeto
OBJECTS = $(addprefix build/, $(notdir $(SOURCES:.cpp=.o)))

all: $(TARGET)
#Compilação
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o build/$(TARGET)

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f build/*.o build/$(TARGET)

run:
	./build/$(TARGET)