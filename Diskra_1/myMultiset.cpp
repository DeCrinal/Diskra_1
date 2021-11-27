#include"myMultiset.h"
vector<pair<vector<int>,int>>Universum;
const int minRank = 1;
const int maxRank = 20;
int powerOfUn;
unsigned int myMultiset::size()const{
	return multiset.size();
}
ostream& operator<<(ostream& of, const myMultiset& mM) {
	if (powerOfUn == 0) {
		of << "This multiset is empty" << endl;
	}
	of << endl;
	for (int i = 0; i < mM.size(); i++) {
		for (int j = 0; j < mM.multiset[i].first.size(); j++)
		of << mM.multiset[i].first[j];
		of << ", " << mM.multiset[i].second << endl;
	}
	return of;
}
myMultiset::myMultiset() {
}
void toFillUniversum_WithGray(int a) {
	if (a == 0) return;
	int upperBoard=powOf2(a);
	cout << "Gray Code generated:" << endl;
	Universum.resize(upperBoard);
	for (int i = 0; i < upperBoard; i++) {
		int temp = (i ^ (i >> 1));
		stack<int>grayCode;
		for (int j = 0; j < a; j++) {
			grayCode.push(temp % 2);
			temp /= 2;
		}
		while(grayCode.size()!=0)
		{
			Universum[i].first.push_back(grayCode.top());
			grayCode.pop();
		}
		Universum[i].second = (rand() % maxRank)+minRank;
		powerOfUn += Universum[i].second;
	}
}
int powOf2(int a) {
	int res = 1;
	res <<= a;
	return res;
}
int power(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) {
		res *= a;
	}
	return res;
}
void print_Universum() {
	if (powerOfUn == 0) {
		cout << "Universum is empty" << endl;
		return;
	}
	for (int i = 0; i < Universum.size(); i++) {
		for (int j = 0; j < Universum[i].first.size(); j++)
			cout << Universum[i].first[j];
		cout << ", "<<Universum[i].second;
		cout << endl;
	}
}
void myMultiset::initialize_auto(int cardinal) {
	if (cardinal > powerOfUn)
		cardinal = powerOfUn;
	multiset.resize(Universum.size());
	for (int i = 0; i < Universum.size(); i++) {
		multiset[i].first = Universum[i].first;
		multiset[i].second = 0;
	}
	for (int i = 0; i < cardinal; i++) {
		int temp = rand() % (Universum.size());
		if (multiset[temp].second < Universum[temp].second) {
			multiset[temp].second++;
		}
		else {
			i--;
		}
	}
 }
void myMultiset::initialize_handly(int cardinal) {
	int amElementsWasInserted = 0;
	multiset.resize(Universum.size());
	for (int i = 0; i < Universum.size(); i++) {
		multiset[i].first = Universum[i].first;
		multiset[i].second = 0;
	}
	for (;true;){
		string input;
		char rankStr[300];
		vector<int>temp;
		int index,rankInt;
		do {
			temp.resize(0);
			do {
				cout << "Input element and rank:" << endl;
				cin >> input;
				cin.clear();
				cin.sync(); 
                fgets(rankStr, sizeof(rankStr), stdin);
                while (sscanf(rankStr, "%d", &rankInt) != 1 || rankInt < 0
					||amElementsWasInserted+rankInt>powerOfUn) {
                    cout << "Incorrect input data, input element again:" << endl;
                    fflush(stdin);
                    fgets(rankStr, sizeof(rankStr), stdin);
                }
                fflush(stdin);
			} while (input.size() != Universum[0].first.size());
			for (int j = 0; j < Universum[0].first.size(); j++) {
				if (input[j] == '0' || input[j] == '1') {
					temp.push_back(input[j] - '0');
				}
			}
		} while (temp.size() != Universum[0].first.size());
		for (int j = 0; j < Universum.size(); j++) {
			if (temp == Universum[j].first) {
				index = j; 
				break;
			}
		}
		if (multiset[index].second + rankInt <= Universum[index].second
			&& amElementsWasInserted + rankInt <= cardinal) {
			multiset[index].second += rankInt;
			amElementsWasInserted += rankInt;
			cout << "Element accepted" << endl;
		}
		else
			cout <<"Incorrect rank, input element and rank again:" << endl;;
		if (amElementsWasInserted == cardinal)
			return;
	}
}
myMultiset integrateWith(const myMultiset& mM1, const myMultiset& mM2) {
	myMultiset res;
	res.multiset.resize(0);
	for (int i = 0; i < Universum.size(); i++) {
		res.multiset.push_back(make_pair(Universum[i].first, max(mM1.multiset[i].second,
			mM2.multiset[i].second)));
	}
	return res;
}
myMultiset myMultiset:: operator=(const myMultiset& mM_from) {
	this->multiset.resize(mM_from.multiset.size());
	for (int i = 0; i < mM_from.multiset.size(); i++) {
		this->multiset[i] = mM_from.multiset[i];
	}
	return *this;
}
myMultiset intersection(const myMultiset& mM1, const myMultiset& mM2) {
	myMultiset res;
	res.multiset.resize(0);
	for (int i = 0; i < Universum.size(); i++) {
		res.multiset.push_back(make_pair(Universum[i].first, min(mM1.multiset[i].second,
			mM2.multiset[i].second)));
	}
	return res;
}
myMultiset arithmeticSum(const myMultiset& mM1, const myMultiset& mM2) {
	myMultiset res;
	res.multiset.resize(0);
	for (int i = 0; i < Universum.size(); i++) {
		int tempSumOfRank = mM1.multiset[i].second + mM2.multiset[i].second;
		tempSumOfRank = min(tempSumOfRank, Universum[i].second);
		res.multiset.push_back(make_pair(Universum[i].first, tempSumOfRank));
	}
	return res;
}
myMultiset arithmeticSub(const myMultiset& mM1, const myMultiset& mM2) {
	myMultiset res;
	res.multiset.resize(0);
	for (int i = 0; i < Universum.size(); i++) {
		int tempSubOfRank = mM1.multiset[i].second - mM2.multiset[i].second;
		tempSubOfRank = max(tempSubOfRank, 0);
		res.multiset.push_back(make_pair(Universum[i].first, tempSubOfRank));
	}
	return res;
}
myMultiset symmetricSub(const myMultiset& mM1, const myMultiset& mM2) {
	myMultiset res;
	res.multiset.resize(0);
	for (int i = 0; i < Universum.size(); i++) {
		int tempSubOfRank = mM1.multiset[i].second - mM2.multiset[i].second;
		tempSubOfRank = (tempSubOfRank < 0) ? (-1) * tempSubOfRank : tempSubOfRank;
		res.multiset.push_back(make_pair(Universum[i].first, tempSubOfRank));
	}
	return res;
}
myMultiset additionToUniv(const myMultiset& mM1){
	myMultiset res;
	res.multiset.resize(0);
	for (int i = 0; i < Universum.size(); i++) {
		int tempSubOfRank = Universum[i].second - mM1.multiset[i].second;
		res.multiset.push_back(make_pair(Universum[i].first, tempSubOfRank));
	}
	return res;
}
myMultiset arithmeticMultip(const myMultiset& mM1, const myMultiset& mM2) {
	myMultiset res;
	res.multiset.resize(0);
	for (int i = 0; i < Universum.size(); i++) {
		int tempMultOfRank = mM1.multiset[i].second * mM2.multiset[i].second;
		tempMultOfRank = min(tempMultOfRank, Universum[i].second);
		res.multiset.push_back(make_pair(Universum[i].first, tempMultOfRank));
	}
	return res;
}
myMultiset subOfmMs(const myMultiset& mM1, const myMultiset& mM2) {
	myMultiset res; 
	res.multiset.resize(0);
	for (int i = 0; i < Universum.size(); i++) {
		int tempSubRank = min(mM1.multiset[i].second,
			Universum[i].second - mM2.multiset[i].second);
		res.multiset.push_back(make_pair(Universum[i].first, tempSubRank));
	}
	return res;
}
myMultiset arithmeticDiv(const myMultiset& mM1, const myMultiset& mM2) {
	myMultiset res;
	res.multiset.resize(0);
	int tempDivRank;
	for (int i = 0; i < Universum.size(); i++) {
		if (mM2.multiset[i].second == 0)
			tempDivRank = 0;
		else
			tempDivRank = mM1.multiset[i].second / mM2.multiset[i].second;
		res.multiset.push_back(make_pair(Universum[i].first, tempDivRank));
	}
	return res;
}
myMultiset powerSet(const myMultiset& mM1,int power_from) {
	myMultiset res;
	res.multiset.resize(0);
	int tempPowRank;
	for (int i = 0; i < Universum.size(); i++) {
		tempPowRank = mM1.multiset[i].second;
		tempPowRank = power(tempPowRank, power_from);
		tempPowRank = min(tempPowRank, Universum[i].second);
		res.multiset.push_back(make_pair(Universum[i].first, tempPowRank));
	}
	return res;
}