//Preston Peck
//CS 323
//September 17, 2016
//Project 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class PQSort {
private:
    int length;
    int* PQAry = new int[length];

    void insertOneDataItem(int data);
    void DeleteRoot(ofstream& outFile1, ofstream& outFile2);
    void bubbleUp(int index);
    void bubbleDown(int index);
    bool isPQAryEmpty();
    bool isPQAryFull();
    void printPQAry();
    void printPQAry(ofstream& outFile);
public:
    PQSort();
    PQSort(int l);
    ~PQSort();
    int getLeftKid(int index);
    int getRightKid(int index);
    int getFather(int index);
    void buildPQAry(ifstream& inFile, ofstream& outFile);
    void deletePQAry(ofstream& outFile1, ofstream& outFile2);
};

int main(int argc, char *argv[]) {
	ifstream inFile;
	ofstream outFile1;
	ofstream outFile2;
    inFile.open(argv[1]);
        if (!inFile.is_open()) {
        cerr<<"File failed to open!"<<endl;
        return 0;
    }
    int data = 0;
    int counter = 1;
	while(inFile >> data) {
		counter++;
	}
	inFile.close();
    inFile.open(argv[1]);
    outFile1.open(argv[2]);
    outFile2.open(argv[3]);
	PQSort* heap = new PQSort(counter);
	heap->buildPQAry(inFile, outFile1);
	heap->deletePQAry(outFile1, outFile2);
}

PQSort::PQSort() {
    length = 1;
	PQAry = new int[length];  
}

PQSort::PQSort(int l) {
    length = l;
	PQAry = new int[length];
}

PQSort::~PQSort() {
    delete PQAry;
}

int PQSort::getLeftKid(int index) {
	return index * 2;
}

int PQSort::getRightKid(int index) {
	return (index * 2) + 1;
}

int PQSort::getFather(int index) {
	return index / 2;
}

void PQSort::buildPQAry(ifstream& inFile, ofstream& outFile) {
    int data = 0;
	while(inFile >> data && !isPQAryFull()) {
		insertOneDataItem(data);
		bubbleUp(PQAry[0]);
		printPQAry(outFile);
	}
	outFile << endl;
	inFile.close();
}

void PQSort::deletePQAry(ofstream& outFile1, ofstream& outFile2) {
	DeleteRoot(outFile1, outFile2);
}

void PQSort::insertOneDataItem(int data) {
	PQAry[PQAry[0] + 1] = data;
	PQAry[0] += 1;
}

void PQSort::DeleteRoot(ofstream& outFile1, ofstream& outFile2) {
	while (!isPQAryEmpty()) {
		outFile2 << PQAry[1] << " ";
		PQAry[1] = PQAry[PQAry[0]];
		PQAry[0] -= 1;
		bubbleDown(1);
		printPQAry(outFile1);
	}
	outFile1.close();
	outFile2.close();
}

void PQSort::bubbleUp(int index) {
	int father = getFather(index);
	while (father != 0 && PQAry[index] < PQAry[father]) {
		PQAry[index] = PQAry[index] + PQAry[father];
		PQAry[father] = PQAry[index] - PQAry[father];
		PQAry[index] = PQAry[index] - PQAry[father];
		index = father;
		father = getFather(index);
	}
}

void PQSort::bubbleDown(int index) {
	int smallKid = 0;
	if (getRightKid(index) <= PQAry[0] && PQAry[getRightKid(index)] < PQAry[getLeftKid(index)]) {
		smallKid = getRightKid(index);
	}
	else {
		smallKid = getLeftKid(index);
	}
	while (smallKid <= PQAry[0] && PQAry[index] > PQAry[smallKid]) {
		PQAry[index] = PQAry[index] + PQAry[smallKid];
		PQAry[smallKid] = PQAry[index] - PQAry[smallKid];
		PQAry[index] = PQAry[index] - PQAry[smallKid];
		index = smallKid;
		if (getRightKid(index) <= PQAry[0] && PQAry[getLeftKid(index)] < PQAry[getRightKid(index)]) {
			smallKid = getLeftKid(index);
		}
		else {
			smallKid = getRightKid(index);
		}
	}
}

bool PQSort::isPQAryEmpty() {
	if (length == 0 || PQAry[0] == 0) {
		return true;
	}
	return false;
}

bool PQSort::isPQAryFull() {
	if (PQAry[0] == length) {
		return true;
	}
	return false;
}

void PQSort::printPQAry(ofstream& outFile) {
	for (int i = 1; i <= PQAry[0] && i <= 10; i++) {
		outFile << PQAry[i] << " ";
	}
	outFile << endl;
}
