"
  This script takes two positive integers n (cell 0) and m (cell 1), and prints their multiplication n*m (cell 2).
  It works by adding m to itself n times.
  In the process it destroys n.
"

,>,<           "Read two integers into cells 0 and 1"
[->            "For loop in cell 0"
    [->+>+<<]  "Destructively add cell 1 to cells 2 and 3"
    >>[-<<+>>] "Destructively add cell 3 into cell 1, effectively adding cell 1 to cell 2"
<<<]>>.!       "Print the result"