#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

int exp_i = 0;
int exp_j = 0;

module_param(exp_i, int, 0);
MODULE_PARM_DESC(exp_i, "this is an int variable");
module_param(exp_j, int, 0);
MODULE_PARM_DESC(exp_j, "this is an int variable");

int param_i(void){
	return exp_i;
}

int param_j(void){
	return exp_j;
}

static int __init m_param_init(void){
	
	printk(KERN_ALERT "m_param inserted\n");
	printk("m_param test_i is: %d\n", param_i());
	printk("m_param test_j is: %d\n", param_j());

	return 0;
}

static void __exit m_param_exit(void){

	printk(KERN_ALERT "m_param removed\n");
}

MODULE_LICENSE("GPL");
EXPORT_SYMBOL_GPL(param_i);
EXPORT_SYMBOL_GPL(param_j);
module_init(m_param_init);
module_exit(m_param_exit);
