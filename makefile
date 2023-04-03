filme: main.c cadastro.c
	gcc main.c cadastro.c -o filme

run: filme
	./filme

clean:
	rm -f filme
