import requests

#url = 'http://35.190.155.168/2923d13786/'
url = list()
url.append('http://35.190.155.168/4a7ea4144d/')
url.append('http://35.190.155.168/4a7ea4144d/background.png')

f = open("Level0.htlm", "w")
for i in url:
	a = requests.get(i)

	f.write(str(a.text))
	f.write("\n\n\n\n\n")
	f.write(str(a.content))
	f.write("\n\n\n\n\n")

f.close()
