func solution(n int) int64 {
	s := []int{1, 2, 3, 5}
	for i := 4; i < n; i++ {
		s = append(s, (s[i-1]+s[i-2])%1234567)
	}
	return int64(s[n-1])
}