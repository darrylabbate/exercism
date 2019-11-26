#include "list_ops.h"
#include <string.h>

list_t *new_list(size_t length, list_value_t values[]) {
    size_t size = length * sizeof(list_value_t);
    list_t *new = calloc(1, sizeof(*new) + size);
    new->length = length;
    memcpy(new->values, values, size);
    return new;
}

list_t *append_list(list_t *list1, list_t *list2) {
    size_t new_length = 0;
    list_value_t new_values[list1->length + list2->length];
    for (size_t i = 0; i < list1->length; i++)
        new_values[new_length++] = list1->values[i];
    for (size_t i = 0; i < list2->length; i++)
        new_values[new_length++] = list2->values[i];
    return new_list(new_length, new_values);
}

list_t *filter_list(list_t *list, bool(*filter) (list_value_t value)) {
    size_t new_length = 0;
    list_value_t new_values[list->length];
    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->values[i])) {
            new_values[new_length++] = list->values[i];
        }
    }
    return new_list(new_length, new_values);
}

size_t length_list(list_t *list) {
    return !list ? 0 : list->length;
}

list_t *map_list(list_t *list, list_value_t(*map) (list_value_t value)) {
    size_t new_length = 0;
    list_value_t new_values[list->length];
    for (size_t i = 0; i < list->length; i++) {
        new_values[new_length++] = map(list->values[i]);
    }
    return new_list(new_length, new_values);
}

list_value_t
foldl_list(list_t *list, list_value_t initial,
           list_value_t(*foldl) (list_value_t value, list_value_t initial)) {
    for (size_t i = 0; i < list->length; i++)
        initial = foldl(list->values[i], initial);
    return initial;
}

list_value_t
foldr_list(list_t *list, list_value_t initial,
           list_value_t(*foldr) (list_value_t value, list_value_t initial)) {
    for (size_t i = list->length; i > 0; i--)
        initial = foldr(list->values[i-1], initial);
    return initial;
}

list_t *reverse_list(list_t *list) {
    size_t new_length = 0;
    list_value_t new_values[list->length];
    for (size_t i = list->length-1; new_length < list->length; i--) {
        new_values[new_length++] = list->values[i];
    }
    return new_list(new_length, new_values);
}

void delete_list(list_t *list) {
    free(list);
}
