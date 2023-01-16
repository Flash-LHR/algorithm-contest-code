package main

import (
	"bufio"
	"fmt"
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
	mod = 998244353
	inf = 0x3f3f3f3f3f3f3f3f
	P   = 101
)

var (
	buf = bufio.NewReader(os.Stdin)
	f   [41][200][101][101]int
	tr  [41][200]TA
)

type TA struct {
	a [100 + P + 1]int
}

func lowbit(n int) int {
	return n & -n
}

func (tr *TA) add(n, p int) {
	for n <= 100+P {
		tr.a[n] += p
		tr.a[n] %= mod
		n += lowbit(n)
	}
}

func (tr *TA) ask(p int) int {
	s := 0
	for p > 0 {
		s += tr.a[p]
		s %= mod
		p -= lowbit(p)
	}
	return s
}

func (tr *TA) query(l, r int) int {
	return (tr.ask(r) - tr.ask(l-1) + mod) % mod
}

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(params[0])
	m, _ := strconv.Atoi(params[1])
	x, _ := strconv.Atoi(params[2])
	y, _ := strconv.Atoi(params[3])
	f[0][0][0][0] = 1
	tr[0][0].add(0+P, 1)
	for i := 1; i <= n; i++ {
		for j := 3 * i; j >= 0; j-- {
			for k := 0; k <= x; k++ {
				for l := 0; l <= y; l++ {
					f[i][j][k][l] += tr[i-1][j].query(k-l+1+P, 100+P)
					f[i][j][k][l] %= mod

					if j >= 1 {
						f[i][j][k][l] += tr[i-1][j-1].query(k-l+P, k-l+P)
					}
					f[i][j][k][l] %= mod

					if j >= 3 {
						f[i][j][k][l] += tr[i-1][j-3].query(0, k-l-1+P)
					}
					f[i][j][k][l] %= mod

					tr[i][j].add(k-l+P, f[i][j][k][l])
				}
			}
		}
	}
	ans := 0
	for i := m; i <= 3*n; i++ {
		ans = (ans + f[n][i][x][y]) % mod
	}
	fmt.Println(ans)
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
