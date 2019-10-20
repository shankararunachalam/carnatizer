.PHONY: clean
CFLAGS=-std=c99 -g -Wall -fno-common -DSIM -I. -I../src -I..//multipass/monome_euro/libavr32/src
DEPS =
OBJ = tt.o \
	../multipass/monome_euro/libavr32/src/euclidean/euclidean.o ..//multipass/monome_euro/libavr32/src/euclidean/data.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tt: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f tt
	rm -rf tt.dSYM
	rm -f *.o
	rm -f ../src/*.o
	rm -f ../libavr32/src/euclidean/*.o
	rm -f ../libavr32/src/*.o
	
