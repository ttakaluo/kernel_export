#include <linux/init.h>
#include <linux/module.h>

int param_i(void);
int param_j(void);
int m_sum(int a, int b);
int m_sub(int a, int b);
int a = 0;
int b = 0;

static int __init m_print_init(void){
	
	printk("m_print inserted\n");

	a = param_i();
	b = param_j();

	printk("Sum of ints is: %d\n", m_sum(a,b));
	printk("Sub of ints is: %d\n", m_sub(a,b));
	return 0;

}

static void __exit m_print_exit(void){

	printk(KERN_ALERT "m_print removed\n");
}

MODULE_LICENSE("GPL");
module_init(m_print_init);
module_exit(m_print_exit);

