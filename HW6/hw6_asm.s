	# HW6
	# This is the skeleton assembly file that you need to fill in. 
	#
	# IMPORTANT: return values are expected to be found in %rax
	

	# declare the function names available in this file
.globl avg	
.globl maxabs
.globl lookup
.globl checksum



	# avg - computes the integer average of two numbers
avg:
cmpl $1, %esi
 jle .L11
 subq $8, %rsp
 movzbl (%rdi), %edx
 movslq %esi, %rax
 leaq -1(%rdi,%rax), %rax
 movzbl (%rax), %ecx
 movb %cl, (%rdi)
 movb %dl, (%rax)
 subl $2, %esi
 addq $1, %rdi
 call f
 addq $8, %rsp
.L11:
 rep ret 


	# maxabs - returns the number whose absolute value is the largest
maxabs:

	

	# your code goes here


	ret	



	# lookup - returns the character found in string str at location x (str[x])
	#
	# IMPORTANT: characters are one byte long and are tightly packed in
	# memory. You will need to use the byte length registers and movb
	# (otherwise you will grab more than one character). This hold for all
	# of the string functions
lookup:

	
	# your code goes here
	

	ret



	# checksum - performs a simple parity checksum, xoring all of the
	# characters in the string and then summing the 1s.
checksum:

	
	# your code goes here
	

	ret
	

	

	
