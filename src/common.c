#include "common.h"

void outb(u16int port, u8int value) {
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port) {
	u8int ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

u16int inw(u16int port) {
	u16int ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

void memcpy(u8int *dest, const u8int *src, u32int len) {
	const u8int *sp = (const u8int *)src;
	u8int *dp = (u8int *)dest;
	for(; len != 0; --len) {
		*dp++ = *sp++;
	}
}

void memset(u8int *dest, u8int val, u32int len) {
	u8int *dp = (u8int *)dest;
	for(; len != 0; --len) {
		*dp++ = val;
	}
}

int strcmp(char *str1, char *str2) {
	int i = 0;
	int failed = 0;
 	while(str1[i] != '\0' && str2[i] != '\0') {
 		if(str1[i] != str2[i]) {
			failed = 1;
			break;
		}
		i++;
	}

	if((str1[i] == '\0' && str2[i] != '\0') || (str1[i] < str2[i])) {
		failed = -1;
	}

	return failed;
}

char *strcpy(char *dest, const char *src) {
	do {
		*dest++ = *src++;
	} while (*src != 0);
}

char *strcat(char *dest, const char *src) {
	while (*dest != 0) {
		*dest = *dest++;
	}

	do {
		*dest++ = *src++;
	} while (*src != 0);

	return dest;
}

extern void panic(const char *message, const char *file, u32int line) {
	asm volatile("cli");

	monitor_write("PANIC(");
	monitor_write(message);
	monitor_write(") at ");
	monitor_write(file);
	monitor_write(":");
	monitor_write_dec(line);
	monitor_write("\n");

	for(;;);
}

extern void panic_assert(const char *file, u32int line, const char *desc) {
	asm volatile("cli");

	monitor_write("ASSERTION-FAILED(");
	monitor_write(desc);
	monitor_write(") at ");
	monitor_write(file);
	monitor_write(":");
	monitor_write_dec(line);
	monitor_write("\n");

	for(;;);
}
