/*
 *	So far, so good.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *parent;
	struct node *leftChild;
	struct node *rightChild;
}*root = NULL, *currentNode = NULL, *enteringNode = NULL, *outputNode = NULL;

struct stack {
	struct node* data;
	struct stack* next;
}*top = NULL, *temp = NULL;

void enterNode();
void printTree();
void inOrder();
void preOrder();
void postOrder();
void push(struct node *);
void pop();

int nodes = 0;

int main() {
	//int levels, elementNumber, nodeElement, currentLevel = 0, entering = 1, choice;
	int intedChoice;
	char choice, *choicePointer;
	while ( 1 ) {

		printf("\n...Enter a choice:...\n");
		printf("1. Enter a new element into the tree.\n");
		printf("2. Print the tree entered so far.\n");
		printf("3. Exit the program.\n\n");
		scanf("%d", &intedChoice);
		//choicePointer = &choice;
		//intedChoice = atoi(choicePointer);

		switch (intedChoice) {
			case 1: enterNode();
				break;
			case 2: printTree();
				break;
			case 3: exit(1);
				break;
			default:printf("Didn't catch that! Try again.");
		}
	}
	return 0;
}

void enterNode() {
	int nodeElement, levels;
	printf("\n\nEnter the element to be pushed into the tree:\n");
	scanf("%d", &nodeElement);
	if( root == NULL) {	
		//The tree is empty. Hence use the element entered first as the root.
		root = (struct node *) malloc( sizeof(struct node) );
		currentNode = (struct node *) malloc( sizeof(struct node) );
		root->data = nodeElement;
		root->parent = NULL;
		root->rightChild = NULL;
		root->leftChild = NULL;
		currentNode = root;
		nodes++;
		printf("Rooted!\n");
	}
	else {
		enteringNode = (struct node *) malloc( sizeof(struct node) );
		enteringNode->data = nodeElement;
		enteringNode->leftChild = NULL;
		enteringNode->rightChild = NULL;
		//checkAgain:
		while ( 1 ) {
			if (enteringNode->data <= currentNode->data) {
			//The incoming element is less than the current one.
				if(currentNode != root) {
				//The current node is not the root node.
					if (enteringNode->data <= currentNode->parent->data) {
						if (currentNode == currentNode->parent->leftChild) {
						//The incoming node is less than the current one and also 
						//less than its parent and the current node is the left
						//child of its parent.
							if (currentNode->leftChild == NULL) {
								currentNode->leftChild = enteringNode;
								enteringNode->parent = currentNode;
								currentNode = enteringNode;
								nodes++;
								break;
							}
							else {
								currentNode = currentNode->leftChild;
							}
						}
						else {
						//The incoming node is less the current node and also less than
						//its parent, but the current node is the right child of its parent.
						//In this case the incoming node belongs to the other side of the parent.
							currentNode = currentNode->parent;
						}
					}
					else {
					//The incoming node is less than the current node but greater than its parent.
						if (currentNode == currentNode->parent->rightChild) {
						//The incoming node belongs to the current one only if the current node
						//is the right child of its parent.
							if (currentNode->leftChild == NULL) {
								currentNode->leftChild = enteringNode;
								enteringNode->parent = currentNode;
								currentNode = enteringNode;
								nodes++;
								break;
							}
							else {
								currentNode = currentNode->leftChild;
							}
						}
						//There can be no 'else' for this, since it is impossible that the current
						//node is left child of its parent and the incoming node is less than it
						//but greater than its parent.
					}
				}
				else {
				//The current node is the root node.
					if (currentNode->leftChild == NULL) {
						currentNode->leftChild = enteringNode;
						enteringNode->parent = currentNode;
						currentNode = enteringNode;
						nodes++;
						break;
					}
					else {
						currentNode = currentNode->leftChild;
					}
				}
			}
			else {
			//The incoming node is greater than the current one, hence go to its right.
				if (currentNode != root) {
				//The current is not root.
					if (enteringNode->data > currentNode->parent->data) {
					//The incoming node is greater than the current node and greater than its parent.
						if (currentNode == currentNode->parent->rightChild) {
						//The entering node is greater than the current node and greater than
						//its parent and the current node is the right child of its parent.
							if (currentNode->rightChild == NULL) {
								currentNode->rightChild = enteringNode;
								enteringNode->parent = currentNode;
								currentNode = enteringNode;
								nodes++;
								break;
							}
							else {
								currentNode = currentNode->rightChild;
							}
						}
						else {
						//The incoming node is greater than the current node and also greater
						//than its parent, but the current node is left child of its parent.
						//In this case, the incoming node belongs to the other side of the parent.
							currentNode = currentNode->parent;
						}
					}
					else {
					//The current element is greater than the current, but less than the parent.
						if (currentNode == currentNode->parent->leftChild) {
							if (currentNode->rightChild == NULL) {
								currentNode->rightChild = enteringNode;
								enteringNode->parent = currentNode;
								currentNode = enteringNode;
								nodes++;
								break;
							}
							else {
								currentNode = currentNode->rightChild;
							}
						}
						//There can be no 'else' for this, since it is impossible that the current
						//node is right child of its parent and the incoming node is less than
						//it but greater than its parent.
					}
				}
				else {
				//The current node is the root node.
					if (currentNode->rightChild == NULL) {
						currentNode->rightChild = enteringNode;
						enteringNode->parent = currentNode;
						currentNode = enteringNode;
						nodes++;
						break;
					}
					else {
						currentNode = currentNode->rightChild;
					}
				}
			}
		}
	}
	printf("The element %d is pushed into the tree.\n", nodeElement);
}


void printTree() {
	int choice;
	printf("\n...Select an option for printing the tree...\n");
	printf("1. Print in pre-order.\n");
	printf("2. Print in in-order.\n");
	printf("3. Print in post-order.\n");
	scanf("%d", &choice);

	switch (choice) {
		case 1: preOrder();
			break;
		case 2: inOrder();
			break;
		case 3: postOrder();
			break;
		default:printf("Didn't catch that! Choose print and try again!\n");
	}
}

void preOrder() {
	currentNode = root;
	//printf("%d\t", currentNode->data);
	while(currentNode->rightChild != NULL && currentNode->leftChild != NULL) {
		printf("%d\t", currentNode->data);
		push(currentNode->rightChild);
		if (currentNode->leftChild == NULL) {
			pop();
		}
		else {
			currentNode = currentNode->leftChild;
		}
	}
	printf("\n\n");
}

void inOrder() {
}

void postOrder() {
}

void push(struct node *child) {
	if (top == NULL) {
		top = (struct stack *) malloc ( sizeof(struct stack) );
		top->next = NULL;
		top->data = child; 
	}
	else {
		temp = (struct stack *) malloc ( sizeof(struct stack) );
		temp->next = top;
		temp->data = child;
		top = temp;
	}
}

void pop() {
	printf("%d\t", top->data->data);
	top = top->next;
}
