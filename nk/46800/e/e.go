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
	eps = 1e-6
	inf = 0x3f3f3f3f3f3f3f3f
)

var (
	buf = bufio.NewReader(os.Stdin)
)

func sign(xa, ya, xb, yb float64) int {
	if xa*yb-xb*ya > 0 {
		return 1
	}
	return -1
}

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	xa, _ := strconv.ParseFloat(params[0], 64)
	ya, _ := strconv.ParseFloat(params[1], 64)
	xb, _ := strconv.ParseFloat(params[2], 64)
	yb, _ := strconv.ParseFloat(params[3], 64)
	xc, _ := strconv.ParseFloat(params[4], 64)
	yc, _ := strconv.ParseFloat(params[5], 64)

	line, _ = buf.ReadString('\n')
	params = strings.Split(strings.TrimSpace(line), " ")
	xd, _ := strconv.ParseFloat(params[0], 64)
	yd, _ := strconv.ParseFloat(params[1], 64)
	xe, _ := strconv.ParseFloat(params[2], 64)
	ye, _ := strconv.ParseFloat(params[3], 64)
	xf, _ := strconv.ParseFloat(params[4], 64)
	yf, _ := strconv.ParseFloat(params[5], 64)

	ba := math.Sqrt(float64((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb)))
	bc := math.Sqrt(float64((xc-xb)*(xc-xb) + (yc-yb)*(yc-yb)))
	if math.Abs(ba-bc) < eps {
		fmt.Println("NO")
		return
	}

	ed := math.Sqrt(float64((xe-xd)*(xe-xd) + (ye-yd)*(ye-yd)))
	ef := math.Sqrt(float64((xe-xf)*(xe-xf) + (ye-yf)*(ye-yf)))

	var sign1, sign2 int
	if ba > bc {
		sign1 = sign(xa-xb, ya-yb, xc-xb, yc-yb)
	} else {
		sign1 = sign(xc-xb, yc-yb, xa-xb, ya-yb)
	}
	if ed > ef {
		sign2 = sign(xd-xe, yd-ye, xf-xe, yf-ye)
	} else {
		sign2 = sign(xf-xe, yf-ye, xd-xe, yd-ye)
	}

	if sign1 != sign2 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}

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
