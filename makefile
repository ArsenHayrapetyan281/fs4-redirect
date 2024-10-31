CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

TARGET = redirect-cin
SRC = redirect-cin.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
