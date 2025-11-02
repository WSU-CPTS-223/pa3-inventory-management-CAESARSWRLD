# Default target
all: mainexe

# Build the executable
mainexe: main.cpp product.cpp csvReading.cpp productMap.cpp
	g++ -g -Wall -std=c++14 main.cpp product.cpp csvReading.cpp productMap.cpp -o mainexe

# Run the program
run: mainexe
	./mainexe

# Clean up build files
clean:
	rm -f mainexe
