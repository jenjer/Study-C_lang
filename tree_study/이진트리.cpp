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

int main()
{
	t_node *root;
	int loop;
	int data;
	int menu_input;
	
	loop = 2;
	root = (t_node *)malloc(sizeof(t_node*));
	if (!root)
		return 0; 
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

t_node *find_rm_up(t_node *root, int data)
{
	if (root->data > data)
	{
		if (root->left == NULL)
		{
			return NULL;
		}
		if (root->left->data == data)
			return root;
		find_rm_up(root->left, data);
	}
	else 
	{
		if (root->right == NULL)
		{
			return NULL;
		}
		if (root->right->data == data)
			return root;
		find_rm_up(root->right, data);
	}
}

//remove_data 이부분은 삭제로 root 삭제 처리가 미완성입니다. 
void remove_data(t_node *root, int data)
{
	t_node *rm_upper;
	t_node *rm;
	t_node *change;
	t_node *change_before;
	int flag;
	
	flag = 0;
	if (root->data == data && root->left == NULL && root->right ==NULL)//노드가 1개뿐일 때 
	{
		root->data = 0;
		return;
	}
	rm_upper = find_rm_up(root,data);
	if (rm_upper->data < data)
		rm = rm_upper->right;
	else
		rm = rm_upper->left;
	if (rm->left == NULL && rm->right == NULL) // 삭제하고자 하는 노드가 끝 노드일때 
	{	
		if  (rm_upper->data > data)
		{
			rm_upper->left = NULL;
			return ;
		}
		else
		{
			rm_upper->right = NULL;
			return ;
		}
	}
	else if (rm->right != NULL)//삭제하고자 하는 노드가 중간에 있을 때 교환 만들어야된다 아직 미완. 
	{
		change = rm->right;
		while (change->left != NULL)
		{
			change_before = change;
			change = change->left;
			flag = 1;
		}
		if (flag == 0)
		{
			rm_upper->right = rm_upper->right->right;
			free(rm);
			return;
		}
		rm->data = change->data;
		change_before->left = NULL;
		free(change);
	}
	else if (rm->left != NULL)
	{
		change = rm->left;
		while (change->right != NULL)
		{
			change_before = change;
			change = change->right;
			flag = 1;
		}
		if (flag == 0)
		{
			rm_upper->left = rm_upper->left->left;
			free(rm);
			return;
		}
		rm->data = change->data;
		change_before->right = NULL;
		free(change);
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

