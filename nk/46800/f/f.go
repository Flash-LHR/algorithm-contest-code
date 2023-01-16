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
	mod = int(1e9) + 7
	inf = 0x3f3f3f3f3f3f3f3f
)

var (
	buf  = bufio.NewReader(os.Stdin)
	n, m int
	c    [M + 5]int
	g    [M + 5][]int
	q    [M + 5]int
	vis  [M + 5]bool
)

func bfs(s int) (size int, allZero bool) {
	l, r := 1, 1
	q[r] = s
	vis[s] = true
	allZero = true
	for l <= r {
		u := q[l]
		l++
		size++
		if c[u] != 0 {
			allZero = false
		}
		for _, v := range g[u] {
			if !vis[v] {
				vis[v] = true
				r++
				q[r] = v
			}
		}
	}
	return
}

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	n, _ = strconv.Atoi(params[0])
	m, _ = strconv.Atoi(params[1])
	for i := 1; i <= n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 1; i <= m; i++ {
		line, _ = buf.ReadString('\n')
		params = strings.Split(strings.TrimSpace(line), " ")
		u, _ := strconv.Atoi(params[0])
		v, _ := strconv.Atoi(params[1])
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	line, _ = buf.ReadString('\n')
	params = strings.Split(strings.TrimSpace(line), " ")
	allZero := true
	for i := 1; i <= n; i++ {
		c[i], _ = strconv.Atoi(params[i-1])
		if c[i] != 0 {
			allZero = false
		}
	}
	if allZero {
		ans := 0
		for i := 1; i <= n; i++ {
			if vis[i] {
				continue
			}
			size, _ := bfs(i)
			ans += size * size
		}
		fmt.Println(ans)
	} else {
		ans := 0
		for i := 1; i <= n; i++ {
			if vis[i] {
				continue
			}
			if size, allZero := bfs(i); !allZero {
				if ans == 0 {
					ans = size * size
				} else {
					ans = 0
					break
				}
			}
		}
		fmt.Println(ans)
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
