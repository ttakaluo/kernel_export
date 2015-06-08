#include <linux/init.h>
#include <linux/module.h>

int export_i;
int export_j;

static int __init modulePrint_init(void){
	
	int i;
	int j;
	i = export_i;
	j = export_j;

	printk("ModulePrint successfully inserted\n");
	printk("Sum of ints is: %d\n", i);
	printk("Sub of ints is: %d\n", j);
	return 0;

}

static void __exit modulePrint_exit(void){

	printk(KERN_ALERT "Module modulePrint removed\n");
}

MODULE_LICENSE("GPL");
module_init(modulePrint_init);
module_exit(modulePrint_exit);

