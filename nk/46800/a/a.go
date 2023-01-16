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
	buf = bufio.NewReader(os.Stdin)
	s   string
)

func work() {
	line, _ := buf.ReadString('\n')
	s = strings.TrimSpace(line)
	a, b := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			if i&1 == 1 {
				b++
			} else {
				a++
			}
		}
		if a > b+(10-i)/2 || b > a+(10-i-1)/2 {
			fmt.Println(i + 1)
			return
		}
	}
	fmt.Println(-1)
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
