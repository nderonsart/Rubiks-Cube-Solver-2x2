CC = gcc
CFLAGS = -Wall


# Objectifs
exec : ../bin/rubiksCube.o ../bin/rotations.o ../bin/structures.o 
	$(CC) $(CFLAGS) $^ -o ../exec

../bin/rubiksCube.o : rubiksCube.c rotations.h structures.h
	$(CC) $(CFLAGS) -c $< -o $@

../bin/rotations.o : rotations.c rotations.h structures.h
	$(CC) $(CFLAGS) -c $< -o $@

../bin/structures.o : structures.c structures.h
	$(CC) $(CFLAGS) -c $< -o $@
	

# Le menage
clean:
	@rm ../bin/*.o 2> /dev/null || true
	@echo "cleaning done"


