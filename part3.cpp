#include <iostream>
#include <queue>
#include "graph.h"
using namespace std;

int partyAlgo(int numPeople){

	Graph G(numPeople);
	bool invite[numPeople];
	queue<int> rejects;
	int input, accepted = 0;

   //Create relationships
	for(int i=0;i<numPeople;i++){
      cout << "Who does " << G.getPerson(i) << " know? Type -1 to end.\n";
      do{
         cout << "Person #: ";
         cin >> input;

         //If valid will add to adjacency matrix 
         if(input > 0 && input <= numPeople && input != i+1)
			{				
				if (G.isEdge(i,input-1))
					cout << "Person " << i+1 << " and Person " << input << " are already connected." << endl;
				else
					G.addEdge(i,input-1);
			}
         else if (input == i+1)
            cout << "That number belongs to them!" << endl;
         else if (input == -1)
            cout << "Person "<< i+1 << " has " << G.getDegree
					(i)<<" relationships." << endl;
         else
            cout << "Invalid input. Try again: ";
      }while(input != -1);
   }

	//First screen of invitees
	for (int i=0;i<numPeople;i++){
		invite[i] = 1; //start off by inviting everyone
		if (G.getDegree(i) < 5)
		{
			rejects.push(i); //this person is blacklisted
			invite[i] = 0; //un-invite those who know <5 people
		}
	}

	//Make sure everyone knows 5+ people
	while(!rejects.empty())
	{
		int j = rejects.front();
		rejects.pop();

		for(int i=0;i<numPeople;i++)
		{
			G.removeEdge(i,j);
			if (G.getDegree(i) < 5 && invite[i] == 1) //Now they cant come
			{
				rejects.push(i);
				invite[i] = 0;
			}
		}
	}

	//Final count of invited guests
	cout << endl;
	for (int i=0;i<numPeople;i++)
	{
		if (invite[i] == 1)
		{
			cout << G.getPerson(i) << " can come\n";
			accepted++;
		}
	}

	return accepted;
}

int main()
{
	//Initialize graph with num of invitees
	int n;
	cout << "Enter number of people: ";
	cin >> n;
	cout << endl;

	//Send to algorithm
	int output = partyAlgo(n);

	//Inform user of results
	if (output == n)
		cout << "Everyone knows each other, so everyone can come!\n";
	else if (output == 0)
		cout << "No one knew enough people, so there cannot be a party.\n";
	else
		cout << "Out of " << n << " people, " << output << " can come to the party.\n";

	cout << endl;
	return 0;
}
