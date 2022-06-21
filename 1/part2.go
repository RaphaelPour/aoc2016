package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"

	"github.com/RaphaelPour/aoc2020/util"
)

type Pos struct {
	x, y int
}

type Path struct {
	a, b Pos
}

func main() {

	commands := util.LoadString("input2")[0]

	x, y, alpha := 0, 0, 0
	paths := make([]Path, 0)
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

		pos := Pos{x: x, y: y}

		if len(paths) == 0 {
			paths := append(paths, Path{Pos{0, 0}, pos})
			continue
		}

		for i := 0; i < len(positions)-2; i++ {

			a := pos
			b := positions[len(positions)-1]
			c := positions[i]

			fmt.Println("a+c = ", manhattan(a, c))
			fmt.Println("b+c = ", manhattan(b, c))
			fmt.Println("a+b = ", manhattan(a, b))

			if manhattan(a, c)+manhattan(b, c) == manhattan(a, b) {
				fmt.Println(x, y, "->", manhattan(Pos{0, 0}, pos))
			}
		}

		positions = append(positions, pos)
	}
	fmt.Println("too high: 240, 233")
	fmt.Println("bad: 72")

}

func manhattan(a, b Pos) int {
	return util.Abs(a.x-b.x) + util.Abs(a.y-b.y)
}
