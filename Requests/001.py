import requests

res = requests.get('http://www.vik.bme.hu/en/')

print(res.text)



