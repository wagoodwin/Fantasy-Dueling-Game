# fdg = Fantasy Dueling Game
fdg: main.o Dueler.o Player.o Computer.o GameProcedures.o
	g++ main.o Dueler.o Player.o Computer.o GameProcedures.o -o fdg

main.o: main.cpp
	g++ -c main.cpp

Dueler.o: Dueler.cpp
	g++ -c Dueler.cpp

Computer.o: Computer.cpp
	g++ -c Computer.cpp

GameProcedures.o: GameProcedures.cpp
	g++ -c GameProcedures.cpp

# *.o means 'select everything with extension .o'.
# We're also removing our executable file FDG
clean:
	rm *.o fdg tempCodeRunnerFile tempCodeRunnerFile.cpp