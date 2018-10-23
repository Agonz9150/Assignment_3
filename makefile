# This makefile is for deck_hands_main.c
 
CC=gcc

#List of source files
Files = deck_hands_main.c Input_check.c deck_operations.c 
Files_2 = print_operations.c hand_operations.c
All_files = $(Files) $(Files_2)

#Required header
Head = deck_hands.h

# builds executable file as standard make
# executable requires 2 user inputs, both int from 1 to 13  
build: $(FILES) $(Head) 
	$(CC) $(All_files)

