```
# Banker-Algorithm
Simple implementation of Banker Algorithm using C
Bank Algorithms that allows upto 10 processes and 10 types of Resources
input.txt is the input format 
Input:
  1: number of processes (p), number of resources types (r)
  2: Allocation matrix of size pxr (allocation)
  3: Max matrix of size pxr (allocation)
  4: Available array of size r (available)
Output:
  If encouter deadlock: System encouter deadlock
  else : safe sequence
  
  
 Documentation: 
    Steps of main function: 
        receiving input and assign input to p, r, allocation, max, available
        enter bank algorithm
    Bank algorithm:
        compute need matrix and assign into needed
        loop through processes to determine which process allocated resources can be released
            determine by check if need < available: 
              true: release process allocation -> retrieve allocated resources into available -> add this process to safe sequence -> go back to check unreleased process
        check if all processes entered safe sequence:
            true: print safe sequence
            false: print encouter deadlock

Use Example:
  Input.txt sample:
5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2

gcc banker.c -o banker
./ banker
  Output:
Safe sequence is: 1 3 0 2 4
```
