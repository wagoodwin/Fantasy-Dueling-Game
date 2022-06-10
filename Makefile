# fdg = Fantasy Dueling Game
fdg: main.o Dueler.o Player.o Computer.o GameProcedures.o randUtils.o
	g++ -g main.o Dueler.o Player.o Computer.o GameProcedures.o randUtils.o -o fdg

main.o: main.cpp
	g++ -g -c main.cpp

Dueler.o: Dueler.cpp
	g++ -g -c Dueler.cpp

Player.o: Player.cpp
	g++ -g -c Player.cpp

Computer.o: Computer.cpp
	g++ -g -c Computer.cpp

GameProcedures.o: GameProcedures.cpp
	g++ -g -c GameProcedures.cpp

randUtils.o: randUtils.cpp
	g++ -g -c randUtils.cpp

# *.o means 'select everything with extension .o'.
# We're also removing our executable file FDG
clean:
	rm *.o fdg tempCodeRunnerFile tempCodeRunnerFile.cpp