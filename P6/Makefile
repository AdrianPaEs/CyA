CXX = g++
CXXFLAGS = -std=c++11 #-Wall #-Wextra
SRC_DIR = src
BUILD_DIR = build

TARGET = p06_automata_simulator

# Lista de archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*.cc)
BUILDS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(BUILDS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)