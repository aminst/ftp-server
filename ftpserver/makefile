CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = includes
CFLAGS = -std=c++11 -pthread -Wall -Werror -I$(INCLUDE_DIR)

EXECUTABLE_FILE = ftpserver.out

OBJECTS = \
	$(BUILD_DIR)/Main.o \
	$(BUILD_DIR)/FtpServer.o \
	$(BUILD_DIR)/CommandHandler.o \
	$(BUILD_DIR)/CommandParser.o \
	$(BUILD_DIR)/Request.o \
	$(BUILD_DIR)/ConfigParser.o \
	$(BUILD_DIR)/User.o \
	$(BUILD_DIR)/UserManager.o

UserManagerSensitivityList = $(SRC_DIR)/UserManager.cpp \
	$(INCLUDE_DIR)/User.hpp

UserSensitivityList = $(SRC_DIR)/User.cpp

ConfigParserSensitivityList = $(SRC_DIR)/ConfigParser.cpp \
	$(INCLUDE_DIR)/User.hpp \
	$(INCLUDE_DIR)/Json.hpp

CommandParserSensitivityList = $(SRC_DIR)/CommandParser.cpp \
	$(INCLUDE_DIR)/Request.hpp

CommandHandlerSensitivityList = $(SRC_DIR)/CommandHandler.cpp \
	$(INCLUDE_DIR)/CommandParser.hpp \
	$(INCLUDE_DIR)/Request.hpp

RequestSensitivityList = $(SRC_DIR)/Request.cpp

FtpServerSensitivityList = $(SRC_DIR)/FtpServer.cpp \
	$(INCLUDE_DIR)/CommandHandler.hpp \
	$(INCLUDE_DIR)/UserManager.hpp \
	$(INCLUDE_DIR)/ConfigParser.hpp

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

$(BUILD_DIR)/CommandHandler.o: $(CommandHandlerSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/CommandHandler.cpp -o $(BUILD_DIR)/CommandHandler.o	

$(BUILD_DIR)/CommandParser.o: $(CommandParserSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/CommandParser.cpp -o $(BUILD_DIR)/CommandParser.o	

$(BUILD_DIR)/Request.o: $(RequestSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Request.cpp -o $(BUILD_DIR)/Request.o

$(BUILD_DIR)/ConfigParser.o: $(ConfigParserSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ConfigParser.cpp -o $(BUILD_DIR)/ConfigParser.o

$(BUILD_DIR)/User.o: $(UserSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/UserManager.o: $(UserManagerSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/UserManager.cpp -o $(BUILD_DIR)/UserManager.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out