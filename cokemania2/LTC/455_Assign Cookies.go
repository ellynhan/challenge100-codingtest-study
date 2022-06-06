package main

import "sort"

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	index_g := 0
	index_s := 0
	for index_g < len(g) && index_s < len(s) {
		if g[index_g] <= s[index_s] {
			index_g += 1
		}
		index_s += 1
	}
	return index_g
}
