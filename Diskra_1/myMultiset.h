#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<map>
#include<vector>
using namespace std;
extern vector<pair<vector<int>,int>>Universum;
extern const int minRank;
extern const int maxRank;
extern int powerOfUn;
void toFillUniversum_WithGray(int a);
void print_Universum(void);
int powOf2(int a);
int power(int a, int b);
class myMultiset {
	vector<pair<vector<int>, int >>multiset;
public:
	friend myMultiset integrateWith(const myMultiset&mM1, const myMultiset& mM2);	//объединение множеств
	friend myMultiset intersection(const myMultiset&mM1, const myMultiset& mM2);	//пересечение множеств	
	friend myMultiset arithmeticSum(const myMultiset&mM1, const myMultiset& mM2);	//арифметическая сумма
	friend myMultiset subOfmMs(const myMultiset& mM1, const myMultiset& mM2);		//вычитание
	friend myMultiset arithmeticDiv(const myMultiset& mM1, const myMultiset& mM2);	//арифм. деление
	friend myMultiset arithmeticSub(const myMultiset&mM1,const myMultiset& mM2);	//арифм. разность
	friend myMultiset symmetricSub(const myMultiset&mM1,const myMultiset& mM2);		//сим. разность
	friend myMultiset additionToUniv(const myMultiset& mM1);						//дополнение до унив
	friend myMultiset arithmeticMultip(const myMultiset& mM1, const myMultiset& mM2);
	friend myMultiset powerSet(const myMultiset& mM1,int power);
	myMultiset operator=(const myMultiset& mM_from);
	myMultiset(int cardinal = Universum.size());
	void initialize_auto(int cardinal);
	void initialize_handly(int cardinal);
	unsigned int size()const;
	friend ostream& operator<<(ostream& of, const myMultiset& mM);
};
