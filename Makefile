CC=c++
FLAGS=-O2 -pipe -Wall -Wextra -march=native
SRC_DIR=./src
EXPORT=lib/libVIS.a

$(SRC_DIR)/%.o: %.cpp
	$(CC) -c $(FLAGS) -o $@ $<


$(EXPORT): $(patsubst %.cpp, %.o, $(wildcard $(SRC_DIR)/*.cpp))
	ar -r -o $@ $^

makedir:
	mkdir lib

clean:
	rm $(SRC_DIR)/*.o
	rm -rf lib
