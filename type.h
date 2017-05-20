struct literal_type{
  int type; // 0 -> int ; 1-> double ; 2-> char  ; 3-> char*  4-> bool
  int ival;
  char cval;
  double dval;
  char* sval;
  int bval;
  int offset;
};

typedef struct literal_type lit_type;

