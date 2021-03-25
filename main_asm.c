#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	asm(
		"push %rbp\n\t"
		"mov %rsp, %rbp\n\t"
		"sub $0x64, %rsp\n\t" //"sub rsp, 64" 64 -> 18
			//???"mov rax, QWORD PTR fs:0x28\n\t"//"mov rax, qword ptr fs:40\n\t"
		//"mov %rax, qword ptr [%rbp-0x18]\n\t"
		"xor %eax, %eax\n\t"
		//"mov dword ptr - 56[rbp], 0"
		"mov %rax, %rdx\n\t"
		"jmp .l2\n\t"
		".l5:\n\t"
		//"mov	dword ptr - 52[rbp], 0"
		"jmp .l3\n\t"
		".l4:\n\t"
		"lea 0x20(%rbp), %rcx\n\t"//"lea %rcx, -48[rbp]\n\t"
		//"mov	eax, dword ptr - 52[rbp]"
		//"movsx %rsi, %eax\n\t"
		//"mov %eax dword ptr [rbp - 56]\n\t"//eax
		//"movsx %rdx, %eax\n\t"
		"mov %rax, %rdx\n\t"
		"add %rax, %rax\n\t"
		"add %rax, %rdx\n\t"
		"add %rax, %rsi\n\t"
		"sarl $2, (%rax)\n\t"//"sal %rax, 2\n\t"
		"add %rax, %rcx\n\t"
		"mov %rsi, %rax\n\t"
		"lea 0x99(%rip), %rdi\n\t"//"lea %rdi, %.lc0[rip]\n\t"
		"mov %eax, 0\n\t"
		"call scanf\n\t"//"call __isoc99_scanf@plt\n\t"
		//"add dword ptr [%rbp-52], 1\n\t"
		".l3:\n\t"
		//"cmp	dword ptr - 52[rbp], 2"
		"jle .l4\n\t"
		//"add	dword ptr - 56[rbp], 1"
		".l2:\n\t"
		//"cmp	dword ptr - 56[rbp], 2"
		"jle .l5\n\t"
		"mov %eax, 0\n\t"
		//"add dword ptr [%ebx+4], 1\n\t"
		//"mov qword ptr[%rbp], %rdi\n\t"//"mov	rdi, qword ptr - 8[rbp]"
		//"xor 0x28(%rdi), qword ptr fs\n\t"//"xor rdi, qword ptr fs : 40"
		"je .l7\n\t"
		"call scanf\n\t"//"call __stack_chk_fail@plt\n\t"
		".l7:\n\t"
		"pop %rbp\n\t"
	);
    return 0;
}
