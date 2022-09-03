/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main04_cpp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:37:20 by haeem             #+#    #+#             */
/*   Updated: 2022/09/01 22:42:02 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cstring>
#include "./ex00/ft_strlen.c"
#include "./ex01/ft_putstr.c"
#include "./ex02/ft_putnbr.c"
#include "./ex03/ft_atoi.c"
//#include "./ex04/ft_putnbr_base.c"
//#include "./ex05/ft_atoi_base.c"
// #include "./ex06/ft_.c"
// #include "./ex07/ft_.c"
// #include "./ex08/ft_.c"
#define fl fflush(stdout)
using namespace std;
int main(void)
{	
	

	// 어디선가 본 적 있지 않나요?
	char bread[] = "너는 지금까지 먹은 빵의 갯수를 일일히 기억하나?";
	cout<<"\n\n°º¤ø,,ø¤º°`°º¤ø, ex 00 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<strlen(bread); cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout<<ft_strlen(bread);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	

	
	// 어디선가 본 적 있지 않나요2?
	char cat[] = "05번 너무 어렵다 정말 집에 가고싶어 보내주세요 제발";
	cout<<"\n\n°º¤ø,,ø¤º°`°º¤ø, ex 01 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";printf("%s", cat);cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putstr(cat);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	



	// 어디선가 본 적 있지 않나요3?
	cout<<"\n\n°º¤ø,,ø¤º°`°º¤ø, ex 02 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'-2147483648'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr(-2147483648);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'-1'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr(-1);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr(0);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'2147483647'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr(2147483647);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	


	// 출력에 유의해야 합니다! (STL atoi가 아닌 문제 그대로 구현!)
	char a[] = " 	 ---+--+1234ab567";
	int b =ft_atoi(a);
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 03 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'-1234'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout<<b;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;


/*
	// 더럽고 치사해도 어쩌겠어요..! 0일 때와 INT_MAX, INT_MIN 값 등 엣지케이스에 유의합시다!
	char n0[] = {"-123123"};
	char n00[] = {"127823"};
	char n000[] = {"0"};
	char n2[] = {"01"};
	char n8[] = {"poneyvif"};
	char n10[] = {"0123456789"};
	char n16[] = {"0123456789ABCDEF"};
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 04 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'np'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(16, n8);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'FF'"<<endl;	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(255, n16);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'-2147483648'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(INT32_MIN, n10);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'2147483647'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(INT32_MAX, n10);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'p'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(0, n8);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'10000'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(16, n2);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "''"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(16, n000);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "''"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(16, n0);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "''"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_putnbr_base(16, n00);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	

	// char n8[] = {"poneyvif"};
	// char n10[] = {"0123456789"};
	// char n16[] = {"0123456789ABCDEF"};
	char aaaaaaaaaaaagh[] = "-poney";
	int molla = ft_atoi_base(aaaaaaaaaaaagh, n8);
	char aaaaaaaaaaaagh2[] = "100000";
	int molla2 = ft_atoi_base(aaaaaaaaaaaagh2, n2);
	char aaaaaaaaaaaagh3[] = "-11";
	int molla3 = ft_atoi_base(aaaaaaaaaaaagh3, n2);
	
	// 이제 당신은 숨도 16진법으로 쉬게 됩니다
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 05 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<-668;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << molla;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	
	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<32;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << molla2;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<-3;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << molla3;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << ft_atoi_base((char*)"", (char*)"");;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << ft_atoi_base((char*)"", (char*)"a");cout<<"'"<<endl;

	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"", (char*)"abcdefa");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"", (char*)"abcdef+");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"", (char*)"abcdef-");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"", (char*)"abcdef\t");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<12345;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"12345", (char*)"0123456789");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<1865;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"abcdef", (char*)"abcdef");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<-43210;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)" \t\n---+edcba", (char*)"abcdefghij");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<INT32_MIN;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"+-++--2147483648--12123", (char*)"0123456789");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"", (char*)"abc");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"---", (char*)"abc");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<-5;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"---+abc", (char*)"abc");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'";cout<<0;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << 	ft_atoi_base((char*)"---+123", (char*)"abc");cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;

*/	
}
