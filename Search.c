//linear search
Time complexity - O(n)
boolean linear()
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == data)
		{
			printf("found data");
			return true;
		}
	}
	return false;
}

//binary search
//array shall be sorted
// mid = floor((l+r)/2)
//Time complexity - O(logn)

int binarysearch()
{
	int l = 0, r = n-1;
	int mid = (l+r)/2
	
	while(i < r)
	{
		if(data == a[mid])
			return mid;
		else if(data < a[mid])
			r = mid - 1;
		else
			l = mid +1;
	}
	return -1;
}