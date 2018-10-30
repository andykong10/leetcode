// Method 1: Traverse the string twice.
int firstUniqChar(string s)
{
	// Stores how many times a particular letter has been seen.
	// Note that int in vector are zero initialized
	// You'd better do vector<int> counts(26, 0) to be more explicit.
	vector<int> counts(26);

	for (int i = 0; i < s.size(); ++i)
	{
		counts[s[i]-'a']++;
	}
	
	for (int i = 0; i < s.size(); ++i)
	{
		if (counts[s[i]-'a'] == 1)
		{
			return s[i];
		}
	}

	return -1;
}

// Method 2: Frist traverse the string, then traverse 26 letters.
// This could be faster is string is long.
int firstUniqChar2(string s)
{
	// .first stores how many times that particular letter has been seen.
	// .second stores the last time that letter has been seen.
	// If a letter is non-repeating, then .first must be 1, 
	// and .second is just first (and last) time it has been seen.
	//
	// Note that in pair<int, int>, both ints are zero-initialized.
	// You may as well do vector<pair<int, int>> counts(26, {0, 0}) to be more explicit.
	vector<pair<int, int>> counts(26);

	for (int i = 0; i < s.size(); ++i)
	{
		counts[s[i]-'a'].first++;
		counts[s[i]-'a'].second = i;
	}

	int index = s.size();

	for (int i = 0; i < counts.size(); ++i)
	{
		if (counts[i].first == 1)
		{
			index = min(index, counts[i].second);
		}
	}

	return index == s.size() ? -1 : index;
}
