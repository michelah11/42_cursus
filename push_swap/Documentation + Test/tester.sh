#!/bin/bash

PUSH_SWAP="./push_swap"
CHECKER_LINUX="./checker_linux"

NUM_RUNS=10

OUTPUT_FILE="push_swap_test_results.txt"
> $OUTPUT_FILE

test_identity() {
    echo "==============================" | tee -a $OUTPUT_FILE
    echo "Testing Identity..." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    local identity_cases=("42" "2 3" "0 1 2 3" "0 1 2 3 4 5 6 7 8 9")
    for args in "${identity_cases[@]}"; do
        echo "Testing with input: $args" | tee -a $OUTPUT_FILE
        for i in $(seq 1 $NUM_RUNS); do
            OUTPUT=$($PUSH_SWAP $args)
            if [ "$OUTPUT" != "" ]; then
                echo "Identity test failed for input: $args" | tee -a $OUTPUT_FILE
                echo "Expected no output, but got:" | tee -a $OUTPUT_FILE
                echo "$OUTPUT" | tee -a $OUTPUT_FILE
                return 1
            else
                echo "Program output: (empty)" | tee -a $OUTPUT_FILE
            fi
        done
    done
    echo "Identity test passed. No operations were needed for already sorted input." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    return 0
}

test_simple() {
    echo "==============================" | tee -a $OUTPUT_FILE
    echo "Testing Simple Case..." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    local simple_case="1 5 2 4 3"
    total_operations=0
    for i in $(seq 1 $NUM_RUNS); do
        echo "Run $i with input: $simple_case" | tee -a $OUTPUT_FILE
        OUTPUT=$($PUSH_SWAP $simple_case)
        OPERATIONS=$(echo "$OUTPUT" | wc -l)
        total_operations=$((total_operations + OPERATIONS))
        CHECK=$(echo "$OUTPUT" | $CHECKER_LINUX $simple_case)
        echo "Program output:" | tee -a $OUTPUT_FILE
        echo "$OUTPUT" | tee -a $OUTPUT_FILE
        echo "Checker output: $CHECK" | tee -a $OUTPUT_FILE
        echo "Number of operations: $OPERATIONS" | tee -a $OUTPUT_FILE

        if [ "$CHECK" != "OK" ]; then
            echo "Simple test failed for input: $simple_case" | tee -a $OUTPUT_FILE
            echo "Expected checker to return 'OK', but got: $CHECK" | tee -a $OUTPUT_FILE
            return 1
        fi

        if [ $OPERATIONS -gt 12 ]; then
            echo "Simple test failed for input: $simple_case" | tee -a $OUTPUT_FILE
            echo "Expected no more than 12 operations, but got: $OPERATIONS" | tee -a $OUTPUT_FILE
            return 1
        fi
    done
    avg_operations=$((total_operations / NUM_RUNS))
    echo "Average number of operations for simple test: $avg_operations" | tee -a $OUTPUT_FILE
    echo "Simple test passed. The case was sorted correctly and efficiently." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    return 0
}

test_errors() {
    echo "==============================" | tee -a $OUTPUT_FILE
    echo "Testing Error Management..." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    local error_cases=("42 a" "2 3 2" "2147483648" "")
    for args in "${error_cases[@]}"; do
        echo "Testing with input: '$args'" | tee -a $OUTPUT_FILE
        for i in $(seq 1 $NUM_RUNS); do
            OUTPUT=$($PUSH_SWAP $args 2>&1)
            echo "Program output:" | tee -a $OUTPUT_FILE
            echo "$OUTPUT" | tee -a $OUTPUT_FILE
            if [ "$args" == "" ]; then
                if [ "$OUTPUT" != "" ]; then
                    echo "Error management failed for input: '$args'" | tee -a $OUTPUT_FILE
                    echo "Expected no output, but got: $OUTPUT" | tee -a $OUTPUT_FILE
                    return 1
                fi
            elif [ "$OUTPUT" != "Error" ]; then
                echo "Error management failed for input: '$args'" | tee -a $OUTPUT_FILE
                echo "Expected 'Error', but got: $OUTPUT" | tee -a $OUTPUT_FILE
                return 1
            fi
        done
    done
    echo "Error management test passed. All invalid inputs were handled correctly." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    return 0
}

test_middle() {
    echo "==============================" | tee -a $OUTPUT_FILE
    echo "Testing Middle Version (100 random values)..." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    total_operations=0
    for i in $(seq 1 $NUM_RUNS); do
        ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
        echo "Run $i with input: $ARG" | tee -a $OUTPUT_FILE
        OUTPUT=$($PUSH_SWAP $ARG)
        OPERATIONS=$(echo "$OUTPUT" | wc -l)
        total_operations=$((total_operations + OPERATIONS))
        CHECK=$(echo "$OUTPUT" | $CHECKER_LINUX $ARG)
        echo "Checker output: $CHECK" | tee -a $OUTPUT_FILE
        echo "Number of operations: $OPERATIONS" | tee -a $OUTPUT_FILE

        if [ "$CHECK" != "OK" ]; then
            echo "Middle test failed for input: $ARG" | tee -a $OUTPUT_FILE
            echo "Expected checker to return 'OK', but got: $CHECK" | tee -a $OUTPUT_FILE
            return 1
        fi

        if [ $OPERATIONS -gt 1500 ]; then
            echo "Middle test failed for input: $ARG" | tee -a $OUTPUT_FILE
            echo "Expected fewer than 1500 operations, but got: $OPERATIONS" | tee -a $OUTPUT_FILE
            return 1
        fi
    done
    avg_operations=$((total_operations / NUM_RUNS))
    echo "Average number of operations for middle test: $avg_operations" | tee -a $OUTPUT_FILE
    echo "Middle test passed. The case was sorted correctly and efficiently." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    return 0
}

test_advanced() {
    echo "==============================" | tee -a $OUTPUT_FILE
    echo "Testing Advanced Version (500 random values)..." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    total_operations=0
    for i in $(seq 1 $NUM_RUNS); do
        ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
        echo "Run $i with input: $ARG" | tee -a $OUTPUT_FILE
        OUTPUT=$($PUSH_SWAP $ARG)
        OPERATIONS=$(echo "$OUTPUT" | wc -l)
        total_operations=$((total_operations + OPERATIONS))
        CHECK=$(echo "$OUTPUT" | $CHECKER_LINUX $ARG)
        echo "Checker output: $CHECK" | tee -a $OUTPUT_FILE
        echo "Number of operations: $OPERATIONS" | tee -a $OUTPUT_FILE

        if [ "$CHECK" != "OK" ]; then
            echo "Advanced test failed for input: $ARG" | tee -a $OUTPUT_FILE
            echo "Expected checker to return 'OK', but got: $CHECK" | tee -a $OUTPUT_FILE
            return 1
        fi

        if [ $OPERATIONS -gt 11500 ]; then
            echo "Advanced test failed for input: $ARG" | tee -a $OUTPUT_FILE
            echo "Expected fewer than 11500 operations, but got: $OPERATIONS" | tee -a $OUTPUT_FILE
            return 1
        fi
    done
    avg_operations=$((total_operations / NUM_RUNS))
    echo "Average number of operations for advanced test: $avg_operations" | tee -a $OUTPUT_FILE
    echo "Advanced test passed. The case was sorted correctly and efficiently." | tee -a $OUTPUT_FILE
    echo "==============================" | tee -a $OUTPUT_FILE
    return 0
}

test_identity || exit 1
test_simple || exit 1
test_errors || exit 1
test_middle || exit 1
test_advanced || exit 1

echo "All tests passed successfully." | tee -a $OUTPUT_FILE
