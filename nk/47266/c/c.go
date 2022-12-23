package main

import (
	"fmt"
)

const M int = 1e6

var cnt int
var prime, v [M + 5]int
var is_prime [M + 5]bool

func get_prime() {
	for i := 2; i <= M; i++ {
		is_prime[i] = true
	}
	for i := 2; i <= M; i++ {
		if is_prime[i] {
			cnt++
			prime[cnt] = i
			v[i] = i
		}
		for j := 1; j <= cnt && i * prime[j] <= M; j++ {
			is_prime[i * prime[j]] = false;
			v[i * prime[j]] = prime[j]
			if i % prime[j] == 0 {
				break;
			}
		}
	}
}

var vis_a [M + 5]bool
var vis_b [M + 5]bool

func divide(vis *[M + 5]bool, a int) {
visit:
	for a > 1 {
		mi := v[a]
		vis[mi] = true
		for mi == v[a] {
			if vis[a] {
				break visit
			}
			a /= mi
		}
	}
}

func work() {
	var n, a, b int
	fmt.Scan(&n)
	for i := 1; i <= n; i++ {
		fmt.Scan(&a)
		divide(&vis_a, a)
	}
	for i := 1; i <= n; i++ {
		fmt.Scan(&b)
		divide(&vis_b, b)
	}
	for i := 1; i <= M; i++ {
		if vis_a[i] && vis_b[i] {
			fmt.Printf("No\n")
			return
		}
	}
	fmt.Printf("Yes\n")
}

func main() {
	get_prime()
	work()
}