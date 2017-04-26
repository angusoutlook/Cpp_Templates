// FunTemplates.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "classTemplate.h"
#include "noTypetemplateParamters.h"
#include "SeniorBasicTech.h"

#include "templateInPratice.h"
#include "fundamentalsInDepth.h"
#include "polymorphism.h"
#include "traits.h"

void BasicKnowledge();

void TemplateInPratice();

void Polymorphism() {

}

void Traits() {
	int num[] = { 1,2,3,4,5 };
	std::cout << "the average value of the integer values is " << accum(&num[0], &num[5]) << std::endl;

	double dNum[] = { 1.1,2.1,3.1,4.1,5.1 };
	std::cout << "the total value of the integer values is " << Accum<double>::accum(&dNum[0], &dNum[5]) << std::endl;

	double dNum1[] = { 1.1,2.1,3.1,4.1,5.1 };
	std::cout << "the mult value of the integer values is " << Accum<double,MultPolicy>::accum(&dNum1[0], &dNum1[5]) << std::endl;


	char name[] = "templates";
	int length = sizeof(name) - 1;

	std::cout << "the average value of the characters in \"" << name << "\" is " << accum(&name[0], &name[length]) / length << std::endl;

	char* namestring[] = { ":","angus","zhang","huaweiwei","zhanghuabing"};
	length = sizeof(namestring)/sizeof(char*);

	std::cout << "the cat value of the characters in \"" << name << "\" is " << Accum<char*,CatPolicy>::accum(&namestring[0], &namestring[length]) << std::endl;
}


int main()
{
	
	//BasicKnowledge();

	//TemplateInPratice();
	
	//Polymorphism();

	Traits();

    return 0;
}

void BasicKnowledge()
{

	max<double>(1.0, -3.0); // explicit template arguments
	max(1.0, -3.0); // template arguments ����ʽ�Ƶ�Ϊ double
	max<long>(1.0, 3.0); // ��ȷָ��<int> �������Ƶ����Ӷ����Ա�������Ϊ 	int

	::max(7, 42, 68); // ���á����������Ա������ĺ���
	::max(7.0, 42.0); // ���� max<double>�������Ա����Ƶ���
	::max('a', 'b'); // ���� max<char>�������Ա����Ƶ���
	::max(7, 42); // ���á��������� int�Ա������� non-template ����
	::max<>(7, 42); // ���� max<int>�������Ա����Ƶ���
	::max<double>(7, 42); // ���� max<double>�������Ա����Ƶ���
						  //::max((char const*)'a',(char const*) '42.7'); // ���á��������� int�Ա������� non-template ����


	::max(7, 42, 68); // ���á����������Ա������ĺ���
	::max(7.0, 42.0); // ���� max<double>�������Ա����Ƶ���
	::max('a', 'b'); // ���� max<char>�������Ա����Ƶ���
	::max(7, 42); // ���á��������� int�Ա������� non-template ����
	::max<>(7, 42); // ���� max<int>�������Ա����Ƶ���
	::max<double>(7, 42); // ���� max<double>�������Ա����Ƶ���
	::max('a', (const int)42.7); // ���á��������� int�Ա������� non-template ����


	::max(7, 42, 68); // OK
	const char* s1 = "frederic";
	const char* s2 = "anica";
	const char* s3 = "lucas";
	::max(s1, s2, s3); // ERROR

					   //---------------------------------------------
	try {

		ref("hello");
		nonref("hello");


		Stack<int> intStack, intStack1;
		Stack<double> doubleStack1;
		Stack<std::string> stringStack;
		intStack.push(7);
		std::cout << intStack.top() << std::endl;

		intStack.push(8);
		intStack.push(9);
		intStack1.push(9);
		intStack = intStack1;
		doubleStack1 = intStack1;
		//intStack1 = stringStack;

		stringStack.push("hello");
		std::cout << stringStack.top() << std::endl;
		stringStack.pop();
		//stringStack.pop();

		Stackv2<double, std::deque<double> >doubleStack;
		doubleStack.push(1212.131);
		std::cout << doubleStack.top() << std::endl;
		doubleStack.pop();
		//doubleStack.pop();

		NtStack<> int100Stack;
		NtStack<int, 40> int40Stack;

		for (int i = 0; i < 50; i++) {
			int100Stack.push(i);
			//int40Stack.push(i);
		}
		std::vector<int> stack1;
		stack1.push_back(1);
		stack1.push_back(2);
		printcoll(stack1);

		Stack<int, std::vector<int> >vStack;
		vStack.push(2);
		vStack.push(4);
		//printcoll(vStack);

	}
	catch (std::exception const &ex) {
		std::cerr << "Exceptioin: " << ex.what() << std::endl;

	}

}


void TemplateInPratice() {
	double ice = 30.0;
	print_typeof(ice);

	//shell(main_client);

	// ׼����������Դ
	SortTracer input[] = { 7, 3, 5, 6, 4, 2, 0, 1, 9, 8 };
	// ��ӡ��ʼֵ
	for (int i = 0; i<10; ++i) {
		std::cerr << input[i].val() << ' ';
	}
	std::cerr << std::endl;
	// ��¼��ʼֵ
	long created_at_start = SortTracer::creations();
	long max_live_at_start = SortTracer::max_live();
	long assigned_at_start = SortTracer::assignments();
	long compared_at_start = SortTracer::comparisons();
	// ִ���㷨
	std::cerr << "---[ Start std::sort() ]--------------------" << std::endl;
	std::sort<>(&input[0], &input[9] + 1);
	std::cerr << "---[ End std::sort() ]----------------------" << std::endl;
	// ������
	for (int i = 0; i<10; ++i) {
		std::cerr << input[i].val() << ' ';
	}
	std::cerr << std::endl << std::endl;
	// ���ձ���
	std::cerr << "std::sort() of 10 SortTracer's"
		<< " was performed by: " << std::endl
		<< SortTracer::creations() - created_at_start
		<< " temporary tracers" << std::endl << ' '
		<< "up to "
		<< SortTracer::max_live()
		<< " tracers at the same time ("
		<< max_live_at_start << " before)" << std::endl << ' '
		<< SortTracer::assignments() - assigned_at_start
		<< " assignments" << std::endl << ' '
		<< SortTracer::comparisons() - compared_at_start
		<< " comparisons" << std::endl << std::endl;
}
