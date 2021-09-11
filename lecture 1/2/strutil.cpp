int strConteins(char *strToSearch, char *originalString)
{
	int
		position = -1,
		counter = 0;

	while (originalString[counter] != '\0')
	{
		if (originalString[counter] == strToSearch[0])
		{
			int
				founded = 1,
				subcounter = 0;

			while (strToSearch[subcounter] != '\0')
			{
				if (strToSearch[subcounter] != originalString[counter + subcounter])
				{
					founded = 0;
					break;
				}
				subcounter++;
			}

			if (founded)
			{
				position = counter;
				break;
			}
		}
		counter++;
	}
	return position;
}
