#include <stdio.h>
#include "linked-list.h"
// #include "stack.h"
//
// static bool is_closing_parenthesis(char ch) {
//     return ch == ')' || ch == ']' || ch == '}';
// }
//
// static char get_opening_pair(char closing_parenthesis) {
//    switch (closing_parenthesis) {
//        case ')': return '(';
//        case ']': return '[';
//        case '}': return '{';
//        default: return 0;
//    }
// }
//
// bool isValidParens(const char *str) {
//     if (str == NULL) return false;
//     stack s = stack_create_default();
//     while (*str) {
//         if (is_closing_parenthesis(*str)) {
//             char pair = get_opening_pair(*str);
//             if (stack_is_empty(&s) ||
//                 pair != stack_pop(&s)) return false;
//         } else
//             stack_push(&s, *str);
//         str++;
//     }
//     return stack_is_empty(&s);
// }

// size_t list_size(linked_list *list);

int main(void) {
    linked_list *list = list_create_default();
    list_push_back(list, 123);
    list_push_back(list, 456);


    list_push_front(list, 999);
    list_push_front(list, 888);

    printf("%zu\n", list_size(list));


    list_print(list);
    // const char *case_1 = "()()(())";
    // const char *case_2 = "(()()(())";
    // const char *case_3 = "([]){}(){{()}}";
    // printf("%d\n", isValidParens(case_1));
    // printf("%d\n", isValidParens(case_2));
    // printf("%d\n", isValidParens(case_3));
}
