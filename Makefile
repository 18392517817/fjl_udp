SER_BIN=server
CLI_BIN=client
SER_SRC= server.cpp
CLI_SRC= client.cpp
INCLUDE=-I./
CC=g++
FLSGE=-g
.PHONY:all 
all:$(SER_BIN) $(CLI_BIN)

$(SER_BIN):$(SER_SRC)
	$(CC) -o $@ $^  $(FLSGE) $(INCLUDE)
$(CLI_BIN):$(CLI_SRC)
	$(CC) -o $@ $^  $(FLSGE) $(INCLUDE)

.PHONY:clean
clean:
	rm -rf $(SER_BIN) $(CLI_BIN)
