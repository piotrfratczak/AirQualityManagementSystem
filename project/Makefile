target = main.exe
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
cpp = $(wildcard src/*.cpp)
obj = $(cpp:%.cpp=$(OBJ_DIR)/%.o)

CFLAGS += -g

all : $(target) 

$(obj) : $(cpp)
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(cpp)

$(target) :$(obj)
	$(CXX) -o $(target) $(obj)

push:
	@git status
	@git stage .
	@git commit -m "Yx"
	@git push

clean :
	-rm $(target) $(obj)
	
	


	