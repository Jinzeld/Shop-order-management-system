CC = g++ -g
EXE_FILE = coffee

all: $(EXE_FILE)

$(EXE_FILE): coffee.o coffee.h display.o display.h menu.o menu.h order.o order.h shop.o shop.h prog.o
	$(CC) coffee.o display.o menu.o order.o shop.o prog.o -o $(EXE_FILE)

coffee.o: coffee.h coffee.cpp
	$(CC) -c coffee.cpp

display.o: display.h display.cpp
	$(CC) -c display.cpp

menu.o: menu.h menu.cpp
	$(CC) -c menu.cpp

order.o: order.h order.cpp
	$(CC) -c order.cpp

shop.o: shop.h shop.cpp
	$(CC) -c shop.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.o  $(EXE_FILE)