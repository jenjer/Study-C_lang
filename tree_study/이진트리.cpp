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
void ft_puts(char *str);
void show_node(t_node *root);
void make_root(t_node *root, int data);

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
				printf("데이터를 입력하세요(2자리수)\n");
				scanf("%d",&data);
				scanf("%*c");
				break;
			case 2:
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

void show_node(t_node *root)
{
	printf("%d\n", root->data);
	if (root->left != NULL)
		show_node(root->left);
	if (root->right != NULL)
		show_node(root->right);
}


void ft_puts(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

t_node start_node(int data)
{
	t_node *root;
	root = (t_node*)malloc(sizeof(t_node*));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return *root;
}
void make_root(t_node *root, int data)
{
	root-> data = data;
}

void add_data(t_node *root, int data)
{
	if (root->left == NULL && root->right==NULL)
	{
		make_root(root, data);
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
			root->right = newnode;
		}
	}
}

