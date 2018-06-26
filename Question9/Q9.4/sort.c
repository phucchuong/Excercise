void sort(int * arr, int count, int(*order)(int, int))
{
	int temp;
	for (register int i = 0; i < count - 1; i++) {
		for (int j = count - 1; j>i; j--) {
			if (order(arr[j], arr[j - 1])) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}