.PHONY: clean
INC = \
		-I../src 														\
		-I../multipass			 										\
		-I../multipass/monome_euro/libavr32/src 						\
		-I../multipass/monome_euro/libavr32/asf/avr32/utils				\
		-I../multipass/monome_euro/libavr32/asf/common/utils			\
		-I../multipass/monome_euro/libavr32/asf/avr32/utils/preprocessor				

OBJ = sim_tt.o ../src/control.o ../src/engine.o sim_main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(INC)

sim_tt: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(INC)

clean:
	rm -f sim_tt
	rm -rf sim_tt.dSYM
	rm -f *.o
	rm -f ../src/*.o
