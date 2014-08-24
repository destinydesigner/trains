include ../../../makefile.comm

INCLUDE = -I../../../main/domain/include \
		  -I$(GTEST_INCLUDE_PATH) \
		  -I$(GMOCK_INCLUDE_PATH) \

LIB = \
	  -L../../../main/domain/lib \
	  -lassignment_trains_domain_model \
	  -lassignment_trains_domain_algorithm \
	  -lassignment_trains_domain_service \
	  -lassignment_trains_domain_comm \
	  -L$(GTEST_LIB_PATH) -lgtest \
	  -L$(GMOCK_LIB_PATH) -lgmock -lgmock_main \

OUTPUT = unittest

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all:$(OUTPUT)

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) $(CPPFLAGS) $(INCLUDE) -c $(filter %.cpp, $^) -o $@

$(OUTPUT): $(OBJECTS)
	$(CXX) $(CPPFLAGS) ${LIB} $^ -o $@

clean:
	rm -f $(OUTPUT)
	rm -f $(OBJECTS)
