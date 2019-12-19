# Author : XIE Yuxuan
# Date : 2019-12-10

SRC_PATH = src
TEST_PATH = test
BUILD_PATH = build
BIN_PATH = $(BUILD_PATH)/bin
TEST_BUILD_PATH = $(BUILD_PATH)/test
SRC_EXT = cpp

SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
TESTS = $(shell find $(TEST_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)

BIN_NAME += $(TESTS:$(TEST_PATH)/%.$(SRC_EXT)=$(BIN_PATH)/%)

CFLAGS += -g -O0

.PRECIOUS: $(OBJECTS) $(TEST_BUILD_PATH)/%.o


all : path $(BIN_NAME)
	
path :
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(TEST_BUILD_PATH)
	@mkdir -p $(BIN_PATH)

$(BUILD_PATH)/%.d: $(SRC_PATH)/%.$(SRC_EXT)
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT) $(BUILD_PATH)/%.d
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BUILD_PATH)/%.o: $(TEST_PATH)/%.$(SRC_EXT)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_PATH)/% : $(OBJECTS)  $(TEST_BUILD_PATH)/%.o 
	$(CXX) $^ -o $@ 
	
-include $(OBJECTS:$(BUILD_PATH)/%.o=$(BUILD_PATH)/%.d)	

clean:
	rm -rf $(BUILD_PATH)/*