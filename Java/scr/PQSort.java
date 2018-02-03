import java.io.*;
import java.util.*;

public class PQSort {
	int PQAry[];
	
	PQSort() {
		PQAry = new int[1];
	}

	PQSort(int l) {
		PQAry = new int[l];
	}
	
	int getLeftKid(int index) {
		return index * 2;
	}
	
	int getRightKid(int index) {
		return (index * 2) + 1;
	}
	
	int getFather(int index) {
		return index/2;
	}
	
	void buildPQAry(Scanner inFile) {
		while(inFile.hasNext() && !isPQAryFull()) {
			int data = inFile.nextInt();
			insertOneDataItem(data);
			bubbleUp(PQAry[0]);
			printPQAry(null);
		}
		inFile.close();
	}
	
	void deletePQAry(PrintWriter outFile1, PrintWriter outFile2) {
		DeleteRoot(outFile1, outFile2);
	}
	
	private void insertOneDataItem(int data) {
		PQAry[PQAry[0] + 1] = data;
		PQAry[0] += 1;
	}
	
	private void DeleteRoot(PrintWriter outFile1, PrintWriter outFile2) {
		while (!isPQAryEmpty()) {
			outFile2.print(PQAry[1] + " ");
			PQAry[1] = PQAry[PQAry[0]];
			PQAry[0] -= 1;
			bubbleDown(1);
			printPQAry(outFile1);
		}
		outFile1.close();
		outFile2.close();
	}
	
	private void bubbleUp(int index) {
		int father = getFather(index);
		while (father != 0 && PQAry[index] < PQAry[father]) {
			PQAry[index] = PQAry[index] + PQAry[father];
			PQAry[father] = PQAry[index] - PQAry[father];
			PQAry[index] = PQAry[index] - PQAry[father];
			index = father;
			father = getFather(index);
		}
	}
	
	private void bubbleDown(int index) {
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
	
	private boolean isPQAryEmpty() {
		if (PQAry.length == 0 || PQAry[0] == 0) {
			return true;
		}
		return false;
	}
	
	private boolean isPQAryFull() {
		if (PQAry[0] == PQAry.length) {
			return true;
		}
		return false;
	}
	
	private void printPQAry(PrintWriter outFile) {
		if (outFile == null) {
			for (int i = 1; i <= PQAry[0]; i++) {
				System.out.print(PQAry[i] + " ");
			}
			System.out.println();
		}
		else {
			for (int i = 1; i <= PQAry[0] && i <= 10; i++) {
				outFile.print(PQAry[i] + " ");
			}
			outFile.println();
		}
	}
}
