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
	cnt  [M*4 + 5]int
	sum  [M*4 + 5]int
)

func lc(k int) int {
	return k << 1
}

func rc(k int) int {
	return k<<1 | 1
}

func pushUp(k int) {
	cnt[k] = min(cnt[lc(k)], cnt[rc(k)])
	sum[k] = sum[lc(k)] + sum[rc(k)]
}

func build(k, l, r int) {
	if l == r {
		cnt[k] = 0
		sum[k] = a[l]
		return
	}
	mid := (l + r) >> 1
	build(lc(k), l, mid)
	build(rc(k), mid+1, r)
	pushUp(k)
}

func update(k, l, r, a, b int) {
	if cnt[k] > lim {
		return
	}
	if l == r {
		cnt[k]++
		sum[k] = int(10.0*math.Sqrt(float64(sum[k])) + 0.5)
		return
	}
	mid := (l + r) >> 1
	if a <= mid {
		update(lc(k), l, mid, a, b)
	}
	if mid < b {
		update(rc(k), mid+1, r, a, b)
	}
	pushUp(k)
}

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
	build(1, 1, n)
	for i := 1; i <= m; i++ {
		line, _ = buf.ReadString('\n')
		params = strings.Split(strings.TrimSpace(line), " ")
		op, _ := strconv.Atoi(params[0])
		if op == 1 {
			l, _ := strconv.Atoi(params[1])
			r, _ := strconv.Atoi(params[2])
			k, _ := strconv.Atoi(params[3])
			k = min(k, lim)
			for j := 1; j <= k; j++ {
				update(1, 1, n, l, r)
			}
		} else {
			fmt.Println(sum[1])
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
