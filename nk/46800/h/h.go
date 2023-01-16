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
)

func work() {
	line, _ := buf.ReadString('\n')
	params := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(params[0])
	ans := 10
	for i := 0; i < n*n-1; i++ {
		line, _ = buf.ReadString('\n')
		s := strings.TrimSpace(line)
		for j := 0; j < 4; j++ {
			switch s[j] {
			case '1':
				ans++
			case '2':
				ans--
			}
		}
	}
	fmt.Println(ans)
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
