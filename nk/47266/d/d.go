package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"strconv"
)

var n, k, m, q int

func f(l int, r int) int {
	ans := 0
	if r * k + k < n {
		ans += r * k + k - l * k + f(l * k + 1, r * k + k)
	} else if n > l * k {
		ans += n - (l * k + 1)
	}
	return ans
}

var inp = bufio.NewReader(os.Stdin)

func work() {
	line, _ := inp.ReadString('\n')
	linel := strings.Split(line[:len(line) - 1], " ")
	n, _ = strconv.Atoi(linel[0])
	k, _ = strconv.Atoi(linel[1])
	m, _ = strconv.Atoi(linel[2])
	line, _ = inp.ReadString('\n')
	query := strings.Split(line[:len(line) - 1], " ")
	for i := 0; i < m; i++ {
		q, _ = strconv.Atoi(query[i])
		if k == 1 {
			fmt.Println(n - q)
		} else {
			fmt.Println(f(q, q) + 1)
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