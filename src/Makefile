run: build
	./sol

build:
	g++ -std=c++20 -Wl,--stack,4194304 -ftrapv -Ofast -funroll-all-loops $(file) -o sol 

clean:
	rm -rf sol sol* *~ .*.un~ *.exe.stackdump

