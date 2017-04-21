.PHONY: all clean force

export CC65_HOME:= /usr/share/cc65/

SOURCES 		:= $(wildcard src/*.c)
A_SOURCES 		:= $(wildcard src/*.s)
OBJECTS	 		:= $(SOURCES:.c=.o)  
A_OBJECTS 		:= $(A_SOURCES:.s=.o)
ALL_OBJECTS 	:= $(addprefix bin/, $(notdir $(A_OBJECTS))) $(addprefix bin/, $(notdir $(OBJECTS)))

force:

all: bin/hello_world.nes
	
sgen/%.s: src/%.c force
	cc65 -Oi $< -o $@ --add-source 
	
bin/%.o: sgen/%.s force
	ca65 -o $@ $<
	
bin/%.o: src/%.s force
	ca65 -o $@ $<
	
bin/hello_world.nes: $(ALL_OBJECTS)
	ld65 -C nes.cfg -o bin/hello_world.nes $^ nes.lib
	
clean:
	-rm bin/* -rfv
	-rm gen/* -rfv