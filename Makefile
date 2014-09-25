all: libclean_bash_environment.so

libclean_bash_environment.so: clean_bash_environment.o
	gcc -shared -Wl,-soname,libclean_bash_environment.so.1 -o libclean_bash_environment.so clean_bash_environment.o -ldl

clean_bash_environment.o:
	gcc -fPIC -Wall -c clean_bash_environment.c

clean:
	rm -f *.o *.so
