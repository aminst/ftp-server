CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = includes
CFLAGS = -std=c++11 -Wall -Werror -I$(INCLUDE_DIR)

EXECUTABLE_FILE = ftpclient.out

OBJECTS = \
	$(BUILD_DIR)/Main.o \
	$(BUILD_DIR)/FtpClient.o

FtpClientSensitivityList = $(SRC_DIR)/FtpClient.cpp \

MainSensitivityList = \
	$(SRC_DIR)/main.cpp \
	$(INCLUDE_DIR)/FtpClient.hpp

all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/Main.o: $(MainSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/Main.o

$(BUILD_DIR)/FtpClient.o: $(FtpClientSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/FtpClient.cpp -o $(BUILD_DIR)/FtpClient.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out