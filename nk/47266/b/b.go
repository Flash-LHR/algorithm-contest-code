package main

import (
	"fmt"
)

func work() {
	var l, r, q, x int
	fmt.Scan(&l, &r, &q)
	sum := (r - l + 1) * (l + r) / 2
	for i := 1; i <= q; i++ {
		fmt.Scan(&x)
		if sum % x == 0 {
			fmt.Println(0)
		} else {
			fmt.Println(1)
		}
	}
}

func main() {
	var T int
	fmt.Scan(&T)
	for ca := 1; ca <= T; ca++ {
		work()
	}
}