CC := g++
CFLAGS := -std=c++11 -Wall -Wextra

SRCS := main.cpp Piece.cpp LstPiece.cpp jeu.cpp
OBJS := $(SRCS:.cpp=.o)

EXEC := tetriste

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	del $(OBJS) $(EXEC)

.PHONY: clean
