import requests
import json
query = input("Enter the topic of query you want the news: ")

url =f"https://newsapi.org/v2/everything?q={query}&from=2023-11-24&sortBy=publishedAt&apiKey=f8a34d116fa14d57b15ad17bccd69e7f"
r = requests.get(url)
news = json.loads(r.text)
for article in news["articles"]:
  print(article["title"])
  print(article["description"])
  print("----------------------------------------------------------------------------------------------------")