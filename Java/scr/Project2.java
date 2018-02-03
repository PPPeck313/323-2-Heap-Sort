//Preston Peck
//CS 323
//September 17, 2016
//Project 2

import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Project2 {
	public static void main(String[] args) {
		try {
			Scanner inFile = new Scanner(new FileReader(args[0]));
			PrintWriter outFile1 = new PrintWriter(args[1]);
			PrintWriter outFile2 = new PrintWriter(args[2]);
			int counter = 1;
			while (inFile.hasNext()) {
				inFile.nextInt();
				counter++;
			}
			inFile.close();
			inFile = new Scanner(new FileReader(args[0]));
			PQSort heap = new PQSort(counter);
			heap.buildPQAry(inFile);
			heap.deletePQAry(outFile1, outFile2);
		}
		catch (Exception e) {
			System.out.println(e);
		}
	}
}
