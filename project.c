
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Task
{
    int id;
    char name[50];
    int priority;
};

struct Task pq[MAX];
int size = 0;
int next_id = 1;

// Insert a new task
void insert()
{
    if (size == MAX)
    {
        printf("Priority Queue is full!\n");
        return;
    }

    pq[size].id = next_id++;

    printf("Enter task name: ");
    scanf(" %49[^\n]", pq[size].name);

    printf("Enter priority: ");
    scanf("%d", &pq[size].priority);

    size++;

    printf("Task inserted successfully!\n");
}

// Process task with highest priority
void process()
{
    int i, highest = 0;

    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    for (i = 1; i < size; i++)
    {
        if (pq[i].priority > pq[highest].priority)
        {
            highest = i;
        }
    }

    printf("Processed Task: %s\n", pq[highest].name);

    for (i = highest; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Display all tasks
void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nID\tTask Name\tPriority\n");
    printf("--------------------------------\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t%s\t\t%d\n",
               pq[i].id, pq[i].name, pq[i].priority);
    }
}

// Update priority of a task
void update()
{
    int id, i, found = 0;

    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Enter Task ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < size; i++)
    {
        if (pq[i].id == id)
        {
            printf("Enter new priority: ");
            scanf("%d", &pq[i].priority);

            printf("Priority updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Task not found!\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Priority Based Task Manager ---\n");
        printf("1. Insert Task\n");
        printf("2. Process Highest Priority Task\n");
        printf("3. Display All Tasks\n");
        printf("4. Update Task Priority\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            process();
            break;

        case 3:
            display();
            break;

        case 4:
            update();
            break;

        case 5:
            printf("Exiting Task Manager...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
