# CS-421 

ProjectName: Paramashivan_Proj1.C

Description: This program is designed to check if the password is valid. The valid password is usually 8 to 10 charaters long. It atleast has 2 uppercase, 2 Digits, 1 Lower case and 1 special characters (@, #, %, $). This program uses recursions to recursively call functions while moving on to the next character in the password index. When the index reaches the end of the password string, the program checks to see if the password is vaild or not.

Installation: https://github.com/Turboash360/CS-421

Usage:
Paramashivan_Proj1  Paramashivan_Proj1.C  Paramashivan_Proj1.C~  Paramashivan_Proj1_Copy.C
[param004@empress cs421]$ g++ Paramashivan_Proj1.C -o Paramashivan_Proj1
[param004@empress cs421]$ ./Paramashivan_Proj1
Use atleast 2 Uppercases, 1 Lowercases, 1 Special Characters (@, %, #, $), 2 Digits in order for the password to be valid.
U - Uppercase
L - Lowercase
S - Special Characters
D - Digits
C - Any Combination of ASCII Characters. U,L,S,D are all subsets of C.
Enter your password: AJ23ls&
---------->  (Start State) ---------->  (U) ---------->  (U) ---------->  (D) ---------->  (D) ---------->  (L) ---------->  (L) ---------->  (C)
 The password is too short.
[param004@empress cs421]$ AJ23li@s
-bash: AJ23li@s: command not found
[param004@empress cs421]$ ./Paramashivan_Proj1
Use atleast 2 Uppercases, 1 Lowercases, 1 Special Characters (@, %, #, $), 2 Digits in order for the password to be valid.
U - Uppercase
L - Lowercase
S - Special Characters
D - Digits
C - Any Combination of ASCII Characters. U,L,S,D are all subsets of C.
Enter your password:  AJ23li@s
---------->  (Start State) ---------->  (U) ---------->  (U) ---------->  (D) ---------->  (D) ---------->  (L) ---------->  (L) ---------->  (S) ---------->  (L)  ---------> (F)

 The password is valid.


Credits: Implemented by Ashwin Paramashivan

