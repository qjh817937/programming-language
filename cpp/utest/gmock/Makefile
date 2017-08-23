all:
	g++ -c FooTest.cpp GtestMain.cpp
	g++ -o gmock_test GtestMain.o FooTest.o -L./ -lgmock -lgtest -lpthread
test:
	./gmock_test
clean:
	rm -f *.o gmock_test
