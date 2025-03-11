#!/bin/bash

# Function to generate 500 unique random integers in the full 32-bit signed range.
    echo "Testing for 500 numbers:"
generate_random_integers() {
    declare -A seen
    count=0
    arr=()

    while [ $count -lt 500 ]; do
        # Read 4 random bytes as an unsigned 32-bit integer.
        num=$(od -An -N4 -tu4 /dev/urandom | tr -d ' ')
        # Convert to signed: if num > INT_MAX, subtract 2^32
        if [ "$num" -gt 2147483647 ]; then
            num=$(( num - 4294967296 ))
        fi
        # Check if the number is unique
        if [ -z "${seen[$num]}" ]; then
             seen[$num]=1
             arr[count]=$num
             ((count++))
        fi
    done

    # Output the 500 numbers as a space-separated string.
    echo "${arr[@]}"
}

# Run the test 10 times.
for i in {1..10}; do
    echo "Test run #$i:"
    # Store the generated numbers into an array so each becomes a separate argument.
    ARG=( $(generate_random_integers) )
    # Execute push_swap with the generated numbers.
    PUSH_SWAP_OUTPUT=$(./push_swap "${ARG[@]}")
    echo "Number of operations:"
    echo "$PUSH_SWAP_OUTPUT" | wc -l

    echo "Checker from 42:"
    echo "$PUSH_SWAP_OUTPUT" | ./checker_linux "${ARG[@]}"

    echo "Checker from bonus:"
    echo "$PUSH_SWAP_OUTPUT" | ./checker "${ARG[@]}"

    echo "--------------------------"
done
