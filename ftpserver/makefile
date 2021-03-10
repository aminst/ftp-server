CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = includes
CFLAGS = -std=c++11 -Wall -Werror -I$(INCLUDE_DIR)

EXECUTABLE_FILE = ftpserver.out

OBJECTS = \
	$(BUILD_DIR)/Main.o \
	$(BUILD_DIR)/FtpServer.o

FtpServerSensitivityList = $(SRC_DIR)/FtpServer.cpp \

MainSensitivityList = \
	$(SRC_DIR)/main.cpp \
	$(INCLUDE_DIR)/FtpServer.hpp

all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/Main.o: $(MainSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/Main.o

$(BUILD_DIR)/FtpServer.o: $(FtpServerSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/FtpServer.cpp -o $(BUILD_DIR)/FtpServer.o	

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out