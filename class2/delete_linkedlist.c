void deleteList(struct node** head_ref) {
    struct node* current = *head_ref;
    struct node* next;
    while (current!= NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}
