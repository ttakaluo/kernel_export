#include <linux/init.h>
#include <linux/module.h>

int param_i(void);
int param_j(void);

int m_sum(int, int);
int m_sub(int, int);

int m_sum(int a, int b){

	int c;
	c = a + b;
	return c;
}

int m_sub(int a, int b){

	int c;
	c = a - b;
	return c;
}

static int __init m_calc_init(void){
	
	int a = param_i();
	int b = param_j();

	printk("m_calc is: %d\n", a);
	printk("m_calc is: %d\n", b);


	return 0;
}

static void __exit m_calc_exit(void){

	printk(KERN_ALERT "m_calc removed\n");
}

MODULE_LICENSE("GPL");
module_init(m_calc_init);
module_exit(m_calc_exit);
EXPORT_SYMBOL_GPL(m_sum);
EXPORT_SYMBOL_GPL(m_sub);

