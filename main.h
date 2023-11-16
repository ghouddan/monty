#ifndef MAIN_H
#define MAIN_H
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

line_t *textfileToArray(const char *filename);
char **splitLine(char *line);
void freeStack(stack_t *head);
void freeLines(line_t *lines);
void error(monty_t *monty);
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);
void opPush(stack_t **stack, unsigned int lineNumber);
void opPall(stack_t **stack, unsigned int lineNumber);
void opPint(stack_t **stack, unsigned int lineNumber);
int _atoi(char *s, int *n);
void getSwap(stack_t **stack, unsigned int lineNumber);
void getSub(stack_t **stack, unsigned int lineNumber);
void getRotr(stack_t **stack, unsigned int lineNnumber);
void getFree(stack_t *stack);
void getNop(stack_t **stack, unsigned int lineNumber);
