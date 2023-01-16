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
)

var (
	buf = bufio.NewReader(os.Stdin)
	f   [41][200][101][101]int
)

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(params[0])
	m, _ := strconv.Atoi(params[1])
	x, _ := strconv.Atoi(params[2])
	y, _ := strconv.Atoi(params[3])
	f[0][0][0][0] = 1
	for i := 0; i < n; i++ {
		for j := 3 * i; j >= 0; j-- {
			for k := 0; k <= x; k++ {
				for l := 0; l <= y; l++ {
					if f[i][j][k][l] == 0 {
						continue
					}
					for o := x - k; o >= 0; o-- {
						for p := y - l; p >= 0; p-- {
							score := 0
							if o > p {
								score = 3
							} else if o == p {
								score = 1
							}
							f[i+1][j+score][k+o][l+p] += f[i][j][k][l]
							f[i+1][j+score][k+o][l+p] %= mod
						}
					}
				}
			}
		}
	}

	for i := 1; i <= n; i++ {
		for j := 3 * i; j >= 0; j-- {
			for k := 0; k <= x; k++ {
				for l := 0; l <= y; l++ {

					fmt.Printf("f[%d][%d][%d][%d]=%d\n", i, j, k, l, f[i][j][k][l])
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
