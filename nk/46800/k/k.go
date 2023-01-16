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
	M   = int(1e3)
	mod = int(1e9) + 7
	inf = 0x3f3f3f3f3f3f3f3f
)

var (
	buf = bufio.NewReader(os.Stdin)
	f   [M + 5][M + 5][2][2]int
)

func check(a, b, c int) int {
	if a+b+c >= 2 {
		return 1
	}
	return 0
}

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(params[0])
	m, _ := strconv.Atoi(params[1])
	for i := 0; i <= n; i++ {
		for j := 0; j <= n; j++ {
			for k := 0; k <= 1; k++ {
				for l := 0; l <= 1; l++ {
					if j <= i && i == 2 && k+l == j {
						f[i][j][k][l] = 0
					} else {
						f[i][j][k][l] = inf
					}
				}
			}
		}
	}
	for i := 3; i <= n; i++ {
		for j := 0; j <= i; j++ {
			for k := 0; k <= 1; k++ {
				for l := 0; l <= 1; l++ {
					for o := 0; o <= 1; o++ {
						if j < k+l+o {
							continue
						}
						f[i][j][k][l] = min(f[i][j][k][l],
							f[i-1][j-l][o][k]+check(o, k, l))
					}
					// fmt.Printf("f[%v][%v][%v][%v]=%v\n", i, j, k, l, f[i][j][k][l])
				}
			}
		}
	}
	mi := inf
	for k := 0; k <= 1; k++ {
		for l := 0; l <= 1; l++ {
			mi = min(mi, f[n][m][k][l])
		}
	}
	fmt.Println(mi)
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
