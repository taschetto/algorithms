compiler = g++
incpath  = ../../include/
cflags   = -std=c++0x -Wall
ldflags  = -std=c++0x -c -Wall
sources	 = main.cpp
objects  = $(sources:.cpp=.o)
folder   = $(shell basename $(CURDIR))
target	 = $(folder)

all: $(sources) $(target)
	
$(target): $(objects) 
	$(compiler) $(objects) -o $@ -I$(incpath)

.cpp.o:
	$(compiler) $(ldflags) $< -I$(incpath)

clean:
	rm -fr *.o $(target)
