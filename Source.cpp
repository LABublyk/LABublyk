#define _CRT_SECURE_NO_WARNINGS
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <iostream> 
using namespace std;
struct newtype {
	float a;
	float b;
	int n;
};

int main(int argc, char* argv[]) {
	char message[25];
	MPI_Group MPI_GROUP_WORLD;
	MPI_Group group;
	MPI_Comm fcomm;
	int size, q, proc;
	int* process_ranks;
	int rank, rankInGroup;
	MPI_Status status;
	MPI_Init(NULL, NULL);
	MPI_Comm_group(MPI_COMM_WORLD, &MPI_GROUP_WORLD);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("New group contains processes:");
	q = size - 1;
	process_ranks = (int*)malloc(q * sizeof(int));
	for (proc = 0; proc < q; proc++) {
		process_ranks[proc] = proc;
		printf("%i ", process_ranks[proc]);
	}
	MPI_Group_incl(MPI_GROUP_WORLD, q, process_ranks, &group);
	MPI_Comm_create(MPI_COMM_WORLD, group, &fcomm);
	printf("\n");
	if (fcomm != MPI_COMM_NULL) {
		MPI_Comm_group(fcomm, &group);
		MPI_Comm_rank(fcomm, &rankInGroup);
		if (rankInGroup == 0) {
			strcpy(message, "Hi, Parallel Programmer!");
			MPI_Bcast(&message, 26, MPI_BYTE, 0, fcomm);
			printf("0, send: %s\n", message);
		}
		else {
			MPI_Bcast(message, 26, MPI_BYTE, 0, fcomm);
			printf("%i received: %s\n", rankInGroup, message);
		}
		MPI_Comm_free(&fcomm);
		MPI_Group_free(&group);
	}
	MPI_Finalize();
	return 0;
}




void task1() {
	char data[25];
	int myrank, count = 26;
	MPI_Status status;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	if (myrank == 0) {
		strcpy(data, "Hi, Parallel Programmer!");
		MPI_Bcast(data, count, MPI_CHAR, 0, MPI_COMM_WORLD);
		printf("send:%s\n", data);
	}
	else {
		MPI_Bcast(data, count, MPI_CHAR, 0, MPI_COMM_WORLD);
		printf("received: %s\n", data);
	}
	MPI_Finalize();
	//return 0;

}

void task2() {
	int myrank;
	int root = 0;
	int count = 1;
	float a, b;
	int n;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	if (myrank == 0) {
		printf("Ented a, b, n\n");
		cin >> a >> b >> n;
		MPI_Bcast(&a, count, MPI_FLOAT, root, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Bcast(&b, count, MPI_FLOAT, root, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Bcast(&n, count, MPI_INT, root, MPI_COMM_WORLD);
	}
	else {
		MPI_Bcast(&a, count, MPI_FLOAT, root, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Bcast(&b, count, MPI_FLOAT, root, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Bcast(&n, count, MPI_INT, root, MPI_COMM_WORLD);
		printf("%i Process got %f %f %i\n", myrank, a, b, n);
	}
	MPI_Finalize();
	//return 0;

}

void task3() {
	char message[25];
	MPI_Group MPI_GROUP_WORLD;
	MPI_Group group;
	MPI_Comm fcomm;
	int size, q, proc;
	int* process_ranks;
	int rank, rankInGroup;
	MPI_Status status;
	MPI_Init(NULL, NULL);
	MPI_Comm_group(MPI_COMM_WORLD, &MPI_GROUP_WORLD);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("New group contains processes:");
	q = size - 1;
	process_ranks = (int*)malloc(q * sizeof(int));
	for (proc = 0; proc < q; proc++) {
		process_ranks[proc] = proc;
		printf("%i ", process_ranks[proc]);
	}
	MPI_Group_incl(MPI_GROUP_WORLD, q, process_ranks, &group);
	MPI_Comm_create(MPI_COMM_WORLD, group, &fcomm);
	printf("\n");
	if (fcomm != MPI_COMM_NULL) {
		MPI_Comm_group(fcomm, &group);
		MPI_Comm_rank(fcomm, &rankInGroup);
		if (rankInGroup == 0) {
			strcpy(message, "Hi, Parallel Programmer!");
			MPI_Bcast(&message, 26, MPI_BYTE, 0, fcomm);
			printf("0, send: %s\n", message);
		}
		else {
			MPI_Bcast(message, 26, MPI_BYTE, 0, fcomm);
			printf("%i received: %s\n", rankInGroup, message);
		}
		MPI_Comm_free(&fcomm);
		MPI_Group_free(&group);
	}
	MPI_Finalize();
	//return 0;

}

///C:\Users\Bublyk\Desktop\PRO\PROLABA1\Debug\PROLABA1.exe