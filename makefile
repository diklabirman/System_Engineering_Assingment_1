CC=gcc
CFLAGS=-Wall 
TARGETS=loops loopd recursives recursived mains maindloop maindrec

all: $(TARGETS)

.c.o:
	$(CC) $(CFLAGS) -c $<

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a $^

loops: libclassloops.a	

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -o libclassloops.so $^

loopd: libclassloops.so

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a $^

recursives: libclassrec.a

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -o libclassrec.so $^
	
recursived: libclassrec.so
	
mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a -lm	
	
maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o ./libclassloops.so -lm
	
maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o ./libclassrec.so -lm
	
clean:
	rm -f *.o *.a *.so 