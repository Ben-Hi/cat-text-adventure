CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors

OBJS = main.o validateInt.o Game.o Space.o Bedroom.o Kitchen.o FrontDoor.o Wall.o Road.o Item.o Catnip.o Shoes.o Cat.o Inventory.o 

SRCS = main.cpp validateInt.cpp Game.cpp Space.cpp Bedroom.cpp Kitchen.cpp FrontDoor.cpp Wall.cpp Road.cpp Item.cpp Catnip.cpp Shoes.cpp Cat.cpp Inventory.cpp

HEADERS = validateInt.hpp Game.hpp Space.hpp Bedroom.hpp Kitchen.hpp FrontDoor.hpp Wall.hpp Road.hpp Item.hpp Catnip.hpp Shoes.hpp Cat.hpp Inventory.hpp

lab3: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS}  -o Cat_Comes_Back

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o Cat_Comes_Back

VOPT =	--tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes


