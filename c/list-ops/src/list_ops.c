#include "list_ops.h"
#include <string.h>

list_t *new_list(size_t length, list_value_t values[]) {
    int size = length * sizeof(list_value_t);
    list_t *new = calloc(1, sizeof(*list) + size);
    new->length = length;
    memcpy(new->values, values, size);
    return new;
}

list_t *append_list(list_t *list1, list_t *list2) {
}

list_t *filter_list(list_t *list, bool(*filter) (list_value_t value)) {
}

size_t length_list(list_t *list) {
    return !list ? 0 : list->length;
}

list_t *map_list(list_t *list, list_value_t(*map) (list_value_t value)) {
}

list_value_t
foldl_list(list_t *list, list_value_t initial,
           list_value_t(*foldl) (list_value_t value, list_value_t initial)) {
}

list_value_t
foldr_list(list_t *list, list_value_t initial,
           list_value_t(*foldr) (list_value_t value, list_value_t initial)) {
}

list_t *reverse_list(list_t *list) {
}

void delete_list(list_t *list) {
    free(list);
}
