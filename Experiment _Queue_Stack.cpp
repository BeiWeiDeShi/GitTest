<<<<<<< HEAD
// #include <stdio.h>
// #include <malloc.h>
// #include <iostream>
// using namespace std;

// #define MaxSize 100
// #define OVERFLOW -2
// #define ERROR 0
// #define OK 1

// typedef struct{
//     int *stack;
//     int top;       //栈顶指针
//     int size;
// }Stack;

// void Create(Stack *S){
//     S->stack = new int[MaxSize];
//     S->top = -1;
//     S->size = 0;
// }

// void Push(Stack *s, int count){
//     cout << "Please enter the value of the stack:  ";
//     for(int i=0; i<count; i++){
//         int data;
//         cin >> data;
//         s->top++;
//         s->stack[s->top] = data;
//         s->size++;
//     }
//     cout << "The size of the Stack:  " << s->size;
// }

// void Pop(Stack *s, int count){
//     cout << "The value pop:  ";
//     for(int i=0; i<count; i++){
//         cout << s->stack[s->top] << "  ";
//         s->top--;
//         s->size--;
//     }
//     cout << "\nThe size of the Stack:  " << s->size;
// }

// void Display(Stack *S){
//     Stack *s = S;
//     cout << "Display the stack: ";
//     for(int i=s->size-1; i>=0; i--)
//         cout << s->stack[i] <<"  ";
//     cout << "\nThe size of the Stack:  " << s->size << endl;
// }

// int main(){
//     Stack *s = (Stack *)malloc(sizeof(Stack));
//     Create(s);
//     int count;
//     cout << "Please enter the count you will push: ";
//     cin >> count;
//     Push(s,count);           cout << "\n-----------------\n";
//     cout << "Please enter the count you will pop:  ";
//     cin >> count;
//     Pop(s,count);            cout << "\n-----------------\n";
//     Display(s);              cout << "-----------------\n";
// }

#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

#define MaxSize 100
#define OVERFLOW -2
#define ERROR 0
#define OK 1

typedef struct{
    int *stack;
    int front;       //栈顶指针
    int rear;
}Queue;

void Create(Queue *S){
    S->stack = new int[MaxSize];
    S->front = 0;
    S->rear = 0;
}

void Push(Queue *s, int count){
    cout << "Please enter the value of the Queue:  ";
    for(int i=0; i<count; i++){
        int data;
        cin >> data;
        s->stack[s->rear] = data;
        s->rear++;
    }
    cout << "The size of the Queue:  " << s->rear;
}

void Pop(Queue *s, int count){
    cout << "The value pop:  ";
    for(int i=0; i<count; i++){
        cout << s->stack[s->front] << "  ";
        s->front++;
    }
    cout << "\nThe size of the Stack:  " << s->rear - s->front;
}

void Display(Queue *S){
    Queue *s = S;
    cout << "Display the Queue: ";
    for(int i=s->front; i<s->rear; i++)
        cout << s->stack[i] <<"  ";
    cout << "\nThe size of the Stack:  " << s->rear - s->front << endl;
}

int main(){
    Queue *s = (Queue *)malloc(sizeof(Queue));
    Create(s);
    int count;
    cout << "Please enter the count you will push: ";
    cin >> count;
    Push(s,count);           cout << "\n-----------------\n";
    cout << "Please enter the count you will pop:  ";
    cin >> count;
    Pop(s,count);            cout << "\n-----------------\n";
    Display(s);              cout << "-----------------\n";
}
=======
// #include <stdio.h>
// #include <malloc.h>
// #include <iostream>
// using namespace std;

// #define MaxSize 100
// #define OVERFLOW -2
// #define ERROR 0
// #define OK 1

// typedef struct{
//     int *stack;
//     int top;       //栈顶指针
//     int size;
// }Stack;

// void Create(Stack *S){
//     S->stack = new int[MaxSize];
//     S->top = -1;
//     S->size = 0;
// }

// void Push(Stack *s, int count){
//     cout << "Please enter the value of the stack:  ";
//     for(int i=0; i<count; i++){
//         int data;
//         cin >> data;
//         s->top++;
//         s->stack[s->top] = data;
//         s->size++;
//     }
//     cout << "The size of the Stack:  " << s->size;
// }

// void Pop(Stack *s, int count){
//     cout << "The value pop:  ";
//     for(int i=0; i<count; i++){
//         cout << s->stack[s->top] << "  ";
//         s->top--;
//         s->size--;
//     }
//     cout << "\nThe size of the Stack:  " << s->size;
// }

// void Display(Stack *S){
//     Stack *s = S;
//     cout << "Display the stack: ";
//     for(int i=s->size-1; i>=0; i--)
//         cout << s->stack[i] <<"  ";
//     cout << "\nThe size of the Stack:  " << s->size << endl;
// }

// int main(){
//     Stack *s = (Stack *)malloc(sizeof(Stack));
//     Create(s);
//     int count;
//     cout << "Please enter the count you will push: ";
//     cin >> count;
//     Push(s,count);           cout << "\n-----------------\n";
//     cout << "Please enter the count you will pop:  ";
//     cin >> count;
//     Pop(s,count);            cout << "\n-----------------\n";
//     Display(s);              cout << "-----------------\n";
// }

#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

#define MaxSize 100
#define OVERFLOW -2
#define ERROR 0
#define OK 1

typedef struct{
    int *stack;
    int front;       //栈顶指针
    int rear;
}Queue;

void Create(Queue *S){
    S->stack = new int[MaxSize];
    S->front = 0;
    S->rear = 0;
}

void Push(Queue *s, int count){
    cout << "Please enter the value of the Queue:  ";
    for(int i=0; i<count; i++){
        int data;
        cin >> data;
        s->stack[s->rear] = data;
        s->rear++;
    }
    cout << "The size of the Queue:  " << s->rear;
}

void Pop(Queue *s, int count){
    cout << "The value pop:  ";
    for(int i=0; i<count; i++){
        cout << s->stack[s->front] << "  ";
        s->front++;
    }
    cout << "\nThe size of the Stack:  " << s->rear - s->front;
}

void Display(Queue *S){
    Queue *s = S;
    cout << "Display the Queue: ";
    for(int i=s->front; i<s->rear; i++)
        cout << s->stack[i] <<"  ";
    cout << "\nThe size of the Stack:  " << s->rear - s->front << endl;
}

int main(){
    Queue *s = (Queue *)malloc(sizeof(Queue));
    Create(s);
    int count;
    cout << "Please enter the count you will push: ";
    cin >> count;
    Push(s,count);           cout << "\n-----------------\n";
    cout << "Please enter the count you will pop:  ";
    cin >> count;
    Pop(s,count);            cout << "\n-----------------\n";
    Display(s);              cout << "-----------------\n";
}
>>>>>>> c
