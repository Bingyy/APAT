ElementType Max(ElementType s[], int N){
	ElementType max = s[0];
	for(int i = 1; i< N; i++){
		if (max < s[i]){
			max = s[i];
		}
	}
	return max;
}