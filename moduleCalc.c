#include <linux/init.h>
#include <linux/module.h>

int export_module_sum(int, int);
int export_module_sub(int, int);

int export_module_sum(int a, int b){

	int c;
	c = a + b;
	return c;
}

int export_module_sub(int a, int b){

	int c;
	c = a - b;
	return c;
}

static int __init moduleCalc_init(void){
	
	printk(KERN_ALERT "Module successfully inserted\n");

	return 0;
}

static void __exit moduleCalc_exit(void){

	printk(KERN_ALERT "Module moduleCalc removed\n");
}

MODULE_LICENSE("GPL");
module_init(moduleCalc_init);
module_exit(moduleCalc_exit);
EXPORT_SYMBOL_GPL(export_module_sum);
EXPORT_SYMBOL_GPL(export_module_sub);


