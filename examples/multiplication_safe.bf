"
  This script takes two positive integers n (cell 0) and m (cell 1), and prints their multiplication n*m (cell 2).
  It works by adding n to itself m times.
"

,>,<                "Read two integers into cells 0 and 1.                                     "
[->                 "For loop in cell 0.                                                       "
    [->+>+<<]       "Destructively add cell 1 to cells 2 and 3.                                "
    >>[-<<+>>]      "Destructively add cell 3 into cell 1, effectively adding cell 1 to cell 2."
    >+              "Increment cell 4.                                                         "
<<<<]               "                                                                          "
>>>>[-<<<<+>>>>]    "Destructively add cell 4 to cell 0                                        "

++++++++++++++++++++++++++++++++
<<<<.>>>>w<<<.>>>w  "Print cell 0 and cell 1.                                                  "
<<.!                "Print the result.                                                         "