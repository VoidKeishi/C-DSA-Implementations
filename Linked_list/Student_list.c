/* Phạm Phan Anh - 20215042
   Thời gian : 15/11/2022
   Tính năng:
        + List học sinh bằng danh sách liên kết
        + Tự động xếp theo điểm mới cập nhật
        + Thêm / bớt / tìm kiếm học sinh
        + Sửa điểm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[10];
    char name[25];
    int grade;
} data_t;

typedef struct node_s
{
    data_t data;
    struct node_s *next;
} node_t, *root_t;

/* Tools */
void showData(data_t data)
{
    printf("%-10s%-25s%d\n", data.id, data.name, data.grade);
}

void showList(root_t root)
{
    while (root)
    {
        showData(root->data);
        root = root->next;
    }
}

node_t *createNewNode(const data_t data)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

root_t llInsertHead(root_t root, const data_t data)
{
    node_t *pNewNode = createNewNode(data);
    pNewNode->next = root;
    return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const data_t data)
{
    node_t *pNewNode = createNewNode(data);

    if (root == NULL)
        return (root_t)pNewNode;

    node_t *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
        ;
    p->next = pNewNode;
    return root;
}

root_t llInsertAfter(root_t root, node_t *pAElem, const data_t data)
{
    if (pAElem == NULL)
        return root;

    node_t *pNewNode = createNewNode(data);
    pNewNode->next = pAElem->next;
    pAElem->next = pNewNode;

    return root;
}

root_t llDeleteHead(root_t root)
{
    if (root == NULL)
        return NULL;

    node_t *p = root->next;
    free(root);
    return (root_t)p;
}

root_t llDeleteAfter(root_t root, node_t *pA)
{
    if ((pA == NULL) || (pA->next == NULL))
        return root;

    node_t *pToDelElem = pA->next;
    pA->next = pA->next->next;

    free(pToDelElem);
    return root;
}

root_t llDeleteAll(root_t root)
{
    node_t *p = NULL;
    for (; root != NULL; root = p)
    {
        p = root->next;
        free(root);
    }

    return NULL;
}

/* Xử lý */
root_t llInsertStudent(root_t root, data_t data)
{
    root_t preNode;
    for (root_t node = root; node != NULL; preNode = node, node = node->next)
    {
        if (node->data.grade < data.grade)
        {
            if (node != root)
                return llInsertAfter(root, preNode, data);
            else
                return llInsertHead(root, data);
        }
    }
    return llInsertTail(root, data);
}

data_t *llFindStudent(root_t root, char id[])
{
    while (root)
    {
        if (strcmp(root->data.id, id) == 0)
        {
            return &root->data;
        }
        root = root->next;
    }
    return NULL;
}

root_t llDeleteStudent(root_t root, char id[])
{
    root_t node = root;
    root_t preNode = NULL;
    while (node)
    {
        if (strcmp(node->data.id, id) == 0)
        {
            if (preNode)
                return llDeleteAfter(root, preNode);
            else
                return llDeleteHead(root);
        }
        preNode = node;
        node = node->next;
    }
    return root;
}

root_t llChangeGrade(root_t root, char id[], int newGrade)
{
    root_t preNode;
    for (root_t node = root; node != NULL; preNode = node, node = node->next)
    {
        if (strcmp(node->data.id, id) == 0)
        {
            node->data.grade = newGrade;
            root = llInsertStudent(root, node->data);
            llDeleteAfter(root, preNode);
            break;
        }
    }
    return root;
}

int main()
{
    root_t root = NULL;

    // tạo mảng 5 sv
    data_t student[] = {
        {"001", "sv1", 3},
        {"002", "sv2", 5},
        {"003", "sv3", 7},
        {"004", "sv4", 9},
        {"005", "sv5", 10},
    };

    // thêm sv
    for (int i = 0; i < 5; i++)
    {
        root = llInsertStudent(root, student[i]);
    }

    // in list hiện tại
    showList(root);
    puts("=============");

    // in thông tin sv 004
    showData(*llFindStudent(root, "004"));
    puts("=============");

    // sửa điểm sv 004
    root = llChangeGrade(root, "004", 6);
    showList(root);
    puts("=============");

    root = llDeleteAll(root);

    return 0;
}