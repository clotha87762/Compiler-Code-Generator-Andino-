#define MAX_TABLE_SIZE 5000

typedef struct symbol_entry *PTR_SYMB;
typedef enum{
	V_INT , V_DOUBLE ,V_CHAR , V_BOOL , V_NONE
} v_type;

struct symbol_entry {
   char *name;
   int scope;
   int offset;
   int id;
   int variant;
   int mtype;
   double dval;
   int type;
   int ival;
   char cval;
   int bval;
   int total_args;
   int total_locals;
   int mode;
   int stack_offset;
   int para_type[10];
}  table[MAX_TABLE_SIZE];

#define T_FUNCTION 1
#define ARGUMENT_MODE   2
#define LOCAL_MODE      4
#define GLOBAL_MODE     8

extern int cur_scope;
extern int cur_counter;
extern int stack_cur_offset;
