#include "mm.h"
#include "sched.h"
#include "entry.h"
#include "printf.h"

int copy_process(unsigned long fn, unsigned long arg){
	preempt_disable();
	struct task_struct *p;

	p = (struct task_struct *)get_free_page();
	if(!p){
		return 1;
	}
	p->priority = current->priority;
	p->state = TASK_RUNNING;
	p->counter = p->priority;
	p->preempt_count = 1;

	p->cpu_context.x19 = fn;
	p->cpu_context.x20 = arg;
	p->cpu_context.pc = (unsigned long)ret_from_fork;
	p->cpu_context.sp = (unsigned long)p+THREAD_SIZE;
	int pid = nr_tasks++;
	task[pid] = p;

	printf("\r\n-----Task%d created-----\r\n", pid);
	printf("Struct task allocated at 0x%08x.\r\n", p);
	printf("p->cpu_context.sp =  0x%08x. (sp)\r\n", p->cpu_context.sp);

	preempt_enable();
	return 0;
}
