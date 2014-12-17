/*Author: Ken Durkin
 *Course: CISC4080
 *Assignment: Final Exam Part 3
 *Submission: 12/16/14
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Graph {
private:
	bool** adjMatrix;
	string* people;
	int vertexNum;
public:
	//constructor
	Graph(int vertexNum){
		this->vertexNum=vertexNum;

		people = new string[vertexNum];
		for(int i=0;i<vertexNum;i++){
			char buff[vertexNum+8];
			sprintf(buff,"Person #%d",i+1);
			people[i] = buff;
		}

		adjMatrix = new bool*[vertexNum];
		for(int i=0;i<vertexNum;i++){
			adjMatrix[i]=new bool[vertexNum];
			for(int j=0;j<vertexNum;j++)
				adjMatrix[i][j]=false;
		}
	}

	void addEdge(int i,int j){
		if(i>=0 && i < vertexNum && j >= 0 && j < vertexNum)
		{
			adjMatrix[i][j] = true;
			adjMatrix[j][i] = true;
		}
	}

	void removeEdge(int i, int j) {
		if (i >= 0 && i < vertexNum && j >= 0 && j < vertexNum)
		{
			adjMatrix[i][j] = false;
			adjMatrix[j][i] = false;
		}
	}

	bool isEdge(int i, int j) {
		if(i>=0 && i<vertexNum && j>=0 && j<vertexNum)
			return adjMatrix[i][j];
		else
			return false;
	}

	string getPerson(int i)
	{
		if(i>=0 && i<vertexNum)
			return people[i];
		else
			return "Does Not Exist";
	}

	int getDegree(int i)
	{
		if(i>=0 && i<vertexNum)
		{
			int totalDeg = 0;
			for(int j=0;j<vertexNum;j++)
				if(adjMatrix[i][j])
					totalDeg++;
			return totalDeg;
		}
		else
			return 0;
	}

	~Graph() {
		delete[] people;

		for (int i=0;i<vertexNum;i++)
			delete[] adjMatrix[i];
		delete[] adjMatrix;
	}
};
#endif
