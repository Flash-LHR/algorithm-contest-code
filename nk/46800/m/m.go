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

func max(a, b float64) float64 {
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
	M   = int(5e2)
	mod = int(1e9) + 7
	inf = 0x3f3f3f3f3f3f3f3f
)

var (
	buf = bufio.NewReader(os.Stdin)
	f   [M + 5][M + 5]float64
)

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(params[0])
	m, _ := strconv.Atoi(params[1])
	for i := 0; i <= n; i++ {
		for j := 0; j <= m; j++ {
			f[i][j] = -float64(inf)
		}
	}
	f[0][0] = 0.0
	for i := 1; i <= n; i++ {
		for j := 0; j <= m; j++ {
			for k := 0; k <= j; k++ {
				f[i][j] = max(f[i][j], f[i-1][k]+float64(j-k)/float64(j))
			}
		}
	}
	fmt.Printf("%.12f\n", f[n][m])
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
