
def main():

	for line in cin:
		ls = list(line)
		for i in range(len(ls)):
			if ls[i] == '=':
				j = i + 1
				while ls[j].isdigit() or ls[j] == '-':
					cout.write(ls[j])
					j += 1
				cout.write(" ")
		cout.write("\n")

		#cout.write("\n")
	#cout.write(str(n) + '\n')

if __name__ == "__main__":
	cin = open('inputf.in', 'r')
	cout = open('outputf.out', 'w')
	main()
	cin.close()
	cout.close()

''''
Sensor at x=1259754, y=1927417: closest beacon is at x=1174860, y=2000000,
Sensor at x=698360, y=2921616: closest beacon is at x=1174860, y=2000000,
Sensor at x=2800141, y=2204995: closest beacon is at x=3151616, y=2593677,
Sensor at x=3257632, y=2621890: closest beacon is at x=3336432, y=2638865,
Sensor at x=3162013, y=3094407: closest beacon is at x=3151616, y=2593677,
Sensor at x=748228, y=577603: closest beacon is at x=849414, y=-938539,
Sensor at x=3624150, y=2952930: closest beacon is at x=3336432, y=2638865,
Sensor at x=2961687, y=2430611: closest beacon is at x=3151616, y=2593677,
Sensor at x=142293, y=3387807: closest beacon is at x=45169, y=4226343,
Sensor at x=3309479, y=1598941: closest beacon is at x=3336432, y=2638865,
Sensor at x=1978235, y=3427616: closest beacon is at x=2381454, y=3683743,
Sensor at x=23389, y=1732536: closest beacon is at x=1174860, y=2000000,
Sensor at x=1223696, y=3954547: closest beacon is at x=2381454, y=3683743,
Sensor at x=3827517, y=3561118: closest beacon is at x=4094575, y=3915146,
Sensor at x=3027894, y=3644321: closest beacon is at x=2381454, y=3683743,
Sensor at x=3523333, y=3939956: closest beacon is at x=4094575, y=3915146,
Sensor at x=2661743, y=3988507: closest beacon is at x=2381454, y=3683743,
Sensor at x=2352285, y=2877820: closest beacon is at x=2381454, y=3683743,
Sensor at x=3214853, y=2572272: closest beacon is at x=3151616, y=2593677,
Sensor at x=3956852, y=2504216: closest beacon is at x=3336432, y=2638865,
Sensor at x=219724, y=3957089: closest beacon is at x=45169, y=4226343,
Sensor at x=1258233, y=2697879: closest beacon is at x=1174860, y=2000000,
Sensor at x=3091374, y=215069: closest beacon is at x=4240570, y=610698,
Sensor at x=3861053, y=889064: closest beacon is at x=4240570, y=610698,
Sensor at x=2085035, y=1733247: closest beacon is at x=1174860, y=2000000,

1259754 1927417 1174860 2000000 
698360 2921616 1174860 2000000 
2800141 2204995 3151616 2593677 
3257632 2621890 3336432 2638865 
3162013 3094407 3151616 2593677 
748228 577603 849414 -938539 
3624150 2952930 3336432 2638865 
2961687 2430611 3151616 2593677 
142293 3387807 45169 4226343 
3309479 1598941 3336432 2638865 
1978235 3427616 2381454 3683743 
23389 1732536 1174860 2000000 
1223696 3954547 2381454 3683743 
3827517 3561118 4094575 3915146 
3027894 3644321 2381454 3683743 
3523333 3939956 4094575 3915146 
2661743 3988507 2381454 3683743 
2352285 2877820 2381454 3683743 
3214853 2572272 3151616 2593677 
3956852 2504216 3336432 2638865 
219724 3957089 45169 4226343 
1258233 2697879 1174860 2000000 
3091374 215069 4240570 610698 
3861053 889064 4240570 610698 
2085035 1733247 1174860 2000000 


'''


