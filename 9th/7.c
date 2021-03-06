#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data;
	struct tree *l_node;
	struct tree *r_node;
}Tree;

Tree* get_node(void);
void entree(Tree** root,int data);
Tree* detree(Tree** root,int data);
int findMax(Tree** root);
Tree* findDelete(Tree** root,int data);
Tree* pre_node(Tree** root,int data);
Tree* nex_node(Tree** root,int data);
void print_Tree(Tree** root);

int main(void){

	Tree *root = NULL;
	Tree *tmp1;
	Tree *tmp2;
	
	entree(&root,50);
	entree(&root,45);
	entree(&root,73);
	entree(&root,32);
	entree(&root,48);
	entree(&root,46);
	entree(&root,16);
	entree(&root,37);
	entree(&root,120);
	entree(&root,47);
	entree(&root,130);
	entree(&root,127);
	entree(&root,124);

	
	printf("origin tree : \n");
	print_Tree(&root);
	detree(&root,130);
	printf("deleted tree : \n");
	print_Tree(&root);
	printf("\n");
}

void entree(Tree** root,int data){

	int num;
	Tree* tmp;
	
	if(*root == NULL){
		tmp = get_node();
		tmp->data = data;
		*root = tmp;		
	}
	else{
		num = (*root)->data;
		data>num ? entree(&((*root)->r_node),data) : entree(&((*root)->l_node),data);
	}

}


Tree* get_node(void){
	Tree *tmp;
	tmp = (Tree*)malloc(sizeof(Tree)*1);
	tmp->l_node = NULL;
	tmp->r_node = NULL;
	
	return tmp;
}


Tree* detree(Tree** root,int data){
	
	Tree *deleted_node;
	Tree *prev_node;
	Tree *tmp;
	int max;
	
	deleted_node = *root;
	deleted_node = findDelete(&deleted_node,data);		
	
	if(deleted_node->l_node)	
		max = findMax(&(deleted_node->l_node));
	else if(deleted_node->r_node)
		max = findMax(&(deleted_node->r_node));
	else
		max = deleted_node->data;

	prev_node = pre_node(root,max);	

	printf("\n\nprev : %d\n",prev_node->data);
	printf("del : %d\nmax : %d\n\n",deleted_node->data,max);

	deleted_node->data = max;


	if(prev_node->r_node){
		tmp = prev_node->r_node;
		if(tmp->l_node)
			prev_node->r_node = tmp->l_node;
		else if(tmp->r_node)
			prev_node->r_node = tmp->r_node;
		else
			prev_node->r_node = NULL;	
	}
	else{
		tmp = prev_node->l_node;
		if(tmp->l_node)
			prev_node->l_node = tmp->l_node;
		else if(tmp->r_node)
			prev_node->l_node = tmp->r_node;
		else
			prev_node->l_node = NULL;	
	}
	free(tmp);

}
	
Tree* findDelete(Tree** root,int data){
	
	Tree* deleted_node;
	deleted_node = *root;
	
	if(deleted_node->data < data)
		findDelete(&(deleted_node->r_node),data);
	else if(deleted_node->data > data)
		findDelete(&(deleted_node->l_node),data);
	else
		return deleted_node;
}

int findMax(Tree** root){
	
	Tree *tmp;
	tmp = *root;
	
	if(tmp->r_node)
		findMax(&(tmp->r_node));
	else
		return tmp->data;
}

Tree* pre_node(Tree** root,int data){
	
	Tree* tmp;
	tmp = *root;

	if(data < tmp->data){
		if((tmp->l_node)->data != data)
			pre_node(&(tmp->l_node),data);
		else
			return tmp;
	}
	else if(data > tmp->data){
		if((tmp->r_node)->data != data)
			pre_node(&(tmp->r_node),data);
		else
			return tmp;
	}
	else
		return NULL;

}

void print_Tree(Tree** root){
	Tree* tmp = *root;
	if((tmp->l_node)&&(tmp->r_node)){
		printf("%d ",tmp->data);
		print_Tree(&(tmp->l_node));
		print_Tree(&(tmp->r_node));
	}
	else if(tmp->l_node){
		printf("%d ",tmp->data);
		print_Tree(&(tmp->l_node));
	}
	else if(tmp->r_node){
		printf("%d ",tmp->data);
		print_Tree(&(tmp->r_node));
	}
	else
		printf("%d ",tmp->data);
//	printf("%d ",tmp->data);
	

}
