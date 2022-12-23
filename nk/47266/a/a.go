package main

import (
	"fmt"
)

const M int = 1e5

var h [M + 5]int

func work() {
	var n int
	fmt.Scan(&n)
	for i := 1; i <= n; i++ {
		fmt.Scan(&h[i])
	}
	var a, b, k, m int
	fmt.Scan(&a, &k, &b, &m)
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if h[j] > k {
				h[j] = b
			}
			if i < m {
				h[j] += a
			}
		}
		fmt.Println(h[n])
	}
	for i := 1; i <= n; i++ {
		fmt.Print(h[i])
		if i < n {
			fmt.Printf(" ")
		} else {
			fmt.Printf("\n")
		}
	}
}

func main() {
	var T int
	fmt.Scan(&T);
	for ca := 1; ca <= T; ca++ {
		work()
	}
}