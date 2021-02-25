


all: gamestate

gamestate:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -D TEST_BUILD=1 test_gamestate.cpp $(SOURCES) -o out/gamestate
	./out/gamestate
# 	rm ./out/gamestate

snake:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -D TEST_BUILD=1 test_snake_obj.cpp $(SOURCES) -o out/snake
	./out/snake
	rm ./out/snake

# engine:
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) -D TEST_BUILD=1 test_engine.cpp $(SOURCES) -o out/gamestate
# 	./out/engine
# 	rm ./out/engine
