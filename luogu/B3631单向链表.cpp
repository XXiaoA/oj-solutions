#include <cstdio>
using namespace std;

using List = struct Node *;
struct Node {
    int data;
    List next;
};

List new_list() {
    List root = new Node;
    root->next = nullptr;
    return root;
}

/**
 * @brief find the xth node
 *
 * @param root the root of list
 * @param x the xth node
 * @return the xth node
 */
List find(List root, int x) {
    if (!root)
        return nullptr;
    if (x == 1)
        return root;
    return find(root->next, x - 1);
}

/**
 * @brief search first data x
 *
 * @param root root
 * @param x data
 * @return node of first data x
 */
List search(List root, int x) {
    if (!root)
        return nullptr;
    if (x == root->data)
        return root;
    return search(root->next, x);
}

/**
 * @brief insert y after index x
 *
 * @param root root of list
 * @param x the position want to insert
 * @param y the data want to insert
 * @return the root of new list
 */
List insert_by_index(List root, int x, int y) {
    List new_node = new Node;
    new_node->data = y;

    if (x == 0) {
        new_node->next = root;
        return new_node;
    } else {
        List current = find(root, x);
        new_node->next = current->next;
        current->next = new_node;
        return root;
    }
}

/**
 * @brief insert y after first data x
 *
 * @param root root
 * @param x position
 * @param y data wanted to insert
 * @return root of new list
 */
List insert_by_data(List root, int x, int y) {
    List new_node = new Node;
    new_node->data = y;

    List current = search(root, x);
    new_node->next = current->next;
    current->next = new_node;
    return root;
}

/**
 * @brief delete the node after x
 *
 * @param root root
 * @param x x
 * @return root of new list
 */
List delete_by_indenx(List root, int x) {
    if (x == 0) {
        List new_root = root->next;
        delete root;
        return new_root;
    } else {
        List previous = find(root, x);
        List current = previous->next;
        previous->next = current->next;
        delete current;
        return root;
    }
}

/**
 * @brief delete the node after first data x
 *
 * @param root root
 * @param x data
 * @return root of new list
 */
List delete_by_data(List root, int x) {
    List previous = search(root, x);
    List current = previous->next;
    previous->next = current->next;
    delete current;
    return root;
}

void print_list(List root) {
    if (root) {
        printf("%d -> ", root->data);
        return print_list(root->next);
    }
    printf("nullptr\n");
}

int main() {
    int q;

    scanf("%d", &q);
    List list = new_list();
    list->data = 1;

    for (int i = 0; i < q; i++) {
        int operate, x, y;
        scanf("%d", &operate);
        switch (operate) {
        case 1:
            scanf("%d %d", &x, &y);
            list = insert_by_data(list, x, y);
            break;
        case 2: {
            scanf("%d", &x);
            List next_node = search(list, x)->next;
            printf("%d\n", (next_node ? next_node->data : 0));
            break;
        }
        case 3:
            scanf("%d", &x);
            list = delete_by_data(list, x);
            break;
        }
    }

    return 0;
}
