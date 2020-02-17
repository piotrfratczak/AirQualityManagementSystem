# Author : XIE Yuxuan
# Date : 2019-12-10

SRC_PATH = src
TEST_PATH = test
BUILD_PATH = build
BIN_PATH = $(BUILD_PATH)/bin
TEST_BUILD_PATH = $(BUILD_PATH)/test
SRC_EXT = cpp

CPLEXPATH			:=	/opt/ibm/ILOG/CPLEX_Studio1263

LIBFORMAT			:=	static_pic
SYSTEM			:=	x86-64_linux


CPLEXDIR			:=	$(CPLEXPATH)/cplex
CONCERTDIR		:= 	$(CPLEXPATH)/concert
CPLEXBINDIR		:=	$(CPLEXDIR)/bin/$(SYSTEM)
CPLEXLIBDIR		:=	$(CPLEXDIR)/lib/$(SYSTEM)/$(LIBFORMAT)
CONCERTLIBDIR	:=	$(CONCERTDIR)/lib/$(SYSTEM)/$(LIBFORMAT)

CPLEXFLAGS		:= -isystem$(CPLEXDIR)/include -isystem$(CONCERTDIR)/include -DNDEBUG
CPLEXLNFLAGS  := -L$(CPLEXLIBDIR) -lilocplex -lcplex -L$(CONCERTLIBDIR) -lconcert -lm -m64 -lpthread

SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
TESTS = $(shell find $(TEST_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)

BIN_NAME += $(TESTS:$(TEST_PATH)/%.$(SRC_EXT)=$(BIN_PATH)/%)

CFLAGS += -g -O0 -pedantic -std=c++1y -DIL_STD

#FLAGS += -g -O0 -pedantic -std=c++1y -DIL_STD


.PRECIOUS: $(OBJECTS) $(TEST_BUILD_PATH)/%.o

all : path $(BIN_NAME)

CXX = g++ 

path :
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(TEST_BUILD_PATH)
	@mkdir -p $(BIN_PATH)

$(BUILD_PATH)/%.d: $(SRC_PATH)/%.$(SRC_EXT)
	@mkdir -p $(BUILD_PATH)
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) $(CPLEXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT) $(BUILD_PATH)/%.d
	$(CXX) $(CFLAGS) -c $< $(CPLEXFLAGS) -o $@

$(TEST_BUILD_PATH)/%.o: $(TEST_PATH)/%.$(SRC_EXT)
	$(CXX) $(CFLAGS) -c $< $(CPLEXFLAGS) -o $@

$(BIN_PATH)/% : $(OBJECTS)  $(TEST_BUILD_PATH)/%.o 
	$(CXX) -o $@ $^ $(CPLEXLNFLAGS) 

py:
	$(CXX) -O3 -Wall -shared -std=c++11 -DIL_STD -fPIC $(CPLEXFLAGS) `python3 -m pybind11 --includes` pm.cpp src/* -o testyx`python3-config --extension-suffix`
	
-include $(OBJECTS:$(BUILD_PATH)/%.o=$(BUILD_PATH)/%.d)	

clean:
	rm -rf $(BUILD_PATH)
