// Finds the smallest element in the array of length R2 whose first element is at RAM[R1] and stores the result in R0.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
@ARR
M = 0
@R1
A = M
D = M
@R0
M = D
@ARR
M = 1
(LOOP)
@ARR
D = M
@R2
D = D - M
@END
D ; JEQ
@R0
D = M
@FIRSTN
D ; JLT
@FIRSTP
D ; JGT
(SAME)
@R0
D = D - M
@LOW
D ; JLT
@ARR
M = M + 1
@LOOP
0 ; JMP
(END)
@END
0 ; JMP
(FIRSTN)
@R1
D = M
@ARR
A = D + M
D = M
@SAME
D ; JLT
@ARR
M = M + 1
@LOOP
0 ; JMP
(FIRSTP)
@R1
D = M
@ARR
A = D + M
D = M
@SAME
D ; JGT
@R0
M = D
@ARR
M = M + 1
@LOOP
0 ; JMP
(LOW)
@R1
D = M
@ARR
A = D + M
D = M
@R0
M = D
@ARR
M = M + 1
@LOOP
0 ; JMP