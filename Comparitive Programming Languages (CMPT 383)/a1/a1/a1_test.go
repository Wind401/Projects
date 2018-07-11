package main

import (
	
	"fmt"
	"testing"
)

func TestCountPrimes(t *testing.T) {

	testArr := []int {-6, 0, 5}
	answerArr := []int {0,0,3}

	
	for i := range testArr {

		answer := countPrimes(testArr[i])
		
		if answer == answerArr[i] {
			fmt.Println("TestCountPrimes working properly")
		} else {
			fmt.Println("TestCountPrimes is not working properly")
		}
	}

}


func testEqualsTime24(t *testing.T) {
	t1 := Time24 {1,2,3}
	t2 := Time24 {4,5,6}
	t3 := Time24 {0,5,6}

	if equalsTime24(t1, t2) == false && equalsTime24(t2,t3) == true {

		fmt.Println("equalsTime24 working properly")
	} else {

		fmt.Println("equalsTime24 is not working properly")
	}

}


func isStringMethodWorking(t *testing.T) {
	t1 := Time24 {1,2,3}
	if t1.String() == "01:02:03" {
		fmt.Println("StringMethod is working properly")
	} else {
		fmt.Println("StringMethod is not working properly")
	}
}

