# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -lcairo -Iinclude -I/usr/include/cairo

# Directories
SRC_DIR = src
INC_DIR = include
OUT_DIR = output
REPORT_DIR = $(OUT_DIR)/ReportCards

# Source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

# Final executable
EXEC = student_manager

# Create necessary directories
$(shell mkdir -p $(OUT_DIR) $(REPORT_DIR))

# Default rule to build the executable
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@ $(CFLAGS)

# Rule to compile the source files into object files
$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean up generated files
clean:
	rm -rf $(OUT_DIR)/*.o $(EXEC)

# Rule to generate a PDF report card for a student with a given ID
generate_report: $(EXEC)
	./$(EXEC) generate_report 101  # Example, change student ID as needed

# Phony targets (not actual files)
.PHONY: all clean generate_report
