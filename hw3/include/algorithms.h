#ifndef ALGORITHMS
#define ALGORITHMS
/**
 * [sort sorts objects from smallest to largest]
 * @param start_obj [beginning of the array containing the list of objects]
 * @param int_comp  [pointer to the first integer contained in the object. this is the integer to compare]
 * @param obj_size  [size of each object in the array]
 * @param length    [total amount of objects in the array]
 */
void sort(void* start_obj, int* int_comp, int obj_size, int length);

#endif