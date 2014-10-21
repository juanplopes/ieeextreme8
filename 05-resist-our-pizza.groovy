// your code goes here//Enter your code here. Read input from STDIN. Print output to STDOUT
Scanner s = new Scanner(System.in)

def d = s.nextInt()
def n = 0;
def totalSlices = 0
def str
def c = 0
def toppingMap = ['Anchovies': 50, 'Artichoke' : 60, 'Bacon' : 92, 'Broccoli' : 24,
'Cheese' : 80, 'Chicken' : 30, 'Feta' : 99, 'Garlic' : 8, 'Ham' : 46,
'Jalapeno' : 5, 'Meatballs' : 120, 'Mushrooms' : 11, 'Olives' : 25, 'Onions' : 11,
'Pepperoni' : 80, 'Peppers' : 6, 'Pineapple' : 21, 'Ricotta' : 108, 'Sausage' : 115,
'Spinach' : 18, 'Tomatoes' : 14]
for (int i = 0; i < d; ++i) {
	n = s.nextInt();
	str = s.next();
	str = str.split(',')
	for (topping in str) {
		c+=toppingMap[topping]*n;
	}
	totalSlices += n;
}

println "The total calorie intake is " + ((270*totalSlices)+c)