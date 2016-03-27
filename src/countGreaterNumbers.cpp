/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0, i, j, k, l, count = 0;
	for (i = 0; date[i] != '-'; i++)
	{
		d1 = (d1 * 10) + (date[i] - '0');
	}
	i = i + 1;
	for (j = i; date[j] != '-'; j++)
	{
		m1 = (m1 * 10) + (date[j] - '0');
	}
	j = j + 1;
	for (k = j; date[k] != '\0'; k++)
	{
		y1 = (y1 * 10) + (date[k] - '0');
	}
	for (l = 0; l < len; l++)
	{
		for (i = 0; (Arr+l)->date[i] != '-'; i++)
		{
			d2 = (d2 * 10) + ((Arr+l)->date[i] - '0');
		}
		i = i + 1;
		for (j = i; Arr->date[j] != '-'; j++)
		{
			m2 = (m2 * 10) + ((Arr + l)->date[j] - '0');
		}
		j = j + 1;
		for (k = j; (Arr + l)->date[k] != '\0'; k++)
		{
			y2 = (y2 * 10) + ((Arr + l)->date[k] - '0');
		}
		if (y2 > y1)
		{
			count++;
		}
		else if (y2 == y1)
		{
			if (m2 > m1)
			{
				count++;
			}
			else if (m2 == m1)
			{
				if (d2 > d1)
				{
					count++;
				}
			}
		}
		d2 = 0, m2 = 0, y2 = 0;
	}
	return count;
}
