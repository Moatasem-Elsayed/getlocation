
CXX = g++
BUILD_DIRECTORY=build/

$(BUILD_DIRECTORY)getlocation: $(BUILD_DIRECTORY)main.o $(BUILD_DIRECTORY)client.o $(BUILD_DIRECTORY)parser.o
	@$(CXX) $^ -o $(BUILD_DIRECTORY)getlocation

$(BUILD_DIRECTORY)parser.o: parser.cpp $(BUILD_DIRECTORY)
	@$(CXX) --std=c++17 -c parser.cpp -o $(BUILD_DIRECTORY)parser.o
$(BUILD_DIRECTORY)client.o: client.cpp $(BUILD_DIRECTORY)
	@$(CXX) --std=c++17 -c client.cpp -o $(BUILD_DIRECTORY)client.o
$(BUILD_DIRECTORY)main.o: main.cpp $(BUILD_DIRECTORY)
	@$(CXX) --std=c++17 -c main.cpp -o $(BUILD_DIRECTORY)main.o

$(BUILD_DIRECTORY):
	@mkdir build
clean:
	@rm -rf $(BUILD_DIRECTORY)
