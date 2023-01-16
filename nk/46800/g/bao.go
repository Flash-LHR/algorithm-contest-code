package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

const (
	M   = int(1e5)
	mod = int(1e9) + 7
	inf = 0x3f3f3f3f3f3f3f3f
)

var (
	buf  = bufio.NewReader(os.Stdin)
	lim  = 15
	n, m int
	a    [M + 5]int
)

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	n, _ = strconv.Atoi(params[0])
	m, _ = strconv.Atoi(params[1])

	line, _ = buf.ReadString('\n')
	params = strings.Split(strings.TrimSpace(line), " ")
	for i := 1; i <= n; i++ {
		a[i], _ = strconv.Atoi(params[i-1])
	}

	for i := 1; i <= m; i++ {
		line, _ = buf.ReadString('\n')
		params = strings.Split(strings.TrimSpace(line), " ")
		op, _ := strconv.Atoi(params[0])
		if op == 1 {
			l, _ := strconv.Atoi(params[1])
			r, _ := strconv.Atoi(params[2])
			k, _ := strconv.Atoi(params[3])
			for j := l; j <= r; j++ {
				for l := 1; l <= k; l++ {
					a[j] = int(0.5 + 10*math.Sqrt(float64(a[j])))
				}
			}
			// fmt.Println(a[:n+1])
		} else {
			s := 0
			for i := 1; i <= n; i++ {
				s += a[i]
			}
			fmt.Println(s)
		}
	}
}

func main() {
	T := 1
	// line, _ := buf.ReadString('\n')
	// params := strings.Split(strings.TrimSpace(line), " ")
	// T, _ = strconv.Atoi(params[0])
	for ca := 1; ca <= T; ca++ {
		work()
	}
}
