package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"

	"github.com/RaphaelPour/aoc2020/util"
)

func main() {

	commands := util.LoadDefaultString()[0]

	x, y, alpha := 0, 0, 0
	for _, rawCommand := range strings.Split(commands, ",") {
		command := strings.Trim(rawCommand, " ")
		direction := string(command[0]) == "R"
		distance, err := strconv.Atoi(command[1:])
		if err != nil {
			fmt.Printf("error converting '%s' to int: %s\n", command[1:], err)
			return
		}
		// fmt.Printf("[%03d] %s %d\n", i, direction, distance)

		beta := 90

		if !direction {
			beta = -90
		}

		alpha += beta
		x += distance * int(math.Cos(util.Radians(float64(alpha))))
		y += distance * int(math.Sin(util.Radians(float64(alpha))))

		fmt.Println(command, "->", x, y)
	}

	fmt.Println("too low: 112")
	fmt.Println(util.Abs(x) + util.Abs(y))
}
