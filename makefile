CC=gcc
CFLAGS=-Wall 
TARGETS=loops loopd recursives recursived mains maindloop maindrec

all: $(TARGETS)

.c.o:
	$(CC) $(CFLAGS) -c $<

loops: basicClassification.o advancedClassificationLoop.o
	$(AR) -r libclassloops.a $^
	ranlib libclassloops.a
	
loopd: basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -o libclassloops.so $^

recursives: basicClassification.o advancedClassificationRecursion.o
	$(AR) -r libclassrec.a $^
	ranlib libclassrec.a
	
recursived: basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -o libclassrec.so $^
	
mains: main.o recursives
	$(CC) $(CFLAGS) -o main main.o -static -L. -lclassrec -lm	
	
maindloop: main.o loopd
	$(CC) -o maindloop main.o -L. -lclassloops -lm
	
maindrec: main.o recursived
	$(CC) -o maindrec main.o -L. -lclassrec -lm
	
clean:
	rm -f *.o *.a *.so 