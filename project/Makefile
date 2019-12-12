SRC_PATH = src
BUILD_PATH = build
BIN_PATH = $(BUILD_PATH)/bin

BIN_NAME = main
SRC_EXT = cpp

SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)

CFLAGS += -g -O0


all : path $(BIN_PATH)/$(BIN_NAME)

path :
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(BIN_PATH)


$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
		$(CXX) $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@
	

$(BIN_PATH)/$(BIN_NAME) : $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ 

clean:
	rm -rf $(BUILD_PATH)