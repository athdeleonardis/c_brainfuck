#ifndef DATA
#define DATA

typedef void * data_t;
typedef int(*data_comparator_t)(data_t,data_t);
typedef void(*data_deleter_t)(data_t);
typedef void(*data_printer_t)(data_t);

#endif
