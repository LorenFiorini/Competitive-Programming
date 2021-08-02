import requests


f = open("Level1.txt", "w")
url = []
url.append('http://35.190.155.168/c65cf2a398/')
url.append('http://35.190.155.168/c65cf2a398/page/1')
url.append('http://35.190.155.168/c65cf2a398/page/2')
url.append('http://35.190.155.168/c65cf2a398/page/create')
url.append('http://35.190.155.168/c65cf2a398/page/12')

for i in range(len(url)):
	a = requests.get(url[i])
	f.write(a.text)
	f.write("\n\n\n\n\n")


b = requests.post('http://35.190.155.168/c65cf2a398/page/create')

f.write(b.text)









