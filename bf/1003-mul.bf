--------------------------------------		substract 38 to index 0
>,------------------------------------------------<		input from user in cell 1
>>,------------------------------------------------<<		input from user in cell 1

>[->>>+>+<<<<]>>>>[-<<<<+>>>>]<<<<<		duplicated 1 to 4 using 5 as a buffer
>>>>[-<<<<
>>[->>>+>+<<<<]>>>>[-<<<<+>>>>]<<<<<<		duplicated 2 to 5 using 6 as a buffer
>>>>>[-<<+>>]<<<<<		moved value from 5 to 3
>>>>]<<<<		mulitiplied 1 and 2 and put the result in 3

10 5 9 45

>>>						point on cell 3
>>>+<<<					set c6 to 1
[->+					reduce c3 and increase c4
----------				reduce c4 by 10 to test it (if it is zero then its previuous value was 10)
[>]>>					if c4 was 10 point to c6 point to c7 otherwise
[<<---------->>>>+<]		this is done if c4 was 10   reduce c4 by 10 add one to c8 (result) points to c7 to be at same point
<<<++++++++++<			add 10 to c4
]
<<<	pointe sur cell 0



>>>>>>>>
[-<<<<<+>>>>>]	move c8 to c3
<<-<<<<<<


>>>++++++++++++++++++++++++++++++++++++++++++++++++.------------------------------------------------<<<		print index 3
>>>>++++++++++++++++++++++++++++++++++++++++++++++++.------------------------------------------------<<<<		print index 4
++++++++++++++++++++++++++++++++++++++++++++++++.------------------------------------------------		print index 0

