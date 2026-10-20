

int count_ones(int value) {
	unsigned val = value;
	int count = 0;
	while (val != 0) {
		count += val & 1;
		val >>= 1;
	}
	return count;
}
