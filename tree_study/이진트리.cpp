#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


typedef struct node 
{
	int data;
	struct node *left;
	struct node *right;
}	t_node;

t_node start_node(int data);
void add_data(t_node *root, int data);
void show_node(t_node *root);
void make_root(t_node *root, int data);
void remove_data(t_node *root, int data);
t_node *search_node(t_node *root, int data);

int main()
{
	t_node *root;
	int loop;
	int data;
	int menu_input;
	
	loop = 2;
	root = (t_node *)malloc(sizeof(t_node*));
	root->left = NULL;
	root->right = NULL;
	root->data = 0;
	while (loop)
	{
		printf("메뉴를 선택해주세요\n \
1. 삽입 \n \
2. 삭제 \n \
3. 출력 \n \
4. 종료 \n \
선택 : ");
		scanf("%d", &menu_input);
		scanf("%*c");
		switch(menu_input)
		{
			case 1:
				printf("삽입할 데이터를 입력하세요(숫자)\n");
				scanf("%d",&data);
				scanf("%*c");
				add_data(root, data);
				break;
			case 2:
				printf("삭제할 데이터를 입력하세요(숫자)\n");
				scanf("%d",&data);
				scanf("%*c");				
				remove_data(root, data);
				break;
			case 3:
				show_node(root);
				break;
			case 4:
				loop = 0;
				break;
			default:
				printf("잘못된 입력입니다.");
		}
	}
}

t_node *search_node(t_node *root, int data)
{
	if (root->data == data)
		return root;
	else if (root-> data > data && root->right != NULL)
		search_node(root->right, data);
	else if (root->data < data && root->left != NULL)
		search_node(root->left, data);
}


//remove_data 이부분은 삭제로 미완성인 부분입니다. 
void remove_data(t_node *root, int data)
{	
	t_node *find_data_node;
	t_node *change_data;
	int flag;
	
	flag = 0;
	find_data_node = search_node(root,data);
	
	if (root->data == find_data_node->data)
		find_data_node =0;

	if(find_data_node->right == NULL)
		if(find_data_node->left != NULL)
		change_data = find_data_node->left;
	else if(find_data_node->left == NULL)
	{
		if(find_data_node->right != NULL)
		{
			change_data = find_data_node->right;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		while (change_data->right != NULL)
		{
			change_data = change_data->right;
		}
	}
	else
	{
		while (change_data->left != NULL)
			change_data = change_data->left;
	}
	find_data_node->data = change_data->data;
	free(change_data);
}


void show_node(t_node *root)
{
	printf("%d\n", root->data);
	if (root->left != NULL)
		show_node(root->left);
	if (root->right != NULL)
		show_node(root->right);
}

t_node start_node(int data)
{
	t_node *root;
	
	root = (t_node*)malloc(sizeof(t_node*));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return (*root);
}


void add_data(t_node *root, int data)
{
	if (root->data == 0)
	{
		root->data = data;
		return;		
	}
	if (data > root->data)
	{
		if (root->right != NULL)
		{
			add_data(root->right, data);
			return;
		}
		else
		{
			t_node *newnode = (t_node *)malloc(sizeof(t_node*));
			newnode->data = data;
			newnode->left = NULL;
			newnode->right = NULL;
			root->right = newnode;
		}
	}
	if (data < root->data)
	{
		if (root->left != NULL)
		{
			add_data(root->left, data);
			return;
		}
		else
		{
			t_node *newnode = (t_node *)malloc(sizeof(t_node*));
			newnode->data = data;
			newnode->left = NULL;
			newnode->right = NULL;
			root->left = newnode;
		}
	}
}

