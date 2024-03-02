Preprocessor.exe: Pre.o Write.o Header.o Macro.o Remove.o Read.o
	gcc Pre.o Write.o Header.o Macro.o Remove.o Read.o -o Preprocessor.exe
Write.o: Write.c
	gcc -c Write.c -o Write.o
Header.o: Header.c
	gcc -c Header.c -o Header.o
Macro.o: Macro.c
	gcc -c Macro.c -o Macro.o
Remove.o: Remove.c
	gcc -c Remove.c -o Remove.o
Read.o: Read.c
	gcc -c Read.c -o Read.o
Pre.o: Pre.c
	gcc -c Pre.c -o Pre.o
