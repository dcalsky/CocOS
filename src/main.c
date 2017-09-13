#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"
#include "kheap.h"

int main(struct multiboot *mboot_ptr) {
	init_descriptor_tables();
	monitor_clear();

	u32int a = kmalloc(8);

	initialize_paging();
	monitor_write("CocOS booted.\n");

	//asm volatile("int $0x3");
	//asm volatile("int $0x4");

	//asm volatile("sti");
	//init_timer(50);

	//u32int *ptr = (u32int*)0xA0000000;
	//u32int do_page_fault = *ptr;

	u32int b = kmalloc(8);
	u32int c = kmalloc(8);
	monitor_write("a: ");
	monitor_write_hex(a);
	monitor_write(", b: ");
	monitor_write_hex(b);
	monitor_write("\nc: ");
	monitor_write_hex(c);

	kfree(c);
	kfree(b);
	u32int d = kmalloc(12);
	monitor_write(", d: ");
	monitor_write_hex(d);

	return 0;
}
