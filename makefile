CXX = g++ 
CFLAGS = -W -Wall --std=c++14 -g -lsfml-graphics -lsfml-window -lsfml-system
SRC = src/
INCLUDE=-I include/
BIN= bin/

all: main

main: $(BIN)main.o $(BIN)box.o $(BIN)game.o $(BIN)engine.o $(BIN)screen.o $(BIN)map.o $(BIN)level.o $(BIN)player.o\
	$(BIN)engineConst.o $(BIN)case.o $(BIN)interface.o $(BIN)uiborder.o $(BIN)GUI.o $(BIN)statusBar.o $(BIN)clickableObject.o\
	$(BIN)point.o $(BIN)unit.o $(BIN)villager.o $(BIN)portrait.o $(BIN)group.o $(BIN)action.o $(BIN)input.o $(BIN)pathFinder.o\
	$(BIN)ground.o $(BIN)buildGround.o $(BIN)obstacleGround.o $(BIN)rect.o
	$(CXX) -o  $@ $^ $(CFLAGS) $(INCLUDE)

$(BIN)%.o: $(SRC)%.cpp
	$(CXX) $(INCLUDE) -o $@ -c $< $(CFLAGS)

clean:
	-rm -f $(BIN)*.o
	-rm main
