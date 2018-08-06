CC=gcc

INCLUDES=-I../commun\
	 -I./

################################################################################

OBJFILES=testMontant.o 

dll:	$(OBJFILES) \
		 /usr/local/galss/libgalcllux.so \
		 /usr/local/galss/libgalinlux.so
	$(CC) $(LDFLAGS) $(OBJFILES) -o testMontant -L/lib -L/usr/local/galss  -lgalcllux -lgalinlux


################################################################################


testMontant.o : ../commun/testMontant.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c ../commun/testMontant.c -o testMontant.o


