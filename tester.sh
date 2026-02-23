#!/bin/bash

# ==============================================================================
# CONFIGURATION
# ==============================================================================
EXEC="./myAwesomePhoneBook"

# Colors (e = interpret backslash escapes)
G='\033[0;32m' # Green
R='\033[0;31m' # Red
Y='\033[1;33m' # Yellow
B='\033[1;34m' # Blue
NC='\033[0m'   # No Color

ID=1

# Helper function to print group headers
print_header() {
    echo -e "\n${B}>>> GROUP: $1${NC}"
}

# The Core Test Function
run_test() {
    # Print test ID and Name (padded to 30 chars for alignment)
    printf "${NC}[%02d] %-30s: " "$ID" "$1"
    
    # Execute program with piped input
    OUTPUT=$(printf "$2" | $EXEC 2>&1)
    
    # Check for keywords ($3)
    if echo "$OUTPUT" | grep -iq "$3"; then
        echo -e "${G}PASS${NC}"
    else
        echo -e "${R}FAIL${NC}"
        echo -e "     ${Y}Expected keyword to find:${NC} '$3'"
    fi
    ((ID++))
}

# ==============================================================================
# STARTING TEST SUITE
# ==============================================================================
echo -e "${Y}--- Starting PhoneBook Validation ---${NC}"

# Check if file exists
if [ ! -f "$EXEC" ]; then
    echo -e "${R}Error: $EXEC not found. Compile your code!${NC}"
    exit 1
fi

# --- GROUP 1: COMMAND LOOP ---
print_header "BASIC FLOW"
run_test "Exit program" "EXIT\n" "command"
run_test "Empty input" "\n\nEXIT\n" "command"

# --- GROUP 2: DATA ENTRY (ADD) ---
print_header "ADD LOGIC"
# Test if it accepts a full contact
ADD_FULL="ADD\nJohn\nDoe\nJD\n123\nSecret\nSEARCH\nEXIT\n"
run_test "Add standard user" "$ADD_FULL" "John"

# Test for empty field handling (Your program should ask again or error)
ADD_EMPTY="ADD\n\nJohn\nDoe\nJD\n123\nSecret\nSEARCH\nEXIT\n"
run_test "Add with empty first name" "$ADD_EMPTY" "error|empty|invalid"

# --- GROUP 3: SEARCH & FORMATTING ---
print_header "SEARCH & FORMATTING"
# Test the 10-character limit (Truncation)
TRUNC="ADD\nBernadette\nDoe\nJD\n123\nSecret\nSEARCH\nEXIT\n"
run_test "10-char Truncation" "$TRUNC" "Bernadett."

# Test index out of range
SEARCH_OOB="ADD\nJ\nD\nJD\n1\nS\nSEARCH\n9\nEXIT\n"
run_test "Search index 9 (Out of Bounds)" "$SEARCH_OOB" "invalid|error"

# --- GROUP 4: CIRCULAR BUFFER ---
print_header "ADVANCED LOGIC"
# Adding 9 contacts (The 9th should replace the 1st)
CIRCULAR="ADD\n1\n1\n1\n1\n1\nADD\n2\n2\n2\n2\n2\nADD\n3\n3\n3\n3\n3\nADD\n4\n4\n4\n4\n4\nADD\n5\n5\n5\n5\n5\nADD\n6\n6\n6\n6\n6\nADD\n7\n7\n7\n7\n7\nADD\n8\n8\n8\n8\n8\nADD\nNEW\n9\n9\n9\n9\nSEARCH\nEXIT\n"
run_test "Circular Buffer (9th replace 1st)" "$CIRCULAR" "NEW"

echo -e "\n${Y}--- End of Tests ---${NC}"