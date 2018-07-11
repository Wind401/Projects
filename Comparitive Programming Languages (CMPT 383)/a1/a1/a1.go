package main

import (
	"log"
	"bufio"
	"os"
	"strconv"
	"errors"
	"reflect"
	"path/filepath"
)

func main() {
}

func countPrimes(n int) int {
	
	sumOfPrimes := 0

	if n > 0 {
	

		i :=1

		for i <=n 	{

			if i % 2 != 0 {

				sumOfPrimes++
			}

			i++
		}
		
	}
	return sumOfPrimes
	
}


func countStrings(pathToFileName string) map[string]int {

	list := make(map[string]int)
	absPath, _ := filepath.Abs(pathToFileName)
	file,err := os.Open(absPath)

	if err!= nil {
		log.Fatal(err)
	}

	defer file.Close()

	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanWords)

	for scanner.Scan() {

		if _, ok := list[scanner.Text()]; ok {

			list[scanner.Text()]++

		} else {

			list[scanner.Text()] = 1

		}

	}

	return list
}

type Time24 struct {
	hour, minute, second uint8
}


func equalsTime24(a Time24, b Time24) bool {

	return a.hour == b.hour && a.minute == b.minute && a.second == b.second
		
}

func lessThanTime24(a Time24, b Time24) bool{

	if a.hour < b.hour {

		return true

	} else if a.hour == b.hour && a.minute < b.minute {

		return true

	} else if a.hour == b.hour && a.minute == b.minute && a.second < b.second {

		return true

	} else {

		return false
	}

}

func (t Time24) String() string {

	var hour = strconv.Itoa(int(t.hour))
	var minute = strconv.Itoa(int(t.minute))
	var second = strconv.Itoa(int(t.second))
	var finalString string

	if t.hour < 10 {

		hour = "0" + hour

	}

	if t.minute < 10 {

		minute = "0" + minute

	}

	if t.second < 10 {

		second = "0" + second

	}

	finalString = hour + ":" + minute + ":" + second
	
	return finalString
}

func (a Time24) validTime24() bool {

	return a.hour >= 0 && a.hour < 25 && a.minute >=0 && a.minute < 60 && a.second >=0 && a.second < 60

}

func minTime24(times []Time24) (Time24, error) {
	
	minTime := Time24{hour: 0, minute: 0, second: 0}

	if len(times) == 0 {

		return minTime, errors.New("Empty List")

	} else {

		minTime = times[0]

		for i :=0; i < len(times) - 1; i++ {

			if lessThanTime24(times[i], times[i+1]) == false {

				minTime = times[i+1]

			}
		}

		return minTime, nil
	}
}

func linearSearch(x interface{}, lst interface{}) int {
	index := -1
	switch reflect.TypeOf(lst).Kind() {
	case reflect.Slice:
		s := reflect.ValueOf(lst)
		for i := 0; i < s.Len(); i++ {
			if reflect.TypeOf(x) != s.Index(i).Type() {
				message := "type '" + reflect.TypeOf(x).String() + "' of search value does not match type '" + s.Index(i).Type().String() + "' of list values"
				panic(message)
			}
			switch x.(type) {
			case int:
				if int64(x.(int)) == s.Index(i).Int() {
					index = i
				}
			case float64:
				if x.(float64) == s.Index(i).Float() {
					index = i
				}
			case string:
				if x.(string) == s.Index(i).String() {
					index = i
				}
			default:
				panic("type is not supported")
			}
		}
	}
	return index
}
