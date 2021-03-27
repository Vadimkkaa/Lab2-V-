#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#include<stdbool.h>

struct Tours {
	int cost;
	char* tourName;
	union {
		char startDate[9];
		int daysNumber;
	}info;
	bool unionFlag;
};

struct Tour* add(struct Tour* tour, int addNumber, int toursNumber)
{
	tour = (struct Tours*)realloc(tour, 24 * (toursNumber + addNumber));
	return tour;
}
void firstInput(struct Tours* tours, int toursNumber) {

	int i = 0;
	int j;
	int choice = 0;

	do {
		system("cls");
		printf("Information about tour  %d\n", i + 1);

		printf("Enter the name\n");
		tours[i].tourName = (char*)malloc(20);
		getchar();
		fgets(tours[i].tourName, 20, stdin);
		tours[i].tourName[0] = toupper(tours[i].tourName[0]);
		j = stringLength(tours[i].tourName);
		tours[i].tourName[j] = '\0';

		printf("Enter the cost in usd\nIf you need the currency transfer, print 0\n");
		tours[i].cost = check(0, 0);
		if (tours[i].cost == 0) {
			tableRate();
			printf("Your currency...\n1 - byn\n2 - pln\n3 - rus\n");
			choice = check(3, 1);
			printf("Enter the cost\n");
			tours[i].cost = check(0, 0);
			switch (choice) {
			case 1:tours[i].cost = tours[i].cost / 3;
				break;
			case 2:tours[i].cost = tours[i].cost / 4;
				break;
			case 3:tours[i].cost = tours[i].cost / 74;
				break;
			}
		}
		printf("Enter\n1 - date of start\n2 - days number\n");
		choice = check(2, 1);

		if (choice == 2) {
			printf("Enter the number\n");
			tours[i].unionFlag = TRUE;
			tours[i].info.daysNumber = check(0, 0);
		}
		else {
			printf("Enter the date in the form (dd/mm/yy)\n");
			tours[i].unionFlag = FALSE;
			getchar();
			fgets(tours[i].info.startDate, 9, stdin);
			while (tours[i].info.startDate[2] != '/' || tours[i].info.startDate[5] != '/' || atoi(tours[i].info.startDate) > 31 || ((tours[i].info.startDate[3] - '0') * 10 + (tours[i].info.startDate[4] - '0')) > 12) {
				rewind(stdin);
				printf("Incorrect input. Try again\n");
				fgets(tours[i].info.startDate, 9, stdin);
			}
			j = stringLength(tours[i].info.startDate);
			tours[i].info.startDate[j] = '\0';
		}
		i++;
	} while (i < toursNumber);
}
int addInput(struct Tours* tours, int index, int toursNumber) {

	system("cls");
	int i = index, j;
	int addNumber, choice;

	do {
		system("cls");
		printf("Information about tour  %d\n", i + 1);

		printf("Enter the name\n");
		tours[i].tourName = (char*)malloc(20);
		getchar();
		fgets(tours[i].tourName, 20, stdin);
		tours[i].tourName[0] = toupper(tours[i].tourName[0]);
		j = stringLength(tours[i].tourName);
		tours[i].tourName[j] = '\0';

		printf("Enter the cost in usd\nIf you need the currency transfer, print 0\n");
		tours[i].cost = check(0, 0);
		if (tours[i].cost == 0) {
			tableRate();
			printf("What currency?\n1 - byn\n2 - pln\n3 - rus\n");
			choice = check(3, 1);
			printf("Enter the cost\n");
			tours[i].cost = check(0, 0);
			switch (choice) {
			case 1:tours[i].cost = tours[i].cost / 3;
				break;
			case 2:tours[i].cost = tours[i].cost / 4;
				break;
			case 3:tours[i].cost = tours[i].cost / 74;
				break;
			}
		}
		printf("Enter\n1 - date of start\n2 - days number\n");
		choice = check(2, 1);

		if (choice == 2) {
			printf("Enter the number\n");
			tours[i].unionFlag = TRUE;
			tours[i].info.daysNumber = check(0, 0);
		}
		else {
			printf("Enter the date in the form (dd/mm/yy)\n");
			tours[i].unionFlag = FALSE;
			getchar();
			fgets(tours[i].info.startDate, 9, stdin);
			while (tours[i].info.startDate[2] != '/' || tours[i].info.startDate[5] != '/' || atoi(tours[i].info.startDate) > 31 || ((tours[i].info.startDate[3] - '0') * 10 + (tours[i].info.startDate[4] - '0')) > 12) {
				rewind(stdin);
				printf("Incorrect input. Try again\n");
				fgets(tours[i].info.startDate, 9, stdin);
			}
			j = stringLength(tours[i].info.startDate);
			tours[i].info.startDate[j] = '\0';
		}
		i++;
		system("cls");
	} while (i < toursNumber);

	system("cls");
	return toursNumber;
}

void singleOutput(struct Tours tours) {

	printf("     |\tName\t|\t     Cost, usd     \t|\tUnion\t\n");
	printf("       -----------------------------------------------------------------\n");
	if (tours.unionFlag == TRUE) {
		printf("     |\t%s\t|          %d\t        |\t%d days\t", tours.tourName, tours.cost, tours.info.daysNumber);
	}
	else {
		printf("     |\t%s\t|          %d\t        |\tstart:%s\t", tours.tourName, tours.cost, tours.info.startDate);

	}
	printf("\n       -----------------------------------------------------------------\n");

}
void output(struct Tours* tours, int toursNumber) {
	int i = 0;
	system("cls");
	printf("     |i|\t Name     \t|\t     Cost, usd     \t|\t     Union     \t\n");
	printf("       -------------------------------------------------------------------------------\n");
	do {
		if (tours[i].unionFlag == TRUE) {
			printf("     [%d]\t %s     \t|          %d\t        |\t%d days", i + 1, tours[i].tourName, tours[i].cost, tours[i].info.daysNumber);
		}
		else {
			printf("     [%d]\t %s     \t|          %d\t        |\tstart:%s", i + 1, tours[i].tourName, tours[i].cost, tours[i].info.startDate);

		}
		printf("\n       -------------------------------------------------------------------------------\n");
		i++;
	} while (i < toursNumber);

}
void search(struct Tours* tours, int toursNumber) {
	system("cls");
	int choice;
	printf("You want to find...\n1 - Name\n2 - The most expensive tour\n3 - The cheapest tour\n4 - The longest tour\n");
	choice = check(4, 1);
	int maxNumber = 0;
	int index = 0;
	int i = 0;
	int flag = 0;
	int minNumber = tours[i].cost;
	switch (choice) {
	case 1:
		printf("Enter the name\n");
		char searchInfo[20];
		getchar();
		fgets(searchInfo, 20, stdin);
		searchInfo[0] = toupper(searchInfo[0]);
		while (searchInfo[i] != '\n' && searchInfo[i] != '\0') {
			i++;
		}
		searchInfo[i] = '\0';
		i = 0;
		do {
			if (strcmp(searchInfo, tours[i].tourName) == 0) {
				index = i;
				flag++;
				break;
			}
			i++;
		} while (i < toursNumber);
		if (flag != 0) {
			printf("Result:\n");
			singleOutput(tours[index]);
		}
		else printf("You did not enter this name\n");
		break;


	case 2: do {
		if (maxNumber < tours[i].cost)
		{
			maxNumber = tours[i].cost;
		}
		i++;
	} while (i < toursNumber);

	printf("Result:\n");
	i = 0;
	do {
		if (maxNumber == tours[i].cost)
		{
			singleOutput(tours[i]);
		}
		i++;
	} while (i < toursNumber);

	break;

	case 3:
		i++;
		do {
			if (minNumber > tours[i].cost) {
				minNumber = tours[i].cost;
			}
			i++;
		} while (i < toursNumber);

		printf("Result:\n");

		i = 0;
		do {
			if (minNumber == tours[i].cost)
			{
				singleOutput(tours[i]);
			}
			i++;
		} while (i < toursNumber);

		break;
	case 4:
		do {
			if (tours[i].unionFlag == TRUE) {
				flag++;
				if (maxNumber < tours[i].info.daysNumber)
				{
					maxNumber = tours[i].info.daysNumber;
				}
			}
			i++;
		} while (i < toursNumber);

		if (flag != 0) {
			printf("Result:\n");
			i = 0;
			do {
				if (tours[i].unionFlag == TRUE) {
					if (maxNumber == tours[i].info.daysNumber)
					{
						singleOutput(tours[i]);
					}
				}
				i++;
			} while (i < toursNumber);
		}
		else printf("You have not entered duration information\n");

		break;
	}

}
void removal(struct Tours* tours, int i, int toursNumber) {
	do {
		tours[i] = tours[i + 1];
		i++;
	} while (i < toursNumber);
	while (1) {
		rewind(stdin);
		if (!(tours = (struct Tours*)realloc(tours, toursNumber * sizeof(struct Tours))))
			printf("Realloc error!"); else break;
	}
}
int  deleteFunction(struct Tours* tours, int toursNumber) {

	int deleteNumber = 0, searchNumber;
	int choice, i = 0;
	int warning;
	int flag = 0;
	char searchInfo[20];
	printf("You want to delete by...\n1 - Name\n2 - Date of start\n3 - Duration\n");
	choice = check(3, 1);
	system("cls");
	switch (choice) {
	case 1:
		printf("Enter the name\n");

		getchar();
		fgets(searchInfo, 20, stdin);
		searchInfo[0] = toupper(searchInfo[0]);
		i = stringLength(searchInfo);
		searchInfo[i] = '\0';
		i = 0;
		do {
			if (strcmp(searchInfo, tours[i].tourName) == 0) {
				flag++;
				printf("A match was found. Are you sure you want to delete this information?\n1 - Yes\n2 - No\n");
				singleOutput(tours[i]);
				warning = check(2, 1);
				system("cls");
				if (warning == 1) {
					toursNumber--;
					removal(tours, i, toursNumber);
				}
				else flag--;
			}
			i++;
		} while (i < toursNumber);

		

		if (flag == 0)printf("Nothing was deleted\n\n");
		break;


	case 2: printf("Enter the data of start\n");

		getchar();
		fgets(searchInfo, 9, stdin);
		while (searchInfo[2] != '/' || searchInfo[5] != '/' || atoi(searchInfo) > 31 || ((searchInfo[3] - '0') * 10 + (searchInfo[4] - '0')) > 12) {
			rewind(stdin);
			printf("Incorrect input. Try again\n");
			fgets(searchInfo, 9, stdin);
		}
		searchInfo[0] = toupper(searchInfo[0]);
		i = stringLength(searchInfo);
		searchInfo[i] = '\0';
		i = 0;
		do {
			if (tours[i].unionFlag == FALSE) {
				if (strcmp(searchInfo, tours[i].info.startDate) == 0) {
					flag++;
					printf("A match was found. Are you sure you want to delete this information?\n1 - Yes\n2 - No\n");
					singleOutput(tours[i]);
					warning = check(2, 1);
					system("cls");
					if (warning == 1) {
						toursNumber--;
						removal(tours, i, toursNumber);
					}
					else flag--;
				}
			}
			i++;
		} while (i <= toursNumber);
		if (flag == 0)printf("Nothing was deleted\n\n");
		break;
	case 3:
		printf("Enter the number\n");
		searchNumber = check(0, 0);

		do {
			if (tours[i].unionFlag == TRUE) {
				if (searchNumber == tours[i].info.daysNumber) {
					flag++;
					printf("A match was found. Are you sure you want to delete this information?\n1 - Yes\n2 - No\n");
					singleOutput(tours[i]);
					warning = check(2, 1);
					system("cls");
					if (warning == 1) {
						toursNumber--;
						removal(tours, i, toursNumber);
					}
					else flag--;
				}
			}
			i++;
		} while (i <= toursNumber);
		if (flag == 0)printf("Nothing was deleted\n\n");
		break;
	}
	if (toursNumber == 0) printf("There is no information\n");
	return toursNumber;

}

int check(int rightBound, int leftBound) {
	int errorFlag;
	int element;
	errorFlag = scanf_s("%d", &element);
	if (rightBound != 0) {
		while (!errorFlag || element > rightBound || element < leftBound) {
			printf("Incorrect input. Try again\n");
			rewind(stdin);
			errorFlag = scanf_s("%d", &element);
		}
	}
	else {
		while (!errorFlag || element < leftBound) {
			printf("Incorrect input. Try again\n");
			rewind(stdin);
			errorFlag = scanf_s("%d", &element);
		}
	}
	return element;
}
void tableRate() {
	printf("                -------------------------\n");
	printf("               |           RATE          |\n");
	printf("                -------------------------\n");
	printf("               |  usd  | byn | pln | rus |\n");
	printf("                -------------------------\n");
	printf("               |   1   |  3  |  4  |  74 |\n");
	printf("                -------------------------\n");
}
void tableMenu() {
	printf("\n                              MENU");
	printf("\n               ====================================    \n\n");
	printf("                      Choose the operation...\n                           1 - input\n                           2 - output\n                           3 - delete\n                           4 - search\n                           0 - end\n");
	printf("\n\n               ====================================    \n\nYour choice is  ");
}
int stringLength(char* string) {
	int i = 0;
	while (1) {
		if (string[i] == '\n' || string[i] == '\0')break;
		i++;
	}
	return i;
}

int menu(struct Tours* tours, int toursNumber) {

	int choice;
	tableMenu();
	choice = check(4, 0);

	return choice;
}

int main() {
	int toursNumber;
	int addNumber;
	int choice;
	struct Tours* tours;
	printf("Enter the number of tours\n");
	toursNumber = check(0, 1);
	tours = (struct Tours*)calloc((toursNumber), 24);
	if (!tours) {
		printf("error");
		return 0;
	}
	firstInput(tours, toursNumber);
	//output(tours, numberTours);
	system("cls");
	while (1) {
		choice = menu(tours, toursNumber);
		switch (choice) {
		case 1:
			printf("How many tours you want to add?\nWrite 0, if you want to get out\n");
			addNumber = check(0, 0);
			if (addNumber != 0) {
				tours = add(tours, toursNumber, addNumber);

				//	tours=(struct Tours*)realloc(tours, 24 * (toursNumber + addNumber));
				toursNumber = addInput(tours, toursNumber, addNumber + toursNumber);
			} break;
		case 2:	output(tours, toursNumber); break;
		case 3:toursNumber = deleteFunction(tours, toursNumber); break;
		case 4:search(tours, toursNumber); break;
		}
		if (toursNumber == 0) break;
		if (choice == 0)break;
	}
	free(tours);
	return 0;
}
