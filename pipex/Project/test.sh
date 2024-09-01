#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print a pass message
pass() {
    echo -e "${GREEN}Pass: $1${NC}"
}

# Function to print a fail message
fail() {
    echo -e "${RED}Fail: $1${NC}"
    exit 1
}

# Function to check a condition
check() {
    if [ $1 -eq 0 ]; then
        pass "$2"
    else
        fail "$2"
    fi
}

# Function to check the existence of a file
check_file() {
    if [ -f "$1" ]; then
        pass "$2"
    else
        fail "$2"
    fi
}

# Prerequisites
echo -e "${YELLOW}Checking prerequisites...${NC}"

# Check if Makefile exists
check_file "Makefile" "Makefile exists."

# Check if the repository is not empty
if [ "$(ls -A .)" ]; then
    pass "Repository is not empty."
else
    fail "Repository is empty."
fi

# Check if the correct files are submitted
check_file "pipex.c" "pipex.c file is present."
check_file "pipex.h" "pipex.h file is present."
check_file "utils.c" "utils.c file is present."



# Check for cheating (-42 score)
# (This would be specific to your system, so let's just assume we're not checking this here)

# Compilation test
echo -e "${YELLOW}Compiling the project...${NC}"
make re > /dev/null 2>&1
check $? "Compilation succeeded without errors."

# Check if the executable is named pipex
check_file "pipex" "Executable named 'pipex' is present."

# Ensure no forbidden functions are used (this check is up to you to define; could involve checking source code manually or with a tool)

# Error and Argument Handling
echo -e "${YELLOW}Testing error and argument handling...${NC}"

# Test invalid number of arguments
./pipex a b c > /dev/null 2>&1
check $? "Correctly handles invalid number of arguments."

# Test invalid file or permission denied
./pipex non_existent_file "ls" "wc -l" output > /dev/null 2>&1
check $? "Correctly handles non-existent input file."

./pipex Makefile "nonexistentcmd" "wc -l" output > /dev/null 2>&1
check $? "Correctly handles non-existent command."

# Test the program's functionality
echo -e "${YELLOW}Testing the program's functionality...${NC}"

# Create input files for testing
echo -e "hello world\nthis is a test file\npipex project\n" > infile

# Expected outputs
echo -e "hello world\nthis is a test file\npipex project\n" | grep test | wc -w > expected_output

# Run the program
./pipex infile "grep test" "wc -w" output > /dev/null 2>&1

# Compare the output
diff output expected_output > /dev/null 2>&1
check $? "Program output matches expected output."

# Final message
echo -e "${GREEN}All checks passed!${NC}"
