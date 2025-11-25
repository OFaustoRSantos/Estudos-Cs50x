
// Queue and Stack structure: Same

const int CAPACITY = 50;

typedef struct
{
    person people[CAPACITY];
    int size; // How much already have a position
} queue;

//Creting a list
int size = 3;

int *list = malloc(size * sizeof(int)); // Place 3 spaces for memory

// we can use same structure as array
list[0] = 1; // ...

// situation where I need to expand list
int new_size = 4;
int new_value = 6;
int *tmp = malloc(new_size * sizeof(int)); // creating a temporary
for(int i; i<3; i++)
{
    tmp[i] = list [i];
}
tmp[list + new_size - list] = new_value;
free(list);

// However looks how big it became for just insert one new value in the list!
// Have a better way insert new value: using realloc! - It's a intelligence way to alloc more memory!
// Two arguments not just one
int *n_tmp = realloc(list, new_size * sizeof(int));
// Don't need to reinsert each value of list by a loop

// linked Lists

typedef struct node
{
    int number;
    struct node *next;
} node;
// strange solution to use a struct inside a struct
// Can I use:
const int CAPACITY = 10;
typedef struct arr_node
{
    int number[CAPACITY];
    struct arr_node *next;
} arr_node;

int creat_list_errado(){
    // fica ao contrário o modelo

    // Memory for numbers
    node *list = NULL;

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;

        // Prepend node to list
        n->next = list;
        list = n;
    }
    return 0;
}

int creat_list_correto(void)
{
    // Memory for numbers
    node *list = NULL;

    int desejo;
    do{
        desejo = get_int("Deseja a lista já organizada, caso sim digite 1, caso não seja necessário digite 0?");
    } while(desejo != 1 && desejo != 0);

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = get_int("Number: "); // acessando node
        n->next = NULL;

        // If list is empty, ou seja estou adicionando 1° elemento
        if (list == NULL)
        {
            // This node is the whole list
            list = n;
        }

        if(desejo == 1){
                // Iterate over nodes in list
                for (node *ptr = list; ptr != NULL; ptr = ptr->next)
                {
                    // If at end of list
                    if (ptr->next == NULL)
                    {
                        // Append node
                        ptr->next = n;
                        break;
                    }
    
                    // If in middle of list
                    if (n->number < ptr->next->number)
                    {
                        n->next = ptr->next;
                        ptr->next = n;
                        break;
                    }
                }
        } else{

            // If list has numbers already, ou seja, estou adicionando um elemento APOS os já existentes
            // Iterate over nodes in list, Criou um pointer, enquanto pointer != NULL, ou seja, enquant não estiver no final, pointer vai para próximo
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            // For MUITO interessante
            {
                // If at end of list, até alcançar o final e break esse loop
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }
            }
        }
    }
    

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory, mass tambémm!
    node *ptr = list; // novo ponteiro
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    // Sistema de ponteiros serão muito importantes no decorrer dos exercícios, vale a pena gastar mais tempo buscando entender isso,
    return 0;
}
