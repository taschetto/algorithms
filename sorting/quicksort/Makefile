compiler = g++
cflags   = -std=c++0x -Wall
ldflags  = -std=c++0x -c -Wall
sources	 = main.cpp
objects  = $(sources:.cpp=.o)
folder   = $(shell basename $(CURDIR))
target	 = $(folder)

all: $(sources) $(target)
	
$(target): $(objects) 
	$(compiler) $(objects) -o $@

.cpp.o:
	$(compiler) $(ldflags) $<

clean:
	rm -fr *.o $(target)
