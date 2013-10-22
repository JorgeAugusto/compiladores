/*
  iks_iloc.h
*/
#ifndef __IKS_ILOC_H
#define __IKS_ILOC_H

#include "comp_list.h"
#include "comp_tree.h"

comp_list_t *program_iloc; //list->item: iloc_t

typedef struct iloc_t iloc_t;
struct iloc_t {
	char *label;
	comp_list_t *oper; //list->item: iloc_oper_t
};

typedef enum { add, sub, mult, _div,
							 addI, subI, multI, divI, rdivI,
							 and, andI, or, orI, xor, xorI, 
							 lshift, rshift,
							 lshiftI, rshifI,
							 load, loadAI, loadA0, loadI,
							 cload, cloadAI, cloadA0,
							 store, storeAI, storeA0,
							 cstore, cstoreAI, cstoreA0,
							 i2i, c2c, c2i, i2c,
							 cmp_LT, cmp_LE, cmp_EQ, cmp_GE, cmp_GT, cmp_NE, cbr,
							 jump, jumpI,
 } opcode_t;

union operands {
	int n;
	char *l;
	char *r;
};

typedef struct iloc_oper_t iloc_oper_t;
struct iloc_oper_t {
	opcode_t opcode;
	comp_list_t *src_opers; //list->item: operands
	comp_list_t *dst_opers; //list->item: operands
};

/**
 * verify if label is valid
 */
int label_is_valid(char *label);

/**
 * iloc code generator
 */
void code_generator(comp_tree_t *ast);

#endif /* __IKS_ILOC_H */
