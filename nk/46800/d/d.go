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

func dbmax(a, b float64) float64 {
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
	buf = bufio.NewReader(os.Stdin)
)

type matrix struct {
	x1, y1, x2, y2 int
}

func (m *matrix) normal() {
	if m.x1 > m.x2 {
		m.x1, m.x2 = m.x2, m.x1
	}
	if m.y1 > m.y2 {
		m.y1, m.y2 = m.y2, m.y1
	}
}

func (m *matrix) area() int {
	x := m.x2 - m.x1
	y := m.y2 - m.y1
	return x * y
}

func intersection(a, b matrix) int {
	x := min(a.x2, b.x2) - max(a.x1, b.x1)
	y := min(a.y2, b.y2) - max(a.y1, b.y1)
	if x < 0 || y < 0 {
		return 0
	}
	return x * y
}

func union(a, b matrix) int {
	return a.area() + b.area() - intersection(a, b)
}

func cal(a, b matrix) float64 {
	a.normal()
	b.normal()
	return float64(intersection(a, b)) / float64(union(a, b))
}

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	x, _ := strconv.Atoi(params[0])
	y, _ := strconv.Atoi(params[1])
	xp, _ := strconv.Atoi(params[2])
	yp, _ := strconv.Atoi(params[3])

	ans := 0.0
	ans = dbmax(ans, cal(matrix{0, 0, x, y}, matrix{0, 0, xp, yp}))
	ans = dbmax(ans, cal(matrix{0, 0, x, y}, matrix{0, y, xp, yp}))
	ans = dbmax(ans, cal(matrix{0, 0, x, y}, matrix{x, 0, xp, yp}))
	ans = dbmax(ans, cal(matrix{0, 0, x, y}, matrix{x, y, xp, yp}))
	fmt.Printf("%.12f\n", ans)
}

func main() {
	T := 1
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	T, _ = strconv.Atoi(params[0])
	for ca := 1; ca <= T; ca++ {
		work()
	}
}
