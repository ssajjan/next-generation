/*  intrpt.c - An interrupt handler.
 *
 *  Copyright (C) 2001 by Peter Jay Salzman
 */

/* The necessary header files */

#ifndef __KERNEL__
# define __KERNEL__
#endif
#ifndef MODULE
# define MODULE
#endif

/* Standard in kernel modules */
#include <linux/kernel.h>
/* We're doing kernel work */
#include <linux/module.h>
/* Specifically, a module */
/* Deal with CONFIG_MODVERSIONS */
#if CONFIG_MODVERSIONS==1
#define MODVERSIONS
//#include "modversions.h"
#endif        

#include <linux/sched.h>
#include <linux/tqueue.h>

/* We want an interrupt */
#include <linux/interrupt.h>

#include <asm/io.h>

/* In 2.2.3 /usr/include/linux/version.h includes a macro for this, but
 * 2.0.35 doesn't - so I add it here if necessary.
 */
#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a,b,c) ((a)*65536+(b)*256+(c))
#endif

/* Bottom Half - this will get called by the kernel as soon as it's safe
 * to do everything normally allowed by kernel modules.
 */
static void got_char(void *scancode)
{
   printk("Scan Code %x %s.\n",
          (int) *((char *) scancode) & 0x7F,
          *((char *) scancode) & 0x80 ? "Released" : "Pressed");
}

/* This function services keyboard interrupts. It reads the relevant
 * information from the keyboard and then scheduales the bottom half
 * to run when the kernel considers it safe.
 */
void irq_handler(int irq, void *dev_id, struct pt_regs *regs)
{
   /* This variables are static because they need to be 
    * accessible (through pointers) to the bottom half routine.
    */
   static unsigned char scancode;
   static struct tq_struct task = {NULL, 0, got_char, &scancode};
   unsigned char status;

   /* Read keyboard status */
   status = inb(0x64);
   scancode = inb(0x60);
  
   /* Scheduale bottom half to run */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,2,0)
   queue_task(&task, &tq_immediate);
#else
   queue_task_irq(&task, &tq_immediate);
#endif
   mark_bh(IMMEDIATE_BH);
}

/* Initialize the module - register the IRQ handler */
int init_module()
{
   /* Since the keyboard handler won't co-exist with another handler,
    * such as us, we have to disable it (free its IRQ) before we do
    * anything.  Since we don't know where it is, there's no way to
		* reinstate it later - so the computer will have to be rebooted
		* when we're done.
    */
   free_irq(1, NULL);

   /* Request IRQ 1, the keyboard IRQ, to go to our irq_handler.
	  * SA_SHIRQ means we're willing to have othe handlers on this IRQ.
		* SA_INTERRUPT can be used to make the handler into a fast interrupt. 
    */
   return request_irq(1,   /* The number of the keyboard IRQ on PCs */ 
              irq_handler, /* our handler */
              SA_SHIRQ, 
              "test_keyboard_irq_handler", NULL);
}

/* Cleanup */
void cleanup_module()
{
   /* This is only here for completeness. It's totally irrelevant, since
	  * we don't have a way to restore the normal keyboard interrupt so the
		* computer is completely useless and has to be rebooted.
    */
   free_irq(1, NULL);
} 
