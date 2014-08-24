INSTALL_PATH = ../../lib

INCLUDE = -I../../include

OUTPUT = libassignment_trains_domain_service.a

OBJECTS=$(patsubst %.cpp, %.o, $(wildcard *.cpp))

all:$(OUTPUT)

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) $(CPPFLAGS) $(INCLUDE) -c $(filter %.cpp, $^) -o $@

.o:
	$(CXX) $(CPPFLAGS) $(INCLUDE) -o $@ $^

$(OUTPUT): $(OBJECTS)
	ar -rs $@ $^

clean:
	rm -f *.o *.a *.~ *.bak
	rm -f $(OBJECTS)

install:
	cp -fv $(OUTPUT) $(INSTALL_PATH)
