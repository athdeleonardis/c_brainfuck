"
  Takes two integers 'n' (cell 0) and 'm' (cell 1) and prints their addition 'n+m' (cell 2).
  Maintains n and m by using a spare cell (cell 3) as temporary storage.
"
,>,<
[->>+>+<<<]     "Destructively add cell 0 to cells 2 and 3."
>>>[-<<<+>>>]   "Destructively add cell 3 to 0.            "
<<[->+>+<<]     "Destructively add cell 1 to cells 2 and 3."
>>[-<<+>>]      "Destructively add cell 3 to cell 1.       "
<.!             "Print the result.                         "