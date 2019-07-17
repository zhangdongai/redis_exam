CFLAGS = -c -g -rdynamic -std=c++11
LINKFLAGS = -lhiredis -lpthread
BUILDFLAGS = -O0 -g -rdynamic
CPPSRCS += $(wildcard ./*.cpp)
CPPOBJS = $(patsubst %.cpp,%.o,$(CPPSRCS))

redis_exam: $(CPPOBJS)
        g++ $(BUILDFLAGS) $^ -o $@ $(LINKFLAGS)

test:
        @echo $(CPPSRCS)
        @echo $(CPPOBJS)



.cpp.o:
#       @echo $^
        g++ $(CFLAGS) $< -o $@