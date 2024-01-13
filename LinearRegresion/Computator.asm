.model flat,c
.const 
	public EPSILON
	EPSILON REAL8 1.0e-12
.code
CalculateLeastSquares PROC
	push ebp
	mov ebp, esp
	sub esp, 8
	
	xor eax,eax
	mov ecx, [ebp+16]
	test ecx, ecx
	jle Done

	mov eax, [ebp+8]
	mov edx, [ebp+12]
	
	fldz 
	fldz 
	fldz 
	fldz 	

@@:
	fld REAL8 PTR [eax]
	fld ST(0)
	fld ST(0)
	fld REAL8 PTR[edx]

	fadd ST(5), ST(0) 
	fmulp 
	
	faddp ST(5),ST(0)
	
	fadd ST(2),ST(0)
	fmulp
	
	faddp ST(4), ST(0)
	
	add eax,8
	add edx,8
	dec ecx
	jnz @B

	fild DWORD PTR[ebp+16];
	
	fmul ST(0), ST(4)
	
	fld ST(1)
	fld ST(0)
	
	fmulp
	
	fsubp

	fst REAL8 PTR[ebp-8] 

	fabs
	fld REAL8 PTR[EPSILON]
	fcomip ST(0),ST(1)
	fstp ST(0) 
	jae InvalidDenom

	fild DWORD PTR[ebp+16]
	fmul ST(0),ST(3)
	
	fld ST(2)
	fld ST(2)
	
	fmulp
	
	fsubp
	
	fdiv REAL8 PTR[ebp-8]
	
	mov eax, [ebp+20]
	fstp REAL8 PTR[eax] 

	fxch ST(3)
	fmulp
	fxch ST(2)
	fmulp
	fsubp
	fdiv REAL8 PTR[ebp-8]
	mov eax, [ebp+24]
	fstp REAL8 PTR[eax]

	mov eax,1
Done:
	mov esp,ebp
	pop ebp
	ret
InvalidDenom:
	fstp st(0)
	fstp st(0)
	fstp st(0)
	fstp st(0)
	xor eax,eax
	jmp Done
CalculateLeastSquares ENDP
	end