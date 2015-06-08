#include <linux/init.h>
#include <linux/module.h>

int export_module_sum(int, int);
int export_module_sub(int, int);
int export_i;
int export_j;

static int __init moduleProcess_init(void){
	
	printk(KERN_ALERT "ModuleProcess successfully inserted\n");

	export_i = 0;
	export_j = 0;
	export_i = export_module_sum(10,10);
	export_j = export_module_sub(10,10);

	printk("%d\n", export_i);
	printk("%d\n", export_j);

	return 0;
}

static void __exit moduleProcess_exit(void){

	printk(KERN_ALERT "Module moduleProcess removed\n");
}

MODULE_LICENSE("GPL");
module_init(moduleProcess_init);
module_exit(moduleProcess_exit);
EXPORT_SYMBOL_GPL(export_i);
EXPORT_SYMBOL_GPL(export_j);


