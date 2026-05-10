CXX = g++
CXXFLAGS = -Iinclude -std=c++11 -Wall

SOURCES = test_runner.cpp \
          src/logger/Logger.cpp \
          src/pager/BufferPool.cpp \
          src/parser/Parser.cpp \
          src/storage/DiskManager.cpp \
          src/storage/Loader.cpp \
          src/storage/Table.cpp \
          src/optimizer/JoinOptimizer.cpp

TARGET = NanoDB.exe

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
