                                                                           UCS301 Data Structures
                                                                              Lab Assignment 1
																			  
	Q.(1) DevelopaMenudrivenprogramtodemonstrate the followingoperations ofArrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5. LINEAR SEARCH
6. EXIT

answer-
 Program Logic
Main Loop: A while loop keeps the menu running until the user selects the EXIT option.
Array Storage: A fixed-size array stores elements, and an integer variable n tracks the current number of active elements.
Validation:Before inserting, check if the array is full (overflow).Before deleting or displaying, check if,
 the array is empty (underflow).Validate user input for positions/indices to prevent out-of-bounds errors.																		  
 
Pseudocode

start
    Declare array ARR of maximum size MAX_SIZE
    Declare integer N = 0  // Tracks current number of elements
    Declare integer CHOICE, ITEM, POS
    
    REPEAT
        PRINT "——MENU——-"
        PRINT "1. CREATE"
        PRINT "2. DISPLAY"
        PRINT "3. INSERT"
        PRINT "4. DELETE"
        PRINT "5. LINEAR SEARCH"
        PRINT "6. EXIT"
        PRINT "Enter your choice: "
        READ CHOICE
        
        SWITCH CHOICE
            CASE 1:
                CALL CREATE_ARRAY(ARR, N)
            CASE 2:
                CALL DISPLAY_ARRAY(ARR, N)
            CASE 3:
                PRINT "Enter item to insert: "
                READ ITEM
                PRINT "Enter position (1 to N+1): "
                READ POS
                CALL INSERT_ELEMENT(ARR, N, ITEM, POS)
            CASE 4:
                PRINT "Enter position to delete (1 to N): "
                READ POS
                CALL DELETE_ELEMENT(ARR, N, POS)
            CASE 5:
                PRINT "Enter item to search: "
                READ ITEM
                CALL LINEAR_SEARCH(ARR, N, ITEM)
            CASE 6:
                PRINT "Exiting program..."
            DEFAULT:
                PRINT "Invalid choice! Please try again."
        END SWITCH
    UNTIL CHOICE == 6
END

1. CREATE Operation

PROCEDURE CREATE_ARRAY(ARR, N)
    PRINT "Enter the number of elements to create: "
    READ LIMIT
    
    IF LIMIT > MAX_SIZE THEN
        PRINT "Error: Limit exceeds maximum allowed size!"
        RETURN
    END IF
    
    N = LIMIT
    FOR I = 0 TO N - 1 DO
        PRINT "Enter element ", I + 1, ": "
        READ ARR[I]
    END FOR
    PRINT "Array created successfully."
END PROCEDURE

2.DISPLAY Operation

PROCEDURE DISPLAY_ARRAY(ARR, N)
    IF N == 0 THEN
        PRINT "Array is empty!"
        RETURN
    END IF
    
    PRINT "Array elements are: "
    FOR I = 0 TO N - 1 DO
        PRINT ARR[I], " "
    END FOR
    PRINT "" // New line
END PROCEDURE

3.INSERT Operation

PROCEDURE INSERT_ELEMENT(ARR, N, ITEM, POS)
    // Check for overflow
    IF N >= MAX_SIZE THEN
        PRINT "Error: Array Overflow! Cannot insert."
        RETURN
    END IF
    
    // Validate position (1-based index converted to 0-based context)
    IF POS < 1 OR POS > N + 1 THEN
        PRINT "Error: Invalid position!"
        RETURN
    END IF
    
    // Shift elements to the right to make space
    FOR I = N - 1 DOWNTO POS - 1 DO
        ARR[I + 1] = ARR[I]
    END FOR
    
    // Insert the item
    ARR[POS - 1] = ITEM
    N = N + 1 // Increase size counter
    PRINT "Item inserted successfully."
END PROCEDURE

4. DELETE Operation

PROCEDURE DELETE_ELEMENT(ARR, N, POS)
    // Check for underflow
    IF N == 0 THEN
        PRINT "Error: Array Underflow! Nothing to delete."
        RETURN
    END IF
    
    // Validate position
    IF POS < 1 OR POS > N THEN
        PRINT "Error: Invalid position!"
        RETURN
    END IF
    
    PRINT "Deleted element: ", ARR[POS - 1]
    
    // Shift elements to the left to fill the gap
    FOR I = POS - 1 TO N - 2 DO
        ARR[I] = ARR[I + 1]
    END FOR
    
    N = N - 1 // Decrease size counter
END PROCEDURE

5. LINEAR SEARCH Operation

PROCEDURE LINEAR_SEARCH(ARR, N, ITEM)
    IF N == 0 THEN
        PRINT "Array is empty! Cannot search."
        RETURN
    END IF
    
    FOR I = 0 TO N - 1 DO
        IF ARR[I] == ITEM THEN
            PRINT "Element found at position: ", I + 1
            RETURN
        END IF
    END FOR
    
    PRINT "Element not found in the array."
END PROCEDURE



Q.(2)Design the logic to remove the duplicate elements from an Array and after the
deletion the array should contain the unique elements.
answer-
logics
1.Sort the array: Sorting shifts identical numbers right next to each other.
2.Two-Pointer Setup:A Unique Pointer (uniqueIndex) stays at the last found unique element.
An Explorer Pointer (i) scans through the rest of the array.
3.Scan and Filter: If the explorer pointer finds a number different from the one at uniqueIndex,
 it means a new unique value is found.
4.Shift Elements: The uniqueIndex advances by one position, and the new value is copied over to it. 
Duplicates are simply skipped and overwritten.

Pseudocode 

ALGORITHM RemoveDuplicates(arr, n)
    // Input: arr (array of elements), n (size of the array)
    // Output: The modified array with unique items and the new size

    // Step 1: Handle edge cases
    if n <= 1 then
        return n
    endif

    // Step 2: Sort the array to bring duplicates together
    Call Sort(arr) 

    // Step 3: Initialize the unique tracker pointer
    uniqueIndex ← 0 

    // Step 4: Loop through the array with an explorer pointer
    for i ← 1 to n - 1 do
        // If current element is different from the last unique element
        if arr[i] ≠ arr[uniqueIndex] then
            uniqueIndex ← uniqueIndex + 1
            arr[uniqueIndex] ← arr[i] // Move unique element forward
        endif
    endfor

    // Step 5: Calculate the new length of unique elements
    newSize ← uniqueIndex + 1

    // Step 6: Return the count of unique elements 
    // (The array from index 0 to uniqueIndex now holds the unique elements)
    return newSize
END

Q.(3) Design the logic of a program to rotate a 1-D array by K positions.
e.g., for A = {1,2,3,4,5} and K = 2, the left rotation is {3,4,5,1,2} and the right
rotation is {4,5,1,2,3}.

ANSWER-
 
 LOGICS
 
 Left Rotation Logic;
 
 Reverse the first \(K\) elements (index \(0\) to \(K-1\)).
 Reverse the remaining \(N-K\) elements (index \(K\) to \(N-1\)).
 Reverse the entire array (index \(0\) to \(N-1\)).
 
 Right Rotation Logic;
 
 Reverse the entire array (index \(0\) to \(N-1\)).
 Reverse the first \(K\) elements (index \(0\) to \(K-1\)).
 Reverse the remaining \(N-K\) elements (index \(K\) to \(N-1\)).
 
 To keep only unique elements, WE can use an in-place approach if the array is sorted,
 or a hash set if it is unsorted.Unsorted Array Deletion LogicCreate an empty hash set.
 Iterate through the array.If an element is not in the set, add it to the set and keep it.
 If it is already in the set, delete/skip it.
 
 Pseudocode
 
  Main function to demonstrate the logic
  
FUNCTION Main()
    ARRAY A = [1, 2, 3, 4, 5]
    INT K = 2
    INT N = LENGTH(A)
    
    // Normalize K
    K = K % N
    
    // Left Rotation Demonstration
    ARRAY leftRotated = COPY(A)
    RotateLeft(leftRotated, K, N)
    OUTPUT "Left Rotated Array: ", leftRotated
    
    // Right Rotation Demonstration
    ARRAY rightRotated = COPY(A)
    RotateRight(rightRotated, K, N)
    OUTPUT "Right Rotated Array: ", rightRotated
    
    // Remove duplicates demonstration
    ARRAY duplicateArray = [1, 2, 2, 3, 4, 4, 5]
    ARRAY uniqueArray = RemoveDuplicates(duplicateArray)
    OUTPUT "Unique Array: ", uniqueArray
END FUNCTION

// Helper function to reverse a section of an array
FUNCTION Reverse(ARRAY arr, INT start, INT end)
    WHILE start < end
        SWAP arr[start] WITH arr[end]
        start = start + 1
        end = end - 1
    END WHILE
END FUNCTION

// Left Rotation Function
FUNCTION RotateLeft(ARRAY arr, INT K, INT N)
    IF K == 0 THEN RETURN
    Reverse(arr, 0, K - 1)
    Reverse(arr, K, N - 1)
    Reverse(arr, 0, N - 1)
END FUNCTION

// Right Rotation Function
FUNCTION RotateRight(ARRAY arr, INT K, INT N)
    IF K == 0 THEN RETURN
    Reverse(arr, 0, N - 1)
    Reverse(arr, 0, K - 1)
    Reverse(arr, K, N - 1)
END FUNCTION

// Function to delete duplicates and return unique elements
FUNCTION RemoveDuplicates(ARRAY arr)
    SET seenElements = EMPTY_SET()
    ARRAY uniqueResult = EMPTY_ARRAY()
    
    FOR EACH element IN arr
        IF element NOT IN seenElements THEN
            ADD element TO seenElements
            APPEND element TO uniqueResult
        END IF
    END FOR
    
    RETURN uniqueResult
END FUNCTION

Q.44) Implement the logic to
a. Reverse the elements of an array
b. Find the matrix multiplication
c. Find the Transpose of a Matrix.

ANSWER-
LOGICS AND Pseudocode(A):
Use a two-pointer approach.
 Place one pointer at the start of the array and another at the end.
 Swap the elements at these pointers, 
 then move the pointers toward the center until they meet.
 
 FUNCTION reverseArray(arr, size)
    START = 0
    END = size - 1
    
    WHILE START < END
        // Swap elements
        TEMP = arr[START]
        arr[START] = arr[END]
        arr[END] = TEMP
        
        // Move pointers
        START = START + 1
        END = END - 1
    ENDWHILE
    
    RETURN arr
ENDFUNCTION

LOGICS AND Pseudocode(B):

To multiply Matrix A (\(R_1 \times C_1\)) by Matrix B 
(\(R_2 \times C_2\)), the columns of A must equal the rows of B (\(C_1 = R_2\)).
 The resulting matrix C will have dimensions \(R_1 \times C_2\). Each element \(C[i][j]\) is 
 the dot product of row \(i\) of Matrix A and column \(j\) of Matrix B.
 
 FUNCTION multiplyMatrices(A, B, R1, C1, R2, C2)
    IF C1 != R2 THEN
        PRINT "Matrices cannot be multiplied"
        RETURN NULL
    ENDIF
    
    // Initialize result matrix C with zeros
    CREATE Matrix C of size R1 x C2 and fill with 0
    
    FOR i FROM 0 TO R1 - 1
        FOR j FROM 0 TO C2 - 1
            FOR k FROM 0 TO C1 - 1
                C[i][j] = C[i][j] + (A[i][k] * B[k][j])
            ENDFOR
        ENDFOR
    ENDFOR
    
    RETURN C
ENDFUNCTION

LOGICS AND Pseudocode(C):

The transpose of a matrix flips the matrix over its diagonal.
 This swaps the row and column indices of each element.
 An element at position \([i][j]\) in the original matrix moves to position
 \([j][i]\) in the transposed matrix.
 
 FUNCTION transposeMatrix(matrix, rows, cols)
    // Initialize a new matrix with swapped dimensions
    CREATE Matrix transpose of size cols x rows
    
    FOR i FROM 0 TO rows - 1
        FOR j FROM 0 TO cols - 1
            transpose[j][i] = matrix[i][j]
        ENDFOR
    ENDFOR
    
    RETURN transpose
ENDFUNCTION

Q.5 Write a program to find sum of every row and every column in a two-dimensional
array.

ANSWER-

LOGICS AND Pseudocode

A two-dimensional array is an array of arrays represented by grid coordinates \((i, j)\),
 where \(i\) denotes the row index and \(j\) denotes the column index
(i)Row Sum Logic: To find the sum of elements in a specific row,
WE lock the row index \(i\) and vary the column index \(j\) from \(0\) to \(\text{cols} - 1\).
WE accumulate the values into a running total, print or store it, and reset the counter for the next row.
(ii)Column Sum Logic: To find the sum of elements in a specific column, we lock the column index \(j\) and
 vary the row index \(i\) from \(0\) to \(\text{rows} - 1\). we accumulate the values, handle the output, and
\ reset the counter for the next column.

BEGIN
    // Step 1: Initialize the 2D array dimensions
    DECLARE rows, cols, i, j, rowSum, colSum
    
    PRINT "Enter number of rows: "
    READ rows
    PRINT "Enter number of columns: "
    READ cols
    
    DECLARE matrix[rows][cols]
    
    // Step 2: Populate the matrix with user inputs
    PRINT "Enter elements of the matrix:"
    FOR i FROM 0 TO rows - 1 DO
        FOR j FROM 0 TO cols - 1 DO
            READ matrix[i][j]
        END FOR
    END FOR

    // Step 3: Calculate and display Sum of Each Row
    PRINT "--- Row Sums ---"
    FOR i FROM 0 TO rows - 1 DO
        SET rowSum = 0              // Reset row sum for each new row
        FOR j FROM 0 TO cols - 1 DO
            SET rowSum = rowSum + matrix[i][j]
        END FOR
        PRINT "Sum of Row " + i + " = " + rowSum
    END FOR

    // Step 4: Calculate and display Sum of Each Column
    PRINT "--- Column Sums ---"
    FOR j FROM 0 TO cols - 1 DO
        SET colSum = 0              // Reset column sum for each new column
        FOR i FROM 0 TO rows - 1 DO
            SET colSum = colSum + matrix[i][j]
        END FOR
        PRINT "Sum of Column " + j + " = " + colSum
    END FOR
END


 
 
 




